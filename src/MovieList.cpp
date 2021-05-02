/*
    Emre Caniklioglu
    21803577
    CS 201 HOMEWORK 03
*/

#include "include/MovieList.h"

#include <iostream>

using namespace std;

MovieList::MovieList()
{
    this->size = 0;
    this->head = NULL;
}

MovieList::MovieList(MovieList& original)
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

MovieList::~MovieList()
{
    this->removeAll();
}

bool MovieList::isEmpty() const
{
    return this->size == 0;
}

int  MovieList::getLenght() const
{
    return this->size;
}

bool MovieList::retrive(int index, Movie& hook) const
{
    if((index < 1) || (index > this->getLenght()))
    {
        return NULL;
    }
    else
    {
        Node* curr = find(index);
        hook = *curr->data;
        return true;
    }
}

bool MovieList::insert(int index, long id, int radius)
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

        // Creating the Movie

        Movie* m1 = new Movie(id, radius);

        newPtr->data = m1;

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

bool MovieList::remove(int index)
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
        delete curr->data;
        delete curr;
        curr = NULL;

        return true;
    }
}

void MovieList::removeAll()
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
            delete fir->data;
            delete fir;
        }
        delete sec->data;
        delete sec;
    }
}

bool MovieList::removeById(long id)
{
    if(this->head == NULL)
    {
        return false;
    }
    else
    {
        int counter = 1;

        Node* iterator = this->head;
    
        while(iterator->next != NULL)
        {
            if(iterator->next != NULL && iterator->data->getId() == id)
            {
                cout << "Movie at " << iterator->data->getDate() << " has been canceled" << endl;
                this->remove(counter);
                return true;
            }    
            iterator = iterator->next;
            counter++;
        }
        if(iterator->next == NULL && iterator->data->getId() == id)
        {
            this->remove(counter);
            return true;       
        }
        return false;
    }
}

void MovieList::showAll() const
{
    if(this->head != NULL)
    {
        Node* iterator = this->head;

        while(iterator->next != NULL)
        {
            iterator->data->showInfo();
            iterator = iterator->next;
        }
        iterator->data->showInfo();
    }
}

bool MovieList::show(long movieId) const 
{
    if(this->head != NULL)
    {
        Node* iterator = this->head;

        while(iterator->next != NULL)
        {
            if(iterator->data->getId() == movieId)
            {
                iterator->data->showPlan();
                return true;
            }
            iterator = iterator->next;
        }
        if(iterator->next == NULL && iterator->data->getId() == movieId)
        {
            iterator->data->showPlan();
            return true;
        }
    }
    return false;
}

int  MovieList::addReservation(const long movieID, const int row, const char col, int code)
{
    char column = col;

    int columnAsInt = ((int) col) - 64;

    // cout << "COL : " << col << " COL AS INT : " << columnAsInt << endl;
    // cout << "MOVIE ID " << movieID << " - CODE " << code << endl;

    if(this->head != NULL)
    {
        Node* iterator = this->head;

        while(iterator->next != NULL)
        {
            // cout << "CURRET MOVIE IN THE ITERATION IS : " << iterator->data->getId() << endl;
            if(iterator->data->getId() == movieID)
            {   
                if(iterator->data->isAvailable(row, columnAsInt))
                {
                    return iterator->data->addReservation(row, columnAsInt, code);
                }
                else
                {
                    cout << "Seat " << col << row << " is not occupiable in Movie at " << iterator->data->getDate() << endl;
                    return -23;
                }
            }
            iterator = iterator->next;
        }
        if(iterator->next == NULL && iterator->data->getId() == movieID)
        {
            // cout << "CURRET MOVIE IN THE ITERATION IS : " << iterator->data->getId() << endl;
            if(iterator->data->isAvailable(row, columnAsInt))
            {
                return iterator->data->addReservation(row, columnAsInt, code);
             }
            else
            {
                cout << "Seat " << col << row << " is not occupiable in Movie at " << iterator->data->getDate() << endl;
                return -23;
            }
        }
    }
    return -73;
}

bool MovieList::showReservation(const int resCode) const
{
    // cout << "RES CODE : " << resCode << endl;
    if(this->head != NULL)
    {
        Node* iterator = this->head;

        while(iterator->next != NULL)
        {
            if(iterator->data->findReservation(resCode))
            {
                return true;
            }
            iterator = iterator->next;
        }
        if(iterator->next == NULL && iterator->data->findReservation(resCode))
        {
            return true;
        }
    }
    cout << "No reservation with the code : " << resCode << endl;
    return false;
}

bool MovieList::allExist(ReservationList& list)
{
    if(list.head != NULL)
    {
        ReservationList::Node * iterator = list.head;
        while(iterator->next != NULL)
        {
            if(!this->exist(iterator->data))
            {
                return false;
            }
            // cout << "LOOP DATA : " << iterator->data << endl;
            iterator = iterator->next;
        }
        if (iterator->next == NULL)
        {
            if(!this->exist(iterator->data))
            {
                return false;
            }
        }
        return true;   
    }
    else
    {
        return false;
    }
}

bool MovieList::exist(int resCode)
{
    // cout << "CHECKING THE CODE : " <<  resCode << endl;

    if(this->head != NULL)
    {
        Node* iterator = this->head;

        while(iterator->next != NULL)
        {
            if(iterator->data->findReservationWithOutPrinting(resCode))
            {
                return true;
            }
            iterator = iterator->next;
        }
        if(iterator->next == NULL && iterator->data->findReservationWithOutPrinting(resCode))
        {
            return true;
        }
    }
    return false;
}

void MovieList::deleteAllReservations(ReservationList& list)
{
    if(this->head != NULL)
    {
        Node* iterator = this->head;

        while(iterator != NULL)
        {
            ReservationList::Node* resIterator = list.head;

            while(resIterator != NULL)
            {
                // cout << "DATA : " << resIterator->data << endl;
                iterator->data->delReservation(resIterator->data);
                resIterator = resIterator->next;
            }
            iterator = iterator->next;
        }
    }
}

void MovieList::showHead()
{
    this->head->data->showAddedInfo();
}

MovieList::Node* MovieList::find(int index) const
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