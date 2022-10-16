# UTC_Date.h

## Parameters
| variable name | Type | Description |
| :-----------: | :--: | :---------: |
|      year     | int  |    Year (A.D. 1 should be -1)      |
|     month     | int  |   Month (1 ~ 12, January = 1)      |
|      date     | int  |   Day(1 ~ 31, depends on month)    |
|      hour     | int  |    Hour (0 ~ 23)                   |
|     minute    | int  |    Minute (0 ~ 59)                 |
|     second    | double  |    Second (0 $\leq$ second < 60)|

> Warning: Not regulated input may cause unknown output or corruption

## Functions

### Constructor

**UTC_Date();**

Empty Constructor, will save the date as March 1st, 1970, 00:00:00

**UTC_Date(int year, int month, int date, int hour, int minute, double second);**

Save the date as "year/month/date/hour/minute/second"

**UTC_Date(const UTC_Date &UTC_date);**

Pass an existed *UTC_Date* object to construct another *UTC_Date* object

### Getter

All variables have getters. The return type are same as there datatype. No parameters needed.

- getYear();       (A.D. 1 will be -1, 0 has no meaning)
- getMonth();      (will return 1 ~ 12)
- getDate();
- getHour();
- getMinute();
- getSecond();

### Setter
All variable have setters. The input type should be same as datatype mentioned before.

- setYear(int year); (A.D. 1 will be -1, 0 has no meaning)
- setMonth(int month); **Please use 1 to 12**
- setDate(int date);
- setHour(int hour);
- setMinute(int minute);
- setSecond(double second);

> Attention: Please input existed days. Otherwise, the program may have unexpected output. <br>
> For example, please do not input *April 31, 2025*

### Operators
Two operators have been implemented: assignment operator (=) and output operator (<<)

#### Operator = 
Will copy value from RHS object to LHS object

#### Operator <<
Will output *year/month/date/hour/minute/second*

### Member Functions

#### isBefore(UTC_Date UTC_date)
- return type: bool <br>
Return true if the calling object is before *UTC_date*<br>
Return false else (Including equal)

#### isJulian()
- return type: bool <br>
Check if the calling object's day is still using Julian Calendar<br>
*(Julian Calendar is used before 1582/10/15)*

### Other Functions
#### UTC2JD(UTC_Date UTC_date)
- return type: long double <br>
Convert UTC_date to Julian Date using Meeus's algorithm

#### JD2UTC(long double JD)
- return type: UTC_Date <br>
Convert Julian Date to UTC_Date