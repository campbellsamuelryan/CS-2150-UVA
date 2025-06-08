#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <string>
#include <vector>
#include <list>


using namespace std;

class hashTable {
    public:
        hashTable();
        hashTable(int size);
        

        bool find(string word);
        void insert(string word);
        int getHash(string word);
        int tableSize;
        
    private:
        vector <list <string>*> table;

    bool checkprime(unsigned int p);
    int getNextPrime (unsigned int n);
    
};

#endif 