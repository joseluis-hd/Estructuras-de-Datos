// Menu.cpp
#include "Menu.hpp"
#include <iostream>
#include <string>

using namespace std;

Menu::Menu(List<Recipe>* _recipeBook) {
    recipeBook = _recipeBook;
}

void Menu::interfaz() {
    int op1 = 0;

    while (op1 != 9) {
        cout << "========== RECETARIO ==========" << endl;
        cout << " 1.- Mostrar recetario." << endl;
        cout << " 2.- Añadir receta." << endl;
        cout << " 3.- Buscar receta." << endl;
        cout << " 4.- Eliminar receta." << endl;
        cout << " 5.- Eliminar recetario." << endl;
        cout << " 6.- Ordenar recetario." << endl;
        cout << " 7.- Guardar recetario en el disco." << endl;
        cout << " 8.- Cargar recetario desde el disco." << endl;
        cout << " 9.- Salir." << endl;
        cout << " Seleccione una opción: ";
        cin >> op1;
switch (op1) {
            case 1: {

                cout << "========== RECETARIO ==========" << endl;
                if (recipeBook.isEmpty()) {
                    cout << "Recetario vacío" << endl;
                } else {
                    cout << recipeBook.toString() << endl;
                }
                cout << "Enter para regresar al menú." << endl;
                cin.ignore();
                cin.get();
                break;
            }

            case 2: {

                cout << "========== RECETARIO ==========" << endl;
                cout << "Nombre del platillo: ";
                cin.ignore();
                getline(cin, rName);
                cout << "  1. Desayuno \n  2. Comida \n  3. Cena \n Seleccione una opción: ";
                cin >> type;
                cout << "Tiempo de preparación (min): ";
                cin >> prepTime;
                cout << "AUTOR: " << endl;
                cout << "Nombre: ";
                cin.ignore();
                getline(cin, aName);
                cout << "Apellidos: ";
                getline(cin, aLastName);

                author.setName(aName);
                author.setLastName(aLastName);

                auxRecipe.setName(rName);

                if (type == 1)
                    {
                        auxRecipe.setType("Desayuno");
                    } else if (type == 2)
                    {
                        auxRecipe.setType("Comida");
                    } else if (type == 3)
                    {
                        auxRecipe.setType("Cena");
                    } else
                    {
                        auxRecipe.setType("Comida");
                    }

                auxRecipe.setAuthor(author);
                auxRecipe.setPrepTime(prepTime);

                ingList.deleteAll();

                cout << " \n Ingredient List (enter '0' in the name to exit) . . . " << endl;
                while (iName != "0") {
                    cout << "Ingrediente: ";
                    getline(cin, iName);
                    if (iName != "0") {
                        cout << "Cantidad: ";
                        cin >> iQuantity;
                        cout << "Medida: ";
                        cin.ignore();
                        getline(cin, iMeasurement);
                        auxIngredient.setName(iName);
                        auxIngredient.setQuantity(iQuantity);
                        auxIngredient.setMeasurement(iMeasurement);
                        ingList.insertData(0, auxIngredient);
                    }
                }
                auxRecipe.setIngredientList(ingList);
                iName = "";

                stepList.deleteAll();

                cout << " \n Step List (type '0' to exit) . . . " << endl;
                while (steps != "0") {
                    cout << "  " << cont+1 << ".- ";
                    getline(cin, steps);
                    if (steps != "0") {
                        stepList.insertData(cont, steps);
                    }
                    cont++;
                }
                auxRecipe.setStepsList(stepList);
                steps = "";
                cont = 0;

                cout << " \n Enter the insertion position: ";
                cin  >> pos;

                recipeBook.insertData(pos, auxRecipe);
                cout << " Recipe added successfully." << endl;

                cout << " Press Enter to return . . . " << endl;
                cin.ignore();
                cin.get();
                break;
            }

            case 3: {

                cout << " - - - - - - - S E A R C H   R E C I P E - - - - - - - " << endl;
                if (recipeBook.isEmpty()) {
                    cout << " The recipe book is empty." << endl;
                    cout << " Press Enter to return . . . " << endl;
                    cin.ignore();
                    cin.get();
                    break;
                }

                wasFound = false;
                cout << " Please note that the list will be sorted under the same search parameter." << endl;
                cout << " 1. Search by name " << endl;
                cout << " 2. Search by category " << endl;
                cout << " Select an option: ";
                cin >> op2;

                if (op2 == 1) {
                    recipeBook.quickSort(Recipe::compareByName);
                    cout << "\n Enter the name of the dish: ";
                    cin.ignore();
                    getline(cin, rName);
                    auxRecipe.setName(rName);

                    pos = recipeBook.findData(auxRecipe, Recipe::compareByName);
                    if (pos != -1) {
                        auxRecipe = recipeBook.retrieve(pos);
                        cout << " Recipe found: \n\n " << auxRecipe.showAll() << endl;
                        wasFound = true;
                    } else {
                        cout << " Recipe not found." << endl;
                    }

                } else if (op2 == 2) {
                    recipeBook.quickSort(Recipe::compareByType);
                    cout << "\n Select the category of the dish . . . " << endl;
                    cout << " 1. Breakfast \n 2. Lunch \n 3. Dinner / Christmas " << endl;
                    cout << " Select an option: ";
                    cin >> type;

                    if (type == 1) {
                        auxType = "Breakfast";
                    } else if (type == 2) {
                        auxType = "Lunch";
                    } else if (type == 3) {
                        auxType = "Dinner / Christmas";
                    }

                    auxRecipe.setType(auxType);

                    pos = recipeBook.findData(auxRecipe, Recipe::compareByType);
                    if (pos != -1) {
                        auxRecipe = recipeBook.retrieve(pos);
                        cout << " Recipe found: \n\n " << auxRecipe.showAll() << endl;
                        wasFound = true;
                    } else {
                        cout << " No recipes of this type exist." << endl;
                    }
                }

                if (wasFound) {
                    cout << " \n 1. End Search \n 2. Make modifications \n Select an option: ";
                    cin >> op3;

                    if (op3 == 2) {
                        cout << "  \n Menu of Modifications: " << endl;
                        cout << "  1. Add ingredient " << endl;
                        cout << "  2. Delete ingredient" << endl;
                        cout << "  3. Modify quantity of an ingredient " << endl;
                        cout << "  4. Add step " << endl;
                        cout << "  5. Delete step " << endl;
                        cout << "  6. Cancel " << endl;
                        cout << "  Select an option: ";
                        cin >> op4;

                        switch (op4) {
                            case 1: // Add Ingredient
                                cout << " Name of the new ingredient: ";
                                cin.ignore();
                                getline(cin, iName);
                                cout << " Quantity of the new ingredient: ";
                                cin >> iQuantity;
                                cout << " Measurement unit of the new ingredient: ";
                                cin.ignore();
                                getline(cin, iMeasurement);

                                auxIngredient.setName(iName);
                                auxIngredient.setQuantity(iQuantity);
                                auxIngredient.setMeasurement(iMeasurement);

                                ingList = auxRecipe.getIngredientList();
                                ingList.insertData(0, auxIngredient);

                                auxRecipe.setIngredientList(ingList);
                                recipeBook.deleteData(pos);
                                recipeBook.insertData(pos, auxRecipe);

                                break;

                            case 2: // Delete Ingredient
                                cout << " Enter the name of the ingredient to delete: ";
                                cin.ignore();
                                getline(cin, iName);
                                auxIngredient.setName(iName);

                                ingList = auxRecipe.getIngredientList();
                                pos2 = ingList.findData(auxIngredient, Ingredient::compareByName);

                                if (pos2 != -1) {
                                    ingList.deleteData(pos2);
                                    auxRecipe.setIngredientList(ingList);
                                    recipeBook.deleteData(pos);
                                    recipeBook.insertData(pos, auxRecipe);
                                    cout << " Ingredient " << iName << " found and deleted." << endl;
                                } else {
                                    cout << " The ingredient does not exist in the recipe." << endl;
                                }
                                break;

                            case 3: // Modify Ingredient
                                cout << " Enter the name of the ingredient to modify: ";
                                cin.ignore();
                                getline(cin, iName);
                                auxIngredient.setName(iName);

                                ingList = auxRecipe.getIngredientList();
                                pos2 = ingList.findData(auxIngredient, Ingredient::compareByName);

                                if (pos2 != -1) {
                                    auxIngredient = ingList.retrieve(pos2);
                                    cout << "  Ingredient found: " << endl;
                                    cout << "  " << auxIngredient.toString();

                                    cout << "  Enter the new quantity: ";
                                    cin >> iQuantity;

                                    auxIngredient.setQuantity(iQuantity);

                                    ingList.deleteData(pos2);
                                    ingList.insertData(pos2, auxIngredient);

                                    auxRecipe.setIngredientList(ingList);
                                    recipeBook.deleteData(pos);
                                    recipeBook.insertData(pos, auxRecipe);
                                } else {
                                    cout << " The ingredient does not exist in the recipe." << endl;
                                }
                                break;

                            case 4: // Add Step
                                cout << "\n Enter the position where the new step will be: ";
                                cin >> pos2;

                                cout << " Write the new step: ";
                                cin.ignore();
                                getline(cin, steps);

                                stepList = auxRecipe.getStepsList();
                                stepList.insertData(pos2 - 1, steps);

                                auxRecipe.setStepsList(stepList);
                                recipeBook.deleteData(pos);
                                recipeBook.insertData(pos, auxRecipe);

                                break;

                            case 5: // Delete Step
                                cout << "\n Enter the step # to delete: ";
                                cin >> pos2;

                                stepList = auxRecipe.getStepsList();
                                stepList.deleteData(pos2 - 1);

                                auxRecipe.setStepsList(stepList);
                                recipeBook.deleteData(pos);
                                recipeBook.insertData(pos, auxRecipe);

                                break;

                            case 6:
                                break;

                            default:
                                cout << " Select a valid option." << endl;
                                break;
                        }
                    }
                }

                cout << " Press Enter to return . . . " << endl;
                cin.ignore();
                cin.get();


                break;
            }

            case 4: {

                cout << " - - - - - - - D E L E T E   R E C I P E - - - - - - - " << endl;
                if (recipeBook.isEmpty()) {
                    cout << " The recipe book is empty." << endl;
                    cout << " Press Enter to return . . . " << endl;
                    cin.ignore();
                    cin.get();
                    break;
                }

                recipeBook.quickSort(Recipe::compareByName);

                cout << " Enter the name of the recipe to delete: ";
                cin.ignore();
                getline(cin, rName);

                auxRecipe.setName(rName);

                pos = recipeBook.findData(auxRecipe, Recipe::compareByName);
                if (pos != -1) {
                    rName = recipeBook.retrieve(pos).getName();
                    recipeBook.deleteData(pos);
                    cout << " Recipe " << rName << " found and deleted." << endl;
                } else {
                    cout << " The recipe does not exist in the registry." << endl;
                }

                cout << " Press Enter to return . . . " << endl;
                cin.ignore();
                cin.get();


                break;
            }

            case 5: {

                cout << " - - - - - - - T O T A L   D E L E T I O N - - - - - - - " << endl;
                cout << " The Recipe Book will be completely deleted." << endl;
                cout << " 1. Confirm \n 2. Cancel \n Confirm: " << endl;
                cin >> op2;

                if (op2 == 1) {
                    recipeBook.deleteAll();
                    cout << " Recipe book deleted." << endl;
                } else if (op2 == 2) {
                    cout << " The Recipe Book will not be deleted." << endl;
                }

                cout << " Press Enter to return . . . " << endl;
                cin.ignore();
                cin.get();


                break;
            }

            case 6: {

                cout << " - - - - - - - - O R D E R - - - - - - - - " << endl;

                if (recipeBook.isEmpty()) {
                    cout << " The recipe book is empty." << endl;
                    cout << " Press Enter to return . . . " << endl;
                    cin.ignore();
                    cin.get();
                    break;
                }

                cout << " 1. Sort by name " << endl;
                cout << " 2. Sort by category " << endl;
                cout << " 3. Sort by preparation time " << endl;
                cout << " Select an option: ";
                cin >> op2;

                if (op2 == 1) {
                    recipeBook.quickSort(Recipe::compareByName);
                } else if (op2 == 2) {
                    recipeBook.quickSort(Recipe::compareByType);
                } else if (op2 == 3) {
                    recipeBook.quickSort(Recipe::compareByPrepTime);
                }

                cout << " Sorted list, press Enter to continue . . . " << endl;
                cin.ignore();
                cin.get();


                break;
            }

            case 7: {

                cout << " - - - - - - S A V E   T O   D I S K - - - - - - " << endl;

                if (recipeBook.isEmpty()) {
                    cout << " There are no recipes to save." << endl;
                    cout << " \n Press Enter to return . . . " << endl;
                    cin.ignore();
                    cin.get();
                    break;
                }

                cout << " Writing recipe book to disk . . ." << endl;
                recipeBook.writeToDisk("recipebook.txt");
                cout << " The recipe book has been successfully backed up." << endl;

                cout << " \n Press Enter to return . . . " << endl;
                cin.ignore();
                cin.get();


                break;
            }

            case 8: {

                cout << " - - - - - - I M P O R T   F R O M   D I S K - - - - - - " << endl;
                cout << " Reading from disk . . ." << endl;
                recipeBook.readFromDisk("recipebook.txt");

                cout << " Recipe book contents: " << endl;
                while (i <= recipeBook.getLastPos()) {
                    cout << recipeBook.retrieve(i).toString() << endl;
                    i++;
                }
                i = 0;

                cout << " \n Press Enter to return . . . " << endl;
                cin.ignore();
                cin.get();


                break;
            }

            case 9:
                cout << " Exiting the program . . ." << endl;
                break;

            default:
                cout << " Select a valid option." << endl;
                cout << " Press Enter to return . . . " << endl;
                cin.ignore();
                cin.get();

                break;
        }
    }
    return 0;
    }
}
