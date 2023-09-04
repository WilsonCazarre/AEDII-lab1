my_list = [8, 2, 9, 6, 4, 5, 9]


def bubble(unsorted: list):
    for i in range(len(unsorted)):
        for j in range(len(unsorted) - i - 1):
            if unsorted[j] > unsorted[j + 1]:
                current_item = unsorted[j]
                unsorted[j] = unsorted[j + 1]
                unsorted[j + 1] = current_item
    return unsorted


print(bubble(my_list))
