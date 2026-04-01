# Exercise 004
# Reads a value from the user and displays information about its type
# and characteristics using Python string methods.

print("====== EXERCISE 004 ======")

value = input("Enter something: ")

print("Primitive type:", type(value))
print("Is numeric?", value.isnumeric())
print("Is alphabetic?", value.isalpha())
print("Is uppercase?", value.isupper())
print("Is lowercase?", value.islower())
print("Is alphanumeric?", value.isalnum())
print("Contains only spaces?", value.isspace())
