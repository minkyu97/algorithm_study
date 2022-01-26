#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int ALPHABET_SIZE = 26;

// trie node
struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    int numOfChild;
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndOfWord;
};

// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode =  new TrieNode;

    pNode->numOfChild = 0;
    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = NULL;

    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'A';
        if (!pCrawl->children[index]) {
            pCrawl->children[index] = getNode();
            pCrawl->numOfChild++;
        }


        pCrawl = pCrawl->children[index];
    }

    // mark last node as leaf
    pCrawl->isEndOfWord = true;
    pCrawl->numOfChild++;
}

long long factorial(long n) {

    if(n==1 || n==0) return 1;
    else return n*factorial(n-1);
}

long long getSolution(TrieNode* trie) {
    if(trie->isEndOfWord && trie->numOfChild==1) return 1;
    long long solution = factorial(trie->numOfChild);
    //cout << endl;
    for(int i=0; i<26; i++) {
        if(trie->children[i]!=NULL) {
            //cout << i << ":" << trie->numOfChild << " " << trie->isEndOfWord;
            solution*= getSolution(trie->children[i]);
        }
    }



    return solution%(1000000007);
}



int main(void) {
    int numOfWords;
    cin >> numOfWords;

    TrieNode* trie = getNode();

    for(int i=0; i<numOfWords; i++) {
        string temp;
        cin >> temp;
        insert(trie, temp);
    }
    long long solution= getSolution(trie);
    cout << solution%(1000000007);
    return 0;
}










