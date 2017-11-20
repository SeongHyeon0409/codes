from math import factorial as fact

def factorial(numStr):
    try:
        n = int(numStr)
        r = str(fact(n))
    except:
        r = 'Error!'
    return r

def decToBin(numStr):
    try:
        n = int(numStr)
        r = bin(n)[2:]
    except:
        r = 'Error!'
    return r

def binToDec(numStr):
    try:
        n = int(numStr, 2)
        r = str(n)
    except:
        r = 'Error!'
    return r

def decToRoman(numStr):
    try:
        n = int(numStr)

    except:
        return 'Error!'

    if n>= 4000:
        return 'Error!'

    romans = {
        1000: 'M', 900: 'CM', 500: 'D', 400: 'CD',
        100: 'C', 90: 'XC', 50: 'L', 40: 'XL',
        10: 'X', 9: 'IX', 5: 'V', 4: 'IV',
        1: 'I'
    }

    result = ''

    for value in sorted(romans.keys(),reverse=True):
        while n >= value:
            result += romans[value]
            n -= value

    return result

def romanToDec(numStr):

    #4000이상의 수를 예외처리 했지만 위에서 4000이상의 수를 변환할 수 없기때문에 동작할 일은 없을 것같다.
    if 'MMMM' in numStr:
        return 'Error!'

    # 9의 자리수와 10의 자리수의 순서를 서로 바꿔준 이유는 950을 바꾸려 하면 900인 'CM'을 인식하기전에
    # 'M'을 인식하여 1000으로 바꿔주기 때문이다. 그 이유로 사전에서 sort를하면 동작하지
    # 않기 때문에 리스트를 사용하였다.
    romans = [
        (900, 'CM'), (1000, 'M'), (400, 'CD'), (500, 'D'),
        (90, 'XC'), (100, 'C'),(40, 'XL'), (50, 'L'),
        (9, 'IX'), (10, 'X'), (4, 'IV'), (5, 'V'),
        (1, 'I')
    ]

    result = 0

    for value,letters in romans:
        while letters in numStr:
            result += value
            numStr = numStr.replace(letters,"",1) #바꿔준 문자열을 공백으로 치환함





    return result

if __name__ == '__main__':
    print(romanToDec('XXXCM'))


