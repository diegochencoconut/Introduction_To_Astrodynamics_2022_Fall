#include "UTC_Date.h"
#include <iostream>
using namespace std;

UTC_Date::UTC_Date()
{
    year = 1900;
    month = 3;
    date = 1;
    hour = 0;
    minute = 0;
    second = 0;
}
UTC_Date::UTC_Date(int iyear, int imonth, int idate, int ihour, int iminute, int isecond)
{
    year = iyear;
    month = imonth;
    date = idate;
    hour = ihour;
    minute = iminute;
    second = isecond;
}

UTC_Date::UTC_Date(const UTC_Date &UTC_date)
{
    year = UTC_date.year;
    month = UTC_date.month;
    date = UTC_date.date;
    hour = UTC_date.hour;
    minute = UTC_date.minute;
    second = UTC_date.second;
}



UTC_Date& UTC_Date::operator= (const UTC_Date &UTC_date)
{
    if (this != &UTC_date)
    {
        year = UTC_date.year;
        month = UTC_date.month;
        date = UTC_date.date;
        hour = UTC_date.hour;
        minute = UTC_date.minute;
        second = UTC_date.second;
    }

    return *this;
}

ostream& operator<< (ostream& out, const UTC_Date date)
{
    out << date.year << "/" << date.month << "/" << date.date << "/" << date.hour << "/" << date.minute << "/" << date.second << endl;
    return out;
}

bool UTC_Date::isBefore(UTC_Date ref)
{
    if (year < ref.year)    return true;
    if (year > ref.year)    return false;

    if (month < ref.month)  return true;
    if (month > ref.month)  return false;
    
    if (date < ref.date)    return true;
    if (date > ref.date)    return false;

    if (hour < ref.hour)    return true;
    if (hour > ref.hour)    return false;

    if (minute < ref.minute)    return true;
    if (minute > ref.minute)    return false;
    
    if (second < ref.second)    return true;
    else return false;
}

bool UTC_Date::isJulian()
{
    UTC_Date Gregorian_start(1582, 10, 15, 0, 0, 0);
    return (isBefore(Gregorian_start));
}

long double UTC2JD(UTC_Date UTC_date)       //UTC to Julian date
{
    // Using Meeus Algorithm
    int year = UTC_date.getYear();
    int month = UTC_date.getMonth();
    if (year < 0)   year = year + 1;
    if (month <= 2)
    {
        year = year - 1;
        month = month + 12;
    }
    int B;
    if (UTC_date.isJulian()) B = 0;
    else B = 2 - static_cast<int>(year / 100.0) + static_cast<int>(static_cast<int>(year / 100.0) / 4.0);
    long long JD1 = static_cast<long long int>(365.25 * (year + 4716));
    long long JD2 = static_cast<long long int>(30.6001 * (month + 1));
    long long JD3 = UTC_date.getDate();
    double JD4 = ((UTC_date.getSecond() / 60.0 + UTC_date.getMinute()) / 60.0 + UTC_date.getHour()) / 24.0;
    long double JD = JD1 + JD2 + JD3 + B - 1524.5 + JD4;
    return JD;
}

UTC_Date JD2UTC(long double JD)     //Julian date to UTC
{
    long long int J = static_cast<long long int>(JD + 0.5);
    long long int N = static_cast<long long int>(4.0 * (J + 68569) / 146097.0);
    long long int L1 = J + 68569 - static_cast<long long int>((146097.0 * N + 3.0) / 4.0);
    long long int Y1 = static_cast<long long int>(4000.0 * (L1 + 1.0) / 1461001.0);
    long long int L2 = L1 - static_cast<long long int>(1461.0 * Y1 / 4.0) + 31;
    long long int M1 = static_cast<long long int>(80.0 * L2 / 2447.0);
    int D = L2 - static_cast<int>(2447.0 * M1 / 80.0);
    long long int L3 = static_cast<long long int>(M1 / 11.0);
    int M = M1 + 2 - 12 * L3;
    int Y = static_cast<int>(100.0 * (N - 49.0) + Y1 + L3);

    UTC_Date result(Y, M, D, 0, 0, 0);
    return result;
}