def func1 (arqs, n):
    for file in arqs:
        for line in open(file):
            if len(line) > n:
                print(line)


