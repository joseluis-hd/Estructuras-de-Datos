#ifndef DATE_HPP
#define DATE_HPP

#include <iostream>

class Date
{
    private:
        int year;
        int month;
        int day;

        int toInt() const;

    public:
        Date();
        Date(const Date&);

        int getYear() const;
        int getMonth() const;
        int getDay() const;

        std::string toString() const;

        void setYear(const int&);
        void setMonth(const int&);
        void setDay(const int&);

        bool operator == (const Date&) const;
        bool operator != (const Date&) const;
        bool operator < (const Date&) const;
        bool operator <= (const Date&) const;
        bool operator > (const Date&) const;
        bool operator >= (const Date&) const;

        Date& operator = (const Date&);

        friend std::ostream& operator <<(std::ostream&, const Date&);
        friend std::istream& operator >>(std::istream&, Date&);
};

#endif // DATE_HPP
