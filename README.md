# Semester 5 - Academic Projects

This repository contains all the coursework, labs, and projects from Semester 5 across multiple subjects.

---

## 📚 Subjects

### 1. **Cryptography**
**Overview:** Study of encryption techniques, cipher systems, and secure communication methods.

This subject covers both classical and modern cryptographic algorithms, including:

#### Lab 1: Classical Ciphers
- **Caesar Cipher** (`Caesar_cipher.py`): Implementation of the Caesar cipher, a simple substitution cipher that shifts letters by a fixed number of positions. Demonstrates basic concepts of encryption and decryption.
- **Hill Cipher** (`Hill_cipher.py`): A polygraphic substitution cipher that uses matrix multiplication for encryption. Shows use of linear algebra in cryptography.

#### Lab 2: Advanced Classical Ciphers
- **Playfair Cipher** (`PlayfairCipher.py`): A digraphic substitution cipher using a 5x5 grid. Encrypts pairs of letters and demonstrates improved security over simple substitution ciphers.
- **Vigenère Cipher** (`VigenereCipher.py`): A polyalphabetic substitution cipher using a keyword. More secure than Caesar cipher as it uses multiple shift values.

#### Lab 3: Transposition Ciphers
- **Rail Fence Cipher** (`Rail_Fence_cipher.py`): A transposition cipher that rearranges plaintext by writing it in a zigzag pattern. Demonstrates a different encryption approach than substitution.

#### Lab 4: Block Ciphers
- **DES (Data Encryption Standard)** (`DES.py`): Implementation of DES symmetric encryption algorithm. Standard encryption method before AES, uses 64-bit blocks and 56-bit keys.

#### Lab 5: Number Theory Foundations
- **GCD (Greatest Common Divisor)** (`GCD.py`): Euclidean algorithm implementation, fundamental for cryptographic operations.

#### Lab 6: Advanced Symmetric Encryption
- **AES-CBC Mode** (`AES-CBC.py`): Advanced Encryption Standard in Cipher Block Chaining mode. Modern symmetric encryption standard, highly secure for protecting sensitive data.

#### Lab 7: Asymmetric Cryptography Foundations
- **Miller-Rabin Primality Test** (`MillerRabin.py`): Probabilistic algorithm for testing if a number is prime, essential for generating RSA keys.
- **Primitive Root** (`PrimitiveRoot.py`): Finding primitive roots modulo n, used in Diffie-Hellman key exchange.
- **Totient/Euler's Phi** (`Totient.py`): Computing Euler's totient function, critical for RSA encryption.

#### Lab 8: Public Key Cryptography
- **RSA** (`RSA.py`): RSA encryption/decryption using public and private keys. Foundation of modern secure communication.
- **Diffie-Hellman Key Exchange** (`DiffieHellman.py`): Secure key exchange protocol allowing two parties to establish a shared secret over an insecure channel.
- **ElGamal Encryption** (`ElGamal.py`): Public key cryptosystem based on discrete logarithm problem. Provides semantic security.

#### Lab 9: Cryptographic Hash Functions
- **MD5** (`MD5.py`): Message Digest Algorithm, produces 128-bit hash. Note: Cryptographically broken, used for educational purposes.
- **SHA** (`SHA.py`): Secure Hash Algorithm, produces cryptographically secure hashes. More reliable than MD5 for security applications.

---

### 2. **Design and Analysis of Algorithms**
**Overview:** Study of algorithm design paradigms, complexity analysis, and optimization techniques.

#### Lab 1: Sorting and Searching Algorithms
- **Binary Search Tree** (`binary search treee.cpp`): Tree-based data structure for efficient searching with O(log n) average time complexity.
- **Bubble Sort** (`bubble sort.cpp`): Simple comparison-based sorting with O(n²) time complexity. Foundation for understanding sorting concepts.
- **Insertion Sort** (`insertion sort.cpp`): Builds sorted array one item at a time, O(n²) but efficient for small datasets.
- **Selection Sort** (`selection sort.cpp`): Finds minimum and places it at beginning repeatedly, O(n²) complexity.
- **Min-Max** (`min max.cpp`): Finding minimum and maximum elements efficiently in arrays.

#### Lab 2: Divide and Conquer Sorting
- **Merge Sort** (`mergesort.cpp`): Divide-and-conquer algorithm with O(n log n) time complexity and stable sorting guarantee.
- **Quick Sort** (`quicksort.cpp`): Efficient partitioning-based sort with average O(n log n) and worst-case O(n²) complexity.
- **Randomized Quick Sort** (`randomized_quicksort.cpp`): Quick sort with random pivot selection to reduce worst-case scenarios.

#### Lab 3: Greedy and Advanced Sorting
- **Heap Sort** (`Heap_sort.cpp`): Uses heap data structure for sorting with O(n log n) guaranteed time complexity.
- **Fractional Knapsack** (`Fraction Knapsack.cpp`): Greedy algorithm for knapsack problem where items can be divided.
- **Job Sequencing** (`job sequencing.cpp`): Greedy algorithm to schedule jobs maximizing profit with deadlines.
- **Kruskal Algorithm** (`Kruskal algorithm.cpp`): Finds minimum spanning tree using greedy approach with union-find.
- **Prim's Algorithm** (`prims_algorithm.cpp`): Alternative minimum spanning tree algorithm using greedy vertex selection.

#### Lab 4: Dynamic Programming and Graph Algorithms
- **Zero-One Knapsack** (`zero_one knapsack.cpp`): Dynamic programming solution where items cannot be divided, optimal value calculation with O(nW) complexity.
- **Floyd Warshall Algorithm** (`floyd warshall.cpp`): All-pairs shortest path algorithm with O(n³) complexity, handles negative weights.

---

### 3. **Simulation and Modeling**
**Overview:** Understanding stochastic simulation, statistical testing, and discrete event simulation (GPSS).

#### Lab 1: Random Number Generation
- **Question 1-5** (`Question-1.cpp` to `Question-5.cpp`): Basic random number generation methods and validation.

#### Lab 2: Statistical Testing and RNG Methods
- **Multiplicative Congruential Method** (`Multiplicative_Congruential_Method.cpp`): Linear congruential generator variant for random number generation.
- **Kolmogorov-Smirnov Test** (`Kolmogorov_Smirnov_Test.cpp`): Statistical test for goodness-of-fit of random numbers.
- **K-S Test for Independence** (`K-S_Test_for_Independence.cpp`): Testing independence of random number sequences.

#### Lab 3: Advanced Statistical Tests
- **Autocorrelation Tests** (`Autocorrelation_Test_Q1.cpp`, `Autocorrelation_Test_Q2.cpp`, etc.): Testing for correlations in random sequences.

#### Lab 4: GPSS Simulation
- **GPSS Models** (`Gpss/`): Discrete event simulation using General Purpose Simulation System.

---

### 4. **System Analysis & Design**
**Overview:** Software engineering principles, system design methodologies, and requirements analysis.

---

### 5. **Web Technology**
**Overview:** Web development, frontend/backend technologies, and web application development.

#### Lab 1-7
Various web development projects and implementations using HTML, CSS, JavaScript, and backend technologies.

---

### 6. **Multimedia**
**Overview:** Multimedia processing, audio/video editing, and digital media concepts.

#### Labs 1-9
Various multimedia projects with audio and video file processing.

---

## 🛠️ Technologies Used

- **Languages:** Python, C++, JavaScript, PHP, HTML, CSS
- **Tools & Technologies:**
  - C++ for algorithm implementations
  - Python for cryptography implementations
  - Web technologies: HTML, CSS, JavaScript, PHP
  - GPSS for discrete event simulation

## 📝 Notes

- Each lab contains practical implementations of theoretical concepts
- Code is organized by subject and lab number for easy navigation
- Reports (.md files) provide detailed analysis and findings
- All implementations are for educational purposes

---

**Created:** Semester 5  
**Repository:** https://github.com/Dr0goblin/Sem-5

