/*
 Name: Samuel Campbell
 Date: 02/27/2022
 Assignment: Pre-lab 5
 
 Filename: 'TreeNode.h'
 */

#ifndef TREENODE_H
#define TREENODE_H

#include <string>
using namespace std;

class TreeNode {
public:
    TreeNode();                     //Default Constructor
    TreeNode(const string & val);   //Constructor

private:
    string value;
    TreeNode *left, *right;         // for trees
    friend class TreeCalc;          //gives TreeCalc access to private data
};

#endif
