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

def miller_rabin(n, k=5):
    """Test if n is prime using Miller-Rabin algorithm"""
    if n < 2:
        return False
    if n == 2 or n == 3:
        return True
    if n % 2 == 0:
        return False
    
    # Write n-1 as d * 2^r
    r = 0
    d = n - 1
    while d % 2 == 0:
        r += 1
        d //= 2
    
    # Witness loop
    for _ in range(k):
        a = random.randint(2, n - 2)
        x = power_mod(a, d, n)
        
        if x == 1 or x == n - 1:
            continue
        
        composite = True
        for _ in range(r - 1):
            x = power_mod(x, 2, n)
            if x == n - 1:
                composite = False
                break
        
        if composite:
            return False
    
    return True

if __name__ == "__main__":
    print("Lab 7a: Miller-Rabin Primality Testing\n")
    
    test_numbers = [17, 19, 25, 97, 100, 541, 1000]
    
    for num in test_numbers:
        result = miller_rabin(num)
        print(f"{num}: {'Prime' if result else 'Not Prime'}")
