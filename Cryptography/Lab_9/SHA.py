import hashlib

def sha1_hash(message):
    """Generate SHA-1 hash of a message"""
    sha1_obj = hashlib.sha1()
    sha1_obj.update(message.encode())
    return sha1_obj.hexdigest()

def sha256_hash(message):
    """Generate SHA-256 hash of a message"""
    sha256_obj = hashlib.sha256()
    sha256_obj.update(message.encode())
    return sha256_obj.hexdigest()

def sha512_hash(message):
    """Generate SHA-512 hash of a message"""
    sha512_obj = hashlib.sha512()
    sha512_obj.update(message.encode())
    return sha512_obj.hexdigest()

if __name__ == "__main__":
    print("Lab 9b: SHA Hash Generation\n")
    
    test_messages = [
        "Hello World",
        "Cryptography",
        "Lab 9",
        "12345"
    ]
    
    for message in test_messages:
        sha1 = sha1_hash(message)
        sha256 = sha256_hash(message)
        sha512 = sha512_hash(message)
        
        print(f"Message: {message}")
        print(f"SHA-1   ({len(sha1)//2} bytes): {sha1}")
        print(f"SHA-256 ({len(sha256)//2} bytes): {sha256}")
        print(f"SHA-512 ({len(sha512)//2} bytes): {sha512}\n")
