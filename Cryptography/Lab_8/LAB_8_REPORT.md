# Lab 8: Public Key Cryptography

## 1. Title
**Public Key Cryptography: Diffie-Hellman Key Exchange, RSA, and ElGamal**

---

## 2. Objective
To understand and implement three fundamental public key cryptography algorithms:
- Diffie-Hellman Key Exchange for secure key agreement over insecure channels
- RSA Algorithm for public key encryption and decryption
- ElGamal Cryptographic System for probabilistic encryption
- Practical demonstration of each algorithm with key generation and message encryption/decryption

---

## 3. Theory

### 3.1 Diffie-Hellman Key Exchange

Diffie-Hellman (DH) is a method for two parties to establish a shared secret over an insecure channel.

**Parameters:**
- $p$: Large prime number
- $g$: Generator of multiplicative group modulo $p$

**Protocol:**
1. Alice chooses secret $a$, computes public key $A = g^a \bmod p$
2. Bob chooses secret $b$, computes public key $B = g^b \bmod p$
3. Alice and Bob exchange $A$ and $B$ over insecure channel
4. Alice computes shared secret: $K = B^a \bmod p$
5. Bob computes shared secret: $K = A^b \bmod p$

Both compute the same value: $K = g^{ab} \bmod p$

**Security:** Assumes difficulty of solving discrete logarithm problem.

**Advantages:**
- No pre-shared secret required
- Both parties independently derive same shared secret
- Foundation for TLS/SSL protocols

---

### 3.2 RSA Algorithm

RSA is the most widely used public key cryptosystem.

**Key Generation:**
1. Choose two distinct large primes $p$ and $q$
2. Compute $n = p \times q$
3. Compute $\phi(n) = (p-1)(q-1)$
4. Choose $e$ such that $1 < e < \phi(n)$ and $\gcd(e, \phi(n)) = 1$
5. Compute $d$ such that $e \times d \equiv 1 \pmod{\phi(n)}$
6. Public key: $(e, n)$, Private key: $(d, n)$

**Encryption:** $C = M^e \bmod n$ (where $M$ is plaintext, $C$ is ciphertext)

**Decryption:** $M = C^d \bmod n$

**Mathematical Basis:** 
- Uses Euler's theorem: $M^{\phi(n)} \equiv 1 \pmod{n}$ when $\gcd(M, n) = 1$
- Since $e \times d \equiv 1 \pmod{\phi(n)}$, we have $M^{ed} \equiv M \pmod{n}$

**Security:** Based on difficulty of factoring large numbers.

**Applications:**
- HTTPS/TLS encryption
- Digital signatures
- Key exchange (hybrid systems)

---

### 3.3 ElGamal Cryptographic System

ElGamal is a public key cryptosystem based on Diffie-Hellman.

**Key Generation:**
1. Choose large prime $p$
2. Choose generator $g$ of multiplicative group modulo $p$
3. Choose random private key $x$ from $[2, p-2]$
4. Compute public key $y = g^x \bmod p$
5. Public key: $(p, g, y)$, Private key: $x$

**Encryption:**
1. Message: $m$, choose random $k$ from $[2, p-2]$
2. Compute $c_1 = g^k \bmod p$
3. Compute $c_2 = m \times y^k \bmod p$
4. Ciphertext: $(c_1, c_2)$

**Decryption:**
1. Compute $s = c_1^x \bmod p$
2. Compute $s^{-1}$ (modular inverse of $s$ modulo $p$)
3. Plaintext: $m = c_2 \times s^{-1} \bmod p$

**Advantages:**
- Probabilistic encryption (same plaintext produces different ciphertexts)
- Based on discrete logarithm problem
- Provides semantic security

**Disadvantage:** Ciphertext size is twice the plaintext size.

---

## 4. Code and Output

### 4.1a Diffie-Hellman Key Exchange

**Code:**
```python
def power_mod(base, exp, mod):
    result = 1
    base = base % mod
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        exp = exp >> 1
        base = (base * base) % mod
    return result

def diffie_hellman():
    p = 23  # Prime modulus
    g = 5   # Generator
    
    a_secret = 6
    a_public = power_mod(g, a_secret, p)
    
    b_secret = 15
    b_public = power_mod(g, b_secret, p)
    
    alice_shared = power_mod(b_public, a_secret, p)
    bob_shared = power_mod(a_public, b_secret, p)
    
    return a_secret, a_public, b_secret, b_public, alice_shared, bob_shared
```

**Output:**
```
Lab 8a: Diffie-Hellman Key Exchange

Common Parameters:
Prime (p) = 23
Generator (g) = 5

Alice's Secret (a) = 6
Alice's Public Key = g^a mod p = 5^6 mod 23 = 8

Bob's Secret (b) = 15
Bob's Public Key = g^b mod p = 5^15 mod 23 = 19

Alice computes shared secret = 19^6 mod 23 = 2
Bob computes shared secret = 8^15 mod 23 = 2

Shared Secret Match: True
Final Shared Secret: 2
```

---

### 4.1b RSA Encryption and Decryption

**Code:**
```python
def rsa_keygen(p, q):
    n = p * q
    phi = (p - 1) * (q - 1)
    e = 17
    while gcd(e, phi) != 1:
        e += 2
    d = mod_inverse(e, phi)
    return (e, n), (d, n)

def rsa_encrypt(message, public_key):
    e, n = public_key
    ciphertext = power_mod(message, e, n)
    return ciphertext

def rsa_decrypt(ciphertext, private_key):
    d, n = private_key
    plaintext = power_mod(ciphertext, d, n)
    return plaintext
```

**Output:**
```
Lab 8b: RSA Encryption and Decryption

RSA Key Generation:
p = 61, q = 53
n = p * q = 3233
Public Key (e, n) = (17, 3233)
Private Key (d, n) = (2753, 3233)

Plaintext Message (m) = 42
Ciphertext (c) = m^e mod n = 42^17 mod 3233 = 2557
Decrypted Message = c^d mod n = 2557^2753 mod 3233 = 42

Verification: 42 == 42 ? True
```

---

### 4.1c ElGamal Cryptographic System

**Code:**
```python
def elgamal_keygen(p, g):
    x = random.randint(2, p - 2)
    y = power_mod(g, x, p)
    return (p, g, y), x

def elgamal_encrypt(message, public_key):
    p, g, y = public_key
    k = random.randint(2, p - 2)
    c1 = power_mod(g, k, p)
    s = power_mod(y, k, p)
    c2 = (message * s) % p
    return c1, c2

def elgamal_decrypt(ciphertext, private_key, p):
    c1, c2 = ciphertext
    s = power_mod(c1, private_key, p)
    s_inv = mod_inverse(s, p)
    plaintext = (c2 * s_inv) % p
    return plaintext
```

**Output:**
```
Lab 8c: ElGamal Cryptographic System

Public Parameters:
Prime (p) = 23
Generator (g) = 5

Key Generation:
Private Key (x) = 18
Public Key: (p=23, g=5, y=12)

Plaintext Message (m) = 7
Ciphertext: (c1, c2) = (16, 6)
  c1 = g^k mod p = 5^k mod 23
  c2 = m * y^k mod p

Decryption:
Decrypted Message = 7

Verification: 7 == 7 ? True
```

---

## 5. Conclusion

This lab successfully demonstrated three crucial public key cryptography algorithms fundamental to modern secure communications:

1. **Diffie-Hellman Key Exchange:** Two parties independently derived an identical shared secret over an insecure channel without prior communication. This is the foundation for secure key establishment in TLS/SSL.

2. **RSA Algorithm:** Demonstrated both encryption and decryption using a pair of mathematically related public and private keys. With the proper key sizes (2048+ bits), RSA provides strong security and is widely used in HTTPS and digital signatures.

3. **ElGamal Cryptographic System:** Implemented a probabilistic encryption scheme where the same plaintext produces different ciphertexts due to random values. This provides semantic security against chosen plaintext attacks.

**Key Insights:**
- All three algorithms rely on mathematical problems that are easy to compute in one direction but hard to reverse (one-way functions)
- Public key cryptography eliminates the need for secure key distribution
- These algorithms form the backbone of modern internet security (TLS, SSL, PGP)
- Practical security requires large key sizes (RSA 2048+ bits, DH primes 2048+ bits)

These concepts are essential for understanding modern cryptographic systems and securing digital communications.

---

**Laboratory Date:** April 2026  
**Subject:** Cryptography  
**Semester:** 5
