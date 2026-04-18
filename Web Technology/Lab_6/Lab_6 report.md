# Lab 6 Report

## Title
PHP Fundamentals: Loops, Strings, Arrays, and Basic Functions

## Objective
1. To understand and implement loops in PHP (for, foreach loops) for iterating over arrays and ranges.
2. To manipulate strings in PHP using string functions and character iteration.
3. To work with PHP arrays and perform array operations (merge, sort, search).
4. To implement functions in PHP with parameters and return values.
5. To understand function argument handling using `func_get_args()` for variable argument functions.
6. To generate dynamic HTML content using PHP server-side scripting.

## Theory
PHP (Hypertext Preprocessor) is a server-side scripting language that generates dynamic web content. This lab covers fundamental PHP concepts:

**Loops**: `for` loops iterate a specific number of times with counters. `foreach` loops iterate directly over array elements, eliminating index management. Nested loops handle multi-dimensional problems.

**String Operations**: Strings are sequences of characters. PHP functions like `strlen()` get length, character access uses index notation `$string[$i]`, `strtolower()` converts to lowercase, and `in_array()` checks if element exists.

**Arrays**: Arrays store multiple values with indices. `array_merge()` combines arrays, `sort()` sorts numerically, `ksort()` sorts by keys, `asort()` sorts by values, `print_r()` displays array structure.

**Functions**: Functions encapsulate reusable code. `func_get_args()` collects variable numbers of arguments into an array, enabling flexible function signatures.

**Dynamic HTML**: PHP generates HTML dynamically using `echo` or `<?php ?>` blocks within HTML, allowing server-side content generation.

**Table Generation**: PHP loops generate table rows and cells dynamically, useful for displaying data from arrays or databases.

## Codes
Main files used in this lab:
1. index.php - Navigation page linking to all lab questions
2. q1.php - Nested for loops generating a 10×10 multiplication table with proper HTML table formatting
3. q2.php - String iteration counting vowels in a text using strlen() and in_array()
4. q3.php - Array operations demonstrating foreach loops to create array of squares
5. q4.php - Variable-argument functions using func_get_args() for function overloading simulation
6. q5.php - Array operations including merge, sort, ksort, and asort with display of results

## Conclusion
Lab 6 successfully introduced PHP server-side scripting fundamentals. Students learned how to use loops for data processing, manipulate strings and arrays, implement flexible functions with variable arguments, and generate dynamic HTML content. These PHP basics form the foundation for building dynamic web applications that can process server-side logic, interact with databases, and generate custom content based on user requests and data conditions.
