# ========================================================================
# CAESAR CIPHER - ENCRYPTION AND DECRYPTION
# ========================================================================

def caesar_encrypt(message, key):
    """Encrypt message using Caesar cipher with given key"""
    result = ""
    
    for char in message:
        if char.isalpha():
            # Determine if character is uppercase or lowercase
            ascii_offset = 65 if char.isupper() else 97
            
            # Shift character and wrap around using modulo
            shifted = (ord(char) - ascii_offset + key) % 26
            result += chr(shifted + ascii_offset)
        else:
            # Keep non-alphabetic characters unchanged
            result += char
    
    return result

def caesar_decrypt(encrypted_message, key):
    """Decrypt message using Caesar cipher with given key"""
    result = ""
    
    for char in encrypted_message:
        if char.isalpha():
            ascii_offset = 65 if char.isupper() else 97
            
            # Reverse the shift for decryption
            shifted = (ord(char) - ascii_offset - key) % 26
            result += chr(shifted + ascii_offset)
        else:
            result += char
    
    return result

# ========================================================================
# MAIN PROGRAM - CAESAR CIPHER
# ========================================================================

print("=" * 60)
print("CAESAR CIPHER - ENCRYPTION AND DECRYPTION")
print("=" * 60)

# My unique message and key
message = "Python Programming is Fun!"
key = 7

print(f"\n ORIGINAL MESSAGE: {message}")
print(f" KEY: {key}")

# Encryption
encrypted = caesar_encrypt(message, key)
print(f"\nENCRYPTED MESSAGE: {encrypted}")

# Decryption
decrypted = caesar_decrypt(encrypted, key)
print(f" DECRYPTED MESSAGE: {decrypted}")

# Verification
print(f"\nVERIFICATION: {'SUCCESSFUL' if message == decrypted else 'FAILED'}")
print(f"   Original matches Decrypted: {message == decrypted}")
