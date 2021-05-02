/*
    Emre Caniklioglu
    21803577
    CS 201 HOMEWORK 03
*/

#include "include/IntList.h"

IntList::IntList()
{
    this->size = 0;
    this->head = NULL;
}

IntList::IntList(IntList& original) : size(original.size)
{
    if(original.head == NULL)
    {
        this->head = NULL;
    }
    else
    {
        this->head = new IntNode;

        this->head->setData(original.head->getData());
        
        IntNode* newPtr = this->head;

        for(IntNode* origPtr = original.head->getNext(); origPtr != NULL; origPtr = origPtr->getNext())
        {
            newPtr->setNext(new IntNode);
            newPtr = newPtr->getNext();
            newPtr->setData(origPtr->getData());
        }
        newPtr->setNext(NULL);
    }
}

IntList::~IntList()
{
    if(this->head != NULL)
    {
        int s = this->size;

        IntNode* fir;
        IntNode* sec = this->head;

        while(sec->getNext() != NULL)
        {
            fir = sec;
            sec = sec->getNext();
            delete fir;
        }
        delete sec;
    }
}

bool IntList::isEmpty() const
{
    return this->size == 0;
}

int  IntList::getSize() const
{
    return this->size;
}

bool IntList::retrive(int index, int& data) const
{
    if((index < 1) || (index > this->getSize()))
    {
        return NULL;
    }
    else
    {
        IntNode* curr = find(index);
        data = curr->getData();
        return true;
    }
}

bool IntList::insert(int index, int data)
{
    int newSize = this->getSize() + 1;

    if ((index < 1) || (index > newSize))
    {
        return false;
    }
    else
    {
        IntNode *newPtr = new IntNode;
        
        this->size = newSize;
        newPtr->setData(data);

        if (index == 1)
        {
            newPtr->setNext(this->head);
            this->head = newPtr;
        }
        else
        {
            IntNode *prev = find(index - 1);
            newPtr->setNext(prev->getNext());
            prev->setNext(newPtr);
        }
        return true;
    }
}

bool IntList::remove(int index)
{
    IntNode* curr;

    if ((index < 1) || (index > this->getSize()))
    {
        return false;
    }
    else
    {
        this->size--;
        
        if(index == 1)
        {   
            curr = this->head;
            this->head = this->head->getNext();
        }
        else
        {
            IntNode* prev = this->find(index - 1);
            curr = prev->getNext();
            prev->setNext(curr->getNext());
        }

        curr->setNext(NULL);
        
        delete curr;
        
        curr = NULL;

        return true;
    }
}

void IntList::print()
{
    this->displayInOrder(this->head);
}

void IntList::displayInOrder(IntNode* head)
{
    if(head != NULL && head->getNext() != NULL)
    {
        cout << head->getData() << " -> ";
        this->displayInOrder(head->getNext());
    }
    else if(head != NULL)
    {
        cout << head->getData() << endl;
    }
}

IntNode* IntList::find(int index) const 
{
    if((index < 1) || (index > this->getSize()))
    {
        return NULL;
    }
    else
    {
        IntNode* cur = this->head;

        for(int skip = 1; skip < index; ++skip)
        {
            cur = cur->getNext();
        }
        return cur;
    }
}

bool IntList::in(int value) const
{
    if(this->head != NULL)
    {
        IntNode* iterator = this->head;

        while(iterator != NULL)
        {
            if(iterator->getData() == value)
            {
                return true;
            }
            iterator = iterator->getNext();
        }
        return false;
    }
    else
    {
        return false;
    }
}

bool IntList::removeById(int id)
{
    if(this->head != NULL)
    {
        IntNode* iterator = this->head;

        int counter = 1;

        while(iterator != NULL)
        {
            if(iterator->getData() == id)
            {
                this->remove(counter);
                return true;
            }
            iterator = iterator->getNext();
            counter++;
        }
    }
    return false;   
}