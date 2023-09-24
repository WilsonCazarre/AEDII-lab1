import time
import sys


def swap(vet, i):
    aux = vet[i]
    vet[i] = vet[i + 1]
    vet[i + 1] = aux


def bubbleSort(vet, n):
    for i in range(n - 1, 0, -1):
        for j in range(i):
            if vet[j + 1] < vet[j]:
                swap(vet, j)
    return vet


arquivo = open(sys.argv[1], "r")
# armazenar os dados do arquivo em int
dadosInt = []

line_number = 1

for linha in arquivo:
    try:
        teste = int(linha)
        dadosInt.append(teste)
        line_number += 1
    except ValueError as e:
        print(f"Line number: {line_number}")
        raise e

tam = len(dadosInt)
inicio = time.time() * 1000
vet = bubbleSort(dadosInt, tam)
fim = time.time() * 1000
print(int(fim - inicio))

arquivo.close()
