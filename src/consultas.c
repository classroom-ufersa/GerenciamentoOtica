#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/consultas.h"
#include "../include/tratativas.h"

typedef struct consulta{
    char cpf[15];
    char id[10];
    char data[15];
    char preco[10];
    char descricao[100];
    Consulta *prox_elemento;
}Consulta;

typedef struct lista_consultas {
    Consulta consulta;
    struct lista_consultas *prox;
}ListaConsultas;

void cria_lista_consultas(ListaConsultas **lista) { 
    *lista = NULL;
}

int verifica_id_consulta(ListaConsultas **lista, char id[10]) {
    ListaConsultas *listaAux = *lista; 

    while(listaAux != NULL){ 
        if(strcmp(listaAux->consulta.id, id) == 0){ 
            printf("ID já existe.\n");
            return 0;
        }
        listaAux = listaAux->prox; 
    }
    return 1;
}

void adicionar_consulta(ListaConsultas **lista) {
    int continuar = 1; 
    char cpf[15], id[10], data[15], preco[10], descricao[100];
    char *cpf_formatado;
    char *data_format;
    
    do {
        do {
            printf("Digite o CPF (apenas números): ");
            scanf("%s", cpf);
        } while (verifica_cpf_paciente(lista, cpf) == 0 || numero_inteiroc(cpf) == 0 || strlen(cpf) != 11); 

        cpf_formatado = formata_cpf(cpf); // Formata o CPF

        do {
            printf("Digite o ID: ");
            scanf("%s", id);
        } while (verifica_id_consulta(lista, id) == 0 || numero_inteiroc(id) == 0); 

        do {
            printf("Digite a data (DD/MM/AAAA): ");
            scanf("%s", data);
        } while (!data_valida(data)); 

        // Convertendo a data para o formato numérico
        long long data_numerica = data_para_num(data);

        do {
            printf("Digite o preço: ");
            scanf("%s", preco);
        } while (numero_inteiroc(preco) == 0);
        
        do {
            printf("Digite a descrição: ");
            scanf("%s", descricao);
        } while (contem_apenas_letras(descricao) == 0);
        
        ListaConsultas *novo = (ListaConsultas*)malloc(sizeof(ListaConsultas)); 
        
        // Copiando os dados fornecidos para a estrutura de consulta do novo elemento
        strcpy(novo->consulta.cpf, cpf_formatado);
        strcpy(novo->consulta.id, id);
        strcpy(novo->consulta.data, num_para_data(data_numerica)); // Converte a data numérica para formato de string
        strcpy(novo->consulta.preco, preco);
        strcpy(novo->consulta.descricao, descricao);
        
        novo->prox = *lista; 
        *lista = novo; 
        
        printf("Deseja adicionar outra consulta? (1 - Sim, 0 - Não): ");
        scanf("%d", &continuar);
    } while (continuar);
}

void remover_consulta_por_id(ListaConsultas **lista, char id[10]){
    ListaConsultas *listaAux = *lista; 
    ListaConsultas *anterior = NULL; 

    while(listaAux != NULL && strcmp(listaAux->consulta.id, id) != 0){  
        anterior = listaAux; 
        listaAux = listaAux->prox; 
    }

    if(listaAux == NULL){ 
        printf("Consulta não encontrada\n");
        return;
    }

    if(anterior == NULL){ 
        *lista = listaAux->prox;
    }
    
    else{ 
        anterior->prox = listaAux->prox;
    }
    
    printf("Consulta removida\n"); 
    free(listaAux);
}
void imprimir_consultas (ListaConsultas **lista){ 
    ListaConsultas *listaAux = *lista; 

    printf("Consultas:\n");
    while(listaAux != NULL){ 
        printf("%s\t %s\t %s\t %s\t %s\n", listaAux->consulta.cpf, listaAux->consulta.id, listaAux->consulta.data, listaAux->consulta.preco, listaAux->consulta.descricao); //imprime os dados da consulta
        listaAux = listaAux->prox; 
    }
}

void adicionar_no_arquivo(ListaConsultas **lista){ 
    FILE *arquivo; 
    ListaConsultas *listaAux = *lista; 

    arquivo = fopen("consultas.txt", "w"); 

    while(listaAux != NULL){ 
        fprintf(arquivo, "%s\t %s\t %s\t %s\t %s\n", listaAux->consulta.cpf, listaAux->consulta.id, listaAux->consulta.data, listaAux->consulta.preco, listaAux->consulta.descricao); //escreve os dados da consulta no arquivo
        listaAux = listaAux->prox; 
    }

    fclose(arquivo); 
}