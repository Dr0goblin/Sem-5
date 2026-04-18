import math

def encryptMessage(plainText, key):
    cipherText = ''
    keylen = math.ceil(len(plainText) / len(key))
    key = key * keylen
    count = 0

    for letter in plainText:
        if letter in lowerCase:
            index = lowerCase.index(letter)
            shifter = lowerCase.index(key[count].lower())
            shiftedIndex = (index + shifter) % 26
            cipherText += lowerCase[shiftedIndex]
            count += 1

        elif letter in upperCase:
            index = upperCase.index(letter)
            shifter = upperCase.index(key[count].upper())
            shiftedIndex = (index + shifter) % 26
            cipherText += upperCase[shiftedIndex]
            count += 1

        else:
            cipherText += letter   # count NOT increased

    return cipherText


def decryptMessage(cipherText, key):
    plainText = ''
    keylen = math.ceil(len(cipherText) / len(key))
    key = key * keylen
    count = 0

    for letter in cipherText:
        if letter in lowerCase:
            index = lowerCase.index(letter)
            shifter = lowerCase.index(key[count].lower())
            shiftedIndex = (index - shifter) % 26
            plainText += lowerCase[shiftedIndex]
            count += 1

        elif letter in upperCase:
            index = upperCase.index(letter)
            shifter = upperCase.index(key[count].upper())
            shiftedIndex = (index - shifter) % 26
            plainText += upperCase[shiftedIndex]
            count += 1

        else:
            plainText += letter

    return plainText


# Alphabet lists
upperCase = []
lowerCase = []

for i in range(65, 91):
    upperCase.append(chr(i))

for j in range(97, 123):
    lowerCase.append(chr(j))


# Driver code
message = input('Enter your Message: ')
key = 'achs'

cipherText = encryptMessage(message, key)
print(f'Your encrypted Message: {cipherText}')

key2 = input('Please enter the secret key to decrypt the message: ')
plainText = decryptMessage(cipherText, key2)
print(f'Your hidden message is: {plainText}')