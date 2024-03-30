#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "../include/consultas.h"

int numero_inteiroc(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

int contem_apenas_letras(char *str) {
    for (int index = 0; str[index] != '\0'; index++) {
        if (!isalpha(str[index]) && str[index] != ' ') {
            printf("A string deve conter apenas letras.\n");
            return 0;
        }
    }
    return 1;
}

long long data_para_num(char *data) {
    int dia, mes;
    long long ano;
    long long tempo_dia = 0;

    // quantidade de dias de cada mês:
    //               J   F   M   A   M   J   J   A   S   O   N   D 
    int meses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    sscanf(data, "%d/%d/%lld", &dia, &mes, &ano);     /* separa os valores da data */

    tempo_dia += (ano-1) * 365;     /* converte ano em dias */
    

    /* Conversão de meses em dias */
    int i;
    for (i = 0; i < (mes-1); i++)
    {
        tempo_dia += meses[i];      /* incrementa os dias de cada mês completo */
    }
    
    tempo_dia += (dia-1);       /* soma os dias no resultado do cálculo */

    return tempo_dia;
}

char *num_para_data(long long data) { 
    long long ano = 0; 
    int mes = 0, dia = 0;
    int dia_mes;

    // quantidade de dias de cada mês:
    //               J   F   M   A   M   J   J   A   S   O   N   D 
    int meses[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    ano = (data / 365);
    
    /* conversão de dias em meses */
    dia_mes = (data % 365);
    while (dia_mes >= meses[mes])    /* verifica os meses, de janeiro a dezembro */
    {
        dia_mes -= meses[mes];      /* decrementa a quantidade de dias do mês */
        mes++;                      /* contabiliza os meses completos */
    }

    dia = dia_mes;                  /* o resto do cálculo será o dia */

    char *data_format = (char*)malloc(11*sizeof(char));
    sprintf(data_format, "%02d/%02d/%04lld", dia+1, mes+1, ano+1); 

    return data_format;
}

int data_valida(char *data) {
    int dia, mes, ano;
    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);
    if (dia == 0 || mes == 0 || ano == 0)   /* verifica se a data é nula */
        return 0;
    
    // verificação do dia máximo de cada mês:
    if (dia > 31 || mes > 12)               /* valores máximos de dia e mês */
        return 0;
    else if (mes == 2 && dia > 28)
        return 0;
    else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
        return 0;

    return 1;
}

char *formata_cpf(char *cpf) {
    static char cpf_formatado[20]; // Declarando como static para preservar seu valor após o retorno da função
    sprintf(cpf_formatado, "%c%c%c.%c%c%c.%c%c%c-%c%c", cpf[0], cpf[1], cpf[2], cpf[3], cpf[4], cpf[5], cpf[6], cpf[7], cpf[8], cpf[9], cpf[10], cpf[11]);
    return cpf_formatado;
}

int verifica_cpf_paciente(ListaPacientes **lista, char cpf[12]){
    ListaPacientes *listaAux = *lista; 

    while(listaAux != NULL){ 
        if(strcmp(listaAux->paciente.cpf, cpf) == 0){ 
            return 0;
        }
        listaAux = listaAux->prox; 
    }
    return 1;
}
