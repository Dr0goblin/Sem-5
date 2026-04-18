def gcd(a, b):
    """Compute GCD of a and b"""
    while b:
        a, b = b, a % b
    return a

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

def rsa_keygen(p, q):
    """Generate RSA public and private keys"""
    n = p * q
    phi = (p - 1) * (q - 1)
    
    # Choose e such that 1 < e < phi and gcd(e, phi) = 1
    e = 17
    while gcd(e, phi) != 1:
        e += 2
    
    # Compute d such that (e * d) % phi = 1
    d = mod_inverse(e, phi)
    
    return (e, n), (d, n)

def rsa_encrypt(message, public_key):
    """Encrypt message using RSA public key"""
    e, n = public_key
    ciphertext = power_mod(message, e, n)
    return ciphertext

def rsa_decrypt(ciphertext, private_key):
    """Decrypt ciphertext using RSA private key"""
    d, n = private_key
    plaintext = power_mod(ciphertext, d, n)
    return plaintext

if __name__ == "__main__":
    print("Lab 8b: RSA Encryption and Decryption\n")
    
    # Generate keys
    p, q = 61, 53
    public_key, private_key = rsa_keygen(p, q)
    e, n = public_key
    d, _ = private_key
    
    print(f"RSA Key Generation:")
    print(f"p = {p}, q = {q}")
    print(f"n = p * q = {n}")
    print(f"Public Key (e, n) = ({e}, {n})")
    print(f"Private Key (d, n) = ({d}, {n})\n")
    
    # Message to encrypt
    plaintext = 42
    
    print(f"Plaintext Message (m) = {plaintext}")
    
    # Encryption
    ciphertext = rsa_encrypt(plaintext, public_key)
    print(f"Ciphertext (c) = m^e mod n = {plaintext}^{e} mod {n} = {ciphertext}")
    
    # Decryption
    decrypted = rsa_decrypt(ciphertext, private_key)
    print(f"Decrypted Message = c^d mod n = {ciphertext}^{d} mod {n} = {decrypted}\n")
    
    print(f"Verification: {plaintext} == {decrypted} ? {plaintext == decrypted}")
