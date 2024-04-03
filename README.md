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

## **7-Funções em Paciente**

## **8- Funções em Tratativas**

## **9-Funções em main**

## **10-Pré-Requisitos:**
Certifique-se de que você possui um compilador C instalado. Recomendamos o uso do [GCC](https://gcc.gnu.org/) para compilar o código.

###### Aqui, é válido salientar que as funções implementadas na pasta "consultas" e "paciente" serão chamadas no arquivo main.c, que está fora da pasta.

## *11- Execução do projeto:*
### 11.1 Compilação do código:
### 11.2 Execução do código: