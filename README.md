# Computabilidade e Complexidade de Algoritmos
Prof. Dr. Leonardo Souto

Projeto Análise e refatoração de algoritmos clássicos

Equipe:
Mateus Martins <br>
Alice Felix <br>
Jessica Viriato <br>
Layssa Evellyn <br>

# Instruções
O desafio. Vocês vão receber o código de um algoritmo clássico da computação, escrito do
jeito mais direto (e mais lento) possível. A missão é analisar esse código com as ferramentas
da disciplina (f(n), O, Ω e Θ), refatorá-lo pelo menos 6 vezes diminuindo a f(n) a cada passo,
provar que cada mudança melhorou de verdade (na conta e na complexidade) e mostrar na
prática, medindo o tempo de execução, que a melhora aparece no computador

# Algorítimo sorteado: Selection Sort

| entrada de pior caso | tamanhos sugeridos para o experimento | classe da v0 |
| -------------------- | ------------------------------------- | ------------ |
| qualquer vetor (a seleção sempre varre tudo); use aleatório e decrescente | 1.000 a 20.000 | Θ(n²) |

Pistas para começar
• Para que serve o teste j > i? Dá para fazer o laço já começar no lugar certo?
• Quantas vezes v[menor] é lido sem ter mudado?


# Versão 0

  - descrição: é o código original fornecido

  - código:
  ```c
    void selecao(int v[], int n) {
      for (int i = 0; i < n; i++) {
        int menor = i;
        for (int j = 0; j < n; j++) {
          if (j > i && v[j] < v[menor]) {
            menor = j;
          }
        }
        int aux = v[i];
        v[i] = v[menor];
        v[menor] = aux;
      }
    }
  ```
- constantes (primitivas):

| primitivas | classif.|
| ---------- | ------- |
| c1 i= | 1  |
| c2 i< | n + 1 |
| c3 i++ | n |
| c4 menor = | n |
| c5 j= | n |
| c6 j< | n² + n |
| c7 j++ | n² |
| c8 j > | n² |
| c9 && | n² |
| c10 v[j] | n² |
| c11 < | n² |
| c12 v[menor] | n²|
| c13 menor= | n² |
| c14 aux= | n |
| c15 v[i] | n |
| c16 v[i] | n |
| c17  = | n |
| c18 v[menor] | n |
| c19 v[menor] | n |
| c20 = | n |

f(n) = 8n² + 12n + 2

c1 = 8n²
c2 = 12n

- tabela:

| n  | c₁·g(n)|   f(n)  |c₂·g(n)|
| -- | ------ | ------- | ----  |
| 1  | 8      | 22      | 22    |
| 2  | 32     | 58      | 88    |
| 3  | 72     | 110     | 198   |
| 4  | 128    | 178     | 352   |
| 5  | 200    | 262     | 550   |
| 6  | 288    | 362     | 792   |
| 7  | 392    | 478     | 1078  |
| 8  | 512    | 610     | 1408  |


- gráfico das tres curvas:
  ```mermaid
  xychart-beta
      title "Gráfico"
      x-axis [1,2,3,4,5,6,7,8]
      y-axis "resultados" 0 --> 1408
      line "c₁·g(n)" [8, 32, 72, 128, 200, 288, 392, 512]
      line "f(n)" [22, 58, 110, 178, 262, 362, 478, 610]
      line "c₂·g(n)" [22, 88, 198, 352, 550, 792, 1078, 1408]
  ```

- Algoritmo recursivo 
  (Fibonacci): a análise é a recorrência T(n), calculada na tabela, como na última aula


  Tempo de execução: 0.000006 segundos
  entrada : 20000, 9000, 5000, 1000, 3000, 10000, 7000, 6000
  saída (vetor ordenado): 1000 3000 5000 6000 7000 9000 10000 20000 


# Escolha uma versão abaixo e faça as primitivas e a tabela como na versão 0 (acima) e mande pra mim em arquivo de texto que eu adiciono aqui
  
# Versão 1
  - código:
  ```c
  void selecao(int v[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int menor = i;
    for (int j = 0; j < n; j++) {
      if (j > i && v[j] < v[menor]) {
        menor = j;
      }
    }
    int aux = v[i];
    v[i] = v[menor];
    v[menor] = aux;
  }
  }
  ```
  -constantes
  -tabela
  -gráfico
  -algorítimo recursivo

  Tempo de execução: 0.000005 segundos
  entrada : 20000, 9000, 5000, 1000, 3000, 10000, 7000, 6000
  saída (vetor ordenado): 1000 3000 5000 6000 7000 9000 10000 20000 
  
# Versão 2

  - código:
  ```c
  void selecao(int v[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int menor = i;
    for (int j = i + 1; j < n; j++) {
      if (j > i && v[j] < v[menor]) {
        menor = j;
      }
    }
    int aux = v[i];
    v[i] = v[menor];
    v[menor] = aux;
  }
  }
  ```

  Tempo de execução: 0.000004 segundos
  entrada : 20000, 9000, 5000, 1000, 3000, 10000, 7000, 6000
  saída (vetor ordenado): 1000 3000 5000 6000 7000 9000 10000 20000 

# Versão 3

  - código:
  
  ```c
  void selecao(int v[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int menor = i;
    for (int j = i + 1; j < n; j++) {
      if ( v[j] < v[menor]) {
        menor = j;
      }
    }
    int aux = v[i];
    v[i] = v[menor];
    v[menor] = aux;
  }
  }
  ```

  Tempo de execução: 0.000003 segundos
  entrada : 20000, 9000, 5000, 1000, 3000, 10000, 7000, 6000
  saída (vetor ordenado): 1000 3000 5000 6000 7000 9000 10000 20000 

# Versão 4

  - código:
  ```c
  void selecao(int v[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int menor = i;

    for (int j = i + 1; j < n; j++) {
      if (v[j] < v[menor]) {
        menor = j;
      }
    }

    if (menor != i) {
      int aux = v[i];
      v[i] = v[menor];
      v[menor] = aux;
    }
  }
  }
  ```

  Tempo de execução: 0.000003 segundos
  entrada : 20000, 9000, 5000, 1000, 3000, 10000, 7000, 6000
  saída (vetor ordenado): 1000 3000 5000 6000 7000 9000 10000 20000 

# Versão 5

  - código:
  ```c
  void selecao(int v[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int menor = i;
    int valorMenor = v[menor];

    for (int j = i + 1; j < n; j++) {
      if (v[j] < valorMenor) {
        menor = j;
        valorMenor = v[j];
      }
    }

    if (menor != i) {
      int aux = v[i];
      v[i] = v[menor];
      v[menor] = aux;
    }
  }
  }
  ```

  Tempo de execução: 0.000003 segundos
  entrada : 20000, 9000, 5000, 1000, 3000, 10000, 7000, 6000
  saída (vetor ordenado): 1000 3000 5000 6000 7000 9000 10000 20000 

# Versão 6

  - código:
  ```c
  void selecao(int v[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int menor = i;
    int valorMenor = v[i];

    for (int j = i + 1; j < n; j++) {
      int atual = v[j];

      if (atual < valorMenor) {
        menor = j;
        valorMenor = atual;
      }
    }

    if (menor != i) {
      int aux = v[i];
      v[i] = valorMenor;
      v[menor] = aux;
    }
  }
  }
  ```

  Tempo de execução: 0.000004 segundos
  entrada : 20000, 9000, 5000, 1000, 3000, 10000, 7000, 6000
  saída (vetor ordenado): 1000 3000 5000 6000 7000 9000 10000 20000 

# tabela de evolução com todos os n utilizados e os resultados de todas as refatorações


