# VIGENERE CIPHER - Encryption and Decryption

def generate_key(message, key):
    key = key.upper()
    message = message.upper()
    key_repeated = ""
    key_index = 0
    
    for char in message:
        if char.isalpha():
            key_repeated += key[key_index % len(key)]
            key_index += 1
        else:
            key_repeated += char
    
    return key_repeated

def encrypt(message, key):
    message = message.upper()
    key = generate_key(message, key)
    result = ""
    
    for i in range(len(message)):
        if message[i].isalpha():
            shift = (ord(message[i]) - 65 + ord(key[i]) - 65) % 26
            result += chr(shift + 65)
        else:
            result += message[i]
    
    return result

def decrypt(cipher, key):
    cipher = cipher.upper()
    key = generate_key(cipher, key)
    result = ""
    
    for i in range(len(cipher)):
        if cipher[i].isalpha():
            shift = (ord(cipher[i]) - 65 - (ord(key[i]) - 65)) % 26
            result += chr(shift + 65)
        else:
            result += cipher[i]
    
    return result

# My unique message and key
message = "Python Programming is Fun"
key = "SECRET"

print("VIGENERE CIPHER")
print("-" * 40)
print(f"Original Message: {message}")
print(f"Key: {key}")

encrypted = encrypt(message, key)
print(f"Encrypted: {encrypted}")

decrypted = decrypt(encrypted, key)
print(f"Decrypted: {decrypted}")