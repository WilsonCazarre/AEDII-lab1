#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *v, int i) {
  int aux;
  aux = v[i];
  v[i] = v[i + 1];
  v[i + 1] = aux;
}

void bubble(int *vet, int linhas) {
  int i, j;

  for (i = linhas - 1; i > 0; i--) {
    for (j = 0; j < i; j++) {
      if (vet[j + 1] < vet[j]) {
        swap(vet, j);
      }
    }
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

  bubble(vet, linhas);

  for (i = 0; i < linhas; i++) {
    fprintf(arquivo, "%d\n", vet[i]);
  }

  fclose(arquivo);

  free(vet);

  fim = time(NULL);
  printf("Tempo em segundos %lf\n\n", difftime(fim, inicio));

  return 0;
}