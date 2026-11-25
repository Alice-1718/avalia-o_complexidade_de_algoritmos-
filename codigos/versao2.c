// Esta é a versao 2 do código

#include <stdio.h>
#include <time.h>

//codigo principal a ser refatorado
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

//variaveis e main (não deve ser alterado)
int main() {

    //variaveis
    int v[] = {20000, 9000, 5000, 1000, 3000, 10000, 7000, 6000};
    int n = 8; //8 tamanhos de n


    //Captura o tempo de início
    struct timespec inicio, fim;
    double tempo_gasto;
    clock_gettime(CLOCK_MONOTONIC, &inicio);

    //teste do codigo 5 vezes
    for(int x=0; x< 5; x++){
        selecao(v, n);
    }

    //calcular tempo final
    clock_gettime(CLOCK_MONOTONIC, &fim);
    tempo_gasto = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;

    printf("Tempo de execução: %f segundos\n", tempo_gasto);

    // visualizar a saida (resultado da execucao)
    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}

/*

Tempo de execução: 0.000004 segundos
entrada : 20000, 9000, 5000, 1000, 3000, 10000, 7000, 6000
Vetor ordenado: 1000 3000 5000 6000 7000 9000 10000 20000 
*/