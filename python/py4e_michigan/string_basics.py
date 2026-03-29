# Basic Python String Operations Exercises
# This script demonstrates fundamental string operations including:
# - String concatenation
# - Membership testing using the 'in' operator
# - String comparison
# - User input handling

print("Hello World")

# -----------------------------
# STRING CONCATENATION
# -----------------------------

# Assign a string to variable 'a'
a = 'Hello'

# Concatenate strings without space
b = a + 'There'
print(b)  # Output: HelloThere

# Concatenate strings with a space between words
c = a + ' ' + 'There'
print(c)  # Output: Hello There


# -----------------------------
# USING 'in' AS A LOGICAL OPERATOR
# -----------------------------

# Assign a string value
fruit = 'banana'

# Check if a character exists in the string
'n' in fruit   # Returns True

# Check if another character exists
'm' in fruit   # Returns False

# Check if a substring exists
'nan' in fruit # Returns True

# Conditional check using the 'in' operator
if 'a' in fruit:
    print('Found it!')


# -----------------------------
# STRING COMPARISON
# -----------------------------

# Ask the user for input
word = input('What fruit do you love? ')

# Direct comparison
if word == 'banana':
    print('All right, bananas')

# Alphabetical comparison
if word < 'banana':
    print('Your word,', word, ', comes before banana.')
elif word > 'banana':
    print('Your word,' + word + ', comes after banana.')
else:
    print('All right, bananas.')
