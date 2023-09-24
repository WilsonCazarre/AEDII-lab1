import subprocess

test_cases = {
    "quicksort": ["c", "java", "python"],
    "bubble": ["c", "java", "python"],
    "counting": ["c", "java", "python"],
}

scenary_a_files = [
    "arquivo1000.csv",
    "arquivo10000.csv",
    "arquivo25000.csv",
    "arquivo50684.csv",
]
scenary_a_lengths = [1000, 10000, 25000, 50684]

scenary_b_files = [
    "arquivoDecrescente1000.csv",
    "arquivoDecrescente10000.csv",
    "arquivoDecrescente25000.csv",
    "arquivoDecrescente50681.csv",
]
scenary_b_lengths = [1000, 10000, 25000, 50681]


def generate_args(algoritm: str, language: str, case_filename: str):
    arguments = {
        "java": [
            "javac",
            f"{algoritm.capitalize()}.java",
            "&&",
            "java",
            "-Xss4m",  # Aumentar tamanho do stack
            f"{algoritm.capitalize()}",
            f"../../data/{case_filename}",
        ],
        "c": [
            "gcc",
            f"{algoritm}.c",
            "-o",
            f"{algoritm}.exe",
            "&&",
            f"{algoritm}.exe",
            f"../../data/{case_filename}",
        ],
        "python": ["python", f"{algoritm}.py", f"../../data/{case_filename}"],
    }
    return arguments[language]


for algoritm in test_cases:
    for iteration in range(0, 3):
        print(
            f"--------------{algoritm.capitalize()} sort Iteração {iteration}--------------"
        )
        for language in test_cases[algoritm]:
            for test_case_file, length in zip(scenary_b_files, scenary_b_lengths):
                output = subprocess.check_output(
                    generate_args(algoritm, language, test_case_file),
                    shell=True,
                    cwd=f"./src/{algoritm}",
                )
                print(
                    f"[{language}] {length} inteiros ordenados em {output.strip().decode()}ms"
                )
