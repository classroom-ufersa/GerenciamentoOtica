#ifndef TRATATIVAS_H
#define TRATATIVAS_H

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int numero_inteiroc(char *str);

int contem_apenas_letras(char *str);

long long data_para_num(char *data);

char *num_para_data(long long data);

int data_valida(char *data);

char *formata_cpf(char *cpf);

void cabecalho(char* linha, char* titulo);

#endif