#include <iostream>
#include <iomanip>
#include "UTC_Date.h"
using namespace std;

long double UTC2JD(UTC_Date UTC_date);
UTC_Date JD2UTC(long double JD);

int main()
{
    int year, month, date, hour, minute;
    float second;
    cin >> year >> month >> date >> hour >> minute >> second;
    UTC_Date UTC_date(year, month, date, hour, minute, second);
    cout << UTC_date << endl;

    long double jd;
    cin >> jd;
    cout << JD2UTC(jd) << endl;
    return 0;   
}