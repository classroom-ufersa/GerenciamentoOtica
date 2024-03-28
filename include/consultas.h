#ifndef CONSULTAS_H
#define CONSULTAS_H

typedef struct consulta Consulta;

typedef struct lista_consultas ListaConsultas;

int verifica_cpf(ListaConsultas **lista, char cpf[20]);

int verifica_id_consulta(ListaConsultas **lista, char id[10]);

void adicionar_consulta(ListaConsultas **lista);

void remover_consulta_por_id(ListaConsultas **lista, char id[10]);

void imprimir_consultas (ListaConsultas **lista);

void adicionar_no_arquivo(ListaConsultas **lista);

#endif