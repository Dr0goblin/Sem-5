import hashlib

def md5_hash(message):
    """Generate MD5 hash of a message"""
    md5_obj = hashlib.md5()
    md5_obj.update(message.encode())
    return md5_obj.hexdigest()

if __name__ == "__main__":
    print("Lab 9a: MD5 Hash Generation\n")
    
    test_messages = [
        "Hello World",
        "Cryptography",
        "Lab 9",
        "12345",
        "The quick brown fox jumps over the lazy dog"
    ]
    
    for message in test_messages:
        hash_value = md5_hash(message)
        print(f"Message: {message}")
        print(f"MD5 Hash: {hash_value}\n")
