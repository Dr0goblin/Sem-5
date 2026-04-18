from Crypto.Cipher import AES
from Crypto.Random import get_random_bytes
from Crypto.Util.Padding import pad, unpad

def encrypt_aes_cbc(message, key):
    iv = get_random_bytes(16)
    cipher = AES.new(key, AES.MODE_CBC, iv)
    ciphertext = cipher.encrypt(pad(message.encode(), AES.block_size))
    return iv, ciphertext

def decrypt_aes_cbc(iv, ciphertext, key):
    cipher = AES.new(key, AES.MODE_CBC, iv)
    plaintext = unpad(cipher.decrypt(ciphertext), AES.block_size)
    return plaintext.decode()

if __name__ == "__main__":
    print("Lab 6: AES Encryption (CBC Mode)\n")
    
    # Message and Key
    message = "Welcome to Cryptography Lab 6"
    key = b"0123456789ABCDEF"  # 16 bytes (128-bit key)
    
    print(f"Original Message: {message}")
    print(f"Key (hex): {key.hex()}\n")
    
    # Encryption
    print("--- Encryption ---")
    iv, ciphertext = encrypt_aes_cbc(message, key)
    print(f"IV (hex): {iv.hex()}")
    print(f"Ciphertext (hex): {ciphertext.hex()}\n")
    
    # Decryption
    print("--- Decryption ---")
    decrypted_message = decrypt_aes_cbc(iv, ciphertext, key)
    print(f"Decrypted Message: {decrypted_message}")
    print(f"Match: {message == decrypted_message}")