#include <iostream>
using namespace std;

class UTC_Date
{
public:
    UTC_Date();
    UTC_Date(int year, int month, int date, int hour, int minute, int second);
    UTC_Date(const UTC_Date &UTC_date);

    void setYear(int iyear){year = iyear;}
    void setMonth(int imonth){month = imonth;}
    void setDate(int idate){date = idate;}
    void setHour(int ihour){hour = ihour;}
    void setMinute(int iminute){minute = iminute;}
    void setSecond(double isecond){second = isecond;}

    int getYear(){return year;}
    int getMonth(){return month;}
    int getDate(){return date;}
    int getHour(){return hour;}
    int getMinute(){return minute;}
    double getSecond(){return second;}

    UTC_Date& operator= (const UTC_Date &UTC_date);
    friend ostream& operator<< (ostream& out, const UTC_Date date);

    bool isBefore(UTC_Date UTC_date);   //return if the day is before UTC_date
    bool isJulian();                    //return if is Julian Calendar

private:
    int year;
    int month;
    int date;
    int hour;
    int minute;
    double second;
};

// date conversion
long double UTC2JD(UTC_Date UTC_date);
UTC_Date JD2UTC(long double JD);