## 06 — Comunicação entre Células

### Introdução

Na Arquitetura Celular Silva (ACS), a comunicação entre células é fundamental para que unidades computacionais simples possam atuar como um único sistema.

Como definido nas seções anteriores, nenhuma célula possui conhecimento completo da arquitetura e não existe um componente central responsável por controlar todas as demais.

A comunicação, portanto, ocorre de forma distribuída e local, utilizando a malha tridimensional como infraestrutura.

---

### Comunicação Local

Cada célula possui um módulo de comunicação responsável por 
e receber informações de suas células vizinhas.

No modelo conceitual atual, uma célula pode estabelecer comunicação direta nas seis direções principais da malha:

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
                    FRENTE ↔ TRÁS           ```   


