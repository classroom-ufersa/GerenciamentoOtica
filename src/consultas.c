#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/consultas.h"
#include "../include/retrativas.h"

typedef struct consulta {
    char id[10];
    char data[10];
    char preco[10];
    char descricao[100];
}Consulta;

//coloca as retrativas nesse arquivo?
void adiciona_consulta() {
    Consulta consulta;
    char *caminho = "resources/consultas.txt";
    FILE *arquivo = fopen(caminho, "a"); 
    if(arquivo == NULL) { 
        printf("Erro ao abrir o aquivo.\n");
        return;
    }

    char id_digitado[10];
    char data_digitada[100];
    char preco_digitado[10];
    char descricao_digitada[100]; 

    do{
    printf("\nDigite o ID da consulta: ");
    scanf("%99[^\n]", id_digitado);
    getchar();
    }while (!numero_inteiroc(id_digitado) || verifica_codigo(id_digitado));

    strcpy(consulta.id, id_digitado);

    do{
    printf("\nDigite a data da consulta: ");
    scanf("%99[^\n]", data_digitada);
    getchar();
    }while (!numero_inteiroc(data_digitada));

    strcpy(consulta.data, data_digitada);

    do{
    printf("\nDigite o preço da consulta: ");
    scanf("%99[^\n]", preco_digitado);
    getchar();
    }while (!numero_inteiroc(preco_digitado));

    strcpy(consulta.preco, preco_digitado);

    do{
    printf("\nDigite a descrição da consulta: ");
    scanf("%99[^\n]", descricao_digitada);
    getchar();
    }while (!contem_apenas_letras(descricao_digitada));

    formata_string(descricao_digitada);
    strcpy(consulta.descricao, descricao_digitada);

    fprintf(arquivo, "\n%s \t %s \t %s \n", consulta.id, consulta.data, consulta.preco, consulta.descricao);

    fclose(arquivo);
}