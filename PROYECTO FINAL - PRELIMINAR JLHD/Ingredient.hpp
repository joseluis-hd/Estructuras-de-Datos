#ifndef INGREDIENT_HPP
#define INGREDIENT_HPP

#include <iostream>
#include <sstream>
#include <fstream>

class Ingredient
{
    private:
        std::string name;
        std::string measeure;
        float quantity;

    public:
        Ingredient();
        Ingredient(const Ingredient&);
        Ingredient(std::string, std::string, float);

        void setName(std::string);
        void setMeasurement(std::string);
        void setQuantity(float);

        std::string getName();
        std::string getMeasure();
        float getQuantity();

        std::string toString();

        static int compareByName(const Ingredient&, const Ingredient&);

        Ingredient& operator = (const Ingredient&);

        bool operator == (const Ingredient&);
        bool operator != (const Ingredient&);
        bool operator < (const Ingredient&);
        bool operator <= (const Ingredient&);
        bool operator > (const Ingredient&);
        bool operator >= (const Ingredient&);

        friend std::ostream& operator<<(std::ostream&, const Ingredient&);
        friend std::istream& operator>>(std::istream&, Ingredient&);
};
#endif // INGREDIENT_HPP
