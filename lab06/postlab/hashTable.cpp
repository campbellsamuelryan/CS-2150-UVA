/*
 Samuel Campbell
 'wordPuzzle.cpp'
 */
#include "hashTable.h"

using namespace std;

hashTable::hashTable(int size){
    max_len = 0;
  table = vector<list<string> > (size);
};

unsigned int hashTable::strHash(string s){

  int hashVal = 0;
  for(int i = 0; i < s.length(); i++){
    hashVal += s.at(i);
  }
  return hashVal % 42069;
}

bool hashTable::contains(string s){
  int index = strHash(s);

  for(string comp: table[index]){
    if(comp == s)
      return true;
  }
  return false;
}

void hashTable::insert(string s){
  int tableLoc = strHash(s);
  int len_ = s.length();
  if(len_ > max_len){
        max_len = len_;
  }
  if(len_ > 22){
        max_len = 22;
  }
  table[tableLoc].push_back(s);
}

