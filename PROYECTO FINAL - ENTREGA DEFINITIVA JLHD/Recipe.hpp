#ifndef RECIPE_HPP
#define RECIPE_HPP


#include <iostream>
#include <sstream>
#include <fstream>

#include "Ingredient.hpp"
#include "Name.hpp"
#include "SimpleLinkedList.hpp"

class Recipe
{
    private:
        SimpleLinkedList<Ingredient> ingList;
        std::string name;
        std::string type;
        std::string steps;
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
        void setIngredientList(SimpleLinkedList<Ingredient>);
        void setSteps(std::string);

        std::string getName();
        std::string getType();
        int getPrepTime();
        Name getAuthor();
        SimpleLinkedList<Ingredient> getIngredientList();
        std::string getSteps();

        std::string toString();
        std::string showAll();

        static int compareByName(const Recipe&, const Recipe&);
        static int compareByType(const Recipe&, const Recipe&);
        static int compareByPrepTime(const Recipe&, const Recipe&);

        Recipe& operator= (const Recipe&);

        friend std::ostream& operator<<(std::ostream&, const Recipe&);
        friend std::istream& operator>>(std::istream&, Recipe&);
};
#endif // RECIPE_HPP
