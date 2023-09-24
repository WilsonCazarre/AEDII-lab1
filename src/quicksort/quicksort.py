import time
import sys

# sys.setrecursionlimit(5000)


def quick_sort(original_list: "list[int]"):
    if len(original_list) == 0:
        return original_list

    pivot = original_list[len(original_list) // 2]
    less_than_pivot = [value for value in original_list if value < pivot]
    greater_than_pivot = [value for value in original_list if value > pivot]
    eq_to_pivot = [value for value in original_list if value == pivot]
    return quick_sort(less_than_pivot) + eq_to_pivot + quick_sort(greater_than_pivot)


arquivo = open(sys.argv[1], "r")
# armazenar os dados do arquivo em int
dadosInt = []

for linha in arquivo:
    teste = int(linha)
    dadosInt.append(teste)

arquivo.close()
inicio = time.time() * 1000
vet = quick_sort(dadosInt)
fim = time.time() * 1000

print(int(fim - inicio))
