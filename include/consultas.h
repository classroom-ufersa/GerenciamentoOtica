#ifndef CONSULTAS_H
#define CONSULTAS_H

#include "../src/tratativas.c"

typedef struct consulta Consulta;

Consulta *adiciona_consulta(Consulta * lista_consultas, Consulta nova_consulta);

Consulta nova_consulta(int *qnt);

#endif