/*
    Emre Caniklioglu
    21803577
    CS 201 HOMEWORK 03
*/

#ifndef MOVIE_BOOKING_SYSTEM_H
#define MOVIE_BOOKING_SYSTEM_H

#include "MovieList.h"
#include "ReservationList.h"


class MovieBookingSystem
{

public:

    const static int numOfRow = 30;
    const static int numOfColumn = 26;

    MovieBookingSystem();
    
    ~MovieBookingSystem();

    void addMovie( const long movieID, const int audienceRadius );
    
    void cancelMovie( const long movieID);

    void showAllMovies() const;
    void showMovie( const long movieID) const;
    
    int makeReservation( const long movieID, const int row, const char col);
    
    void cancelReservations(ReservationList resCodes);
    void showReservation( const int resCode) const;

private:

    MovieList movieList;

    IntList movieIdList;

    int  generateReservationId();
    int  reservationIdInitial;
};

#endif