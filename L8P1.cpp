/*
Lab 8 
Problem 1
CS 008 - Jason Li
*/

#include <iostream>
#include <fstream>

using namespace std;

class Node {
public:
    int data;
    Node* leftChild;
    Node* rightChild;

    Node(int value) : data(value), leftChild(nullptr), rightChild(nullptr) {}
};

class bTree{
public:
    bTree() : root(nullptr) {}

    void insertNode(int value){

    }

    void deleteNode(int pos){

    }

    
private:
    Node* root;
};