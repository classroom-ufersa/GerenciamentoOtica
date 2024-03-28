
#ifndef TRATATIVAS_H
#define TRATATIVAS_H

// Path: GerenciamentoOtica/include/tratativas.h
#include "../include/consultas.h"

void cria_lista_consultas(ListaConsultas **lista);

int numero_inteiroc(char *str);

int contem_apenas_letras(char *str);

long long data_para_num(char *data);

char *num_para_data(long long data);

int data_valida(char *data);

char *formata_cpf(char *cpf);


#endif
