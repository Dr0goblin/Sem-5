def gcd(a, b):
    while b != 0:
        a, b = b, a % b
    return a

def extended_euclid(a, b):
    if b == 0:
        return a, 1, 0
    g, x1, y1 = extended_euclid(b, a % b)
    return g, y1, x1 - (a // b) * y1

def additive_inverse(a, n):
    return (-a) % n

def multiplicative_inverse(a, n):
    g, x, _ = extended_euclid(a, n)
    return x % n if g == 1 else None

def are_relatively_prime(a, b):
    return gcd(a, b) == 1

if __name__ == "__main__":
    print("Lab 5: Modular Arithmetic\n")
    
    print("--- Additive Inverse ---")
    a, n = 7, 11
    result = additive_inverse(a, n)
    print(f"Additive Inverse of {a} mod {n} = {result}")
    print(f"Verification: ({a} + {result}) mod {n} = {(a + result) % n}\n")
    
    print("--- Multiplicative Inverse ---")
    a, n = 3, 11
    result = multiplicative_inverse(a, n)
    print(f"Multiplicative Inverse of {a} mod {n} = {result}")
    print(f"Verification: ({a} * {result}) mod {n} = {(a * result) % n}\n")
    
    print("--- Relatively Prime ---")
    x, y = 12, 35
    print(f"GCD({x}, {y}) = {gcd(x, y)} → {x}, {y} are {'relatively prime' if are_relatively_prime(x, y) else 'not relatively prime'}")
    x, y = 15, 25
    print(f"GCD({x}, {y}) = {gcd(x, y)} → {x}, {y} are {'relatively prime' if are_relatively_prime(x, y) else 'not relatively prime'}")
