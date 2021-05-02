/*
    Emre Caniklioglu
    21803577
    CS 201 HOMEWORK 03
*/

#include "include/Reservation.h"

#include <iostream>

using namespace std;

Reservation::Reservation()
{
    this->row  = -23;
    this->col  = -23;
    this->code = -23;
}

Reservation::Reservation(int row, int col, int code)
{
    this->row  = row;
    this->col  = col;
    this->code = code;
}

Reservation::Reservation(Reservation& orig)
{
    this->row  = orig.row;
    this->col  = orig.col;
    this->code = orig.code;
}

Reservation::~Reservation(){}

int Reservation::getCode()
{   
    return this->code;
}

int Reservation::getRow()
{
    return this->row;
}

int Reservation::getCol()
{
    return this->col;
}

char Reservation::getColAsChar()
{
    return char(this->col + 64);
}

bool Reservation::validateSeat(int row, int col)
{
    // cout << endl << "VALIDATING THE RESERVATION WITH ORIG : " << this->row << " - " << this->col << " - INPUT : " << row << " - " << col << endl; 
    return this->row == row && this->col == col;
}
