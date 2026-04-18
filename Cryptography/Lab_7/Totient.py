import math

def gcd(a, b):
    """Compute GCD of a and b"""
    while b:
        a, b = b, a % b
    return a

def euler_totient(n):
    """Compute Euler's totient function φ(n)"""
    result = 0
    for i in range(1, n + 1):
        if gcd(i, n) == 1:
            result += 1
    return result

def euler_totient_formula(n):
    """Compute φ(n) using formula: φ(n) = n * ∏(1 - 1/p) for all prime factors p"""
    result = n
    p = 2
    
    while p * p <= n:
        if n % p == 0:
            while n % p == 0:
                n //= p
            result -= result // p
        p += 1
    
    if n > 1:
        result -= result // n
    
    return result

if __name__ == "__main__":
    print("Lab 7b: Euler's Totient Function\n")
    
    test_numbers = [6, 12, 20, 30, 37, 100]
    
    for num in test_numbers:
        count = euler_totient(num)
        formula = euler_totient_formula(num)
        coprimes = [i for i in range(1, num) if gcd(i, num) == 1]
        print(f"n = {num}: Totient = {count}, Coprime = {coprimes}")
