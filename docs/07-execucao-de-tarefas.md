# 07 — Execução de Programas

## Introdução

Nas seções anteriores, a Arquitetura Celular Silva (ACS) foi definida como uma arquitetura composta por células computacionais organizadas em uma malha tridimensional e capazes de se comunicar localmente.

A próxima questão é fundamental:

> **Como um programa é executado quando não existe um processador central responsável por executar todas as instruções?**

Na ACS, a execução é baseada na **distribuição de tarefas entre as células**.

---

## Execução Distribuída

Um programa não precisa ser executado por uma única célula.

Suas operações podem ser organizadas em tarefas que são distribuídas pela malha computacional.

```text
                    PROGRAMA
                       │
                       ▼
                ┌─────────────┐
                │    Tarefas  │
                └──────┬──────┘
                       │
             ┌─────────┴─────────┐
             ▼                   ▼
          Tarefa A            Tarefa B
             │                   │
             ▼                   ▼
        ┌─────────┐         ┌─────────┐
        │ Células │         │ Células │
        │    A    │         │    B    │
        └────┬────┘         └────┬────┘
             │                   │
             └─────────┬─────────┘
                       ▼
                  RESULTADOS
                       │
                       ▼
                 Resultado final
```

A distribuição das tarefas não depende de uma CPU central.

As próprias células participam do processo de distribuição utilizando a comunicação definida na Seção 06.

---

## Distribuição de Tarefas

Quando uma tarefa chega a uma célula, ela poderá avaliar sua própria capacidade de participar daquela execução.

A célula poderá:

* executar a tarefa;
* encaminhar a tarefa;
* colaborar com outra célula;
* aguardar informações necessárias;
* informar que não possui recursos disponíveis.

Dessa forma, a distribuição ocorre de maneira cooperativa.

```text
                 TAREFA
                    │
                    ▼
                  ● C1
                 /    \
                /      \
               ▼        ▼
             ● C2      ● C3

              │          │
              ▼          ▼
             ● C4      ● C5
                \      /
                 \    /
                  ▼  ▼
                RESULTADO
```

O objetivo não é determinar antecipadamente uma célula específica para cada tarefa, mas permitir que a arquitetura encontre recursos disponíveis dentro da própria malha.

---

## Conhecimento Local

Uma célula não precisa conhecer toda a arquitetura para participar da execução de um programa.

Ela conhece apenas as informações necessárias para sua atuação local, como:

* seu próprio estado;
* suas conexões;
* tarefas recebidas;
* informações necessárias para executar ou encaminhar uma tarefa.

Esse princípio mantém a arquitetura distribuída e evita a criação de um ponto central de controle.

---

## Cooperação Durante a Execução

Algumas tarefas podem depender dos resultados produzidos por outras células.

Nesse caso, as células podem trocar mensagens através da malha para compartilhar dados e resultados intermediários.

```text
Tarefa A
   │
   ▼
  ● C1 ─────→ ● C2
                │
                ▼
             Resultado
                │
                ▼
              ● C3
                │
                ▼
           Próxima tarefa
```

A execução de um programa pode, portanto, envolver diversas células trabalhando simultaneamente e trocando informações durante o processo.

---

## Execução e Falhas

A execução distribuída também está relacionada ao princípio de tolerância a falhas da ACS.

Se uma célula falhar durante uma tarefa, o sistema poderá identificar a interrupção da comunicação e procurar outro recurso disponível para continuar o processamento.

```text
Execução normal:

C1 ─── C2 ─── C3
       │
     Tarefa


Falha em C2:

C1 ─── X ─── C3
       ↑
     Falha


Possível redirecionamento:

C1 ─── C4 ─── C3
       │
     Tarefa
```

A capacidade de recuperação dependerá das informações mantidas pela arquitetura e dos mecanismos de comunicação e gerenciamento de tarefas que serão definidos posteriormente.

---

## Resultado da Execução

Quando todas as tarefas necessárias forem concluídas, seus resultados poderão ser combinados para produzir o resultado final do programa.

Assim, a execução deixa de ser uma sequência obrigatoriamente centralizada e passa a ser um processo cooperativo entre diferentes células.
### Representação visual

**Acompanhe, no rascunho abaixo, uma representação visual de como uma tarefa pode ser distribuída e executada entre diferentes células da Arquitetura Celular Silva.**



<img width="1179" height="1334" alt="modelo" src="https://github.com/user-attachments/assets/ff869322-6d87-4570-9e31-db955f1cb7ed" />

---

## Princípio de Execução da ACS

A execução de programas na Arquitetura Celular Silva segue o seguinte princípio:

> **Um programa pode ser executado pela cooperação de múltiplas células, sem depender de uma única unidade central de processamento.**

Esse modelo mantém a coerência com os princípios fundamentais da ACS: distribuição, cooperação, modularidade e tolerância a falhas.

---

## Resumo

A Seção 07 estabelece o modelo conceitual de execução distribuída da ACS.

Programas podem ser divididos em tarefas, distribuídos entre células e executados de forma cooperativa. As células utilizam a malha tridimensional e o sistema de comunicação para compartilhar informações e resultados.

A definição detalhada do conjunto de instruções, da forma como programas serão representados e dos mecanismos de distribuição será desenvolvida nas próximas etapas da arquitetura.

<img width="1179" height="1334" alt="modelo" src="https://github.com/user-attachments/assets/b04daf52-a811-4c22-8d5c-9230bf09acaf" />
Próxima seção: [08 — Memória Distribuída](./08-memoria-distribuida.md)

