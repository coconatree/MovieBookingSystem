/*
    Emre Caniklioglu
    21803577
    CS 201 HOMEWORK 03
*/

#include "include/IntNode.h"

IntNode::IntNode()
{
    this->data = -1;
    this->next = NULL;
}

IntNode::IntNode(IntNode& original)
{
    this->data = original.data;
    this->next = original.next;
}

IntNode::~IntNode()
{
    this->next = NULL;
}

int  IntNode::getData()
{
    return this->data;
}

IntNode* IntNode::getNext()
{
    return this->next;
}

void IntNode::set(int data, IntNode* next)
{
    this->data = data;
    this->next = next;
}

void IntNode::setData(int data)
{
    this->data = data;
}

void IntNode::setNext(IntNode* next)
{
    this->next = next;
}
