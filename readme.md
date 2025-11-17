# ordenacao-rgm-kaua (exemplo)

## Descrição
Projeto para a avaliação "Ordenação e Análise de Desempenho em C" — ordena os dígitos do RGM e compara 3 algoritmos:
- **Insertion Sort** (crescente; in-place; O(n²) worst/avg)
- **Quick Sort** (Lomuto partition; in-place; O(n log n) médio)
- **Merge Sort** (divide-and-conquer; extra memória; O(n log n) worst)

RGM usado por padrão: **045620920** (9 dígitos).

## Estrutura
/ordenacao-rgm-seuusuario ├─ src/ │   ├─ main.c │   ├─ sorts.c │   └─ sorts.h └─ README.md


## Como compilar
Use gcc (sugestão: sem -O3 enquanto contar passos; -O1 é aceitável):
```bash
gcc -std=c11 src/*.c -o ordena

Como executar

Usando o RGM padrão (045620920):
./ordena

Ou passando outro RGM como argumento:
./ordena 123456789

Saída: CSV no stdout com colunas:
metodo,N,caso,passos,tempo_ms 
Política de contagem de passos (adotada)
Comparações: contado 1 para cada comparação explícita entre elementos (macro COUNT_CMP).

Trocas/movimentações: contado 1 para cada atribuição que move/coloca elementos no vetor (macro COUNT_SWAP).

No Merge, cada cópia/atribuição para o buffer e cópia de volta conta como um movimento.


Nos resultados combinamos as duas medidas (passos = comparações + movimentações) para facilitar comparação agregada.


Medição de tempo

Usado clock() de <time.h>. O tempo é apresentado em ms.

Cada caso é repetido 5 vezes; o CSV informa a média dos tempos e média dos passos.


Casos testados

RGM: ordena os dígitos do RGM (9 elementos).

Aleatório: vetores gerados aleatoriamente para N = 100, 1000, 10000.


Observações sobre compilação/otimização

Enquanto contar passos, otimizações agressivas podem alterar o “fluxo” e pular instruções observáveis; recomenda-se compilar com -O0 ou -O1 para medições de passos consistentes:


gcc -std=c11 -O1 src/*.c -o ordena
