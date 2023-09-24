files = ["arquivo1000", "arquivo10000", "arquivo25000", "arquivo50684"]

for filename in files:
    orignal_list = []
    with open(f"./{filename}.csv", "r") as infile:
        orignal_list = [int(line.strip()) for line in infile.readlines()]
        upper_sort_bound = int(len(orignal_list) * 0.95)
        orignal_list[0:upper_sort_bound] = sorted(orignal_list[0:upper_sort_bound])

    with open(f"{filename}-parcial.csv", "w") as outfile:
        outfile.writelines(map(lambda value: f"{value}\n", orignal_list))
