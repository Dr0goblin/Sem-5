def gcd(a, b):
    """Compute GCD of a and b"""
    while b:
        a, b = b, a % b
    return a

def euler_totient(n):
    """Compute Euler's totient function φ(n)"""
    result = n
    p = 2
    temp_n = n
    
    while p * p <= temp_n:
        if temp_n % p == 0:
            while temp_n % p == 0:
                temp_n //= p
            result -= result // p
        p += 1
    
    if temp_n > 1:
        result -= result // temp_n
    
    return result

def is_primitive_root(g, n):
    """Check if g is a primitive root modulo n"""
    phi = euler_totient(n)
    
    # g^φ(n) ≡ 1 (mod n)
    if pow(g, phi, n) != 1:
        return False
    
    # Check that no smaller exponent works
    p = 2
    temp_phi = phi
    factors = []
    
    while p * p <= temp_phi:
        if temp_phi % p == 0:
            factors.append(p)
            while temp_phi % p == 0:
                temp_phi //= p
        p += 1
    
    if temp_phi > 1:
        factors.append(temp_phi)
    
    # Check g^(φ(n)/p) ≠ 1 (mod n) for all prime factors p of φ(n)
    for prime in factors:
        if pow(g, phi // prime, n) == 1:
            return False
    
    return True

def find_primitive_roots(n):
    """Find all primitive roots modulo n"""
    phi = euler_totient(n)
    roots = []
    
    for g in range(1, n):
        if gcd(g, n) == 1 and is_primitive_root(g, n):
            roots.append(g)
    
    return roots

if __name__ == "__main__":
    print("Lab 7c: Primitive Root Illustration\n")
    
    test_primes = [5, 7, 11, 13]
    
    for p in test_primes:
        phi = euler_totient(p)
        roots = find_primitive_roots(p)
        print(f"n = {p}, Totient = {phi}")
        print(f"Primitive roots: {roots}\n")
