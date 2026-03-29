"""
File: text_analyzer.py

Description:
Utility module for basic text analysis operations.

Functions included:
- count_vowels(text): Counts the number of vowels in a string.
- count_words(text): Counts the number of words in a string.
- normalize_text(text): Converts text to lowercase and removes extra whitespace.
- find_substring(text, substring): Finds the position of a substring inside a text.

Author: Filipe Amoedo
"""

def count_vowels(text):
    """
    Count the number of vowels in a given text.

    Args:
        text (str): Input string.

    Returns:
        int: Total number of vowels found.
    """
    vowels = "aeiou"
    count = 0

    for char in text.lower():
        if char in vowels:
            count += 1

    return count


def count_words(text):
    """
    Count the number of words in a string.

    Args:
        text (str): Input string.

    Returns:
        int: Number of words.
    """
    words = text.split()
    return len(words)


def normalize_text(text):
    """
    Normalize text by converting it to lowercase
    and removing leading/trailing whitespace.

    Args:
        text (str): Input string.

    Returns:
        str: Cleaned text.
    """
    return text.strip().lower()


def find_substring(text, substring):
    """
    Find the first occurrence of a substring in the text.

    Args:
        text (str): The main text.
        substring (str): The substring to search for.

    Returns:
        int: Position of the substring or -1 if not found.
    """
    return text.find(substring)


# Example usage when running this file directly
if __name__ == "__main__":

    sample_text = "  Hello World from Python  "

    print("Original text:", sample_text)

    print("Normalized:", normalize_text(sample_text))
    print("Word count:", count_words(sample_text))
    print("Vowel count:", count_vowels(sample_text))
    print("Find 'World':", find_substring(sample_text, "World"))
