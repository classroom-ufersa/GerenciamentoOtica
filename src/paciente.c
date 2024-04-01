#include "../include/consultas.h"
#include "../include/paciente.h"
#include "../include/tratativas.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

struct paciente{
    char nome[100];
    char cpf[12];
    char idade[4];
    Consulta * historico_consultas;
    Paciente * prox_elemento;
};

typedef struct lista_pacientes {
    Paciente paciente;
    struct lista_pacientes *prox;
}ListaPacientes;

void cria_lista_paciente(ListaPacientes **listap) { 
    *listap = NULL;
}

int verifica_cpf_paciente(ListaPacientes **lista, char cpf[12]){
    ListaPacientes *listaAux = *lista; 

    while(listaAux != NULL){ 
        if(strcmp(listaAux->paciente.cpf, cpf) == 0){ 
            return 0;
        }
        listaAux = listaAux->prox; 
    }
    return 1;
}

void formata_string(char *str) {
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




Paciente *novo_paciente(ListaPacientes **lista) {
    cabecalho("============", "Adicionar Cliente");
    Paciente *novo = (Paciente *)malloc(sizeof(Paciente));
    if (novo == NULL) {
        printf("\nErro ao alocar memória!");
        return menu;
    }
    
    char cpf_digitado[12], nome_digitado[100], idade_digitada[4];

    do {
        printf("Digite o CPF (apenas números): ");
        scanf(" %11[^\n]", cpf_digitado);
    } while (verifica_cpf_paciente(lista, cpf_digitado) == 0 || numero_inteiroc(cpf) == 0 || strlen(cpf) != 11);

    cpf_formatado = formata_cpf(cpf); // Formata o CPF

    do {
        printf("\nDigite o nome do paciente: ");
        scanf(" %99[^\n]", nome_digitado);
    } while (!contem_apenas_letras(nome_digitado));

    formata_string(nome_digitado);
    
    do {
        printf("\nDigite a idade do paciente: ");
        scanf(" %3[^\n]", idade_digitada);
    } while (!numero_inteiroc(idade_digitada));

    strcpy(novo->cpf, cpf_digitado);
    strcpy(novo->nome, nome_digitado);
    strcpy(novo->idade, idade_digitada);
    novo->historico_consultas = NULL;
    novo->prox_elemento = NULL;

    return novo;
}

void adicionar_paciente(ListaPacientes **lista) {
    Paciente *novo = novo_paciente(lista);

    ListaPacientes *novo_elemento = (ListaPacientes *)malloc(sizeof(ListaPacientes));
    if (novo_elemento == NULL) {
        printf("\nErro ao alocar memória!");
        exit(1);
    }

    novo_elemento->paciente = *novo;
    novo_elemento->prox = *lista;
    *lista = novo_elemento;

    printf("\nPaciente cadastrado com sucesso!");
}

void remover_paciente(ListaPacientes **lista, char *cpf) {
    ListaPacientes *atual = *lista;
    ListaPacientes *anterior = NULL;

    // Percorre a lista de pacientes
    while (atual != NULL) {
        if (strcmp(atual->paciente.cpf, cpf) == 0) { // Se o CPF corresponder
            // Remove as consultas associadas ao paciente
            Consulta *consulta_atual = atual->paciente.historico_consultas;
            while (consulta_atual != NULL) {
                Consulta *temp = consulta_atual;
                consulta_atual = consulta_atual->prox;
                free(temp); // Libera a memória da consulta
            }

            // Remove o paciente da lista
            if (anterior == NULL) { // Se o paciente for o primeiro da lista
                *lista = atual->prox;
            } 
            else {
                anterior->prox = atual->prox;
            }
            
            free(atual); // Libera a memória do nó paciente removido
            printf("\nPaciente removido com sucesso!");
            return menu;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Paciente com CPF %s não encontrado!\n", cpf);
}


void upper_string(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void buscar_paciente_por_nome(ListaPacientes *lista, char *nome) {
    upper_string(nome); // Converte o nome digitado para letras maiúsculas

    ListaPacientes *atual = lista;
    int encontrado = 0;

    while (atual != NULL) {
        char *nome_paciente = atual->paciente.nome;
        upper_string(nome_paciente);

        if (strstr(nome_paciente, nome) != NULL) {
            printf("Paciente encontrado:\n");
            printf("Nome: %s\n", atual->paciente.nome);
            printf("CPF: %s\n", atual->paciente.cpf);
            printf("Idade: %s\n", atual->paciente.idade);

            Consulta *consulta_atual = atual->paciente.historico_consultas;
            if (consulta_atual != NULL) {
                printf("Historico de consultas:\n");
                while (consulta_atual != NULL) {
                    printf("Data: %s\n", consulta_atual->data);
                    printf("CPF do paciente: %s\n", consulta_atual->cpf);
                    printf("ID: %s\n", consulta_atual->id);
                    printf("Valor da consulta: %s\n", consulta_atual->preco);
                    printf("Descricao: %s\n", consulta_atual->descricao);
                    consulta_atual = consulta_atual->prox;
                }
            } else {
                printf("Este paciente ainda não possui histórico de consultas.\n");
            }

            encontrado = 1;
        }
        atual = atual->prox;
    }

    if (!encontrado) {
        printf("Paciente não encontrado!\n");
    }
}

void busca_paciente() {
    char nome_digitado[100];

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