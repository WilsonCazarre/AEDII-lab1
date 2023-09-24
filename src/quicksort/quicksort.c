#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void swap(int *seq, int i, int indice) {
  int auxiliar;
  auxiliar = seq[i];
  seq[i] = seq[indice];
  seq[indice] = auxiliar;
}

int partition(int *seq, int inicio, int fim) {
  int x;
  int i, j;
  int indice;
  x = seq[fim];
  indice = inicio;

  for (i = inicio; i < fim; i++) {
    if (seq[i] <= x) {
      swap(seq, i, indice);
      indice++;
    }
  }
  swap(seq, indice, fim);
  return indice;
}

void quicksort(int *seq, int inicio, int fim) {
  int q;  // indice do pivo
  if (inicio < fim) {
    q = partition(seq, inicio, fim);
    quicksort(seq, inicio, q - 1);
    quicksort(seq, q + 1, fim);
  }
}

int main() {
  time_t inicio, fim;
  inicio = time(NULL);
  int *vet;
  FILE *arquivo;
  arquivo = fopen("arquivo.csv", "r");
  int i = 0;
  int ch = 0;
  int linhas = 0;

  if (arquivo == NULL) {
    return 1;
  } else {
    // Efetua a contagem de linhas lendo o arquivo e procurando a quebra de
    // linha
    while (fscanf(arquivo, "%d", &ch) != EOF) {
      linhas++;
    }
  }

  vet = (int *)malloc(linhas * sizeof(int));

  rewind(arquivo);

  for (i = 0; i < linhas; i++) {
    fscanf(arquivo, "%d", &vet[i]);
  }

  fclose(arquivo);

  arquivo = fopen("arquivo_ordenado.csv", "w+");

  quicksort(vet, 0, linhas - 1);

  for (i = 0; i < linhas; i++) {
    fprintf(arquivo, "%d\n", vet[i]);
  }

  fclose(arquivo);

  free(vet);

  fim = time(NULL);
  printf("Tempo em segundos %lf\n\n", difftime(fim, inicio));

  return 0;
}