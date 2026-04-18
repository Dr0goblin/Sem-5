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

def diffie_hellman():
    """Demonstrate Diffie-Hellman Key Exchange"""
    print("Lab 8a: Diffie-Hellman Key Exchange\n")
    
    # Common parameters (p and g)
    p = 23  # Prime modulus
    g = 5   # Generator
    
    print(f"Common Parameters:")
    print(f"Prime (p) = {p}")
    print(f"Generator (g) = {g}\n")
    
    # Alice's secret and public key
    a_secret = 6
    a_public = power_mod(g, a_secret, p)
    
    # Bob's secret and public key
    b_secret = 15
    b_public = power_mod(g, b_secret, p)
    
    print(f"Alice's Secret (a) = {a_secret}")
    print(f"Alice's Public Key = g^a mod p = {g}^{a_secret} mod {p} = {a_public}")
    print(f"\nBob's Secret (b) = {b_secret}")
    print(f"Bob's Public Key = g^b mod p = {g}^{b_secret} mod {p} = {b_public}\n")
    
    # Compute shared secret
    alice_shared = power_mod(b_public, a_secret, p)
    bob_shared = power_mod(a_public, b_secret, p)
    
    print(f"Alice computes shared secret = {b_public}^{a_secret} mod {p} = {alice_shared}")
    print(f"Bob computes shared secret = {a_public}^{b_secret} mod {p} = {bob_shared}\n")
    
    print(f"Shared Secret Match: {alice_shared == bob_shared}")
    print(f"Final Shared Secret: {alice_shared}")

if __name__ == "__main__":
    diffie_hellman()
