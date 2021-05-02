/*
    Emre Caniklioglu
    21803577
    CS 201 HOMEWORK 03
*/

#include "include/ReservationListCustom.h"

ReservationListCustom::ReservationListCustom()
{
    this->size = 0;
    this->head = NULL;
    this->date = "NULL";
}

ReservationListCustom::ReservationListCustom(ReservationListCustom& original)
{
    if(original.head == NULL)
    {
        this->head = NULL;
    }
    else
    {
        this->head = new Node;

        this->head->data = original.head->data;
        
        Node* newPtr = this->head;

        for(Node* origPtr = original.head->next; origPtr != NULL; origPtr = origPtr->next)
        {
            newPtr->next = new Node;
            newPtr = newPtr ->next;
            newPtr->data = origPtr->data;
        }
        newPtr->next = NULL;
    }
}   

ReservationListCustom::~ReservationListCustom()
{
    this->removeAll();
}

bool ReservationListCustom::isEmpty() const
{
    return this->size == 0;
}

int  ReservationListCustom::getLenght() const
{
    return this->size;
}

bool ReservationListCustom::retrive(int index, Reservation& hook) const
{
    if((index < 1) || (index > this->getLenght()))
    {
        return NULL;
    }
    else
    {
        Node* curr = find(index);
        hook = curr->data;
        return true;
    }
}

bool ReservationListCustom::insert(int index, int row, int col, int code)
{
    int newSize = this->getLenght() + 1;

    if ((index < 1) || (index > newSize))
    {
        return false;
    }
    else
    {
        Node *newPtr = new Node;
        
        this->size = newSize;

        // Creating the Reservation

        Reservation r1(row, col, code);

        newPtr->data = r1;

        if (index == 1)
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

bool ReservationListCustom::remove(int index)
{
    Node* curr;

    if ((index < 1) || (index > this->getLenght()))
    {
        return false;
    }
    else
    {
        this->size--;
        
        if(index == 1)
        {   
            curr = this->head;
            this->head = this->head->next;
        }
        else
        {
            Node* prev = this->find(index - 1);
            curr = prev->next;
            prev->next = curr->next;
        }

        curr->next = NULL;
        delete curr;
        curr = NULL;

        return true;
    }
}

void ReservationListCustom::removeAll()
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

bool ReservationListCustom::removeByCode(int code)
{
    // Finding the element with the given code

    if(this->head == NULL)
    {
        return false;
    }

    Node* iterator = this->head;

    int counter = 1;

    while(iterator->next != NULL)
    {
        // cout << "HERE WITH CODE ORIG : " << iterator->data.getCode() << " PASSEED VALUE : " << code << endl;

        if(iterator->data.getCode() == code)
        {
            // cout << "HERE WITH CODE ORIG : " << iterator->data.getCode() << " PASSEED VALUE : " << code << endl;
            cout << "Reservation on Code " << code << ": Seat " << iterator->data.getCol() << iterator->data.getRow() << " in Movie at " << this->date << endl;
            this->remove(counter);
            return true;
        }
        iterator = iterator->next;
        counter++;
    }
    if(iterator->next == NULL && iterator->data.getCode() == code)
    {
        cout << "Reservation on Code " << code << " is canceled: Seat " << iterator->data.getColAsChar() << iterator->data.getRow() << " in Movie at " << this->date << endl;
        this->remove(counter);
        return true;
    }
    return false;
}

bool ReservationListCustom::isReserved(int row, int col)
{
    if(this->head == NULL)
    {
        return false;
    }

    Node* iterator = this->head;

    while(iterator->next != NULL)
    {
        if(iterator->data.validateSeat(row, col))
        {
            // cout << endl << "RETURNING TRUE FOR ROW : " << row <<  " - COL: " << col << endl;
            return true;
        }
        iterator = iterator->next;
    }
    if(iterator->next == NULL && iterator->data.validateSeat(row, col))
    {
        return true;
    }
    return false;
}

bool ReservationListCustom::findByCode(int code, bool print)
{
    if(this->head == NULL)
    {
        return false;
    }

    Node* iterator = this->head;

    while(iterator->next != NULL)
    {
        // cout << "ITERATOR CODE : " << iterator->data.getCode() << " PASSED CODE : " << code << endl; 

        if(iterator->data.getCode() == code)
        {
            if(print)
            {
                cout << "Reservation with Code " << code << ": Seat " << iterator->data.getColAsChar() << iterator->data.getRow() << " in Movie at " << this->date << endl;
            }
            return true;
        }
        iterator = iterator->next;
    }
    if(iterator->next == NULL && iterator->data.getCode() == code)
    {
        if(print)
        {
            cout << "Reservation with Code " << code << ": Seat " << iterator->data.getCol() << iterator->data.getRow() << " in Movie at " << this->date << endl;
        }
        return true;
    }
    return false;
} 

void ReservationListCustom::setDate(string date)
{
    this->date = date;
}

ReservationListCustom::Node* ReservationListCustom::find(int index) const
{
    if((index < 1) || (index > this->getLenght()))
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

bool ReservationListCustom::in(int row, int col, int code)
{
    if(this->head != NULL)
    {   
        Node* iterator = this->head;

        // cout << "PASSED " << row << " - " << col << " - " << code << endl;

        while(iterator != NULL)  
        {    
            // cout << "ITERATOR " << iterator->data.getRow() << " - " <<  iterator->data.getCol() << " - "  << iterator->data.getCode() << endl;

            if(iterator->data.getRow() == row && iterator->data.getCol() == col)
            {
                // cout << "EQUAL" << endl;
                return true;
            }
            iterator = iterator->next;
        }

        return false;
    }
    else
    {
        return false;
    }
}
