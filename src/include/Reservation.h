/*
    Emre Caniklioglu
    21803577
    CS 201 HOMEWORK 03
*/

#ifndef RESERVATION_H
#define RESERVATION_H

class Reservation
{

public:

    Reservation();
    Reservation(int, int, int);
    Reservation(Reservation&);

    ~Reservation();

    int getCode();

    int  getRow();
    int getCol();

    bool validateSeat(int, int);

    char getColAsChar();

private:

    int row;
    int col;
    int code;
};

#endif