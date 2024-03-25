#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/consultas.h"

struct consulta{
    char id[10];
    char data[6];
    char valor[10];
};

void adicionar_consulta() {
    FILE *file;
    Consulta consulta;

    printf("Digite o ID da consulta: ");
    scanf("%s", consulta.id);

    printf("Digite a data da consulta: ");
    scanf("%s", consulta.data);

    printf("Digite o valor da conculta: ");
    scanf("%s", consulta.valor);

    printf("Digite a descricao da consulta: ");
    getchar();
    consulta.descricao = (char *)malloc(100 * sizeof(char)); 
    fgets(consulta.descricao, 100, stdin);

    // Abrir o arquivo para adicionar a consulta
    file = fopen("consultas.txt", "a");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    // Escrever a consulta no arquivo
    fprintf(file, "%s %s %s %s\n", consulta.id, consulta.data, consulta.preco, consulta.descricao);

    fclose(file);

    printf("Consulta adicionada com sucesso.\n");
}
