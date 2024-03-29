/*
    Emre Caniklioglu
    21803577
    CS 201 HOMEWORK 03
*/

#include <iostream>

using namespace std;

#include "include/MovieBookingSystem.h"

int main()
{
    MovieBookingSystem M;

    int* codes = new int[2];
    
    ReservationList RL;
    
    M.showAllMovies();
    
    cout << endl;
    
    M.addMovie(1614791273,0);
    M.addMovie(1614801273,3);
    M.addMovie(1615801273,1);
    
    cout << endl;
    
    M.showAllMovies();
    
    cout << endl;
    
    M.addMovie(1614791273,2);
    
    cout << endl;
    
    codes[1] = M.makeReservation(1614801273, 1, 'A');
    codes[0] = M.makeReservation(1614801273, 9, 'A');
    
    RL.insert(0, codes[0]);
    RL.insert(0, codes[1]);
    
    cout<<endl;
    
    M.showMovie(1614801273);
    
    cout<<endl;
    
    M.showReservation( codes[0] );
    
    cout<<endl;
    
    M.cancelReservations(RL);
    
    cout<<endl;
    
    codes[0] = M.makeReservation(1614801273,1,'A');
    
    M.makeReservation(1614801273,1,'A');
    M.makeReservation(1614801273,5,'E');
    M.makeReservation(1614801273,5,'M');
    
    cout<<endl;
    
    RL.remove(0);
    RL.remove(0);

    RL.insert(0, -1);
    RL.insert(0, codes[0] );
    
    M.cancelReservations(RL);
    M.showReservation( codes[0] );
    
    cout<<endl;
    
    M.makeReservation(1614801273,12,'D');
    
    cout<<endl;
    
    M.showMovie(1614801273);
    
    cout<<endl;
    
    M.cancelMovie(1614801273);
    M.showReservation( codes[0] );
    
    cout<<endl;
    
    M.cancelMovie(1614801273);
    M.addMovie(1614801273,4);
    M.showMovie(1614801273);
    
    delete [] codes;

    return 0;
}
