## 06 — Comunicação entre Células

### Introdução

Na Arquitetura Celular Silva (ACS), a comunicação entre células é fundamental para que unidades computacionais simples possam atuar como um único sistema.

Como definido nas seções anteriores, nenhuma célula possui conhecimento completo da arquitetura e não existe um componente central responsável por controlar todas as demais.

A comunicação, portanto, ocorre de forma distribuída e local, utilizando a malha tridimensional como infraestrutura.

---

### Comunicação Local

Cada célula possui um módulo de comunicação responsável por enviar e receber informações de suas células vizinhas.

No modelo conceitual atual, uma célula pode estabelecer comunicação direta nas seis direções principais da malha:

```
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
                    FRENTE ↔ TRÁS ```

A célula central representa a unidade que está realizando a comunicação.

A comunicação com uma célula que não seja uma vizinha direta ocorre através das células intermediárias.

Comunicação por Mensagens
A ACS utiliza, conceitualmente, um modelo baseado em mensagens.

Uma célula não acessa diretamente o interior de outra célula. Em vez disso, envia uma mensagem contendo as informações necessárias para a operação.

Uma mensagem pode representar, por exemplo:

uma solicitação de processamento;

um dado;

uma resposta;

uma solicitação de memória;

uma informação sobre o estado de uma célula;

uma solicitação de encaminhamento.

Esse modelo mantém a independência entre as células e reduz a necessidade de conhecimento global da arquitetura.

Percurso de uma Mensagem
Quando uma célula precisa se comunicar com outra que está distante, a mensagem percorre a malha através de células intermediárias.

┌────┐      ┌────┐      ┌────┐      ┌────┐
│ C01│ ───→ │ C02│ ───→ │ C03│ ───→ │ C04│
└────┘      └────┘      └────┘      └────┘
  Origem                              Destino

A célula de origem não precisa conhecer diretamente toda a arquitetura.

Ela apenas envia a mensagem para a direção apropriada, enquanto as células intermediárias participam do encaminhamento.

Comunicação na Malha 3D
Como a malha da ACS possui três dimensões, uma mensagem pode percorrer diferentes caminhos entre origem e destino.

                         ●
                        /│\
                       / │ \
                      ●──●──●
                     /│  │  │\
                    ●─●──●──●─●
                     \│  │  │/
                      ●──●──●
                       \ │ /
                        \│/
                         ●

A existência de múltiplos caminhos cria uma característica importante da arquitetura: a possibilidade de redirecionamento das informações.

Caso determinado caminho deixe de estar disponível, outro caminho poderá ser utilizado, desde que existam células e conexões alternativas.

Independência entre as Células
A comunicação foi projetada para preservar a independência das células.

Uma célula:

não precisa conhecer toda a malha;

não depende de uma CPU central para enviar mensagens;

não precisa acessar diretamente a memória de outra célula;

pode receber, processar e encaminhar informações;

pode participar do processamento de uma tarefa mesmo sem conhecer o objetivo completo do sistema.

Dessa forma, a comunicação local contribui para que a inteligência global da ACS surja da cooperação entre suas unidades.

Comunicação e Tolerância a Falhas
A comunicação entre células também está diretamente relacionada ao princípio de tolerância a falhas definido anteriormente.

Se uma célula deixar de responder, as células vizinhas podem detectar a ausência de comunicação e evitar o encaminhamento de novas mensagens através daquele ponto.

Quando existirem caminhos alternativos, as informações poderão ser redirecionadas pela malha.

Caminho original:


C01 ─── C02 ─── C03 ─── C04
              X
           Falha

Caminho alternativo:

C01 ─── C05 ─── C06 ─── C04
O objetivo é que a falha de uma célula não represente necessariamente a falha de todo o sistema.

Princípio da Comunicação Distribuída
A comunicação da ACS segue um princípio fundamental:

Nenhuma célula precisa conhecer toda a arquitetura para participar dela.

Cada célula conhece apenas as conexões necessárias para sua participação local na malha.

A partir da cooperação entre essas células, mensagens podem percorrer grandes regiões da arquitetura e permitir a execução de tarefas distribuídas.

Resumo
A comunicação entre células transforma a malha tridimensional da ACS em uma rede computacional cooperativa.

Cada célula possui capacidade de comunicação local e pode receber, processar e encaminhar informações. Dessa forma, operações complexas podem ser realizadas pela cooperação entre diversas células, sem depender de um controlador central.

Próxima Etapa
Continue a evolução do estudo e veja como a arquitetura lida com softwares:

* **[Ir para a Seção 07 — Execução de Programas](./07-execucao-de-programas.md)**

                         

