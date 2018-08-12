import cs50
import sys


def vigenere():

  # Handle KEYz
    keys = []
    key = sys.argv[1]
    keyCounter = 0

    for i in key:
        if(not i.isalpha()):
            print('not alpha')
            sys.exit(1)
        if(i.isupper()):
          # ord gets the ascii
            keys.append(ord(i) - 65)
        else:
            keys.append(ord(i) - 97)

    # handle INPUT string
    input = cs50.get_string("input:")
    print(f"plaintext: {input}")
    print("ciphertext: ", end="")

    for i in input:
        if(keyCounter > len(key) - 1):
            keyCounter = 0
        # check that first letter is alpha of input
        if(i.isalpha()):
          # check if upper
            if(i.isupper()):
                # call coverter funcion
                converter(keys, key, keyCounter, i, True)
                # increment global counter
                keyCounter += 1
            else:
                # same as above but for lowercase
                converter(keys, key, keyCounter, i, False)
                keyCounter += 1
        elif(not input[0].isalpha()):
            # if not alpha to start
            print("Not alpha")
        else:
            # if not alpha elsewhere, just print no cipher
            print(i, end="")

    print("\n")


def converter(keys, key, counter, char, isUpper):
    convertKey = keys[counter % len(key)]
    # consider case with T or F setting
    if(isUpper == True):
        # ord gets ascii
        convertInput = ord(char) - 65
    else:
        convertInput = ord(char) - 97
    if(isUpper == True):
         # add 65 back to end, after formula!, t``o get ascii
        ascii = 65
    else:
        ascii = 97
    result = ((convertInput + convertKey) % 26) + ascii
    result = chr(result)
    print(result, end="")
    return result


vigenere()