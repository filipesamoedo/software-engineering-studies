"""
File: string_indexing_loops_slicing.py

Description:
Exercises demonstrating fundamental string manipulation techniques in Python,
including indexing, iteration, counting characters, and slicing.

Author: Filipe S Amoedo
"""

# -----------------------------
# LOOKING INSIDE STRINGS (INDEXING)
# -----------------------------

fruit = 'banana'

# Access a character by its index position
letter = fruit[1]
print(letter)  # Output: 'a'

# Using a variable to determine the index
x = 3
w = fruit[x-1]
print(w)  # Output: 'n'


# -----------------------------
# STRING LENGTH
# -----------------------------

fruit = 'banana'

# len() returns the number of characters in the string
print(len(fruit))  # Output: 6


# -----------------------------
# LOOPING THROUGH STRINGS (WHILE LOOP)
# -----------------------------

fruit = 'banana'
index = 0

# Iterate through each character using a while loop
while index < len(fruit):
    letter = fruit[index]
    print(index, letter)
    index = index + 1


# -----------------------------
# LOOPING THROUGH STRINGS (FOR LOOP)
# -----------------------------

# A shorter and more Pythonic way to iterate through a string
f = 0
for letter in fruit:
    print(f, letter)
    f = f + 1


# -----------------------------
# LOOPING AND COUNTING CHARACTERS
# -----------------------------

word = 'banana'
count = 0

# Count how many times the letter 'a' appears
for letter in word:
    if letter == 'a':
        count = count + 1

print(count)  # Output: 3


# -----------------------------
# STRING SLICING
# -----------------------------

s = 'Monty Python'

# Slice characters from index 0 up to (but not including) index 4
print(s[0:4])  # Mont

# Slice a single character
print(s[6:7])  # P

# Slicing beyond the string length is allowed
print(s[6:20])  # Python

# Omitting the start index
print(s[:2])  # Mo

# Omitting the end index
print(s[8:])  # thon

# Full copy of the string
print(s[:])  # Monty Python
