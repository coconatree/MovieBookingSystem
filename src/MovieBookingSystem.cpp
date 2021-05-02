/*
    Emre Caniklioglu
    21803577
    CS 201 HOMEWORK 03
*/

#include "include/MovieBookingSystem.h" 

MovieBookingSystem::MovieBookingSystem()
{
    this->reservationIdInitial = 0;
    
    MovieList m1;

    this->movieList = m1;

    IntList idList;

    this->movieIdList = idList;
}

MovieBookingSystem::~MovieBookingSystem(){}

void MovieBookingSystem::addMovie(const long movieID, const int audienceRadius)
{
    if(!this->movieIdList.in(movieID))
    {
        this->movieList.insert(1, movieID, audienceRadius);
        this->movieList.showHead();
        this->movieIdList.insert(1, movieID);
    }
    else
    {
        cout << "Movie with the ID : " << movieID << " already exists" << endl;
    }
}

void MovieBookingSystem::cancelMovie(const long movieID)
{
    if(this->movieIdList.in(movieID))
    {
        this->movieList.removeById(movieID);
        this->movieIdList.removeById(movieID);
    }
    else
    {
        cout << "Movie with the id : " << movieID << " does not exist" << endl;
    }
}

void MovieBookingSystem::showAllMovies() const
{
    if(this->movieList.isEmpty())
    {
        cout << "No movie on show" << endl;
    }
    else
    {
        this->movieList.showAll();
    }
}   

void MovieBookingSystem::showMovie(const long movieID) const
{
    if(this->movieIdList.in(movieID))
    {
        this->movieList.show(movieID);    
    }
    else
    {
        cout << "Movie with the id : " << movieID << " does not exist" << endl;
    }
}

int MovieBookingSystem::makeReservation(const long movieID, const int row, const char col)
{
    return this->movieList.addReservation(movieID, row, col, this->generateReservationId());
}

void MovieBookingSystem::cancelReservations(ReservationList resCodes)
{
    // cout << "Printing !!! " << endl;
    // resCodes.printLn();

    if(this->movieList.allExist(resCodes))
    {
        this->movieList.deleteAllReservations(resCodes);
    }
    else
    {
        cout << "Some reservation codes do not exist. Cancelation is failed" << endl;
    }
}

void MovieBookingSystem::showReservation(const int resCode) const
{
    this->movieList.showReservation(resCode);
}

int MovieBookingSystem::generateReservationId()
{
    this->reservationIdInitial = this->reservationIdInitial + 1; 
    return this->reservationIdInitial;
}