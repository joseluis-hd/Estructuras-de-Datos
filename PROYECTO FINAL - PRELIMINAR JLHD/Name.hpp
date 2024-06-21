#ifndef NAME_HPP
#define NAME_HPP

#include <iostream>
#include <sstream>
#include <fstream>

class Name
{
    private:
        std::string name;
        std::string lastName;

    public:
        Name();
        Name(const Name&);
        Name(std::string, std::string);

        void setName(std::string);
        void setLastName(std::string);

        std::string getName();
        std::string getLastName();

        std::string toString();

        Name& operator = (const Name&);

        bool operator == (Name&);
        bool operator != (Name&);
        bool operator < (Name&);
        bool operator > (Name&);
        bool operator <= (Name&);
        bool operator >= (Name&);

        friend std::ostream& operator<<(std::ostream&, const Name&);
        friend std::istream& operator>>(std::istream&, Name&);
};

#endif // NAME_HPP
