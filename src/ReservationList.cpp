/*
    Emre Caniklioglu
    21803577
    CS 201 HOMEWORK 03
*/

#include "include/ReservationList.h"

ReservationList::ReservationList()
{
    this->size = 0;
    this->head = NULL;
}

ReservationList::ReservationList(const ReservationList& original) : size(original.size)
{
    // cout << "INSIDE THE COPY CONSTRUCTOR !!! " << endl;

    if(original.head == NULL)
    {
        this->head = NULL;
        // cout << "HEAD IS NULL" << endl;
    }
    else
    {
        // cout << "ELSE" << endl;
        this->head = new Node;

        this->head->data = original.head->data;
        
        Node* newPtr = this->head;

        for(Node* origPtr = original.head->next; origPtr != NULL; origPtr = origPtr->next)
        {
            // cout << "FOOOOR" << endl;

            newPtr->next = new Node;
            newPtr = newPtr->next;
            newPtr->data = origPtr->data;
        }
        newPtr->next = NULL;
    }
}

ReservationList::~ReservationList()
{
    if(this->head != NULL)
    {
        int s = this->size;

        Node* fir;
        Node* sec = this->head;

        while(sec->next != NULL)
        {
            fir = sec;
            sec = sec->next;
            delete fir;
        }
        delete sec;
    }
}

bool ReservationList::isEmpty() const
{
    return this->size == 0;
}

int  ReservationList::getSize() const
{
    return this->size;
}

bool ReservationList::retrive(int index, int& data) const
{
    if((index < 1) || (index > this->getSize()))
    {
        return NULL;
    }
    else
    {
        Node* curr = find(index);
        data = curr->data;
        return true;
    }
}

bool ReservationList::insert(int index, int data)
{
    int newSize = this->getSize() + 1;

    if ((index < 0) || (index > newSize))
    {
        return false;
    }
    else
    {
        Node *newPtr = new Node;
        
        this->size = newSize;
        newPtr->data = data;

        if (index == 0)
        {
            newPtr->next = this->head;
            this->head = newPtr;
        }
        else
        {
            Node *prev = find(index - 1);
            newPtr->next = prev->next;
            prev->next = newPtr;
        }
        return true;
    }
}

bool ReservationList::remove(int index)
{
    Node* curr;

    if ((index < 0) || (index > this->getSize()))
    {
        return false;
    }
    else
    {
        this->size--;
        
        if(index == 0)
        {   
            curr = this->head;
            this->head = this->head->next;
        }
        else
        {
            Node* prev = this->find(index - 1);
            curr = prev->next;
            prev->next= curr->next;
        }

        curr->next = NULL;
        
        delete curr;
        
        curr = NULL;

        return true;
    }
}

ReservationList::Node* ReservationList::find(int index) const 
{
    if((index < 0) || (index > this->getSize()))
    {
        return NULL;
    }
    else
    {
        Node* cur = this->head;

        for(int skip = 1; skip < index; ++skip)
        {
            cur = cur->next;
        }
        return cur;
    }
}

void ReservationList::printLn()
{
    if(this->head != NULL)
    {
        cout << "HERE INSIDE THE IF STATEMENT !!! " << endl;
        Node* iterator = this->head;

        while(iterator != NULL)
        {   
            cout << " | " << iterator->data << " -> " << endl;
            iterator = iterator->next;
        }
    }
    cout << "OUTSIDE !! "<< endl;
}
