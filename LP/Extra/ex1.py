def isDigit(value):
    try:
        assert value.isdigit()
        assert int(value) >= 0 and int(value) < 10
        return True

    except:
        print("{} is not a digit".format(value))
        return False
         
         
listDigits = []

while True:
    try:
        digit = input()
        if isDigit(digit):
            listDigits.append(digit)
 
    except EOFError:
        break

listDigits = sorted(listDigits, reverse=True)

print("{}{}".format(listDigits[0], listDigits[1]))
