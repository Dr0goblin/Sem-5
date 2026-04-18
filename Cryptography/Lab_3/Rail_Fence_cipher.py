# LAB-3: RAIL FENCE CIPHER - COMPLETE IMPLEMENTATION

print("=" * 40)
print("RAIL FENCE CIPHER")
print("=" * 40)

class RailFenceCipher:
    """Rail Fence Cipher implementation"""
    
    def __init__(self, message, rails):
        self.message = message
        self.rails = rails
        self.clean_message = message.replace(" ", "")
    
    def encrypt(self):
        """Encrypt using Rail Fence"""
        fence = [''] * self.rails
        rail = 0
        direction = 1
        
        for char in self.clean_message:
            fence[rail] += char
            rail += direction
            if rail == 0 or rail == self.rails - 1:
                direction = -direction
        
        return ''.join(fence)
    
    def decrypt(self, ciphertext):
        """Decrypt using Rail Fence"""
        # Create pattern
        pattern = []
        rail = 0
        direction = 1
        
        for i in range(len(ciphertext)):
            pattern.append(rail)
            rail += direction
            if rail == 0 or rail == self.rails - 1:
                direction = -direction
        
        # Split ciphertext
        counts = [pattern.count(i) for i in range(self.rails)]
        fence = []
        pos = 0
        for count in counts:
            fence.append(list(ciphertext[pos:pos+count]))
            pos += count
        
        # Read in order
        result = ''
        rail = 0
        direction = 1
        for i in range(len(ciphertext)):
            result += fence[rail].pop(0)
            rail += direction
            if rail == 0 or rail == self.rails - 1:
                direction = -direction
        
        return result
    
    def show_pattern(self):
        """Visualize the rail fence pattern"""
        fence = [['.' for _ in range(len(self.clean_message))] 
                 for _ in range(self.rails)]
        
        rail = 0
        direction = 1
        
        for col, char in enumerate(self.clean_message):
            fence[rail][col] = char
            rail += direction
            if rail == 0 or rail == self.rails - 1:
                direction = -direction
        
        print("\nRail Fence Pattern:")
        for i in range(self.rails):
            print(f"   Rail {i+1}: ", end="")
            for j in range(len(self.clean_message)):
                print(fence[i][j], end=" ")
            print()

my_message = "Data Encryption Standard"
my_rails = 4  # Key

print(f"Original Message: {my_message}")
print(f"Key (Rails): {my_rails}")

# Create cipher object
cipher = RailFenceCipher(my_message, my_rails)

# Show pattern
cipher.show_pattern()

# Encrypt
encrypted = cipher.encrypt()
print(f"\nEncrypted: {encrypted}")

# Decrypt
decrypted = cipher.decrypt(encrypted)
print(f"Decrypted: {decrypted}")

# Verify
original_clean = my_message.replace(" ", "")
print(f"\nVerification: {'PASSED' if original_clean == decrypted else 'FAILED'}")
print(f"Original (no spaces): {original_clean}")
print(f"Decrypted: {decrypted}")