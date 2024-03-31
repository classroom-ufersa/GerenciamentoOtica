/*Arquivo interface do algoritmo gerenciamento de ótica (consultas)*/

#ifndef CONSULTAS_H 
#define CONSULTAS_H 

/*Definição de um novo tipo: consulta*/
typedef struct consulta Consulta;

/*Definição de um novo tipo: lista de consultas*/
typedef struct lista_consultas ListaConsultas;

/**
 * @brief Cria uma lista de consultas.
 *
 * Esta função cria uma lista de consultas vazia, atribuindo NULL ao ponteiro para a lista.
 *
 * @param[in,out] lista O endereço do ponteiro para a lista de consultas a ser criada.
 */
void cria_lista_consultas(ListaConsultas **lista);

/**
 * @brief Verifica se um ID de consulta já existe na lista.
 *
 * Esta função verifica se um ID de consulta já existe na lista de consultas.
 *
 * @param[in,out] lista O endereço do ponteiro para a lista de consultas.
 * @param[in] id O ID da consulta a ser verificado.
 * @return 0 se o ID já existe na lista, 1 caso contrário.
 */
int verifica_id_consulta(ListaConsultas **lista, char id[10]);

/**
 * @brief Adiciona uma nova consulta à lista de consultas.
 *
 * Esta função permite ao usuário adicionar uma nova consulta à lista de consultas. O usuário é solicitado a fornecer informações sobre o paciente, como CPF, ID da consulta, data, preço e descrição. 
 * As informações são validadas antes de serem adicionadas à lista. Após a adição de uma consulta, o usuário é solicitado a decidir se deseja adicionar outra consulta ou não.
 *
 * @param[in,out] lista O endereço do ponteiro para a lista de consultas.
 */
void adicionar_consulta(ListaConsultas **lista);

/**
 * @brief Remove uma consulta e seu histórico de consultas dos pacientes.
 *
 * Esta função remove uma consulta, identificada pelo ID, da lista de consultas e remove também essa consulta do histórico de consultas de todos os pacientes que a possuem.
 * 
 * @param[in,out] lista_pacientes O endereço do ponteiro para a lista de pacientes.
 * @param[in,out] lista_consultas O endereço do ponteiro para a lista de consultas.
 * @param[in] id O ID da consulta a ser removida.
 */
void remover_consulta_e_historico(ListaPacientes **lista_pacientes, ListaConsultas **lista_consultas, char id[10]);

/**
 * @brief Imprime todas as consultas armazenadas na lista.
 *
 * Esta função imprime os dados de todas as consultas armazenadas na lista de consultas. Cada linha impressa contém informações como CPF do paciente, ID da consulta, data, preço e descrição.
 * 
 * @param[in] lista O endereço do ponteiro para a lista de consultas a ser impressa.
 */
void imprimir_consultas(ListaConsultas **lista);


/**
 * @brief Adiciona as consultas ao arquivo "consultas.txt".
 *
 * Esta função escreve os dados de todas as consultas armazenadas na lista de consultas em um arquivo de texto chamado "consultas.txt". Cada linha do arquivo contém informações como CPF do paciente, ID da consulta, data, preço e descrição.
 * 
 * @param[in] lista O endereço do ponteiro para a lista de consultas a ser escrita no arquivo.
 */
void adicionar_no_arquivo(ListaConsultas **lista);


#endif