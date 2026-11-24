# Computabilidade e Complexidade de Algoritmos
Prof. Dr. Leonardo Souto

Projeto Análise e refatoração de algoritmos clássicos

Equipe:
Mateus Martins
Alice Felix
Jessica Viriato
Layssa Evellyn

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

# Resolução (usando python)

# Versão 0

  - descrição: é o código original fornecido

  - código:
  ```python
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
- contantes (primitivas):

| primitivas | variav.|
| ---------- | ------- |
| c1 i= | 1  |
| c2 i< | n |
| c3 i++ | n |
| c4 menor = | n |
| c5 j= | n |
| c6 j< | n² |
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


*adicionar um contador de primitivas para comprovar que ta batendo o valor de f(n) apresentado aqui com o do codigo

- tabela:

| c₁·g(n) | f(n) | c₂·g(n) |
f(n) = 11n + 8n² + 1


classe utilizada Θ(n²)

- gráfico das tres curvas:

- Algoritmo recursivo
  (Fibonacci): a análise é a recorrência T(n), calculada na tabela, como na última aula

- valores de entrada utilizados:
  
- resultado do código (saída):
  tem sempre que dar o mesmo resultado
  
- tempo de execução:
  • usar 8 tamanhos de n e 5 repetições
  • utilizar graficos para comparar esta refatoração com a ultima qual foi mais rapida
  • Implementem todas as versões numa mesma linguagem e meçam o tempo de execução com pelo menos 8 tamanhos de n e 5 repetições por tamanho (usem a mediana)
  • Gráficos obrigatórios: tempo × n de todas as versões no mesmo plano; e tempo ÷ f(n) × n (se
a análise estiver certa, essa razão tende a ficar parada).
  • Mostrem o ganho total: quantas vezes a v6 é mais rápida que a v0 no maior n que as duas
conseguem rodar.




  
# Versão 1 exemplo - deve conter todos os topicos como na versao 0!
  descrição: neste código iniciamos a primeira refatoração substituindo o código diga o que voce alterou antes de fazer
  código : será o mesmo anterior só que alterado uma parte com o objetivo de otimizar
  -- preencher do mesmo jeito que a versao 0
  
# Versão 2
# Versão 3
# Versão 4
# Versão 5
# Versão 6

# tabela de evolução com todos os n utilizados e os resultados de todas as refatorações


