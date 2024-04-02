#ifndef PACIENTE_H
#define PACIENTE_H

#include "../src/consultas.c"

typedef struct paciente Paciente;

void formata_string(char *str);

Paciente *insere_consulta(Paciente * lista_pacientes, int *qnt);

Paciente *remover_consulta_lista_pacientes(Paciente * lista_pacientes, int id_digitado);

Paciente *remover_paciente_lista_pacientes(Paciente * lista_pacientes);

Paciente * remove_paciente(Paciente * lista_pacientes, char cpf[20]);

Paciente *adiciona_paciente(Paciente *lista_pacientes, Paciente paciente);

Paciente novo_paciente(Paciente * lista_pacientes);

void upper_string(char *str);

Paciente * encontra_paciente(Paciente * lista_pacientes, char cpf[12]);

int verifica_cpf_paciente(Paciente *lista_pacientes, char cpf[15]);

#endif