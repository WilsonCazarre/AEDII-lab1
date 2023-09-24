#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void countingsort(int *vet, int *B, int N) {
  int i, j;
  int maior_valor = vet[0];
  for (i = 1; i < N; i++) {
    if (vet[i] > maior_valor) {
      maior_valor = vet[i];
    }
  }
  int C[maior_valor + 1];
  for (i = 0; i <= maior_valor; i++) {
    C[i] = 0;
  }

  for (j = 0; j < N; j++) {
    C[vet[j]]++;
  }
  for (i = 1; i <= maior_valor; i++) {
    C[i] = C[i] + C[i - 1];
  }
  for (j = N - 1; j >= 0; j--) {
    B[C[vet[j]] - 1] = vet[j];
    C[vet[j]]--;
  }

  for (i = 0; i < N; i++) {
    vet[i] = B[i];
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
  int B[linhas];
  // B = (int *)malloc(linhas * sizeof(int));

  rewind(arquivo);

  for (i = 0; i < linhas; i++) {
    fscanf(arquivo, "%d", &vet[i]);
  }

  fclose(arquivo);

  arquivo = fopen("arquivo_ordenado.csv", "w+");

  countingsort(vet, B, linhas);
  for (i = 0; i < linhas; i++) {
    fprintf(arquivo, "%d\n", vet[i]);
  }

  fclose(arquivo);

  free(vet);
  // free(B);

  fim = time(NULL);
  printf("Tempo em segundos %lf\n\n", difftime(fim, inicio));

  return 0;
}