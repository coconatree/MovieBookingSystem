/*
    Emre Caniklioglu
    21803577
    CS 201 HOMEWORK 03
*/

#ifndef MOVIE_H
#define MOVIE_H

#include "IntList.h"
#include "ReservationListCustom.h"

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Movie
{

public:

    Movie();
    Movie(long, int);
    Movie(Movie&);

    ~Movie();

    void showInfo();
    void showPlan();
    void showAddedInfo();

    int  addReservation(int, int, int);
    void delReservation(int);

    bool findReservation(int resCode);
    bool findReservationWithOutPrinting(int code);

    long getId();
    string getDate();

    bool isAvailable(int, int);

private:

    void init();
    void initDate();
    
    void populate();

    int calculate(int);

    IntList rowList;
    IntList colList;

    ReservationListCustom resList;

    long id;

    int radius;

    int size;
    int available;

    int numOfRow;
    int numOfCol;

    string date;
};

#endif