# Lab 9: Hash Functions (MD5 and SHA)

## 1. Title
**Hash Functions: MD5 and SHA Algorithms for Data Integrity and Security**

---

## 2. Objective
To understand and implement cryptographic hash functions:
- Generate hash values using MD5 algorithm
- Generate hash values using SHA algorithms (SHA-1, SHA-256, SHA-512)
- Understand properties of secure hash functions
- Verify hash functions with multiple inputs

---

## 3. Theory

### 3.1 Cryptographic Hash Functions

A cryptographic hash function is a mathematical algorithm that converts any input data into a fixed-size string of bytes. The output, called a hash value or digest, is unique to each unique input.

**Properties of Secure Hash Functions:**
1. **Deterministic:** Same input always produces same output
2. **Quick computation:** Hash value computed efficiently
3. **Avalanche effect:** Small input change produces completely different hash
4. **One-way function:** Infeasible to reverse - cannot derive input from hash
5. **Collision-resistant:** Hard to find two different inputs with same hash
6. **Fixed output size:** Output always same length regardless of input size

**Applications:**
- Password storage (not storing passwords directly)
- Data integrity verification
- Digital signatures
- Blockchain and cryptocurrencies
- File checksums

---

### 3.2 MD5 (Message Digest Algorithm 5)

MD5 is a 128-bit cryptographic hash function that produces a 32-character hexadecimal output.

**Specifications:**
- **Hash size:** 128 bits (16 bytes)
- **Output:** 32 hexadecimal characters
- **Algorithm:** Processes input in 512-bit blocks through 64 rounds
- **Operations:** Uses logical functions (AND, OR, XOR, NOT) and modular addition

**How MD5 Works:**
1. Pad input to multiple of 512 bits
2. Parse padded message into 512-bit blocks
3. Initialize four 32-bit variables (A, B, C, D)
4. Process each block through 4 main rounds (16 operations each)
5. Produce final 128-bit hash

**Vulnerabilities:**
- Prone to collision attacks (two different inputs produce same hash)
- No longer considered cryptographically secure
- Deprecated for security purposes but still used for non-security checksums

**Example:**
- Input: "Hello World"
- MD5: a591a6d40bf420404a011733cfb7b190

---

### 3.3 SHA (Secure Hash Algorithm)

SHA is a family of cryptographic hash functions designed by NSA. Current versions are SHA-1, SHA-2 (256-bit, 512-bit), and SHA-3.

**SHA-1:** (Deprecated)
- **Hash size:** 160 bits (20 bytes)
- **Output:** 40 hexadecimal characters
- **Status:** Cryptographically broken, no longer recommended

**SHA-256 (SHA-2 family):**
- **Hash size:** 256 bits (32 bytes)
- **Output:** 64 hexadecimal characters
- **Status:** Widely used and secure (currently recommended)
- **Uses:** Digital signatures, SSL/TLS, Bitcoin

**SHA-512 (SHA-2 family):**
- **Hash size:** 512 bits (64 bytes)
- **Output:** 128 hexadecimal characters
- **Status:** Highly secure for critical applications
- **Uses:** Enterprise security, long-term data protection

**How SHA Works:**
1. Pad message to specific length
2. Parse into 512-bit (SHA-1/256) or 1024-bit (SHA-512) blocks
3. Initialize hash values
4. Process each block through multiple rounds
5. Produce final hash

**Comparison:**

| Algorithm | Hash Size | Output Length | Status | Collision Time |
|-----------|-----------|---------------|--------|-----------------|
| MD5 | 128 bits | 32 chars | Broken | 2^21 operations |
| SHA-1 | 160 bits | 40 chars | Broken | 2^63 operations |
| SHA-256 | 256 bits | 64 chars | Secure | 2^128 operations |
| SHA-512 | 512 bits | 128 chars | Secure | 2^256 operations |

---

## 4. Code and Output

### 4.1a MD5 Hash Generation

**Code:**
```python
import hashlib

def md5_hash(message):
    md5_obj = hashlib.md5()
    md5_obj.update(message.encode())
    return md5_obj.hexdigest()

if __name__ == "__main__":
    print("Lab 9a: MD5 Hash Generation\n")
    
    test_messages = [
        "Hello World",
        "Cryptography",
        "Lab 9",
        "12345",
        "The quick brown fox jumps over the lazy dog"
    ]
    
    for message in test_messages:
        hash_value = md5_hash(message)
        print(f"Message: {message}")
        print(f"MD5 Hash: {hash_value}\n")
```

**Output:**
```
Lab 9a: MD5 Hash Generation

Message: Hello World
MD5 Hash: b10a8db164e0754105b7a99be72e3fe5

Message: Cryptography
MD5 Hash: 64ef07ce3e4b420c334227eecb3b3f4c

Message: Lab 9
MD5 Hash: 3bb7fbaea451722d86e2e05bf62cebe6

Message: 12345
MD5 Hash: 827ccb0eea8a706c4c34a16891f84e7b

Message: The quick brown fox jumps over the lazy dog
MD5 Hash: 9e107d9d372bb6826bd81d3542a419d6
```

---

### 4.1b SHA Hash Generation

**Code:**
```python
import hashlib

def sha1_hash(message):
    sha1_obj = hashlib.sha1()
    sha1_obj.update(message.encode())
    return sha1_obj.hexdigest()

def sha256_hash(message):
    sha256_obj = hashlib.sha256()
    sha256_obj.update(message.encode())
    return sha256_obj.hexdigest()

def sha512_hash(message):
    sha512_obj = hashlib.sha512()
    sha512_obj.update(message.encode())
    return sha512_obj.hexdigest()

if __name__ == "__main__":
    print("Lab 9b: SHA Hash Generation\n")
    
    test_messages = [
        "Hello World",
        "Cryptography",
        "Lab 9",
        "12345"
    ]
    
    for message in test_messages:
        sha1 = sha1_hash(message)
        sha256 = sha256_hash(message)
        sha512 = sha512_hash(message)
        
        print(f"Message: {message}")
        print(f"SHA-1   ({len(sha1)//2} bytes): {sha1}")
        print(f"SHA-256 ({len(sha256)//2} bytes): {sha256}")
        print(f"SHA-512 ({len(sha512)//2} bytes): {sha512}\n")
```

**Output:**
```
Lab 9b: SHA Hash Generation

Message: Hello World
SHA-1   (20 bytes): 0a4d55a8d778e5022fab701977c5d840bbc486d0
SHA-256 (32 bytes): a591a6d40bf420404a011733cfb7b190d62c65bf0bcda32b57b277d9ad9f146e
SHA-512 (64 bytes): 2c74fd17edafd80e8447b0d46741ee243b7eb74dd2149a0ab1b9246fb30382f27e853d8585719e0e67cbda0daa8f51671064615d645ae27acb15bfb1447f459b

Message: Cryptography
SHA-1   (20 bytes): b804ec5a0d83d19d8db908572f51196505d09f98
SHA-256 (32 bytes): b584eec728548aced5a66c0267dd520a00871b5e7b735b2d8202f86719f61857
SHA-512 (64 bytes): 1dbb2224e5108b80246acacd67afa3304c023c467a4a5b4d3c3aaf97508ab11208b5635a7d759a7cacac4e688141dedb953030f364ceff54d9b7f34813e2ca20

Message: Lab 9
SHA-1   (20 bytes): fcc5f6ce9ee10b900283a1d63894c0cc1fa87d4b
SHA-256 (32 bytes): 54d7a17c04963fa217649aea748c48950591573df84ff87f42f778770b1c0d96
SHA-512 (64 bytes): 36221e31c5f1fac5003b509f75b4d2f054ff4cf1109690420f48bae68ac9a816b9753f6388b913831fa67ce8596fe785fbf8a95af283912d02b6234f3f1fa0a3

Message: 12345
SHA-1   (20 bytes): 8cb2237d0679ca88db6464eac60da96345513964
SHA-256 (32 bytes): 5994471abb01112afcc18159f6cc74b4f511b99806da59b3caf5a9c173cacfc5
SHA-512 (64 bytes): 3627909a29c31381a071ec27f7c9ca97726182aed29a7ddd2e54353322cfb30abb9e3a6df2ac2c20fe23436311d678564d0c8d305930575f60e2d3d048184d79
```

---

## 5. Conclusion

This lab successfully demonstrated cryptographic hash functions using MD5 and SHA algorithms:

1. **MD5 Hash Function:** Generated 128-bit (32 character) hashes for various inputs. While MD5 produces fast and deterministic hashes, it is no longer considered secure due to collision vulnerabilities and should be avoided for security purposes.

2. **SHA Hash Functions:** Implemented three SHA variants:
   - **SHA-1:** Historical use only (deprecated)
   - **SHA-256:** Current standard for most applications (recommended)
   - **SHA-512:** For enhanced security requirements

3. **Key Observations:**
   - Same input always produces identical hash (deterministic)
   - Different algorithms produce different hash values for same input
   - Longer hash outputs (SHA-512) provide stronger collision resistance
   - Fixed output sizes regardless of input length
   - Avalanche effect ensures similar inputs produce completely different hashes

4. **Real-World Applications:**
   - **Password storage:** Store SHA-256 hash of passwords
   - **Digital signatures:** Sign hash of documents instead of full document
   - **Data integrity:** Verify files via hash comparison
   - **Blockchain:** Bitcoin uses SHA-256; Ethereum uses Keccak-256
   - **SSL/TLS certificates:** Use SHA-256 for signing

5. **Recommendations:**
   - Use SHA-256 or SHA-512 for new applications
   - Avoid MD5 and SHA-1 for security purposes
   - Combine with salt for password hashing for additional security
   - Use iterative hashing (bcrypt, PBKDF2) for password storage

---

**Laboratory Date:** April 2026  
**Subject:** Cryptography  
**Semester:** 5
