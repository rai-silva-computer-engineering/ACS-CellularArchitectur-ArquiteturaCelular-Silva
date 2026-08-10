# 06 — Comunicação entre Células

## Introdução

Na Arquitetura Celular Silva (ACS), a comunicação entre células é fundamental para que unidades computacionais simples possam atuar como um único sistema.

Conforme definido nas seções anteriores, a ACS não depende de um processador central para coordenar todas as operações. As células são organizadas em uma **malha tridimensional** e cooperam entre si por meio de comunicação distribuída.

A comunicação é, portanto, um dos mecanismos fundamentais que permite transformar milhares ou milhões de células individuais em uma única arquitetura computacional.

---

## Comunicação Local

Cada célula possui um mecanismo de comunicação responsável por enviar e receber informações de suas células vizinhas.

No modelo conceitual atual, uma célula pode estabelecer comunicação direta nas seis direções principais da malha tridimensional:

```text
                         ACIMA
                           ↑
                           │
                           ●
                           │
        ESQUERDA ← ────── ● ────── → DIREITA
                           │
                           ●
                           │
                         ABAIXO

                    FRENTE ↔ TRÁS
```

A célula central representa a unidade que está realizando a comunicação.

A comunicação com células mais distantes ocorre por meio das células intermediárias da malha.

---

## Comunicação por Mensagens

A ACS adota, conceitualmente, um modelo de comunicação baseado em **mensagens**.

Uma célula não acessa diretamente o funcionamento interno de outra célula. Em vez disso, envia uma mensagem contendo as informações necessárias para determinada operação.

Uma mensagem poderá representar, por exemplo:

* uma solicitação de processamento;
* um dado;
* uma resposta;
* uma solicitação de informação;
* uma solicitação de memória;
* uma informação sobre o estado de uma célula;
* uma solicitação de encaminhamento.

A definição detalhada do formato dessas mensagens será desenvolvida posteriormente.

---

## Percurso de uma Mensagem

Quando uma célula precisa se comunicar com outra que está distante, a mensagem percorre a malha através de células intermediárias.

```text
┌─────┐      ┌─────┐      ┌─────┐      ┌─────┐
│ C01 │ ───→ │ C02 │ ───→ │ C03 │ ───→ │ C04 │
└─────┘      └─────┘      └─────┘      └─────┘
 Origem                                  Destino
```

A célula de origem não precisa conhecer toda a arquitetura.

Ela utiliza suas conexões locais para encaminhar a mensagem, enquanto outras células participam do percurso até o destino.

Esse modelo mantém o princípio de **conhecimento local** definido anteriormente.

---

## Comunicação na Malha 3D

Como a ACS utiliza uma malha tridimensional, as mensagens podem percorrer diferentes caminhos entre uma origem e um destino.

```text
                         ●
                        /|\
                       / | \
                      ●──●──●
                     /|  |  |\
                    ●─●──●──●─●
                     \|  |  |/
                      ●──●──●
                       \ | /
                        \|/
                         ●
```

A existência de múltiplos caminhos permite que a arquitetura tenha alternativas para o encaminhamento das informações.

Essa característica será importante para o mecanismo de tolerância a falhas da ACS.

---

## Encaminhamento

Uma célula que recebe uma mensagem deverá determinar se:

1. a mensagem é destinada a ela;
2. a mensagem precisa ser processada localmente;
3. a mensagem deve ser encaminhada para outra célula.

No terceiro caso, a célula encaminha a mensagem através de uma de suas conexões disponíveis.

O mecanismo exato de roteamento ainda será definido durante o desenvolvimento da arquitetura.

---

## Independência entre as Células

A comunicação foi concebida para preservar a independência das células.

Uma célula:

* não precisa conhecer toda a malha;
* não depende de uma CPU central para se comunicar;
* não precisa acessar diretamente a memória interna de outra célula;
* pode receber, processar e encaminhar informações;
* pode participar de uma tarefa sem conhecer todo o objetivo do sistema.

Essa independência permite que o comportamento global da ACS resulte da cooperação entre suas unidades.

---

## Comunicação e Tolerância a Falhas

A comunicação entre células também está diretamente relacionada ao princípio de tolerância a falhas da ACS.

Se uma célula deixar de responder, as células vizinhas poderão detectar a ausência de comunicação e evitar o encaminhamento de novas mensagens através daquele ponto.

Quando existirem caminhos alternativos, as informações poderão ser redirecionadas pela malha.

```text
Caminho original:

C01 ─── C02 ─── C03 ─── C04
             X
           Falha


Possível caminho alternativo:

C01 ─── C05 ─── C06 ─── C04
```

A capacidade de recuperação dependerá dos mecanismos de detecção de falhas e roteamento que serão definidos posteriormente.

---

## Princípio da Comunicação Distribuída

A comunicação da ACS segue um princípio fundamental:

> **Nenhuma célula precisa conhecer toda a arquitetura para participar dela.**

Cada célula conhece apenas as informações necessárias para sua atuação local.

Através da cooperação entre essas células, mensagens podem percorrer diferentes regiões da malha e permitir a execução de tarefas distribuídas.

---

## Resumo

A comunicação entre células transforma a malha tridimensional da ACS em uma rede computacional cooperativa.

Cada célula possui capacidade de comunicação local e pode receber, processar e encaminhar informações. Dessa forma, operações complexas podem ser realizadas pela cooperação entre diversas células, sem depender de um controlador central.

A próxima seção abordará como programas e tarefas computacionais são executados de forma distribuída entre as células da ACS.
[07 — Execução de Tarefas e Programas](./07-execucao-de-tarefas.md)

