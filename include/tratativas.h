#ifndef TRATATIVAS_H
#define TRATATIVAS_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * @brief Verifica se uma string contém apenas dígitos.
 * 
 * Esta função verifica se todos os caracteres da string são dígitos (0-9).
 * 
 * @param[in] str A string a ser verificada.
 * @return Retorna 1 se a string contém apenas dígitos e 0 caso contrário.
 */
int numero_inteiroc(char *str);


/**
 * @brief Verifica se uma string contém apenas letras (alfabéticas).
 * 
 * Esta função verifica se todos os caracteres da string são letras (alfabéticas) ou espaços em branco.
 * 
 * @param[in] str A string a ser verificada.
 * @return Retorna 1 se a string contém apenas letras ou espaços em branco, e 0 caso contrário.
 */
int contem_apenas_letras(char *str);


/**
 * @brief Converte uma data no formato DD/MM/AAAA para o formato numérico de dias desde uma data base.
 * 
 * Esta função converte uma data no formato de string DD/MM/AAAA para o formato numérico de dias desde uma data base.
 * 
 * @param[in] data A string contendo a data no formato DD/MM/AAAA.
 * @return Retorna o número de dias desde uma data base até a data fornecida.
 */
long long data_para_num(char *data);


/**
 * @brief Converte um número de dias desde uma data base para o formato de data DD/MM/AAAA.
 * 
 * Esta função converte um número de dias desde uma data base para o formato de data DD/MM/AAAA.
 * 
 * @param[in] data O número de dias desde uma data base.
 * @return Retorna uma string contendo a data no formato DD/MM/AAAA.
 * @warning A string retornada é alocada dinamicamente e deve ser liberada pelo usuário após o uso.
 */
char *num_para_data(long long data);


/**
 * @brief Verifica se uma data é válida.
 * 
 * Esta função verifica se uma data fornecida está em um formato válido e representa uma data válida do calendário.
 * 
 * @param[in] data A string contendo a data no formato DD/MM/AAAA.
 * @return Retorna 1 se a data é válida e 0 caso contrário.
 */
int data_valida(char *data);


/**
 * @brief Formata um número de CPF para o formato XXX.XXX.XXX-XX.
 * 
 * Esta função formata um número de CPF para o formato XXX.XXX.XXX-XX.
 * 
 * @param[in] cpf O número de CPF a ser formatado.
 * @return Retorna uma string contendo o CPF formatado.
 * @warning A string retornada é uma variável estática interna à função e não deve ser liberada pelo usuário.
 */
char *formata_cpf(char *cpf);


/**
 * @brief Imprime um cabeçalho formatado.
 * 
 * Esta função imprime um cabeçalho formatado com o tipo de linha e um título.
 * 
 * @param[in] linha A string que representa o caractere utilizado para desenhar a linha do cabeçalho.
 * @param[in] titulo O título do cabeçalho a ser impresso.
 */
void cabecalho(char* linha, char* titulo);


/**
 * @brief Aguarda a pressão da tecla ENTER para continuar a execução.
 * 
 * Esta função imprime uma mensagem para o usuário solicitando que ele pressione a tecla ENTER para continuar a execução.
 * Após isso, aguarda até que a tecla ENTER seja pressionada.
 */
void pressiona_enter();


/**
 * @brief Formata uma string para que a primeira letra de cada palavra seja maiúscula e as demais minúsculas.
 * 
 * Esta função formata uma string para que a primeira letra de cada palavra seja maiúscula e as demais minúsculas.
 * 
 * @param[in,out] str A string a ser formatada.
 */
void formata_string(char *str);


/**
 * @brief Converte uma string para letras maiúsculas.
 * 
 * Esta função converte todos os caracteres de uma string para letras maiúsculas.
 * 
 * @param[in,out] str A string a ser convertida.
 */
void upper_string(char *str);

#endif