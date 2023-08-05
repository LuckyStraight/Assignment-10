# Trie Data Structure for Counting Word Occurrences

This is a C program that implements a Trie data structure to count the number of occurrences of words in a given dictionary. The words in the dictionary are assumed to be in lowercase.

## Trie Data Structure

The Trie data structure is used to efficiently store and search for strings in a dictionary. Each node in the Trie represents a character in the words, and the edges between nodes represent the characters in the words. Each node has an array of pointers to its children, corresponding to the characters 'a' to 'z'. The "count" variable in each node is used to store the number of times a particular word appears in the dictionary.

## Code Files

    trie.c: This file contains the implementation of the Trie data structure, including functions for creating a Trie node, inserting words into the Trie, computing the number of occurrences of a word, and deallocating the Trie.

    main.c: This file contains the main() function, which reads the dictionary from a file, builds the Trie data structure, and then tests the occurrences of specific words.

## Usage

    To use this program, save the list of words in lowercase in a file named "dictionary.txt" in the same directory as the code files.

    Compile the code using a C compiler:

bash

gcc trie.c main.c -o trie_program

    Run the compiled program:

bash

./trie_program

## Output

The program will first print all the words read from the "dictionary.txt" file. Then, it will test the occurrences of specific words and display the results.

## Note

    Words in the dictionary should be separated by newline characters in the "dictionary.txt" file.

    The program deallocates the Trie data structure and frees memory used for storing words in the dictionary before exiting.

    The code assumes that the maximum number of words in the dictionary is 256. You can modify the char* inWords[256] in main.c if you have a larger dictionary.

    The code assumes that the length of each word in the dictionary will not exceed 255 characters. You can modify the size of the word array in the readDictionary function in main.c if longer words are expected.

    The code will not handle special characters or digits in the words as it is designed to handle lowercase letters only.
