#ifndef RECIPE_HPP
#define RECIPE_HPP

#include <iostream>
#include <string>

#include "List.hpp"
#include "Ingredient.hpp"
#include "Name.hpp"

class Recipe
{
    private:
        List<Ingredient> ingList;
        List<std::string> stepList;
        std::string name;
        std::string type;
        int prepTime;
        Name author;

        std::string formatData(std::string Data);

    public:
        Recipe();
        Recipe(const Recipe&);
        Recipe(std::string, std::string, int, Name);

        void setName(std::string);
        void setType(std::string);
        void setPrepTime(int);
        void setAuthor(Name);
        void setIngredientList(List<Ingredient>);
        void setStepsList(List<std::string>);

        std::string getName();
        std::string getType();
        int getPrepTime();
        Name getAuthor();
        List<Ingredient> getIngredientList();
        List<std::string> getStepsList();

        std::string toString();
        std::string showAll();

        static int compareByName(const Recipe&, const Recipe&);
        static int compareByType(const Recipe&, const Recipe&);
        static int compareByPrepTime(const Recipe&, const Recipe&);

        Recipe& operator= (const Recipe&);

        friend std::ostream& operator<<(std::ostream&, Recipe&);
        friend std::istream& operator>>(std::istream&, Recipe&);
};

#endif // RECIPE_HPP
