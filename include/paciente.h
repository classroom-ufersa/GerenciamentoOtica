#ifndef PACIENTE_H 
#define PACIENTE_H

#include "../src/consultas.c" 

/*definição de um novo tipo: paciente*/
typedef struct paciente Paciente;



/**
 * @brief Encontra um paciente na lista de pacientes com base no CPF fornecido.
 * 
 * Esta função busca um paciente na lista de pacientes com o CPF fornecido.
 * Se o paciente com o CPF especificado for encontrado, ele é retornado.
 * Caso contrário, NULL é retornado, indicando que o paciente não foi encontrado.
 * 
 * @param[in] lista_pacientes Ponteiro para o início da lista de pacientes.
 * @param[in] cpf O CPF do paciente a ser encontrado.
 * @return O ponteiro para o paciente encontrado ou NULL se o paciente não for encontrado.
 */
Paciente *encontra_paciente(Paciente *lista_pacientes, char cpf[20]);


/**
 * @brief Insere uma nova consulta para um paciente na lista de pacientes.
 * 
 * Esta função solicita ao usuário as informações necessárias para criar uma nova consulta,
 * como data, preço e descrição. Em seguida, solicita o CPF do paciente ao qual deseja adicionar a consulta.
 * Se o paciente com o CPF especificado existir na lista de pacientes, a nova consulta é adicionada ao seu histórico de consultas.
 * Caso contrário, uma mensagem indicando que o paciente não existe é exibida.
 * 
 * @param[in] lista_pacientes Ponteiro para o início da lista de pacientes.
 * @param[in,out] qnt Ponteiro para a quantidade total de consultas, que será atualizada após a criação da nova consulta.
 * @return O ponteiro para a lista de pacientes atualizada após a inserção da consulta, ou NULL se o paciente não existir.
 */
Paciente *insere_consulta(Paciente *lista_pacientes, int *qnt);


/**
 * @brief Remove uma consulta de um paciente na lista de pacientes com base no ID fornecido.
 * 
 * Esta função solicita ao usuário o CPF do paciente do qual deseja remover a consulta.
 * Se o paciente com o CPF especificado existir na lista de pacientes, a consulta com o ID fornecido é removida do seu histórico de consultas.
 * Caso contrário, uma mensagem indicando que o paciente não existe é exibida.
 * 
 * @param[in] lista_pacientes Ponteiro para o início da lista de pacientes.
 * @param[in] id_digitado O ID da consulta a ser removida.
 * @return O ponteiro para a lista de pacientes atualizada após a remoção da consulta, ou NULL se o paciente não existir.
 */
Paciente *remover_consulta_lista_pacientes(Paciente *lista_pacientes, int id_digitado);


/**
 * @brief Remove um paciente da lista de pacientes com base no CPF fornecido.
 * 
 * Esta função solicita ao usuário o CPF do paciente que deseja remover.
 * Se o paciente com o CPF especificado existir na lista de pacientes, ele é removido da lista.
 * Caso contrário, uma mensagem indicando que o paciente não existe é exibida.
 * 
 * @param[in] lista_pacientes Ponteiro para o início da lista de pacientes.
 * @return O ponteiro para a lista de pacientes atualizada após a remoção do paciente, ou NULL se o paciente não existir.
 */
Paciente *remover_paciente_lista_pacientes(Paciente * lista_pacientes);
   

   /**
 * @brief Remove um paciente da lista de pacientes com base no CPF fornecido.
 * 
 * Esta função percorre a lista de pacientes e remove o paciente com o CPF fornecido.
 * Se o paciente com o CPF especificado for encontrado, ele é removido da lista.
 * Caso contrário, uma mensagem indicando que o paciente não foi encontrado é exibida.
 * 
 * @param[in] lista_pacientes Ponteiro para o início da lista de pacientes.
 * @param[in] cpf O CPF do paciente a ser removido.
 * @return O ponteiro para a lista de pacientes atualizada após a remoção do paciente, ou NULL se o paciente não for encontrado.
 */
Paciente *remove_paciente(Paciente * lista_pacientes, char cpf[20]);


/**
 * @brief Verifica se um CPF já está presente na lista de pacientes.
 * 
 * Esta função verifica se um CPF já está presente na lista de pacientes.
 * 
 * @param[in] lista_pacientes A lista de pacientes a ser verificada.
 * @param[in] cpf O CPF a ser verificado.
 * @return Retorna 0 se o CPF já estiver presente na lista, caso contrário, retorna 1.
 */
int verifica_cpf_paciente(Paciente *lista_pacientes, char cpf[20]);


/**
 * @brief Verifica se o CPF editado de um paciente já existe na lista de pacientes, considerando o CPF antigo.
 * 
 * Esta função verifica se o CPF editado de um paciente já existe na lista de pacientes, considerando o CPF antigo.
 * Se o CPF editado for igual ao CPF antigo, significa que o CPF não foi alterado e retorna 1.
 * Se o CPF editado for diferente do CPF antigo e já existir na lista de pacientes, retorna 0.
 * Caso contrário, retorna 1.
 * 
 * @param[in] lista_pacientes Ponteiro para o início da lista de pacientes.
 * @param[in] cpf_editado O CPF editado que será verificado.
 * @param[in] cpf_antigo O CPF antigo do paciente.
 * @return 1 se o CPF editado for igual ao CPF antigo ou não existir na lista de pacientes, 0 se o CPF editado já existir na lista.
 */
int verifica_cpf_paciente_edicao(Paciente *lista_pacientes, char cpf_editado[20], char cpf_antigo[20]);


/**
 * @brief Edita um paciente na lista de pacientes com base no CPF fornecido.
 * 
 * Esta função solicita ao usuário o CPF do paciente que deseja editar.
 * Se o paciente com o CPF especificado existir na lista de pacientes, ele é editado.
 * Caso contrário, uma mensagem indicando que o paciente não existe é exibida.
 * 
 * @param[in] lista_pacientes Ponteiro para o início da lista de pacientes.
 * @return O ponteiro para a lista de pacientes atualizada após a edição do paciente, ou NULL se o paciente não existir.
 */
Paciente *editar_paciente_lista_pacientes(Paciente *lista_pacientes);


/**
 * @brief Edita as informações de um paciente na lista de pacientes com base no CPF antigo fornecido.
 * 
 * Esta função busca um paciente na lista de pacientes com o CPF antigo fornecido e edita suas informações.
 * Se o paciente com o CPF antigo especificado for encontrado, o usuário pode editar o CPF, nome e idade do paciente.
 * Caso contrário, uma mensagem indicando que o paciente não foi encontrado é exibida.
 * 
 * @param[in] lista_pacientes Ponteiro para o início da lista de pacientes.
 * @param[in] cpf_antigo O CPF antigo do paciente a ser editado.
 * @return O ponteiro para a lista de pacientes atualizada após a edição do paciente, ou NULL se o paciente não for encontrado.
 */
Paciente *edita_paciente(Paciente * lista_pacientes, char cpf_antigo[20]);


/**
 * @brief Adiciona um novo paciente à lista de pacientes.
 * 
 * Esta função cria um novo nó para armazenar as informações do paciente fornecido
 * e o adiciona à lista de pacientes de forma ordenada pelo nome do paciente.
 * 
 * @param[in] lista_pacientes Ponteiro para o início da lista de pacientes.
 * @param[in] paciente O paciente a ser adicionado à lista.
 * @return O ponteiro para a lista de pacientes atualizada após a adição do novo paciente.
 */
Paciente *adiciona_paciente(Paciente *lista_pacientes, Paciente paciente);


/**
 * @brief Cria um novo paciente com base nas informações fornecidas pelo usuário.
 * 
 * Esta função solicita ao usuário as informações necessárias para criar um novo paciente,
 * como CPF, nome e idade. Em seguida, cria e retorna uma estrutura de paciente com essas informações.
 * 
 * @param[in] lista_pacientes Ponteiro para o início da lista de pacientes, utilizado para verificar a unicidade do CPF.
 * @return Uma estrutura de paciente contendo as informações do novo paciente.
 */
Paciente novo_paciente(Paciente * lista_pacientes);


/**
 * @brief Busca um paciente na lista de pacientes por nome.
 * 
 * Esta função busca na lista de pacientes por um paciente cujo nome contenha a sequência de caracteres especificada.
 * Se um paciente com o nome especificado for encontrado, suas informações são exibidas, incluindo o histórico de consultas, se houver.
 * 
 * @param[in] lista_pacientes Ponteiro para o início da lista de pacientes.
 * @param[in] nome Sequência de caracteres para buscar na lista de pacientes.
 */
void buscar_paciente_por_nome(Paciente *lista_pacientes, char *nome);


/**
 * @brief Lista todos os pacientes cadastrados, incluindo seus respectivos históricos de consultas.
 * 
 * Esta função percorre a lista de pacientes e exibe as informações de cada paciente, incluindo seu nome, CPF, idade
 * e seu histórico de consultas, se houver. Caso não haja pacientes cadastrados, uma mensagem indicando isso é exibida.
 * 
 * @param[in] lista_pacientes Ponteiro para o início da lista de pacientes.
 */
void lista_paciente(Paciente *lista_pacientes);


/**
 * @brief Escreve os dados dos pacientes e suas consultas em um arquivo de texto.
 * 
 * Esta função cria ou abre um arquivo de texto especificado e escreve nele as informações dos pacientes
 * presentes na lista de pacientes fornecida, juntamente com seus respectivos históricos de consultas.
 * 
 * @param[in] lista_para_pacientes Ponteiro para o início da lista de pacientes.
 * @param[in] local_do_arquivo Caminho para o arquivo de texto onde os dados serão escritos.
 */
void escreve_no_arquivo(Paciente *lista_para_pacientes, char *local_do_arquivo);

/**
 * @brief Verifica se a lista de pacientes está vazia e, se não estiver, exibe a lista.
 * 
 * Esta função verifica se a lista de pacientes está vazia. Se estiver vazia, imprime uma mensagem informando que nenhum paciente foi cadastrado.
 * Se a lista não estiver vazia, exibe a lista de pacientes.
 * 
 * @param[in] lista_pacientes A lista de pacientes a ser verificada e, possivelmente, exibida.
 * @return Retorna a lista de pacientes se ela não estiver vazia.
 */
Paciente lista_vazia(Paciente *lista_pacientes);

/**
 * @brief Lê os dados dos pacientes e suas consultas de um arquivo de texto e os carrega na lista de pacientes.
 * 
 * Esta função abre um arquivo de texto especificado, lê as informações dos pacientes e suas consultas e os carrega
 * na lista de pacientes fornecida. Ela retorna a lista de pacientes atualizada.
 * 
 * @param[in] local_do_arquivo Caminho para o arquivo de texto onde os dados serão lidos.
 * @param[in,out] lista_para_pacientes Ponteiro para o início da lista de pacientes.
 * @param[in,out] qnt Ponteiro para a quantidade total de pacientes, atualizado conforme os pacientes são lidos do arquivo.
 * @return O ponteiro para a lista de pacientes atualizada com os dados lidos do arquivo.
 */
Paciente *ler_do_arquivo(char *local_do_arquivo, Paciente *lista_para_pacientes, int *qnt);
#endif