/*
    Emre Caniklioglu
    21803577
    CS 201 HOMEWORK 03
*/

#ifndef INT_NODE_H
#define INT_NODE_H

#include <iostream>
#include <cstddef>

using namespace std;

class IntNode
{

public:

    IntNode();
    IntNode(IntNode&);

    ~IntNode();

    void set(int, IntNode*);

    int getData();
    IntNode* getNext();

    void setData(int);
    void setNext(IntNode*);


private:

    int data;
    IntNode* next;

};

#endif