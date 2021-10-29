## Travelling Salesman Problem - Brute Force solution written in C. 

## Authors
## 28/10/2021

## Bruno da Freiria Mischiati Borges 
## https://github.com/BrunoFreiria

## Daniel Coutinho Ribeiro
## https://github.com/dcoutinhoribeiro

## Yan Köhler de Araujo
## https://github.com/Yan-Kohler

**O Problema do Caixeiro Viajante (PCV)**

O Problema do Caixeiro Viajante (PCV) é um dos problemas clássicos na
área de Otimização e pode ser descrito da seguinte maneira. Suponha que você
seja um representante comercial e precisa visitar n cidades diferentes para vender
seu produto. Nesta viagem, cada cidade deve ser visitada uma única vez e, ao
final do trajeto, você deve retornar à cidade de origem. Existem diferentes
possibilidades de realizar este trajeto, mas o interesse está no trajeto de menor
custo.

Para compilar o programa, abra o terminal no diretório que contem o código fonte e execute: 

```
    make linux
```

Após compilar o programa, execute no terminal para iniciar o programa:

```
    ./tsp_solve -f <nome do arquivo de teste>
```

Ao executar, o programa irá solicitar para entrar com a cidade de origem, o programa então vai calcular a melhor rota possível por brute-force. 

