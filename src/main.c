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
#include <stdio.h>
#include "include/consultas.h"
#include "include/paciente.h"

void menu(void) {
    printf("------------------- MENU -------------------\n");
    printf("1. Adicionar paciente\n");
    printf("2. Remover paciente\n");
    printf("3. Adicionar consulta\n");
    printf("4. Remover consulta\n");
    printf("5. Editar informação de paciente");
    printf("6. Buscar paciente por nome\n");
    printf("7. Listar pacientes e histórico de consultas\n");
    printf("8. Sair\n");
    printf("--------------------------------------------\n");
}

int main(void){
    menu();
}