# Lab 7: Number Theory and Primality Testing

## 1. Title
**Primality Testing using Miller-Rabin, Euler's Totient Function, and Primitive Roots**

---

## 2. Objective
To understand and implement key concepts in number theory used in cryptography:
- Primality testing using Miller-Rabin algorithm for efficient prime detection
- Computing Euler's totient function φ(n) to count coprime numbers
- Finding and verifying primitive roots modulo n
- Practical applications in cryptographic key generation

---

## 3. Theory

### 3.1 Primality Testing using Miller-Rabin Algorithm

The Miller-Rabin test is a probabilistic algorithm for testing whether a number is prime.

**Concept:**
- For a prime number $n$, write $n - 1 = 2^r \cdot d$ where $d$ is odd
- For any witness $a$: either $a^d \equiv 1 \pmod{n}$ or $a^{2^i \cdot d} \equiv -1 \pmod{n}$ for some $0 \le i < r$

**Algorithm:**
1. Find $r$ and $d$ such that $n - 1 = 2^r \cdot d$
2. Repeat $k$ times:
   - Pick random $a$ in range $[2, n-2]$
   - Compute $x = a^d \bmod n$
   - If $x = 1$ or $x = n-1$, continue to next iteration
   - For $i$ from 0 to $r-2$, compute $x = x^2 \bmod n$
   - If $x = n-1$, continue; else return COMPOSITE
3. Return PROBABLY PRIME

**Properties:**
- Error probability reduces to $(1/4)^k$ with $k$ iterations
- Much faster than trial division for large numbers
- Deterministic variant exists for numbers up to $2^{64}$

---

### 3.2 Euler's Totient Function φ(n)

Euler's totient function counts the number of integers from 1 to $n$ that are coprime to $n$.

**Definition:** φ(n) = number of integers $k$ in $[1, n]$ where $\gcd(k, n) = 1$

**Formula:** For $n = p_1^{a_1} \cdot p_2^{a_2} \cdots p_k^{a_k}$:
$$\phi(n) = n \prod_{p \mid n} \left(1 - \frac{1}{p}\right)$$

**Properties:**
- For prime $p$: $\phi(p) = p - 1$
- For prime powers: $\phi(p^k) = p^{k-1}(p-1)$
- Multiplicative: if $\gcd(m, n) = 1$, then $\phi(mn) = \phi(m) \cdot \phi(n)$
- Euler's theorem: $a^{\phi(n)} \equiv 1 \pmod{n}$ if $\gcd(a, n) = 1$

**Examples:**
- φ(6) = 2 (numbers: 1, 5)
- φ(12) = 4 (numbers: 1, 5, 7, 11)
- φ(30) = 8 (numbers: 1, 7, 11, 13, 17, 19, 23, 29)

---

### 3.3 Primitive Roots

A primitive root modulo $n$ is a number $g$ whose powers generate all numbers coprime to $n$.

**Definition:** $g$ is a primitive root modulo $n$ if the multiplicative order of $g$ modulo $n$ is φ(n).

**Condition for Existence:** 
Primitive roots exist modulo $n$ if and only if $n$ is 1, 2, 4, $p^k$, or $2p^k$ where $p$ is an odd prime.

**Property:** If $g$ is a primitive root modulo $n$, then $\{g^0, g^1, g^2, \ldots, g^{\phi(n)-1}\}$ modulo $n$ is a permutation of all integers coprime to $n$.

**Testing:** $g$ is a primitive root modulo $n$ if:
- $g^{\phi(n)} \equiv 1 \pmod{n}$
- $g^{\phi(n)/p} \not\equiv 1 \pmod{n}$ for all prime factors $p$ of φ(n)

**Example:** For $n = 7$, φ(7) = 6
- 3 is a primitive root because: $3^1 \equiv 3$, $3^2 \equiv 2$, $3^3 \equiv 6 \equiv -1$, $3^4 \equiv 4$, $3^5 \equiv 5$, $3^6 \equiv 1 \pmod{7}$
- All residues coprime to 7 are generated

---

## 4. Code and Output

### 4.1a Miller-Rabin Primality Testing

**Code:**
```python
import random

def power_mod(base, exp, mod):
    result = 1
    base = base % mod
    while exp > 0:
        if exp % 2 == 1:
            result = (result * base) % mod
        exp = exp >> 1
        base = (base * base) % mod
    return result

def miller_rabin(n, k=5):
    if n < 2:
        return False
    if n == 2 or n == 3:
        return True
    if n % 2 == 0:
        return False
    
    r = 0
    d = n - 1
    while d % 2 == 0:
        r += 1
        d //= 2
    
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
```

**Output:**
```
Lab 7a: Miller-Rabin Primality Testing

17: Prime
19: Prime
25: Not Prime
97: Prime
100: Not Prime
541: Prime
1000: Not Prime
```

---

### 4.1b Euler's Totient Function

**Code:**
```python
def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

def euler_totient(n):
    result = 0
    for i in range(1, n + 1):
        if gcd(i, n) == 1:
            result += 1
    return result

def euler_totient_formula(n):
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
```

**Output:**
```
Lab 7b: Euler's Totient Function

n = 6: Totient = 2, Coprime = [1, 5]
n = 12: Totient = 4, Coprime = [1, 5, 7, 11]
n = 20: Totient = 8, Coprime = [1, 3, 7, 9, 11, 13, 17, 19]
n = 30: Totient = 8, Coprime = [1, 7, 11, 13, 17, 19, 23, 29]
n = 37: Totient = 36, Coprime = [1, 2, 3, ..., 36]
n = 100: Totient = 40, Coprime = [1, 3, 7, 9, 11, ..., 99]
```

---

### 4.1c Primitive Roots

**Code:**
```python
def is_primitive_root(g, n):
    phi = euler_totient(n)
    
    if pow(g, phi, n) != 1:
        return False
    
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
    
    for prime in factors:
        if pow(g, phi // prime, n) == 1:
            return False
    
    return True

def find_primitive_roots(n):
    phi = euler_totient(n)
    roots = []
    
    for g in range(1, n):
        if gcd(g, n) == 1 and is_primitive_root(g, n):
            roots.append(g)
    
    return roots
```

**Output:**
```
Lab 7c: Primitive Root Illustration

n = 5, Totient = 4
Primitive roots: [2, 3]

n = 7, Totient = 6
Primitive roots: [3, 5]

n = 11, Totient = 10
Primitive roots: [2, 6, 7, 8]

n = 13, Totient = 12
Primitive roots: [2, 6, 7, 11]
```

---

## 5. Conclusion

This lab successfully demonstrated three crucial concepts in cryptographic number theory:

1. **Miller-Rabin Primality Testing:** Implemented a probabilistic algorithm that efficiently determines if a number is prime with controllable error probability. This is fundamental for generating cryptographic keys (RSA, DSA).

2. **Euler's Totient Function:** Computed φ(n) to count integers coprime to n. This function is essential in RSA encryption, where φ(pq) is used to compute the private key.

3. **Primitive Roots:** Identified and verified primitive roots modulo n, which generate all coprime residues. Primitive roots are used in Diffie-Hellman key exchange and other cryptographic protocols.

These concepts together form the mathematical foundation of modern cryptography. Miller-Rabin enables fast prime generation, totient function is crucial for RSA, and primitive roots enable secure key exchange protocols.

---

**Laboratory Date:** April 2026  
**Subject:** Cryptography  
**Semester:** 5
