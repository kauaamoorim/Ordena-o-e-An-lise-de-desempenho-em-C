Projeto de Ordenação e Análise de Desempenho em C

1. Descrição

Projeto desenvolvido para a avaliação “Ordenação e Análise de Desempenho em C”, cujo objetivo é ordenar os dígitos do RGM e comparar o desempenho de três algoritmos de ordenação:

Insertion Sort — crescente; in-place; O(n²) no pior e caso médio.

Quick Sort — partição de Lomuto; in-place; O(n log n) médio.

Merge Sort — divide and conquer; requer memória extra; O(n log n) no pior caso.


RGM utilizado: 045620920 (9 dígitos).


---

2. Estrutura do Projeto

/ordenacao-rgm/
│
├── src/
│   ├── main.c
│   ├── sorts.c
│   └── sorts.h
│
└── README.md


---

3. Compilação

Para compilar o projeto usando gcc:

gcc -std=c11 src/*.c -o ordena

> Observação importante:
Para manter a contagem de passos coerente, evite -O3.
Recomenda-se usar -O0 ou -O1, pois otimizações agressivas removem instruções e distorcem resultados.



Exemplo recomendado:

gcc -std=c11 -O1 src/*.c -o ordena


---

4. Execução

Usando o RGM padrão (045620920):

./ordena

Usando outro RGM como argumento:

./ordena 123456789


---

5. Saída (Formato CSV)

O programa escreve no stdout uma tabela CSV com as seguintes colunas:

metodo, N, caso, passos, tempo_ms

Casos testados:

RGM: vetor com os 9 dígitos do RGM.

Aleatório: vetores aleatórios com tamanhos

N = 100

N = 1000

N = 10000



Cada teste é repetido 5 vezes e o CSV exibe a média de passos e tempos.


---

6. Política de Contagem de Passos

A contagem segue o modelo didático adotado em sala:

✔ Comparações

Cada comparação entre elementos conta 1 passo (COUNT_CMP).

✔ Trocas / Movimentações

Cada atribuição ou cópia que movimenta valores conta 1 passo (COUNT_SWAP).

No Merge Sort, cada cópia para o vetor auxiliar e cada cópia de volta ao vetor original contam como movimentações.

✔ Passos totais

Para facilitar a análise, o relatório usa:

passos = comparações + movimentações


---

7. Medição de Tempo

Usado clock() da biblioteca <time.h>.

Resultados apresentados em milissegundos (ms).

Média de 5 execuções por caso e por algoritmo.



---

8. Observações Importantes

Insertion Sort se destaca em vetores pequenos ou quase ordenados.

Quick Sort pode degradar no pior caso (pivô ruim).

Merge Sort é estável e possui desempenho garantido, ao custo de memória extra.

Quick e Insertion são in-place; Merge não é.



---

9. Conclusão

A análise comparativa entre Insertion Sort, Quick Sort e Merge Sort demonstrou como diferentes estratégias de ordenação influenciam o desempenho computacional. O Insertion Sort mostrou eficiência apenas em vetores pequenos ou quase ordenados, exibindo crescimento quadrático conforme o tamanho dos dados aumenta. O Quick Sort apresentou o melhor desempenho no caso médio, sendo geralmente o algoritmo mais rápido, embora possua pior caso quadrático. Já o Merge Sort manteve desempenho estável e previsível, com complexidade garantida de O(n log n), porém demandando memória extra devido ao uso de vetores auxiliares.

Os resultados confirmam que não há um algoritmo universalmente superior, e sim algoritmos que se adaptam melhor a cenários específicos. Fatores como tamanho do vetor, distribuição dos dados e restrições de memória influenciam diretamente a escolha da técnica mais adequada. Assim, o estudo contribuiu para a compreensão prática do comportamento dos algoritmos e reforça a importância da análise de complexidade no desenvolvimento de soluções computacionais eficientes.
