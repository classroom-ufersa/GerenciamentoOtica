# Gerenciamento de Ótica
Neste arquivo você verá:

- [Introdução](#1-Introdução)
- [Problemática](#2-problemática)
- [Descrição](#3-descrição)
- [Organização do repositório](#4-organização-do-repositório)
- [Listas encadeadas](#5-listas-encadeadas)
- [Funções em Consulta](#6-funções-em-consulta)
- [Funções em Paciente](#7-funções-em-paciente)
- [Funções em tratativas](#8--funções-em-tratativas)
- [Funções em main](#9-funções-em-main)
- [Pré-requisitos](#10-pré-requisitos)
- [Execução do projeto](#11--execução-do-projeto)

## **1-Introdução**
O gerenciamento de ótica é fundamental para garantir o bom funcionamento e a eficiência de uma ótica, abrangendo gestão de pacintes e suas consultas. Um sistema de gerenciamento específico para óticas é desenvolvido com o intuito de facilitar todas as operações necessárias para o funcionamento do negócio.

## **2-Problemática**
O sistema de gerenciamento de ótica, implementado em Linguagem C, visa facilitar as operações essenciais para o funcionamento eficiente de uma ótica. Ele oferece funcionalidades como adicionar, excluir, buscar e editar pacientes e consultas, bem como listar e pacientes e seu histórico de consultas. Essas operações são fundamentais para garantir uma gestão eficaz e organizada das atividades da ótica.

## **3-Descrição**

O sistema de gerenciamento conta com duas TADs e um módulo. Sendo estas para pacientes e consultas. Já no módulo, estão contidos as tratativas, que são funções gerais utilizadas pelas duas TAD.


O sistema foi criado para ser capaz de adicionar/remover clientes e consultas, fornecer listagens de clientes e seu histórica de consultas, buscar paciente por nome e editar dados existentes, particularmente no menu de clientes.

## **4-Organização do Repositório**
A organização desse repositório está disposta da seguinte forma:

``` 
📁 - GerenciamentoOtica
│
└─── bin
│
└─── include
        │
        ├──consultas.h
        ├──paciente.h
        ├──tratrativas.h
│
└─── resources
        │
        ├──consultas.txt
        ├──paciente.txt
│
└─── src
        │
        ├──consultas.c
        ├──main.c
        ├──paciente.c
        ├──tratrativas.c
│
└───test
│
└───README.md
```

## **5-Listas Encadeadas**

Nesse projeto, o sistema de gerenciamento de ótica foi estruturado a partir do uso de listas encadeadas, que permitem percorrer a lista apenas em uma direção, do início para o fim.   

As listas encadeadas são compostas por nós que contêm dados e um ponteiro para o próximo nó na sequência. Essa estrutura oferece uma abordagem eficiente para lidar com coleções de dados dinâmicas.   

Apesar de permitir apenas o percurso sequencial da lista, as listas encadeadas simples oferecem uma solução eficaz para diversas aplicações de gerenciamento de dados, especialmente quando a ordem dos elementos é importante e as operações de inserção e remoção são frequentes.

### **Vantagens**
As principais vantagens apresentadas pelo uso de Listas encadeadas são:

- **Flexibilidade:** Oferecem flexibilidade na inserção e remoção de elementos, uma vez que não requerem uma alocação contígua de memória.

- **Inserção e remoção eficiente:** Em comparação com estruturas de dados como vetores, as listas encadeadas oferecem operações eficientes de inserção e remoção de elementos, especialmente quando se trata de operações no meio da lista.

- **Baixo custo de realocação:** A inserção e remoção de elementos em uma lista encadeada não requerem realocação de memória, o que pode ser vantajoso em situações onde a quantidade de elementos na lista é desconhecida ou variável.

### **Desvantagens**
As principais desvantagens apresentadas pelo uso de Listas encadeadas são:

- **Acesso sequencial e menor desempenho:** O acesso aos elementos de uma lista encadeada é sequencial, o que pode resultar em desempenho inferior em comparação com estruturas de dados que oferecem acesso aleatório, como arrays.

- **Consumo de memória**: As listas encadeadas podem consumir mais memória do que outras estruturas de dados, devido à necessidade de armazenar ponteiros adicionais para cada elemento.

## **6-Funções em Consulta** 
### Função adiciona_consulta

- **Descrição:** Esta função cria um novo nó de consulta e o adiciona à lista encadeada de consultas. Se a lista estiver vazia, o novo nó será o primeiro da lista.

```c
Consulta *adiciona_consulta(Consulta * lista_consultas, Consulta nova_consulta);
```

### Função nova_consulta

- **Descrição:** Esta função solicita ao usuário as informações necessárias para criar uma nova consulta: data, preço e descrição. Em seguida, cria e retorna uma estrutura de consulta preenchida com essas informações.

```c
Consulta nova_consulta(int *qnt);
```

### Função imprimir_consultas

- **Descrição:** Esta função imprime os detalhes de todas as consultas presentes na lista encadeada. Se a lista estiver vazia, uma mensagem indicando que não há consultas é exibida.

```c
void imprimir_consultas(Consulta *lista_consultas);
```
### Função remove_consulta

- **Descrição:** Esta função busca um nó na lista de consultas com o ID fornecido e remove-o da lista. Se o nó com o ID especificado não for encontrado, a função exibe uma mensagem indicando isso.

```c
Consulta *remove_consulta(Consulta *lista_consultas, int id_digitado);
```

## **7-Funções em Paciente**
### Função encontra_paciente

- **Descrição:** Esta função busca um paciente na lista de pacientes com o CPF fornecido.Se o paciente com o CPF especificado for encontrado, ele é retornado. Caso contrário, NULL é retornado, indicando que o paciente não foi encontrado.

```c
Paciente *encontra_paciente(Paciente *lista_pacientes, char cpf[20]);
```

### Função insere_consulta

- **Descrição:** Esta função solicita ao usuário as informações necessárias para criar uma nova consulta, como data, preço e descrição. Em seguida, solicita o CPF do paciente ao qual deseja adicionar a consulta. Se o paciente com o CPF especificado existir na lista de pacientes, a nova consulta é adicionada ao seu histórico de consultas. Caso contrário, uma mensagem indicando que o paciente não existe é exibida.

```c
Paciente *insere_consulta(Paciente *lista_pacientes, int *qnt);
```

### Função remover_consulta_lista_pacientes

- **Descrição:** Esta função solicita ao usuário o CPF do paciente do qual deseja remover a consulta. Se o paciente com o CPF especificado existir na lista de pacientes, a consulta com o ID fornecido é removida do seu histórico de consultas. Caso contrário, uma mensagem indicando que o paciente não existe é exibida.

```c
Paciente *remover_consulta_lista_pacientes(Paciente *lista_pacientes, int id_digitado);
```
### Função remover_paciente_lista_pacientes

- **Descrição:** Esta função solicita ao usuário o CPF do paciente que deseja remover. Se o paciente com o CPF especificado existir na lista de pacientes, ele é removido da lista. Caso contrário, uma mensagem indicando que o paciente não existe é exibida.

```c
Paciente *remover_paciente_lista_pacientes(Paciente * lista_pacientes);
```
### Função remove_paciente

- **Descrição:** Esta função percorre a lista de pacientes e remove o paciente com o CPF fornecido. Se o paciente com o CPF especificado for encontrado, ele é removido da lista. Caso contrário, uma mensagem indicando que o paciente não foi encontrado é exibida.

```c
Paciente *remove_paciente(Paciente * lista_pacientes, char cpf[20]);
```
### Função verifica_cpf_paciente

- **Descrição:** Esta função verifica se um CPF já está presente na lista de pacientes.

```c
int verifica_cpf_paciente(Paciente *lista_pacientes, char cpf[20]);
```
### Função verifica_cpf_paciente_edicao

- **Descrição:** Esta função verifica se o CPF editado de um paciente já existe na lista de pacientes, considerando o CPF antigo. Se o CPF editado for igual ao CPF antigo, significa que o CPF não foi alterado e retorna 1. Se o CPF editado for diferente do CPF antigo e já existir na lista de pacientes, retorna 0. Caso contrário, retorna 1.

```c
int verifica_cpf_paciente_edicao(Paciente *lista_pacientes, char cpf_editado[20], char cpf_antigo[20]);
```
### Função editar_paciente_lista_pacientes

- **Descrição:** Esta função solicita ao usuário o CPF do paciente que deseja editar. Se o paciente com o CPF especificado existir na lista de pacientes, ele é editado. Caso contrário, uma mensagem indicando que o paciente não existe é exibida.

```c
Paciente *editar_paciente_lista_pacientes(Paciente *lista_pacientes);
```
### Função edita_paciente

- **Descrição:** Esta função busca um paciente na lista de pacientes com o CPF antigo fornecido e edita suas informações. Se o paciente com o CPF antigo especificado for encontrado, o usuário pode editar o CPF, nome e idade do paciente. Caso contrário, uma mensagem indicando que o paciente não foi encontrado é exibida.

```c
Paciente *edita_paciente(Paciente * lista_pacientes, char cpf_antigo[20]);
```
### Função adiciona_paciente

- **Descrição:** Esta função cria um novo nó para armazenar as informações do paciente fornecido e o adiciona à lista de pacientes de forma ordenada pelo nome do paciente.

```c
Paciente *adiciona_paciente(Paciente *lista_pacientes, Paciente paciente);
```
### Função novo_paciente

- **Descrição:** Esta função solicita ao usuário as informações necessárias para criar um novo paciente, como CPF, nome e idade. Em seguida, cria e retorna uma estrutura de paciente com essas informações.

```c
Paciente novo_paciente(Paciente * lista_pacientes);
```
### Função buscar_paciente_por_nome

- **Descrição:** Esta função busca na lista de pacientes por um paciente cujo nome contenha a sequência de caracteres especificada. Se um paciente com o nome especificado for encontrado, suas informações são exibidas, incluindo o histórico de consultas, se houver.

```c
void buscar_paciente_por_nome(Paciente *lista_pacientes, char *nome);
```
### Função lista_paciente

- **Descrição:** Esta função percorre a lista de pacientes e exibe as informações de cada paciente, incluindo seu nome, CPF, idade e seu histórico de consultas, se houver. Caso não haja pacientes cadastrados, uma mensagem indicando isso é exibida.

```c
void lista_paciente(Paciente *lista_pacientes);
```
### Função escreve_no_arquivo

- **Descrição:** Esta função cria ou abre um arquivo de texto especificado e escreve nele as informações dos pacientes presentes na lista de pacientes fornecida, juntamente com seus respectivos históricos de consultas.

```c
void escreve_no_arquivo(Paciente *lista_para_pacientes, char *local_do_arquivo);
```
### Função ler_do_arquivo

- **Descrição:** Esta função abre um arquivo de texto especificado, lê as informações dos pacientes e suas consultas e os carrega na lista de pacientes fornecida. Ela retorna a lista de pacientes atualizada.

```c
Paciente *ler_do_arquivo(char *local_do_arquivo, Paciente *lista_para_pacientes, int *qnt);
```

## **8- Funções em Tratativas**

### Função número_inteiro

- **Descrição:** Esta função verifica se todos os caracteres da string são dígitos (0-9).
```c
int numero_inteiroc(char *str);
```

### Função contem_apenas_letras

- **Descrição:** Esta função verifica se todos os caracteres da string são letras (alfabéticas) ou espaços em branco.
```c
int contem_apenas_letras(char *str);
```

### Função data_para_num

- **Descrição:** Esta função converte uma data no formato de string DD/MM/AAAA para o formato numérico de dias desde uma data base.
```c
long long data_para_num(char *data);
```

### Função num_para_data

- **Descrição:** Esta função converte um número de dias desde uma data base para o formato de data DD/MM/AAAA.
```c
char *num_para_data(long long data);
```

### Função data_valida

- **Descrição:** Esta função verifica se uma data fornecida está em um formato válido e representa uma data válida do calendário.

```c
int data_valida(char *data);
```

### Função formata_cpf

- **Descrição:** Esta função formata um número de CPF para o formato XXX.XXX.XXX-XX.

```c
char *formata_cpf(char *cpf);
```

### Função cabecalho

- **Descrição:** Esta função imprime um cabeçalho formatado com o tipo de linha e um título.

```c
void cabecalho(char* linha, char* titulo);
```
### Função pressiona_enter

- **Descrição:** Esta função imprime uma mensagem para o usuário solicitando que ele pressione a tecla ENTER para continuar a execução. Após isso, aguarda até que a tecla ENTER seja pressionada.
```c
void pressiona_enter();
```

### Função formata_string

- **Descrição:** Esta função formata uma string para que a primeira letra de cada palavra seja maiúscula e as demais minúsculas.

```c
void formata_string(char *str);
```

### Função upper_string

- **Descrição:** Esta função converte todos os caracteres de uma string para letras maiúsculas.
```c
void upper_string(char *str);
```

## **9-Funções em main**

## **10-Pré-Requisitos:**
Certifique-se de que você possui um compilador C instalado. Recomendamos o uso do [GCC](https://gcc.gnu.org/) para compilar o código.

###### Aqui, é válido salientar que as funções implementadas na pasta "consultas" e "paciente" serão chamadas no arquivo main.c, que está fora da pasta.

## *11- Execução do projeto:*
### 11.1 Compilação do código:
### 11.2 Execução do código: