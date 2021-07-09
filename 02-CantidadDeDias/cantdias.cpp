#include <iostream>
#include <cassert>
using std::cout;
using std::cin;

//Function to insert month.
int insertMonth()
{
    int month;
    cout<<"Insert month between 1 and 12: \n";
    cin >> month;
    return (month >= 1 && month <= 12)? month : insertMonth();
}

//Function to insert year.
int insertYear()
{
    int year;
    cout<<"Insert year between 1583 and 3021: \n";
    cin >> year;
    return (year >= 1583 && year <= 3021)? year : insertYear();
}

//Function will return total number of days in case of leap year.
bool isLeapYear(int year)
{
    if((year%400==0) || (year%4==0 && year%100!=0))
        return true;
    else
        return false;
}

//Function will return total number of days.
int  getNumberOfDays(int month)
{
	//Leap year condition, if month is 2.
	if( month == 2)
    {
	    return isLeapYear(insertYear())? 29:28;
	}
	//Months which has 31 or 30 days.
	else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 ||month == 10 || month==12)
		return 31;
	else
		return 30;
}

//Function to response final message.
void response(int numberOfDays)
{
    cout<<"Number of days: "<< numberOfDays;
}

//Function to test isLeapYear functionality.
void testIsLeapYear()
{
    assert(isLeapYear(2000));
    assert(not isLeapYear(2019));
    assert(isLeapYear(1908));
    assert(not isLeapYear(1910));
    assert(isLeapYear(1584));
}

//Function to test getNumberOfDays functionality.
void testGetNumberOfDays()
{
    assert(31 == getNumberOfDays(1));
    assert(31 == getNumberOfDays(3));
    assert(30 == getNumberOfDays(4));
    assert(31 == getNumberOfDays(5));
    assert(30 == getNumberOfDays(6));
    assert(31 == getNumberOfDays(7));
    assert(31 == getNumberOfDays(8));
    assert(30 == getNumberOfDays(9));
    assert(31 == getNumberOfDays(10));
    assert(30 == getNumberOfDays(11));
    assert(31 == getNumberOfDays(12));
}

//Main program.
int main()
{
    {
        //Tests function isLeapYear
        testIsLeapYear();
        //Test function getNumberOfDays
        testGetNumberOfDays();
    }

    {
        //App
        int month=insertMonth();
        response(getNumberOfDays(month));
    }
}
