/*
 Name: Samuel Campbell
 Date: 03/02/2022
 Assignment: Post-lab 5
 
 Filename: 'AVLPathTest.cpp'
 */

#include "AVLTree.h"

#include <iostream>
using namespace std;

int main() {
    AVLTree avl;
    while (cin.good()) {
        string instr, word;
        cin >> instr;
        cin >> word;
        if (instr == "I") {
            avl.insert(word);
        } else if (instr == "R") {
            avl.remove(word);
        } else if (instr == "L") {
            cout << "AVL path: " << avl.pathTo(word) << endl;
        }else{
            cout << "AVL numNodes: " << avl.numNodes() << endl;
        }
    }
    cout << "AVL numNodes: " << avl.numNodes() << endl;
}
