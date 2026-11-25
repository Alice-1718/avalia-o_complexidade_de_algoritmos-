//0
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


//1
podemos melhorar o primeiro for substituindo i < n por i < n - 1
Isso reduz uma iteração do primeiro laço e evita verificações desnecessárias.

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




//2
podemos melhorar o segundo for substituindo j = 0 por int j = i + 1.
Pois o código estava percorrendo posições que não precisa verificar.

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



//3
Retirar a condição j > i do if
- Como o segundo for já começa em i + 1, essa condição se torna desnecessária.
- Basta usar if (v[j] < v[menor]).

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


//4
adicionamos if (menor != i) antes da troca.
Benefício: evita trocas desnecessárias quando o menor elemento já está na posição correta, 
melhorando um pouco o desempenho do algoritmo.


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


//5
mantém o menor valor encontrado em uma variável local, evitando leituras repetidas de v[menor].
a melhoria pode ser pequena, pois compiladores modernos já conseguem otimizar esse tipo de acesso. 


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

//6
Armazenamos v[j] na variável atual, evitando consultar o vetor repetidamente na comparação.
Utilizamos valorMenor diretamente na troca, evitando uma nova leitura de v[menor].
a alteração pode reduzir alguns acessos à memória

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