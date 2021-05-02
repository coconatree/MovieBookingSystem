/*
    Emre Caniklioglu
    21803577
    CS 201 HOMEWORK 03
*/

#include "include/Movie.h"

Movie::Movie()
{
    this->id = 1;
    this->radius = -17;

    this->numOfRow = -17;
    this->numOfCol = -17;

    this->size = -17;
    this->available = -17;
}   

Movie::Movie(long id, int r)
{
    this->id = id;
    this->radius = r;

    this->numOfRow = this->calculate(30);
    this->numOfCol = this->calculate(26);

    this->size = numOfRow * numOfCol;
    this->available = this->size;

    this->init();
    this->initDate();
    this->populate();

    this->resList.setDate(this->date);
}  

Movie::Movie(Movie& orig)
{   
    this->id = orig.id;
    this->radius = orig.radius;

    this->numOfRow = orig.numOfRow;
    this->numOfCol = orig.numOfCol;

    this->size = orig.size;
    this->available = orig.available;

    this->rowList = orig.rowList;
    this->colList = orig.colList;
}

Movie::~Movie()
{}

// Printing an info line about the Movie

void Movie::showInfo()
{
    // DEBUG 
    // cout << "MOVIE ID : " << this->id << endl;

    cout << "Movie at " << this->date << " (" << this->available << " available seats)" << endl;
}

// Printing the seating plan for the movie 

void Movie::showPlan()
{
    bool firstRow = true;
    bool firstCol = true;

    if(!(this->rowList.isEmpty()) && (!this->colList.isEmpty()))
    {
        int hook01 = 0;
        int hook02 = 0;

        int characterCounter = 2;
        int firstCharachter  = 0;

        int curRow = 0;
        int numTem = 0;

        int firstRow = 1;
        int additional = 0;
        
        int currentRow = 1;
        int currentCol = 1;

        this->colList.retrive(1, firstCharachter);

        cout << "Movie at " << this->date << " has " << this->available << " available seats" << endl;

        for(int i = 0; i < this->numOfRow; i++)
        {
            // i == 0 means that this is the first line to be printed

            if(i == 0)
            {
                 cout <<  "    " << char(firstCharachter + 64) << " ";

                this->colList.retrive(characterCounter, hook01);

                while(hook01 != firstCharachter)
                {
                    cout << "  " << char(hook01 + 64) << " ";
                    characterCounter++;
                    this->colList.retrive(characterCounter, hook01);
                }
                cout << endl;
            }

            cout << (firstRow + additional);

            if((firstRow + additional) % 10 != (firstRow + additional))
            {
                cout << " ";
            }
            else
            {
                cout << "  ";
            }

            for(int j = 0; j < this->numOfCol; j++)
            {
                if(this->resList.isReserved(currentRow, currentCol)) // arr[index].isReserved()
                {
                    cout << " x  ";
                }
                else
                {
                    cout << " o  ";
                }
                currentCol = currentCol + this->radius + 1;
            }
            currentCol = 1;
            
            currentRow = currentRow + this->radius + 1;

            cout << endl;

            additional = additional + this->radius + 1;
        }
        cout << endl;
    }
    else
    {
        cout << "Movie doesn't have any seats !!!" << endl;
    }
}

void Movie::showAddedInfo()
{
       cout << "Movie at " << this->date << " has been added" << endl;
}

// Adding a new reservation

int  Movie::addReservation(int row, int col, int code)
{
    if(this->resList.in(row, col, code))
    {
        cout << "Seat " << char(col + 64) << row << " is not available in Movie at " << this->date << endl;
        return -23;
    }
    else
    {
        if(this->resList.insert(1, row, col, code) == true)
        {
            this->available--;
            cout << "Reservation done for " << char(col + 64) << row << " in " << this->date << endl;
            return code;
        }
        else
        {
            return -23;
        }
    }
}

// Deleting a reservation

void Movie::delReservation(int code)
{
    if(this->resList.removeByCode(code))
    {
        this->available++;
    }
}

bool Movie::findReservation(int resCode)
{
    return this->resList.findByCode(resCode, true);
}

bool Movie::findReservationWithOutPrinting(int resCode)
{
    return this->resList.findByCode(resCode, false);
}

long Movie::getId()
{
    return this->id;
}

string Movie::getDate()
{
    return this->date;
}

// Initializing the int lists for row and column

void Movie::init()
{
    IntList list01;
    IntList list02;

    this->rowList = list01;
    this->colList = list02;

    // Initializeing the Reservation List

    ReservationListCustom list03;
    this->resList = list03;
}

// Initializing the date

void Movie::initDate()
{
    time_t curr_time;
    time(&curr_time);
    
    string with_new_line = ctime(&curr_time);

    this->date = with_new_line.substr(0, with_new_line.length() - 1);
}

void Movie::populate()
{
    int num  = 0;
    int rNum = 1;
    int cNum = 1;

    for(int i = 1; i <= this->numOfRow; i++)
    {
        for(int j = 1; j <= this->numOfCol; j++)
        {
            this->rowList.insert(i, rNum);
            this->colList.insert(j, cNum);
            num++;
            cNum = cNum + this->radius + 1;
        }
        cNum = 1;
        rNum = rNum + this->radius + 1;
    }
}

// Calculating the number of row and colunms needed

int Movie::calculate(int maxSize)
{
    int total = 0;
    int count = 0;

    while(total <= maxSize)
    {
        total++;
        count++;
        
        if(total + this->radius < maxSize)
        {
            total = total + this->radius;
        }
        else
        {
            return count;
        }   
    }
    return -17;
}

bool Movie::isAvailable(int row, int col)
{
    return this->rowList.in(row) && this->colList.in(col);
}