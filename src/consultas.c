#include "../include/consultas.h"


typedef struct consulta{
    int id;
    char data[11];
    char preco[10];
    char descricao[100];
    Consulta *prox_elemento;
}Consulta;



Consulta *adiciona_consulta(Consulta * lista_consultas, Consulta nova_consulta){
    Consulta * nova = (Consulta*) malloc(sizeof(Consulta));
    nova->id = nova_consulta.id;
    strcpy(nova->preco, nova_consulta.preco);
    strcpy(nova->descricao, nova_consulta.descricao);
    strcpy(nova->data, nova_consulta.data);
    nova->prox_elemento = NULL;
    if (lista_consultas == NULL){
        return nova;
    }
    Consulta *atual = lista_consultas;
    Consulta *anterior = NULL;
    while (atual != NULL)
    {
        anterior = atual;
        atual = atual->prox_elemento;
    }
    anterior->prox_elemento = nova;
    nova->prox_elemento = atual;
    return lista_consultas;
}

Consulta nova_consulta(int *qnt){
    Consulta consulta;
    char data[11], preco[10], descricao[100];
    do {
        printf("Digite a data (DD/MM/AAAA): ");
        scanf(" %[^\n]", data);
    } while (!data_valida(data) || strlen(data) > 10); 

    do {
        printf("Digite o preco (apenas uma virgula): ");
        scanf(" %[^\n]", preco);
        fflush(stdin);
    } while (numero_decimal(preco) == 0 || strlen(preco) > 9);
    
    do {
        printf("Digite a descricao: ");
        scanf(" %99[^\n]", descricao);
    } while (contem_apenas_letras(descricao) == 0);
    fflush(stdin);
    strcpy(consulta.data, data);
    strcpy(consulta.preco, preco);
    strcpy(consulta.descricao, descricao);
    consulta.id = (*qnt) + 100;
    (*qnt)++;
    consulta.prox_elemento = NULL;
    return consulta;
}

void imprimir_consultas(Consulta *lista_consultas) {
    Consulta *atual = lista_consultas;

    if (atual == NULL) {
        printf("\nNao há consultas para imprimir.\n");
    }

    printf("Lista de consultas:\n");
    printf("ID\tData\t\tPreco\tDescricao\n");

    while (atual != NULL) {
        printf("%d\t%s\t%s\t%s\n", 
               atual->id, 
               atual->data, 
               atual->preco, 
               atual->descricao);
        atual = atual->prox_elemento;
    }
}

Consulta *remove_consulta(Consulta *lista_consultas, int id_digitado) {
    Consulta *anterior = NULL;
    Consulta *novo = lista_consultas;

    while (novo != NULL && novo->id != id_digitado) {
        anterior = novo;
        novo = novo->prox_elemento;
    }

    if (novo == NULL) {
        printf("\nConsulta nao encontrada");
        return lista_consultas;
    }

    if (anterior == NULL) {
        lista_consultas = novo->prox_elemento;
    } 
    else {
        anterior->prox_elemento = novo->prox_elemento;
    }

    free(novo);    
    return lista_consultas;
}
