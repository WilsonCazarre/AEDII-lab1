import time


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


arquivo = open("arquivo.txt", "r")
# armazenar os dados do arquivo em int
dadosInt = []

for linha in arquivo:
    teste = int(linha)
    dadosInt.append(teste)

tam = len(dadosInt)
inicio = time.time()
vet = bubbleSort(dadosInt, tam)
print(vet)
fim = time.time()

print(fim - inicio)

arquivo.close()
