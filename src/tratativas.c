#include "../include/tratativas.h"

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
            printf("\nA string deve conter apenas letras.");
            return 0;
        }
    }
    return 1;
}

int data_valida(char *data) {
    int dia, mes, ano;
    sscanf(data, "%d/%d/%d", &dia, &mes, &ano);
    if (dia == 0 || mes == 0 || ano == 0)   /* verifica se a data é nula */
        return 0;

    // Verifica se o ano tem 4 dígitos
    if (ano < 1000 || ano > 9999) {
        printf("Formato de data inválido. O ano deve ter 4 dígitos.\n");
        return 0;
    }
    
    // verificação do dia máximo de cada mês:
    if (dia > 31 || mes > 12){     /* verifica se o dia e o mês são válidos */
        return 0;
    }

    //verifica se o ano é bissexto 
    else if (mes == 2 && ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))) { 
        if (dia > 29) {
            printf("Formato de data inválido.\n");
            return 0;
        }
    }   

    else if (mes == 2 && dia > 28){
        return 0;
    }

    else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30){
        return 0;
    }

    return 1;
}

char *formata_cpf(char *cpf) {
    static char cpf_formatado[20]; // Declarando como static para preservar seu valor após o retorno da função
    sprintf(cpf_formatado, "%c%c%c.%c%c%c.%c%c%c-%c%c", cpf[0], cpf[1], cpf[2], cpf[3], cpf[4], cpf[5], cpf[6], cpf[7], cpf[8], cpf[9], cpf[10], cpf[11]);
    return cpf_formatado;
}

void cabecalho(char* linha, char* titulo) {
    printf("%s\t%s\t%s\n", linha, titulo, linha);
}

void pressiona_enter() {
    printf("\nPressione ENTER para continuar...");
    while (getchar() != '\n');
    getchar();
}

