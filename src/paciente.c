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
    char cpf[20];
    Consulta consulta_nova = nova_consulta(qnt);
    do {
        printf("\nDigite o CPF do paciente que deseja adicionar a consulta(apenas numeros): ");
        scanf(" %[^\n]", cpf);
    } while (numero_inteiroc(cpf) == 0 || strlen(cpf) != 11);
    formata_cpf(cpf);
    if (verifica_cpf_paciente(lista_pacientes, cpf) == 0) {
        Paciente * aux = encontra_paciente(lista_pacientes, cpf);
        aux->historico_consultas = adiciona_consulta(aux->historico_consultas, consulta_nova);
        return lista_pacientes;
    } else {
        printf("\nEsse paciente ainda nao existe, cadastre-o para adicionar sua consulta.\n");
        return lista_pacientes;
    }
}

Paciente *remover_consulta_lista_pacientes(Paciente * lista_pacientes, int id_digitado){
    char cpf[20];
    do {
        printf("\nDigite o CPF do paciente que deseja remover a consulta(apenas numeros): ");
        scanf(" %[^\n]", cpf);
    } while (numero_inteiroc(cpf) == 0 || strlen(cpf) != 11);
    formata_cpf(cpf);
    if (verifica_cpf_paciente(lista_pacientes, cpf) == 0) {
        Paciente * aux = encontra_paciente(lista_pacientes, cpf);
        aux->historico_consultas = remove_consulta(aux->historico_consultas, id_digitado);
        return lista_pacientes;
    } else {
        printf("\nEsse paciente ainda nao existe.\n");
        return lista_pacientes;
    }
}


Paciente *remover_paciente_lista_pacientes(Paciente * lista_pacientes){
    cabecalho("----------------", "Remover Paciente");
    char cpf[20];
    do {
        printf("\nDigite o CPF do paciente que deseja remover (apenas numeros): ");
        scanf(" %[^\n]", cpf);
    } while (numero_inteiroc(cpf) == 0 || strlen(cpf) != 11);
    formata_cpf(cpf);
    if (verifica_cpf_paciente(lista_pacientes, cpf) == 0) {
        lista_pacientes = remove_paciente(lista_pacientes, cpf);
        return lista_pacientes;
    } else {
        printf("\nEsse paciente ainda nao existe.\n");
        return lista_pacientes;
    }
}

Paciente * remove_paciente(Paciente * lista_pacientes, char cpf[20]){
    Paciente *anterior = NULL;
    Paciente *novo = lista_pacientes;
    while (novo != NULL && strcmp(novo->cpf, cpf) != 0 ){ 
        anterior = novo; //
        novo = novo->prox_elemento;
    }
    if (novo == NULL){
        printf("\nPaciente nao encontrado");
        return lista_pacientes;
    }
    if (anterior == NULL){
        lista_pacientes = novo->prox_elemento;
    }
    else{
        anterior->prox_elemento = novo->prox_elemento;
    }
    free(novo);
    return lista_pacientes;
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

int verifica_cpf_paciente_edicao(Paciente *lista_pacientes, char cpf_editado[20], char cpf_antigo[20]){
    Paciente *listaAux = lista_pacientes; 
    
    if(strcmp(cpf_editado, cpf_antigo) == 0){
        printf("\nFoi digitado o mesmo cpf, entao ele continuara o mesmo depois da edicao.");
        return 1;
    }
    while(listaAux != NULL){ 
        if(strcmp(listaAux->cpf, cpf_editado) == 0){ 
            if(strcmp(listaAux->cpf, cpf_antigo) == 0){
                return 1;
            }
            return 0;
        }
        listaAux = listaAux->prox_elemento; 
    }
    return 1;
} 

Paciente * editar_paciente_lista_paciente(Paciente *lista_pacientes) {
    char cpf[20];
    do {
        printf("\nDigite o CPF do paciente que deseja editar(apenas numeros): ");
        scanf(" %[^\n]", cpf);
    } while (numero_inteiroc(cpf) == 0 || strlen(cpf) != 11);
    formata_cpf(cpf);
    if (verifica_cpf_paciente(lista_pacientes, cpf) == 0) {
        lista_pacientes = edita_paciente(lista_pacientes, cpf);
        return lista_pacientes;
    } else {
        printf("\nEsse paciente ainda nao existe, cadastre-o para edita-lo.\n");
        return lista_pacientes;
    }
}

Paciente * edita_paciente(Paciente * lista_pacientes, char cpf_antigo[20]) {
    cabecalho("--------------", "Editar Paciente");
    Paciente * copia;
    if (copia == NULL){
        printf("\nPaciente nao existe.");
    }
    else{
        for(copia = lista_pacientes; copia != NULL; copia = copia->prox_elemento){
            if (strcmp(copia->cpf, cpf_antigo) == 0){
                char cpf_digitado[20], nome_digitado[100], idade_digitada[4];

                do {
                    printf("Digite o CPF (apenas numeros): ");
                    scanf(" %[^\n]", cpf_digitado);
                } while (verifica_cpf_paciente_edicao(lista_pacientes, cpf_digitado, cpf_antigo) == 0 || numero_inteiroc(cpf_digitado) == 0 || strlen(cpf_digitado) != 11);

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

                strcpy(copia->cpf, cpf_digitado);
                strcpy(copia->nome, nome_digitado);
                strcpy(copia->idade, idade_digitada);
                return lista_pacientes;
            }
        }
        printf("\nEsse paciente nao existe, entao nao sera possivel edita-lo");

    }
    return lista_pacientes;
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
        printf("Digite o CPF (apenas numeros): ");
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

void buscar_paciente_por_nome(Paciente *lista_pacientes, char *nome) {
    upper_string(nome); 

    Paciente *atual = lista_pacientes;
    int encontrado = 0;

    while (atual != NULL) {
        char *nome_paciente = atual->nome;
        upper_string(nome_paciente);

        if (strstr(nome_paciente, nome) != NULL) {
            printf("Paciente encontrado:\n");
            formata_string(nome);
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
                printf("Este paciente ainda nao possui historico de consultas.\n");
            }
            encontrado = 1;
        }
        formata_string(nome_paciente);
        atual = atual->prox_elemento;
    }
    formata_string(nome);

    if (!encontrado) {
        printf("Paciente nao encontrado!\n");
    }
}

void lista_paciente(Paciente *lista_pacientes) {

    Paciente *atual = lista_pacientes;
    int encontrado = 0;

    if (atual == NULL){
        printf("\nAinda nao foi cadastrado nenhum paciente.");
    }
    else{
        cabecalho("====================", "Lista de Paciente");
        while (atual != NULL) {
            cabecalho("====================", "Paciente");
        
            printf("\nNome: %s\n", atual->nome);
            printf("CPF: %s\n", atual->cpf);
            printf("Idade: %s\n", atual->idade);

            Consulta *consulta_atual = atual->historico_consultas;
            if (consulta_atual != NULL) {
                cabecalho("--------------------", "Historico de Consultas");
                while (consulta_atual != NULL) {
                    printf("\nData: %s\n", consulta_atual->data);
                    printf("ID: %d\n", consulta_atual->id);
                    printf("Valor da consulta: R$%s\n", consulta_atual->preco);
                    printf("Descricao: %s\n", consulta_atual->descricao);
                    consulta_atual = consulta_atual->prox_elemento;
                    printf("\n------------------------------------------------------\n");
                }
            } 
            else {
                printf("\nEste paciente ainda nao possui historico de consultas.");
                printf("\n--------------------------------------------------------\n");
            }
            atual = atual->prox_elemento;
        }
        
    }
}

void escreve_no_arquivo(Paciente *lista_para_pacientes, char *local_do_arquivo){
    FILE *arquivo = fopen(local_do_arquivo, "wt"); 
    if (arquivo == NULL){ 
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    Paciente *aux = lista_para_pacientes; 
    while (aux != NULL){ 
        fprintf(arquivo, "Paciente:\t%s\t%s\t%s\n", aux->nome, aux->cpf, aux->idade); 
        Consulta *consultas = aux->historico_consultas; // Aponta para o histórico de consultas do paciente
        while (consultas != NULL){
            fprintf(arquivo, "Consulta: %d\t%s\t%s\t%s\n", consultas->id, consultas->data, consultas->preco, consultas->descricao);
            consultas = consultas->prox_elemento;
        }
        aux = aux->prox_elemento; 
    }
    fclose(arquivo);
}

Paciente lista_vazia(Paciente *lista_pacientes){
    if (lista_pacientes == NULL){
        // printf("\nAinda nao foi cadastrado nenhum paciente.\n");
    }
    else{
        lista_paciente(lista_pacientes);
    }
}

Paciente *ler_do_arquivo(char *local_do_arquivo, Paciente *lista_para_pacientes, int *qnt){
    FILE *arquivo = fopen(local_do_arquivo, "rt"); 
    if (arquivo == NULL){ 
        perror("Erro ao abrir o arquivo");
        exit(1);
    }
    lista_vazia(lista_para_pacientes);
    char linha[200]; 
    Paciente paciente; 
    Consulta consulta;
    int maior_id = 0; // Variável para armazenar o maior ID encontrado
    
    while (fgets(linha, 200, arquivo) != NULL){ 
        Paciente *aux;
        if (strstr(linha, "Paciente") != NULL){ 
            sscanf(linha, "Paciente:\t%[^\t\n]\t%[^\t\n]\t%[^\t\n]\n", paciente.nome, paciente.cpf, paciente.idade);
            paciente.prox_elemento = NULL; 
            paciente.historico_consultas = NULL; 
            lista_para_pacientes = adiciona_paciente(lista_para_pacientes, paciente); 
            aux = encontra_paciente(lista_para_pacientes, paciente.cpf);
        } 
        else{ 
            sscanf(linha,"Consulta: %d\t%[^\t\n]\t%[^\t\n]\t%[^\t\n]\n", &consulta.id, consulta.data, consulta.preco, consulta.descricao);
            aux->historico_consultas = adiciona_consulta(aux->historico_consultas, consulta); 
            // Verifica se o ID atual é maior que o armazenado em 'maior_id'
            if (consulta.id > maior_id) {
                maior_id = consulta.id;
            }
        }
    }
    fclose(arquivo);
    // Armazena o maior ID encontrado na variável qnt
    *qnt = maior_id - 99;
    return lista_para_pacientes;
}