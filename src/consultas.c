#include "../include/consultas.h"


typedef struct consulta{
    int id;
    char data[10];
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
    if (lista_consultas == NULL)
        return nova;
    Consulta *atual = lista_consultas;
    Consulta *anterior = lista_consultas;
    while (atual != NULL)
    {
        anterior = atual;
        atual = atual->prox_elemento;
    }
    anterior->prox_elemento = nova;
    return lista_consultas;
}

Consulta nova_consulta(int *qnt){
    Consulta consulta;
    char data[10], preco[10], descricao[100];
    do {
        printf("Digite a data (DD/MM/AAAA): ");
        scanf("%s", data);
    } while (!data_valida(data)); 

    // Convertendo a data para o formato numérico
    long long data_numerica = data_para_num(data);

    do {
        printf("Digite o preço: ");
        scanf("%s", preco);
    } while (numero_inteiroc(preco) == 0);
    
    do {
        printf("Digite a descrição: ");
        scanf("%s", descricao);
    } while (contem_apenas_letras(descricao) == 0);
    
    // Copiando os dados fornecidos para a estrutura de consulta do novo elemento
    strcpy(consulta.data, num_para_data(data_numerica)); // Converte a data numérica para formato de string
    strcpy(consulta.preco, preco);
    strcpy(consulta.descricao, descricao);
    consulta.id = (*qnt) + 100;
    (*qnt)++;
    consulta.prox_elemento = NULL;
    return consulta;
}
