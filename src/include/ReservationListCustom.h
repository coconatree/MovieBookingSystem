/*
    Emre Caniklioglu
    21803577
    CS 201 HOMEWORK 03
*/

#ifndef RESERVATION_LIST_CUSTOM_H
#define RESERVATION_LIST_CUSTOM_H

#include "Reservation.h"

#include <iostream>
#include <cstddef>
#include <string>

using namespace std;

class ReservationListCustom
{

public:

    ReservationListCustom();
    ReservationListCustom(ReservationListCustom&);

    ~ReservationListCustom();

    bool isEmpty() const;
    int  getLenght() const;

    bool retrive(int, Reservation&) const;
    
    bool insert(int, int, int, int);
    bool remove(int);

    void removeAll();

    bool removeByCode(int code);

    bool isReserved(int, int);
    
    bool findByCode(int, bool);

    void setDate(string date);

    bool in(int, int, int);

    struct Node
    {
        Reservation data;
        Node * next;
    };

    Node* head;

private:

    Node* find(int) const;

    int size;

    string date;
};

#endif