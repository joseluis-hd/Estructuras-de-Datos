#ifndef MENU_HPP
#define MENU_HPP

#include "List.hpp"
#include "Recipe.hpp"

class Menu {
private:
    List<Recipe>* recipeBook;

public:
    Menu(List<Recipe>* _recipeBook);
    void interfaz();
};

#endif // MENU_HPP
