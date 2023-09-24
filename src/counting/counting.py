import time
import sys


def countingSort(vet):
    tam = len(vet)
    MAX = max(vet)
    ctam = MAX + 1
    # inicializa com 0
    b = [0] * tam
    c = [0] * ctam

    for i in vet:
        c[i] += 1
    for i in range(1, ctam):
        c[i] += c[i - 1]
    i = tam - 1
    while i >= 0:
        b[c[vet[i]] - 1] = vet[i]
        c[vet[i]] -= 1
        i -= 1
    return b


arquivo = open(sys.argv[1], "r")
# armazenar os dados do arquivo em int
dadosInt = []

for linha in arquivo:
    teste = int(linha)
    dadosInt.append(teste)

inicio = time.time() * 1000
vet = countingSort(dadosInt)
fim = time.time() * 1000
print(int(fim - inicio))

arquivo.close()
