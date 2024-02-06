#include "Date.hpp"

using namespace std;

int Date::toInt() const
{
    return year * 10000 + month * 100 + day;
}

Date::Date() {}

Date::Date(const Date& d) : year(d.year), month(d.month), day(d.day) {}

Date& Date::operator=(const Date& d)
{
    if (this != &d)
        {
            year = d.year;
            month = d.month;
            day = d.day;
        }
    return *this;
}

int Date::getYear() const
{
    return year;
}

int Date::getMonth() const
{
    return month;
}

int Date::getDay() const
{
    return day;
}

string Date::toString() const
{
    return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

void Date::setYear(const int& y)
{
    year = y;
}

void Date::setMonth(const int& m)
{
    month = m;
}

void Date::setDay(const int& d)
{
    day = d;
}

bool Date::operator==(const Date& d) const
{
    return toInt() == d.toInt();
}

bool Date::operator!=(const Date& d) const
{
    return toInt() != d.toInt();
}

bool Date::operator<(const Date& d) const
{
    return toInt() < d.toInt();
}

bool Date::operator>(const Date& d) const
{
    return toInt() > d.toInt();
}

bool Date::operator<=(const Date& d) const
{
    return toInt() <= d.toInt();
}

bool Date::operator>=(const Date& d) const
{
    return toInt() >= d.toInt();
}
