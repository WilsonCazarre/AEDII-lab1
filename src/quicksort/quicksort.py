import time


def particiona(vet, inicio, final):
    x = vet[final]
    i = inicio - 1
    for j in range(inicio, final):
        if vet[j] <= x:
            i = i + 1
            aux = vet[i]
            vet[i] = vet[j]
            vet[j] = aux
    aux = vet[i + 1]
    vet[i + 1] = vet[final]
    vet[final] = aux
    return i + 1


def quickSort(vet, inicio, fim):
    if fim > inicio:
        pivo = particiona(vet, inicio, fim)
        quickSort(vet, inicio, pivo - 1)
        quickSort(vet, pivo + 1, fim)
    return vet


arquivo = open("teste.txt", "r")
# armazenar os dados do arquivo em int
dadosInt = []

for linha in arquivo:
    teste = int(linha)
    dadosInt.append(teste)

tam = len(dadosInt)

inicio = time.time()
vet = quickSort(dadosInt, 0, tam - 1)
print(vet)
fim = time.time()

print(fim - inicio)

arquivo.close()
