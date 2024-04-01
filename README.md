# Gerenciamento de Ótica
Neste arquivo você verá:

- [Pré-Requisitos;](#1-pré-requisitos)
- [Organização do repositório;](#2-organização-do-repositório)
- [Execução do projeto;](#3-execução-do-projeto)

## **Introdução**
O gerenciamento de ótica é fundamental para garantir o bom funcionamento e a eficiência de uma ótica, abrangendo gestão de pacintes e suas consultas. Um sistema de gerenciamento específico para óticas é desenvolvido com o intuito de facilitar todas as operações necessárias para o funcionamento do negócio.

## **Problemática**
O sistema de gerenciamento de ótica, implementado em Linguagem C, visa facilitar as operações essenciais para o funcionamento eficiente de uma ótica. Ele oferece funcionalidades como adicionar, excluir, buscar e editar pacientes e consultas, bem como listar e pacientes e seu histórico de consultas. Essas operações são fundamentais para garantir uma gestão eficaz e organizada das atividades da ótica.

## **Descrição**

O sistema de gerenciamento conta com duas TADs e um módulo. Sendo estas para pacientes e consultas. Já no módulo, estão contidos as tratativas, que são funções gerais utilizadas pelas duas TAD.


O sistema foi criado para ser capaz de adicionar/remover clientes e consultas, fornecer listagens de clientes e seu histórica de consultas, buscar paciente por nome e editar dados existentes, particularmente no menu de clientes.

## **Organização do Repositório**
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

## **Listas Duplamente Encadeadas**

Nesse projeto, o sistema de gerenciamento de ótica foi estruturado a partir do uso de listas duplamente encadeadas, que permitem a possibilidade de percorrer a lista nos dois sentidos, tanto do início para o fim, como do fim para o início.

### **Vantagens**

As maiores vantagens apresentadas pelo uso de Listas duplamente encadeadas é:

- Possibilidade de percorrer a lista em qualquer direção;

<p align="center">
 <img src="./aluguel_de_carros/lista-dupla-encadeada.jpg"/>
</p>

- Flexibilidade.
  
- Inserção e remoção eficiente em comparação à estruturas de dados como vetores.

### **Desvantagens**

As maiores desvantagens apresentadas pelo seu uso é:

- Consome mais memória;

- Complexidade de implementação;
  
- Acesso sequencial.


## **Funções em Consulta** 

## **Funções em Paciente**

## **Funções em main**

## *Pré-Requisitos:*
Certifique-se de que você possui um compilador C instalado. Recomendamos o uso do [GCC](https://gcc.gnu.org/) para compilar o código.

###### Aqui, é válido salientar que as funções implementadas na pasta "consultas" e "paciente" serão chamadas no arquivo main.c, que está fora da pasta.

## 3. Execução do projeto
### 3.1 Compilação do código:
### 3.2 Execução do código: