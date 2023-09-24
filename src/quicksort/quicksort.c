#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/timeb.h>

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

int main(int argc, char *argv[]) {
  struct timeb inicio, fim;
  int *vet;
  FILE *arquivo;
  arquivo = fopen(argv[1], "r");
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
  ftime(&inicio);
  quicksort(vet, 0, linhas - 1);
  ftime(&fim);
  for (i = 0; i < linhas; i++) {
    fprintf(arquivo, "%d\n", vet[i]);
  }

  fclose(arquivo);
  free(vet);
  int diff =
      (int)(1000.0 * (fim.time - inicio.time) + (fim.millitm - inicio.millitm));
  printf("%d\n", diff);

  return 0;
}