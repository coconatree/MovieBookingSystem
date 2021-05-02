#ifndef RESERVATION_LIST_H
#define RESERVATION_LIST_H

#include <iostream>
#include <cstddef>

using namespace std;

class ReservationList
{

public:

    ReservationList();
    ReservationList(const ReservationList&);

    ~ReservationList();

    bool isEmpty() const;
    int  getSize() const;

    bool retrive(int, int&) const;
    
    bool insert(int, int);
    bool remove(int);
    
    struct Node
    {
        int data;
        Node* next;
    };

    Node* head;

    void printLn();

private:

    int   size;
    
    ReservationList::Node* find(int index) const;
};

#endif