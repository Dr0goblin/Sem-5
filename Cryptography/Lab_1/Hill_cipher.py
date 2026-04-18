# HILL CIPHER (Pure Python)

def text_to_numbers(text):
    """Convert text to numbers (A=0, B=1, ..., Z=25)"""
    return [ord(c) - 65 for c in text.upper() if c.isalpha()]

def numbers_to_text(nums):
    """Convert numbers back to text"""
    return ''.join([chr(n + 65) for n in nums])

def matrix_multiply(matrix, vector, mod=26):
    """Multiply 2x2 matrix by 2-element vector"""
    return [
        (matrix[0][0] * vector[0] + matrix[0][1] * vector[1]) % mod,
        (matrix[1][0] * vector[0] + matrix[1][1] * vector[1]) % mod
    ] 


def determinant(matrix):
    """Calculate determinant of 2x2 matrix"""
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]

def mod_inverse(a, m=26):
    """Find modular inverse of a modulo m"""
    a = a % m
    for x in range(1, m):
        if (a * x) % m == 1:
            return x
    return None

def inverse_matrix(matrix, mod=26):
    """Calculate inverse of 2x2 matrix modulo 26"""
    det = determinant(matrix)
    det_inv = mod_inverse(det, mod)
    
    if det_inv is None:
        raise ValueError("Matrix is not invertible modulo 26")
    
    # For 2x2 matrix: [a b; c d] inverse = (det_inv) * [d -b; -c a]
    return [
        [(matrix[1][1] * det_inv) % mod, (-matrix[0][1] * det_inv) % mod],
        [(-matrix[1][0] * det_inv) % mod, (matrix[0][0] * det_inv) % mod]
    ]

def encrypt(message, key):
    """Encrypt using Hill cipher"""
    nums = text_to_numbers(message)
    
    # Pad if odd length
    if len(nums) % 2 != 0:
        nums.append(0)  # Pad with 'A'
    
    result = []
    for i in range(0, len(nums), 2):
        block = nums[i:i+2]
        encrypted = matrix_multiply(key, block)
        result.extend(encrypted)
    
    return numbers_to_text(result)

def decrypt(cipher, key):
    """Decrypt using Hill cipher"""
    key_inv = inverse_matrix(key)
    nums = text_to_numbers(cipher)
    
    result = []
    for i in range(0, len(nums), 2):
        block = nums[i:i+2]
        decrypted = matrix_multiply(key_inv, block)
        result.extend(decrypted)
    
    return numbers_to_text(result)

# MY UNIQUE MESSAGE AND KEY
message = "HELLOWORLD"
key = [[3, 3], [2, 5]]  # 2x2 key matrix

print("=" * 50)
print("HILL CIPHER")
print("=" * 50)
print(f"Original Message: {message}")
print(f"Key Matrix: {key[0]}")
print(f"            {key[1]}")

# Encryption
encrypted = encrypt(message, key)
print(f"\nEncrypted: {encrypted}")

# Decryption
decrypted = decrypt(encrypted, key)
print(f"Decrypted: {decrypted}")

# Remove padding for verification
original_clean = message.upper().replace(" ", "")
decrypted_clean = decrypted.rstrip('A')  # Remove padding 'A's
print(f"\nVerification: {'✓ Success' if original_clean == decrypted_clean else '✗ Failed'}")