#include "include/consultas.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

struct paciente{
    char nome[100];
    char cpf[12];
    char idade[3];
    Consulta * historico_consultas;
};

int contem_apenas_letras(char *str) {
    for (int index = 0; str[index] != '\0'; index++) {
        if (!isalpha(str[index]) && str[index] != ' ') {
            printf("\nA string deve conter apenas letras.");
            return 0; 
        }
    }
    return 1; 
}

int numero_inteiroc(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void formata_string(char *str){
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (i==0){
            str[0] = toupper(str[0]);
        }
        else{
            if (str[i - 1] == ' ') {
                str[i] = toupper(str[i]);
            } 
            else {
                str[i] = tolower(str[i]);
            }
        }
    }
}

int verifica_cpf(char *cpf_digitado) {
    char linha[300];
    char cpf_arquivo[100];
    char idade_arquivo[100];
    char nome_arquivo[100];

    FILE *arquivo = fopen("pacientes.txt", "r"); 
    if (arquivo == NULL) {
        printf("\nErro ao abrir o arquivo.");
        return menu; 
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) { 
        if (sscanf(linha, "%99[^\t]\t%11[^\t]\t%2[^\t ]", nome_arquivo, cpf_arquivo, idade_arquivo) == 3) {
            if (strcmp(cpf_arquivo, cpf_digitado) == 0) {
                printf("\nEsse cliente ja foi cadastrado.");
                fclose(arquivo);
                return 1; 
            }
        }
    }

    fclose(arquivo);
    return 0; 
}

Paciente * novo_paciente (){
    char nome_digitado[100];
    char cpf_digitado[11];
    char idade_digitada[3];

    do{
        printf("\nDigite o nome do paciente: ");
        scanf("%99[^\n]", nome_digitado);
    }while(!contem_apenas_letras(nome_digitado));

    formata_string(nome_digitado);
    strcpy(nome_digitado, paciente->nome);

    do{
        printf("\nDigite o cpf do paciente: ");
        scanf("%11[^\n]", cpf_digitado);
        getchar();
    }while (!numero_inteiroc(cpf_digitado) || verifica_cpf(cpf_digitado));

    do{
    printf("\nDigite a idade do paciente: ");
    scanf("%2[^\n]", idade_digitada);
    getchar();
    }while (!numero_inteiroc(idade_digitada));
}



void procura_nome() {
    char nome_digitado[100];
    char linha[300];

    FILE *arquivo = fopen("pacientes.txt", "a");
    FILE *arquivo = fopen("consultas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    do{
        printf("Digite o nome do paciente que deseja buscar: ");
        scanf(" %99[^\n]", nome_digitado);
    } while (!contem_apenas_letras(nome_digitado));
    int encontrou = 0;

    formata_string(nome_digitado);

    while (fgets(linha, sizeof(linha), arquivo)) {
        char nome_arquivo[100], cpf_arquivo[12], idade_arquivo[3];
        if (sscanf(linha, "%99[^\t]\t%99[^\t]\t%99[^\t ]", nome_arquivo, cidade, codigo) >= 2) {
            if (strcmp(nome_arquivo, nome_digitado) == 0 || strstr(nome_arquivo, nome_digitado) != NULL) {
                printf("Nome %s\nCPF: %s\nIdade: %s\n", nome_arquivo, cpf_arquivo, idade_arquivo);
                //Vou colocar aqui a parte de abrir o arquiv de consultas e, de acorod com o CPF:
                // while (fgets(linha, sizeof(linha), arquivo)) {
                //     char nome_arquivo[100], cpf_arquivo[12], idade_arquivo[3];
                //     if (sscanf(linha, "%99[^\t]\t%99[^\t]\t%99[^\t ]", nome_arquivo, cidade, codigo) >= 2) {
                //         if (strcmp(nome_arquivo, nome_digitado) == 0 || strstr(nome_arquivo, nome_digitado) != NULL) {
                //             printf("Nome %s\nCPF: %s\nIdade: %s\n", nome_arquivo, cpf_arquivo, idade_arquivo);

                //             encontrou = 1;
                //         }
                //     }
                // }

                encontrou = 1;
            }
        }
    }

    if (!encontrou) {
        printf("Cliente nao encontrado!\n");
    }

    pressiona_enter();
    fclose(arquivo);
}