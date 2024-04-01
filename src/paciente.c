#include "../include/paciente.h"

struct paciente{
    char nome[100];
    char cpf[15];
    char idade[4];
    Consulta * historico_consultas;
    Paciente * prox_elemento;
};

 Paciente * encontra_paciente(Paciente * lista_pacientes, char cpf[12]){
    Paciente * auxiliar;
	for (auxiliar = lista_pacientes; auxiliar != NULL; auxiliar = auxiliar->prox_elemento){
        formata_cpf(cpf);
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
    if (verifica_cpf_paciente(lista_pacientes, cpf) == 0) {
        // O paciente existe, então adicionamos a nova consulta
        // Encontre o paciente na lista usando uma função auxiliar que será criada depois;
        Paciente *aux = encontra_paciente(lista_pacientes, cpf);
        aux->historico_consultas = adiciona_consulta(aux->historico_consultas, consulta_nova);
        return lista_pacientes;
    } else {
        printf("\nEsse paciente ainda não existe, cadastre-o para adicionar sua consulta.\n");
        return lista_pacientes;
    }
}


int verifica_cpf_paciente(Paciente *lista_pacientes, char cpf[15]){
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
    
    char cpf_digitado[15], nome_digitado[100], idade_digitada[4];

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



// void remover_paciente(ListaPacientes **lista, char *cpf) {
//     ListaPacientes *atual = *lista;
//     ListaPacientes *anterior = NULL;
//     int encontrado = 0;

//     // Percorre a lista de pacientes
//     while (atual != NULL) {
//         if (strcmp(atual->paciente.cpf, cpf) == 0) { // Se o CPF corresponder
//             // Remove as consultas associadas ao paciente
//             Consulta *consulta_atual = atual->paciente.historico_consultas;
//             while (consulta_atual != NULL) {
//                 Consulta *temp = consulta_atual;
//                 consulta_atual = consulta_atual->prox_elemento;
//                 free(temp); // Libera a memória da consulta
//             }

//             // Remove o paciente da lista
//             if (anterior == NULL) { // Se o paciente for o primeiro da lista
//                 *lista = atual->prox;
//             } 
//             else {
//                 anterior->prox = atual->prox;
//             }
            
//             free(atual); // Libera a memória do nó paciente removido
//             printf("\nPaciente removido com sucesso!");
//             encontrado = 1;
//             break; // Sair do laço após remover o paciente
//         }
//         anterior = atual;
//         atual = atual->prox;
//     }
//     if (!encontrado) {
//         printf("Paciente com CPF %s não encontrado!\n", cpf);
//     }
// }


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
            } else {
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


// void busca_paciente() {
//     char nome_digitado[100];

//     FILE *arquivo = fopen("pacientes.txt", "a");
//     FILE *arquivo = fopen("consultas.txt", "r");
//     if (arquivo == NULL) {
//         printf("Erro ao abrir o arquivo.\n");
//         return;
//     }

//     do{
//         printf("Digite o nome do paciente que deseja buscar: ");
//         scanf(" %99[^\n]", nome_digitado);
//     } while (!contem_apenas_letras(nome_digitado));
//     int encontrou = 0;

//     formata_string(nome_digitado);

//     while (fgets(linha, sizeof(linha), arquivo)) {
//         char nome_arquivo[100], cpf_arquivo[12], idade_arquivo[3];
//         if (sscanf(linha, "%99[^\t]\t%99[^\t]\t%99[^\t ]", nome_arquivo, cidade, codigo) >= 2) {
//             if (strcmp(nome_arquivo, nome_digitado) == 0 || strstr(nome_arquivo, nome_digitado) != NULL) {
//                 printf("Nome %s\nCPF: %s\nIdade: %s\n", nome_arquivo, cpf_arquivo, idade_arquivo);
//                 //Vou colocar aqui a parte de abrir o arquiv de consultas e, de acorod com o CPF:
//                 // while (fgets(linha, sizeof(linha), arquivo)) {
//                 //     char nome_arquivo[100], cpf_arquivo[12], idade_arquivo[3];
//                 //     if (sscanf(linha, "%99[^\t]\t%99[^\t]\t%99[^\t ]", nome_arquivo, cidade, codigo) >= 2) {
//                 //         if (strcmp(nome_arquivo, nome_digitado) == 0 || strstr(nome_arquivo, nome_digitado) != NULL) {
//                 //             printf("Nome %s\nCPF: %s\nIdade: %s\n", nome_arquivo, cpf_arquivo, idade_arquivo);

//                 //             encontrou = 1;
//                 //         }
//                 //     }
//                 // }

//                 encontrou = 1;
//             }
//         }
//     }

//     if (!encontrou) {
//         printf("Cliente nao encontrado!\n");
//     }

//     pressiona_enter();
//     fclose(arquivo);
// }