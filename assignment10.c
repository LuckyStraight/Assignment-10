#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Trie structure
struct TrieNode {
    struct TrieNode* children[26]; // 26 letters of the alphabet
    int count; // to store the occurrence count of the word
};

struct TrieNode* createTrieNode();
void insert(struct TrieNode* root, char* word);
int numberOfOccurrences(struct TrieNode* root, char* word);
void deallocateTrie(struct TrieNode* root);
int readDictionary(char* filename, char** pInWords);

int main(void) 
{
    char* inWords[256];

    // Read the number of words in the dictionary
    int numWords = readDictionary("dictionary.txt", inWords);

    for (int i = 0; i < numWords; ++i) 
    {
        printf("%s\n", inWords[i]);
    }

    struct TrieNode* pTrie = createTrieNode();

    for (int i = 0; i < numWords; i++) 
    {
        insert(pTrie, inWords[i]);
    }

    // Test the occurrences of words
    char* pWords[] = {"notaword", "ucf", "no", "note", "corg"};

    for (int i = 0; i < 5; i++) 
    {
        printf("\t%s : %d\n", pWords[i], numberOfOccurrences(pTrie, pWords[i]));
    }

    // Deallocate the Trie
    deallocateTrie(pTrie);

    // Free memory used for words in the dictionary
    for (int i = 0; i < numWords; i++) 
    {
        free(inWords[i]);
    }

    return 0;
}

// Initializes a Trie node
struct TrieNode* createTrieNode() 
{
    struct TrieNode* newNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));

    if (newNode) 
    {
        newNode->count = 0;

        for (int i = 0; i < 26; i++) 
        {
            newNode->children[i] = NULL;
        }
    }
    return newNode;
}

// Inserts the word to the Trie structure
void insert(struct TrieNode* root, char* word) 
{
    struct TrieNode* currentNode = root;
    int len = strlen(word);

    for (int i = 0; i < len; i++) 
    {
        int index = word[i] - 'a';

        if (currentNode->children[index] == NULL) 
        {
            currentNode->children[index] = createTrieNode();
        }
        currentNode = currentNode->children[index];
    }
    currentNode->count++;
}

// Computes the number of occurrences of the word
int numberOfOccurrences(struct TrieNode* root, char* word) 
{
    struct TrieNode* currentNode = root;
    int len = strlen(word);

    for (int i = 0; i < len; i++) 
    {
        int index = word[i] - 'a';

        if (currentNode->children[index] == NULL) 
        {
            return 0;
        }
        currentNode = currentNode->children[index];
    }
    return currentNode->count;
}

// Deallocates the Trie structure
void deallocateTrie(struct TrieNode* root) 
{
    if (root == NULL) 
    {
        return;
    }

    for (int i = 0; i < 26; i++) 
    {
        deallocateTrie(root->children[i]);
    }
    free(root);
}

// Reads the dictionary and builds the Trie
int readDictionary(char* filename, char** pInWords) 
{
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) 
    {
        printf("Error opening file.\n");
        return 0;
    }

    int numWords;
    if (fscanf(fp, "%d", &numWords) != 1) 
    {
        printf("Error reading the number of words.\n");
        fclose(fp);
        return 0;
    }

    int i;
    for (i = 0; i < numWords; i++) 
    {
        char word[256];
        if (fscanf(fp, "%s", word) != 1) 
        {
            printf("Error reading word from the dictionary.\n");
            break;
        }
        int len = strlen(word);
        pInWords[i] = (char*)malloc(len + 1);
        strcpy(pInWords[i], word);
    }

    fclose(fp);
    return i;
}