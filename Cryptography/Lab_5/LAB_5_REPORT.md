# Lab 5: Modular Arithmetic

## 1. Title
**Modular Arithmetic: Additive Inverse, Multiplicative Inverse, and Relatively Prime Numbers**

---

## 2. Objective
To understand and implement fundamental concepts in modular arithmetic including:
- Computing the additive inverse of a number in modular arithmetic
- Computing the multiplicative inverse using the Extended Euclidean Algorithm
- Identifying and verifying relatively prime numbers (coprime numbers)
- Verifying the properties of these mathematical operations

---

## 3. Theory

### 3.1 Modular Arithmetic
Modular arithmetic is arithmetic on integers where numbers "wrap around" after reaching a modulus $n$. For integers $a$ and $b$:
- $a \equiv b \pmod{n}$ means $(a - b)$ is divisible by $n$
- The remainder when $a$ is divided by $n$ is $a \bmod n$

---

### 3.2 Additive Inverse
The additive inverse of $a$ modulo $n$ is a number $x$ such that:
$$a + x \equiv 0 \pmod{n}$$

**Formula:** $x = (-a) \bmod n$

**Example:** Additive inverse of $7$ modulo $11$ is $(-7) \bmod 11 = 4$  
Verification: $(7 + 4) \bmod 11 = 0$ ✓

---

### 3.3 Multiplicative Inverse (Extended Euclidean Algorithm)
The multiplicative inverse of $a$ modulo $n$ is a number $x$ such that:
$$a \cdot x \equiv 1 \pmod{n}$$

**Exists if and only if:** $\gcd(a, n) = 1$

**Extended Euclidean Algorithm:** Finds $x$ and $y$ where $ax + ny = \gcd(a, n)$. If $\gcd(a, n) = 1$, then $ax \equiv 1 \pmod{n}$, so $x$ is the multiplicative inverse.

**Example:** Multiplicative inverse of $3$ modulo $11$ is $4$  
Verification: $(3 \times 4) \bmod 11 = 1$ ✓

---

### 3.4 Relatively Prime (Coprime)
Two integers $a$ and $b$ are relatively prime if:
$$\gcd(a, b) = 1$$

**Property:** If $a$ and $b$ are relatively prime, then $a$ has a multiplicative inverse modulo $b$.

**Examples:**
- $\gcd(12, 35) = 1$ → Relatively prime ✓
- $\gcd(15, 25) = 5 \neq 1$ → Not relatively prime ✗

---

## 4. Code and Output

### 4.1 Python Code

```python
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
```

### 4.2 Program Output

```
Lab 5: Modular Arithmetic

--- Additive Inverse ---
Additive Inverse of 7 mod 11 = 4
Verification: (7 + 4) mod 11 = 0

--- Multiplicative Inverse ---
Multiplicative Inverse of 3 mod 11 = 4
Verification: (3 * 4) mod 11 = 1

--- Relatively Prime ---
GCD(12, 35) = 1 → 12, 35 are relatively prime
GCD(15, 25) = 5 → 15, 25 are not relatively prime
```

---

## 5. Conclusion

This lab successfully demonstrated key concepts of modular arithmetic:

1. **Additive Inverse:** Using the formula $x = (-a) \bmod n$, we found that adding the additive inverse to a number results in 0 modulo $n$.

2. **Multiplicative Inverse:** The Extended Euclidean Algorithm efficiently computes the multiplicative inverse when $\gcd(a, n) = 1$.

3. **Relatively Prime Numbers:** Two numbers are relatively prime if their GCD is 1, which is necessary for the multiplicative inverse to exist.

These concepts are fundamental to cryptographic algorithms like RSA and ElGamal, where modular arithmetic and inverses are essential for encryption and decryption operations.

---

**Laboratory Date:** April 2026  
**Subject:** Cryptography  
**Semester:** 5
