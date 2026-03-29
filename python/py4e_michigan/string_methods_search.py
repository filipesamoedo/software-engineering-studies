"""
File: string_methods_search.py

Description:
Exercises demonstrating built-in Python string methods including
text normalization, substring searching, whitespace stripping,
and object introspection.

Author: Filipe S Amoedo
"""

# -----------------------------
# STRING METHODS (STRING LIBRARY)
# -----------------------------

greet = 'Hello Bob'

# Convert the string to lowercase
zap = greet.lower()

print(zap)   # Output: hello bob
print(greet) # Original string remains unchanged (strings are immutable)

# Calling a string method directly on a literal
print('Hi There'.lower())  # Output: hi there


# -----------------------------
# EXPLORING STRING METHODS
# -----------------------------

stuff = 'Hello world'

# Check the type of the variable and print
print(type(stuff))

# dir() shows all available methods for the object
print(dir(stuff))

# Note: dir() returns a list of available attributes and methods,
# but it does not print automatically unless explicitly printed.


# -----------------------------
# SEARCHING WITHIN A STRING
# -----------------------------

fruit = 'banana'

# find() returns the index of the first occurrence
pos = fruit.find('na')
print(pos)  # Output: 2

# If the substring does not exist, find() returns -1
aa = fruit.find('z')
print(aa)  # Output: -1


# -----------------------------
# STRIPPING WHITESPACE
# -----------------------------

greet = '   Hello Bob   '

# Remove whitespace from the left side
print(greet.lstrip())  # Output: 'Hello Bob   '

# Remove whitespace from the right side
print(greet.rstrip())  # Output: '   Hello Bob'

# Remove whitespace from both sides
print(greet.strip())   # Output: 'Hello Bob'
