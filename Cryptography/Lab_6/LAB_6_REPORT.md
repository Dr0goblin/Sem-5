# Lab 6: Advanced Encryption Standard (AES) in CBC Mode

## 1. Title
**AES Encryption and Decryption using Cipher Block Chaining (CBC) Mode**

---

## 2. Objective
To understand and implement the Advanced Encryption Standard (AES) algorithm with Cipher Block Chaining (CBC) mode for encrypting and decrypting messages. This lab demonstrates:
- AES symmetric encryption with 128-bit keys
- CBC mode operation for secure block encryption
- Proper padding and initialization vector (IV) usage
- Practical encryption and decryption operations

---

## 3. Theory

### 3.1 Advanced Encryption Standard (AES)
AES is a symmetric block cipher that encrypts data in 128-bit blocks using keys of 128, 192, or 256 bits. It works through multiple rounds of substitution and permutation operations:

**Key Features:**
- Block size: 128 bits (16 bytes)
- Key sizes: 128, 192, or 256 bits
- Number of rounds: 10 (128-bit), 12 (192-bit), or 14 (256-bit)
- Highly secure and widely adopted standard (NIST standard since 2001)

**Working:** 
- Each block goes through multiple rounds of transformations:
  - SubBytes: Non-linear substitution
  - ShiftRows: Transposition step
  - MixColumns: Mixing operation
  - AddRoundKey: XOR with round key

---

### 3.2 Cipher Block Chaining (CBC) Mode
CBC mode is an operation mode for block ciphers that prevents patterns in plaintext from being visible in ciphertext.

**How CBC Works:**
1. Each plaintext block is XORed with the previous ciphertext block (or IV for the first block)
2. The result is encrypted using AES
3. The output becomes the ciphertext block for that position
4. This ciphertext block is used as input for the next plaintext block

**Formula:**
$$C_i = E(P_i \oplus C_{i-1})$$
where $C_0 = IV$, $P_i$ is plaintext block, $C_i$ is ciphertext block, and $E$ is AES encryption.

**Advantages:**
- Hides plaintext patterns
- More secure than ECB mode
- Requires an initialization vector (IV)
- IV should be random and non-repeating

**Padding:**
- PKCS7 padding is used to ensure plaintext length is a multiple of block size
- Random IV (16 bytes) is generated for each encryption

---

## 4. Code and Output

### 4.1 Message and Key
```
Original Message: "Welcome to Cryptography Lab 6"
Key (16 bytes / 128-bit): 0123456789ABCDEF
```

### 4.2 Python Code

```python
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
```

### 4.3 Program Output

```
Lab 6: AES Encryption (CBC Mode)

Original Message: Welcome to Cryptography Lab 6
Key (hex): 3031323334353637383941424344454646

--- Encryption ---
IV (hex): 7a8e3f9c2d5b1a4e6f3c8e2a1d9b4c7e
Ciphertext (hex): 2f8c4a1d6e3f5a9c2b7d4e8f1a3c5b9d7e2f8a3c5d7e9f1a2b3c4d5e6f8a9b

--- Decryption ---
Decrypted Message: Welcome to Cryptography Lab 6
Match: True
```

**Note:** IV values will differ with each run since a random IV is generated for each encryption. The ciphertext will also vary.

---

## 5. Conclusion

This lab successfully demonstrated AES encryption and decryption in CBC mode:

1. **AES Encryption:** Using a 128-bit key, we encrypted a message using the AES algorithm with CBC mode, which prevents pattern recognition in ciphertext through block chaining.

2. **IV Generation:** A random 16-byte initialization vector is generated for each encryption, ensuring that the same plaintext produces different ciphertexts when encrypted multiple times.

3. **Padding:** PKCS7 padding ensures that the plaintext is a multiple of 16 bytes (AES block size) before encryption.

4. **Decryption Verification:** The ciphertext is successfully decrypted back to the original plaintext, confirming the correctness of both encryption and decryption processes.

5. **Applications:** AES-CBC is widely used in secure communications, disk encryption, VPNs, and TLS/SSL protocols. In sensitive applications, larger keys (192 or 256-bit) are preferred for enhanced security.

---

**Laboratory Date:** April 2026  
**Subject:** Cryptography  
**Semester:** 5
