/*
    Emre Caniklioglu
    21803577
    CS 201 HOMEWORK 03
*/

#ifndef LIST_H
#define LIST_H

#include "IntNode.h"

class IntList
{

public:

    IntList();
    IntList(IntList&);

    ~IntList();

    bool isEmpty() const;
    int  getSize() const;

    bool retrive(int, int&) const;
    
    bool insert(int, int);
    bool remove(int);
    
    void print();

    bool in(int) const;

    bool removeById(int);

private:

    void displayInOrder(IntNode*);

    IntNode* find(int) const;

    int      size;
    IntNode* head;
};

#endif