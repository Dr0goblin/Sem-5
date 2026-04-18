KEY = [
    1,0,1,0,0,0,0,0,
    1,0,1,0,0,0,0,0, 
    1,0,1,0,0,0,0,0,
    1,0,1,0,0,0,0,0,
    1,0,1,0,0,0,0,0,
    1,0,1,0,0,0,0,0,
    1,0,1,0,0,0,0,0,
    1,0,1,0,0,0,0,0
]

PC1 = [
    57,49,41,33,25,17,9,1,58,50,42,34,26,18,
    10,2,59,51,43,35,27,19,11,3,60,52,44,36,
    63,55,47,39,31,23,15,7,62,54,46,38,30,22,
    14,6,61,53,45,37,29,21,13,5,28,20,12,4
]

PC2 = [
    14,17,11,24,1,5,3,28,15,6,21,10,
    23,19,12,4,26,8,16,7,27,20,13,2,
    41,52,31,37,47,55,30,40,51,45,33,48,
    44,49,39,56,34,53,46,42,50,36,29,32
]

EXPANSION = [
    32,1,2,3,4,5,4,5,6,7,8,9,
    8,9,10,11,12,13,12,13,14,15,16,17,
    16,17,18,19,20,21,20,21,22,23,24,25,
    24,25,26,27,28,29,28,29,30,31,32,1
]

SHIFTS = [1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1]

S_BOX = [
    [14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7],
    [0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8],
    [4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0],
    [15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13]
]

def permute(data, table):
    return [data[i-1] for i in table]

def left_shift(bits, n):
    return bits[n:] + bits[:n]

def generate_round_keys(key):
    key = permute(key, PC1)
    C, D = key[:28], key[28:]
    keys = []
    for s in SHIFTS:
        C = left_shift(C, s)
        D = left_shift(D, s)
        keys.append(permute(C + D, PC2))
    return keys

def sbox(block):
    row = int(f"{block[0]}{block[5]}", 2)
    col = int("".join(map(str, block[1:5])), 2)
    return [int(b) for b in format(S_BOX[row][col], '04b')]

def feistel(R, K):
    expanded = permute(R, EXPANSION)
    xor = [expanded[i] ^ K[i] for i in range(48)]
    out = []
    for i in range(0, 48, 6):
        out.extend(sbox(xor[i:i+6]))
    return out

def des_process(block, keys):
    L, R = block[:32], block[32:]
    for i in range(16):
        temp = feistel(R, keys[i])
        newR = [temp[j] ^ L[j] for j in range(32)]
        L, R = R, newR
    return R + L

def text_to_bits(text):
    bits = ''.join(format(ord(c), '08b') for c in text)
    bits = bits.ljust(64, '0')
    return [int(b) for b in bits[:64]]

def bits_to_text(bits):
    chars = [bits[i:i+8] for i in range(0, 64, 8)]
    return ''.join(chr(int(''.join(map(str,c)),2)) for c in chars)

message = "HELLO"
block = text_to_bits(message)

round_keys = generate_round_keys(KEY)

cipher = des_process(block, round_keys)
plain = des_process(cipher, round_keys[::-1])

print("Message :", message)
print("Encrypted:", ''.join(map(str, cipher)))
print("Decrypted:", bits_to_text(plain)) 
