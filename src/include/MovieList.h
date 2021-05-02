/*
    Emre Caniklioglu
    21803577
    CS 201 HOMEWORK 03
*/

#ifndef MOVIE_LIST_H
#define MOVIE_LIST_H

#include "ReservationList.h"
#include "Movie.h"

#include <cstddef>

class MovieList
{

public:

    MovieList();
    MovieList(MovieList&);

    ~MovieList();

    bool isEmpty() const;
    int  getLenght() const;

    bool retrive(int, Movie&) const;
    
    bool insert(int, long, int);
    bool remove(int);

    void removeAll();

    bool removeById(long);

    void showAll() const;
    bool show(long) const;

    int  addReservation(const long, const int, const char, int);
    bool showReservation(const int) const;

    bool allExist(ReservationList&);
    bool exist(int);

    void deleteAllReservations(ReservationList&);
    void showHead();

private:

    struct Node
    {
        Movie* data;
        Node * next;
    };

    Node* find(int) const;

    int size;

    Node* head;
};

#endif