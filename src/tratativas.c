#include <stdio.h>
#include <ctype.h>
#include <string.h>

int numero_inteiroc(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void formata_string(char *str) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (i == 0) {
            str[0] = toupper(str[0]);
        }
        else {
            if (str[i - 1] == ' ') {
                str[i] = toupper(str[i]);
            }
            else {
                str[i] = tolower(str[i]);
            }
        }
    }
}

int verifica_codigo(char *id_digitado) {
    char linha[130];
    char id_arquivo[10];
    char data_arquivo[10];
    char preco_arquivo[10];
    char descricao_arquivo[100];

    FILE *arquivo = fopen("consultas.txt", "r");
    if (arquivo == NULL) {
        return 0;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (sscanf(linha, "%99[^\t]\t%99[^\t]\t%99[^\t ]", id_arquivo, data_arquivo, preco_arquivo, descricao_arquivo) == 4) {
            if (strcmp(id_arquivo, id_digitado) == 0) {
                printf("\nCodigo ja existe.");
                fclose(arquivo);
                return 1;
            }
        }
    }

    fclose(arquivo);
    return 0;
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
