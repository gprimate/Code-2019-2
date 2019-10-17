def charPraInt(c):
    try:
        return int(c)

    except ValueError:
        return c

def inputNum():
    
    while True:
        num = input('Type an integer: ')
        num = charPraInt(num)

        if type(num) is int:
            return num

        elif num is '-':
            return num

        else:
            print('Invalid input! Try again')
    

def main():
    listNum = []
    
    while True:
        num = inputNum()
        if num is '-':
            break
        else:
            listNum.append(num)
    listNum.sort(reverse=True)

    listNum = "".join(str(i) for i in listNum)
    print(listNum)






