#ifndef PACIENTE_H
#define PACIENTE_H

typedef struct paciente Paciente;

typedef struct lista_pacientes ListaPacientes;

void cria_lista_paciente(ListaPacientes **listap);

int verifica_cpf_paciente(ListaPacientes **lista, char cpf[12]);

void formata_string(char *str);

void upper_string(char *str);

Paciente *novo_paciente(ListaPacientes **lista);

void adicionar_paciente(ListaPacientes **lista);

void remover_paciente(ListaPacientes **lista, char *cpf);

Paciente *buscar_paciente_por_nome(ListaPacientes *lista, char *nome_digitado);


#endif