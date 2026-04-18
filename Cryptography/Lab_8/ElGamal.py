import random

def power_mod(base, exp, mod):
    """Compute (base^exp) % mod efficiently"""
    result = 1
    base = base % mod
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        exp = exp >> 1
        base = (base * base) % mod
    return result

def extended_gcd(a, b):
    """Extended Euclidean Algorithm"""
    if b == 0:
        return a, 1, 0
    g, x1, y1 = extended_gcd(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return g, x, y

def mod_inverse(a, m):
    """Compute modular multiplicative inverse of a mod m"""
    g, x, _ = extended_gcd(a, m)
    if g != 1:
        return None
    return (x % m + m) % m

def elgamal_keygen(p, g):
    """Generate ElGamal public and private keys"""
    x = random.randint(2, p - 2)  # Private key
    y = power_mod(g, x, p)  # Public key
    return (p, g, y), x

def elgamal_encrypt(message, public_key):
    """Encrypt message using ElGamal"""
    p, g, y = public_key
    k = random.randint(2, p - 2)
    c1 = power_mod(g, k, p)
    s = power_mod(y, k, p)
    c2 = (message * s) % p
    return c1, c2

def elgamal_decrypt(ciphertext, private_key, p):
    """Decrypt ciphertext using ElGamal"""
    c1, c2 = ciphertext
    s = power_mod(c1, private_key, p)
    s_inv = mod_inverse(s, p)
    plaintext = (c2 * s_inv) % p
    return plaintext

if __name__ == "__main__":
    print("Lab 8c: ElGamal Cryptographic System\n")
    
    # Public parameters
    p = 23
    g = 5
    
    print(f"Public Parameters:")
    print(f"Prime (p) = {p}")
    print(f"Generator (g) = {g}\n")
    
    # Generate keys
    public_key, private_key = elgamal_keygen(p, g)
    _, _, y = public_key
    
    print(f"Key Generation:")
    print(f"Private Key (x) = {private_key}")
    print(f"Public Key: (p={p}, g={g}, y={y})\n")
    
    # Message to encrypt
    plaintext = 7
    
    print(f"Plaintext Message (m) = {plaintext}")
    
    # Encryption
    c1, c2 = elgamal_encrypt(plaintext, public_key)
    print(f"Ciphertext: (c1, c2) = ({c1}, {c2})")
    print(f"  c1 = g^k mod p = {g}^k mod {p}")
    print(f"  c2 = m * y^k mod p")
    
    # Decryption
    decrypted = elgamal_decrypt((c1, c2), private_key, p)
    print(f"\nDecryption:")
    print(f"Decrypted Message = {decrypted}\n")
    
    print(f"Verification: {plaintext} == {decrypted} ? {plaintext == decrypted}")
