#include <stdio.h>
#include <stdlib.h>
#include <sys\timeb.h>

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

int main(int argc, char *argv[]) {
  struct timeb start, end;

  int *vet;
  FILE *arquivo;
  arquivo = fopen(argv[1], "r");
  int i = 0;
  int ch = 0;
  int linhas = 0;

  if (arquivo == NULL) {
    printf("File not found %s\n", argv[1]);
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

  ftime(&start);
  bubble(vet, linhas);
  ftime(&end);
  int diff =
      (int)(1000.0 * (end.time - start.time) + (end.millitm - start.millitm));

  arquivo = fopen("arquivo_ordenado.csv", "w+");

  for (i = 0; i < linhas; i++) {
    fprintf(arquivo, "%d\n", vet[i]);
  }

  fclose(arquivo);

  free(vet);

  printf("%u\n", diff);

  return 0;
}