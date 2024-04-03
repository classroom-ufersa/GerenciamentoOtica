/*Um menu com as seguintes opções deverá ser apresentado:   
1. Adicionar paciente;  - TAD paciente
2. Remover paciente;    - TAD paciente 
3. Adicionar consulta;
4. Remover consulta;   
5. Editar informação de paciente;   
6. Buscar paciente por nome;  
7. Listar todos os pacientes e seu histórico de consultas;   
8. Sair.   
A opção Sair é a única que permite sair do programa. Sendo assim, após cada operação, o programa volta ao menu.
Além disso, você deve levar em consideração o seguinte: a cada execução do seu programa, os dados devem ser 
carregados (armazenados em um arquivo texto); cada novo paciente cadastrado deve ser inserido em ordem 
alfabética (para isso, você pode utilizar as funções da biblioteca padrão de C, string.h) e cada nova consulta
é pra ser inserida em ordem de identificação; você deve atualizar o arquivo texto para refletir o estado atual
dos dados em virtude da adição ou remoção.
*/
#include "paciente.c"


void menu(Paciente *lista_para_pacientes, char *local_do_arquivo) {
    char opcao[100];
    char sistema_operacional[10];
    strcpy(sistema_operacional, "cls");
    Paciente paciente_novo;
    Consulta consulta_nova;
    int qnt = 0;
    int id_digitado;

    while (1) {
        printf("------------------- MENU -------------------\n");
        printf("1. Adicionar paciente\n");
        printf("2. Remover paciente\n");
        printf("3. Adicionar consulta\n");
        printf("4. Remover consulta\n");
        printf("5. Editar informacao de paciente\n");
        printf("6. Buscar paciente por nome\n");
        printf("7. Listar pacientes e historico de consultas\n");
        printf("8. Sair\n");
        printf("--------------------------------------------\n");

        do{
            printf("Escolha uma opcao dentre as do menu: ");
            scanf(" %[^\n]", opcao);
            getchar();
            }while(!numero_inteiroc(opcao));

            if (strcmp(opcao, "1") == 0) {
                system(sistema_operacional);
                sleep(1); 
                paciente_novo = novo_paciente(lista_para_pacientes);
                lista_para_pacientes = adiciona_paciente(lista_para_pacientes, paciente_novo);
                escreve_no_arquivo(lista_para_pacientes, local_do_arquivo);
                pressiona_enter();
                system(sistema_operacional); 
            } else if (strcmp(opcao, "2") == 0) {
                system(sistema_operacional);
                lista_para_pacientes = remover_paciente_lista_pacientes(lista_para_pacientes);
                pressiona_enter();
                system(sistema_operacional);
            } else if (strcmp(opcao, "3") == 0) {
                system(sistema_operacional);
                lista_para_pacientes = insere_consulta(lista_para_pacientes, &qnt);
                pressiona_enter();
                system(sistema_operacional);
            } else if (strcmp(opcao, "4") == 0) {
                system(sistema_operacional);
                printf("\n Qual o ID da consulta: ");
                scanf("%d", id_digitado);
                lista_para_pacientes = remover_consulta_lista_pacientes(lista_para_pacientes, id_digitado);
            } else if (strcmp(opcao, "5") == 0) {
                system(sistema_operacional);
            } else if (strcmp(opcao, "6") == 0) {
                system(sistema_operacional);
                cabecalho("----------------", "Busca Paciente");
                char nome_paciente_digitado[100];
                printf("\nDigite o nome do paciente que deseja buscar:");
                scanf(" %99[^\n]", nome_paciente_digitado);
                buscar_paciente_por_nome(lista_para_pacientes, nome_paciente_digitado);
                pressiona_enter();
                system(sistema_operacional);
            } else if (strcmp(opcao, "7") == 0) {
                system(sistema_operacional);
                system(sistema_operacional);
            } else if (strcmp(opcao, "8") == 0) {
                printf("Saindo...\n"); 
                sleep(1);
                system(sistema_operacional);
                break;
            } else {
                printf("Opcao invalida!\n");
                sleep(1);
                system(sistema_operacional);
            }
    }


}

int main(void){
    char local_do_arquivo[50];
    strcpy(local_do_arquivo, "../resources/dados.txt");
    Paciente *lista_para_pacientes = NULL;
    menu(lista_para_pacientes, local_do_arquivo);
    
    return 0;
}