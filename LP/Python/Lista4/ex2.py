def printNames(arqs):
    numLines = 0

    for file in arqs:
        yield(file)

        numLinesFile = 0
        for _ in open(file):
            numLines += 1
            numLinesFile += 1

        yield(numLinesFile)
    
    yield (numLines)



def main(arqs):
    for item in printNames(arqs):
        print(item)





