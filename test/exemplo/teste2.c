#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct consulta { 
    char cpf[20];
    char id[10];
    char data[10];
    char preco[10];
    char descricao[100];
} Consulta;

typedef struct listaconsultas { 
    Consulta consulta; 
    struct listaconsultas *prox; 
} ListaConsultas;

void cria_lista_consultas(ListaConsultas **lista) { 
    *lista = NULL;
}

//tratativa que verifica se tem o id na lista de consultas
int verifica_id_consulta(ListaConsultas **lista, char id[10]) {
    ListaConsultas *listaAux = *lista; 

    while(listaAux != NULL){ 
        if(strcmp(listaAux->consulta.id, id) == 0){ 
            printf("ID ja existe.\n");
            return 0;
        }
        listaAux = listaAux->prox; 
    }
    return 1;
}
//tratativa que verfica se é número inteiro
int numero_inteiroc(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

//tratativa que verifica se a string contém apenas letras
int contem_apenas_letras(char *str) {
    for (int index = 0; str[index] != '\0'; index++) {
        if (!isalpha(str[index]) && str[index] != ' ') {
            printf("A string deve conter apenas letras.\n");
            return 0;
        }
    }
    return 1;
}

int verifica_cpf(ListaConsultas **lista, char cpf[20]){
    ListaConsultas *listaAux = *lista; 

    while(listaAux != NULL){ 
        if(strcmp(listaAux->consulta.cpf, cpf) == 0){ 
            return 0;
        }
        listaAux = listaAux->prox; 
    }
    return 1;
}

void adicionar_consulta(ListaConsultas **lista) {
    //se atentar ao nome da lista no verifica_cpf que Hillary vai implementar
    int continuar = 1; 
    
    do {
        char cpf[20], id[10], data[10], preco[10], descricao[100];
        
        do{
            printf("Digite o CPF: ");
            scanf("%s", cpf);
        } while(verifica_cpf(lista, cpf) == 1); //tenho  que ver issoooo depois
        

        /* 
        if(verifica_cpf(lista, cpf) == 0){
            printf("Paciente nao encontrado.");
            //return menu();
        }*/ 

        do {
            printf("Digite o ID: ");
            scanf("%s", id);
        } while (verifica_id_consulta(lista, id) == 0);

        do {
            printf("Digite o ID: ");
            scanf("%s", id);
        } while (numero_inteiroc(id) == 0);
        
        do{
            printf("Digite a data: ");
            scanf("%s", data);
        } while(numero_inteiroc(data) == 0); 
        
        do{
            printf("Digite o preco: ");
            scanf("%s", preco);
        } while(numero_inteiroc(preco) == 0);
        
        do{
            printf("Digite a descricao: ");
            scanf("%s", descricao);
        } while(contem_apenas_letras(descricao) == 0);
        
        ListaConsultas *novo = (ListaConsultas*)malloc(sizeof(ListaConsultas)); 
        
        // Copia os dados fornecidos para a estrutura de consulta do novo elemento
        strcpy(novo->consulta.cpf, cpf);
        strcpy(novo->consulta.id, id);
        strcpy(novo->consulta.data, data);
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
        printf("Consulta nao encontrada\n");
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


int main(){
    ListaConsultas *lista;
    cria_lista_consultas(&lista);
    adicionar_consulta(&lista);
    imprimir_consultas(&lista);
    
    return 0;
}

    
    