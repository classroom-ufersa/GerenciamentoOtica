#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "../src/tratativas.c"

/*definição de um novo tipo: consulta*/
typedef struct consulta Consulta;

/**
 * @brief Adiciona uma nova consulta à lista de consultas.
 * 
 * Esta função cria um novo nó de consulta e o adiciona à lista encadeada de consultas.
 * Se a lista estiver vazia, o novo nó será o primeiro da lista.
 * 
 * @param[in] lista_consultas Ponteiro para o início da lista de consultas.
 * @param[in] nova_consulta A consulta a ser adicionada à lista.
 * @return O ponteiro para o início da lista de consultas atualizada.
 */
Consulta *adiciona_consulta(Consulta * lista_consultas, Consulta nova_consulta);

/**
 * @brief Cria uma nova consulta com base nas informações fornecidas pelo usuário.
 * 
 * Esta função solicita ao usuário as informações necessárias para criar uma nova consulta:
 * data, preço e descrição. Em seguida, cria e retorna uma estrutura de consulta preenchida com essas informações.
 * 
 * @param[in,out] qnt Ponteiro para a quantidade total de consultas, que será atualizada após a criação da nova consulta.
 * @return A nova consulta criada.
 */
Consulta nova_consulta(int *qnt);

/**
 * @brief Imprime a lista de consultas.
 * 
 * Esta função imprime os detalhes de todas as consultas presentes na lista encadeada.
 * Se a lista estiver vazia, uma mensagem indicando que não há consultas é exibida.
 * 
 * @param[in] lista_consultas Ponteiro para o início da lista de consultas a ser impressa.
 */
void imprimir_consultas(Consulta *lista_consultas);

/**
 * @brief Remove uma consulta da lista de consultas com base no ID fornecido.
 * 
 * Esta função busca um nó na lista de consultas com o ID fornecido e remove-o da lista.
 * Se o nó com o ID especificado não for encontrado, a função exibe uma mensagem indicando isso.
 * 
 * @param[in] lista_consultas Ponteiro para o início da lista de consultas.
 * @param[in] id_digitado O ID da consulta a ser removida.
 * @return O ponteiro para o início da lista de consultas atualizada após a remoção.
 */
Consulta *remove_consulta(Consulta *lista_consultas, int id_digitado);

#endif