#include "../include/paciente.h"

struct paciente{
    char nome[100];
    char cpf[20];
    char idade[4];
    Consulta * historico_consultas;
    Paciente * prox_elemento;
};

Paciente *encontra_paciente(Paciente *lista_pacientes, char cpf[20]) {
    formata_cpf(cpf); 
    Paciente *auxiliar;
    for (auxiliar = lista_pacientes; auxiliar != NULL; auxiliar = auxiliar->prox_elemento) {
        if (strcmp(auxiliar->cpf, cpf) == 0)
            return auxiliar;
    }
    return NULL;
}

Paciente *insere_consulta(Paciente * lista_pacientes, int *qnt){
    char cpf[15];
    Consulta consulta_nova = nova_consulta(qnt);
    printf("\nQual é o cpf do paciente? ");
    scanf(" %[^\n]", cpf);
    formata_cpf(cpf);
    if (verifica_cpf_paciente(lista_pacientes, cpf) == 0) {
        Paciente * aux = encontra_paciente(lista_pacientes, cpf);
        aux->historico_consultas = adiciona_consulta(aux->historico_consultas, consulta_nova);
        return lista_pacientes;
    } else {
        printf("\nEsse paciente ainda não existe, cadastre-o para adicionar sua consulta.\n");
        return lista_pacientes;
    }
}

Paciente *remover_consulta_lista_pacientes(Paciente * lista_pacientes, int id_digitado){
    char cpf[15];
    printf("\nQual é o cpf do paciente que deseja retirar a consulta? ");
    scanf(" %[^\n]", cpf);
    formata_cpf(cpf);
    if (verifica_cpf_paciente(lista_pacientes, cpf) == 0) {
        Paciente * aux = encontra_paciente(lista_pacientes, cpf);
        aux->historico_consultas = remove_consulta(aux->historico_consultas, id_digitado);
        return lista_pacientes;
    } else {
        printf("\nEsse paciente ainda não existe.\n");
        return lista_pacientes;
    }
}


int verifica_cpf_paciente(Paciente *lista_pacientes, char cpf[20]){
    Paciente *listaAux = lista_pacientes; 

    while(listaAux != NULL){ 
        if(strcmp(listaAux->cpf, cpf) == 0){ 
            return 0;
        }
        listaAux = listaAux->prox_elemento; 
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

Paciente *adiciona_paciente(Paciente *lista_pacientes, Paciente paciente) {
    Paciente *novo = (Paciente *)malloc(sizeof(Paciente));
    if (novo == NULL) {
        perror("Erro ao alocar memoria");
        exit(1);
    }

    strcpy(novo->cpf, paciente.cpf);
    strcpy(novo->nome, paciente.nome);
    strcpy(novo->idade, paciente.idade);
    novo->prox_elemento = NULL;
    novo->historico_consultas = paciente.historico_consultas;

    if (lista_pacientes == NULL || strcmp(lista_pacientes->nome, paciente.nome) > 0) {
        novo->prox_elemento = lista_pacientes;
        return novo;
    }

    Paciente *anterior = NULL;
    Paciente *atual = lista_pacientes;

    while (atual != NULL && strcmp(atual->nome, paciente.nome) < 0) {
        anterior = atual;
        atual = atual->prox_elemento;
    }

    anterior->prox_elemento = novo;
    novo->prox_elemento = atual;

    return lista_pacientes;
}

Paciente novo_paciente(Paciente * lista_pacientes) {
    cabecalho("--------------", "Adicionar Paciente");

    Paciente novo;
    
    char cpf_digitado[20], nome_digitado[100], idade_digitada[4];

    do {
        printf("Digite o CPF (apenas números): ");
        scanf(" %[^\n]", cpf_digitado);
    } while (verifica_cpf_paciente(lista_pacientes, cpf_digitado) == 0 || numero_inteiroc(cpf_digitado) == 0 || strlen(cpf_digitado) != 11);

     formata_cpf(cpf_digitado); // Formata o CPF

    do {
        printf("\nDigite o nome do paciente: ");
        scanf(" %99[^\n]", nome_digitado);
    } while (!contem_apenas_letras(nome_digitado));

    formata_string(nome_digitado);
    
    do {
        printf("\nDigite a idade do paciente: ");
        scanf(" %3[^\n]", idade_digitada);
    } while (!numero_inteiroc(idade_digitada));

    strcpy(novo.cpf, cpf_digitado);
    strcpy(novo.nome, nome_digitado);
    strcpy(novo.idade, idade_digitada);
    novo.historico_consultas = NULL;
    novo.prox_elemento = NULL;

    return novo;
}


void upper_string(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);
    }
}

void buscar_paciente_por_nome(Paciente *lista_pacientes, char *nome) {
    upper_string(nome); 

    Paciente *atual = lista_pacientes;
    int encontrado = 0;

    while (atual != NULL) {
        char *nome_paciente = atual->nome;
        upper_string(nome_paciente);

        if (strstr(nome_paciente, nome) != NULL) {
            printf("Paciente encontrado:\n");
            formata_string(nome_paciente);
            printf("Nome: %s\n", atual->nome);
            printf("CPF: %s\n", atual->cpf);
            printf("Idade: %s\n", atual->idade);

            Consulta *consulta_atual = atual->historico_consultas;
            if (consulta_atual != NULL) {
                printf("Historico de consultas:\n");
                while (consulta_atual != NULL) {
                    printf("Data: %s\n", consulta_atual->data);
                    printf("ID: %d\n", consulta_atual->id);
                    printf("Valor da consulta: R$%s\n", consulta_atual->preco);
                    printf("Descricao: %s\n", consulta_atual->descricao);
                    consulta_atual = consulta_atual->prox_elemento;
                }
                sleep(3);
            } 
            else {
                printf("Este paciente ainda não possui histórico de consultas.\n");
            }

            encontrado = 1;
        }
        atual = atual->prox_elemento;
    }

    if (!encontrado) {
        printf("Paciente não encontrado!\n");
    }
}


void carrega_dados_para_arquivo(Paciente * lista_pacientes){
    FILE * arquivo = fopen("pacientes.txt", "r");


}