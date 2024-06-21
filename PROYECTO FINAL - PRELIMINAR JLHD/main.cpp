#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "Ingredient.hpp"
#include "Recipe.hpp"
#include "Name.hpp"
#include "List.hpp"

using namespace std;

int main()
{
    setlocale(LC_CTYPE, "spanish");

    List<Recipe> recipeBook, copyBook;
    List<string> stepList;
    Recipe auxRecipe;
    string recName, steps("");
    int prepTime, type;

    List<Ingredient> ingList;
    Ingredient auxIngredient;
    string iName(""), iMeasurement;
    float iQuantity(1);

    Name author;
    string aName, aLastName;

    int op1 = 0, op2 = 0, op3 = 0, op4 = 0, cont = 0, i = 0, pos = 0, pos2 = 0;
    bool wasFound = false;
    string auxType, data;

    while (op1 != 9)
    {
        cout << "=============== RECETARIO ===============" << endl;
        cout << "1.- Mostrar recetario." << endl;
        cout << "2.- Añadir receta." << endl;
        cout << "3.- Buscar receta." << endl;
        cout << "4.- Eliminar receta." << endl;
        cout << "5.- Eliminar recetario." << endl;
        cout << "6.- Ordenar recetario." << endl;
        cout << "7.- Guardar recetario en el disco." << endl;
        cout << "8.- Cargar recetario desde el disco." << endl;
        cout << "9.- Salir." << endl;
        cout << "Seleccione una opción: ";
        cin  >> op1;

        switch (op1)
        {
            case 1:
                system("cls");
                cout << "=============== LISTA DE RECETAS ===============" << endl;

                if (recipeBook.isEmpty())
                {
                    cout << "Recetario vacío..." << endl;
                    cout << "Presione enter para continuar..." << endl;
                    getline(cin, data); getline(cin, data);
                    system("cls");
                    break;
                }

            op2 = 0;
            while (op2 < 1 or op2 > 4)
            {
                while (i <= recipeBook.getLastPos())
                {
                    cout << recipeBook.retrieve(i).toString() << endl;
                    i++;
                }
                i = 0;
                cout << " \n 1.- Desayuno \n 2.- Comida \n 3.- Cena \n 4.- Volver" << endl;
                cout << " Seleccione una opción: "; cin >> op2;
            }

            if (op2 == 1)
            {
                auxType = "Desayuno";
            } else if (op2 == 2)
            {
                auxType = "Comida";
            } else if (op2 == 3)
            {
                auxType = "Cena";
            } else if (op2 == 4)
            {
                system("cls");
                break;
            }

            auxRecipe.setType(auxType);

            system("cls");
            cout << "=============== LISTA DE RECETAS ===============" << endl;

            while (i <= recipeBook.getLastPos())
            {
                if (recipeBook.retrieve(i).getType() == auxRecipe.getType())
                {
                    cout << recipeBook.retrieve(i).toString() << endl;
                }
                i++;
            }
            auxType = "";
            i = 0;
            cout << " \n\nPresione enter para continuar..." << endl;
            getline(cin, data); getline(cin, data);
            system("cls");
            break;

        case 2:
            system("cls");
            cout << "=============== AGREGAR RECETA ===============" << endl;
            cout << "Nombre del platillo: "; getline(cin, recName); getline(cin, recName);
            cout << "  1.- Desayuno \n  2.- Comida \n  3.- Cena \n Seleccione una opción: "; cin >> type;
            cout << "Tiempo de preparacion (min): "; cin >> prepTime;
            cout << "===== CHEF =====" << endl;
            cout << "Nombre: "; getline(cin, aName); getline(cin, aName);
            cout << "Apellido: "; getline(cin, aLastName);

            author.setName(aName);
            author.setLastName(aLastName);

            auxRecipe.setName(recName);

            if (type == 1)
            {
                auxRecipe.setType("Desayuno");
            }
            else if (type == 2)
            {
                auxRecipe.setType("Comida");
            }
            else if (type == 3)
            {
                auxRecipe.setType("Cena");
            }
            else
            {
                auxRecipe.setType("Comida");
            }

            auxRecipe.setAuthor(author);
            auxRecipe.setPrepTime(prepTime);

            ingList.deleteAll();

            cout << "\nLista de ingredientes (Ingrese '0' para salir)" << endl;
            while (iName != "0")
            {
                cout << "Ingrediente: "; getline(cin, iName);

                if (iName != "0")
                {
                    cout << "Cantidad: "; cin >> iQuantity;
                    cout << "Medida: "; getline(cin, iMeasurement); getline(cin, iMeasurement);
                    auxIngredient.setName(iName);
                    auxIngredient.setQuantity(iQuantity);
                    auxIngredient.setMeasurement(iMeasurement);
                    ingList.insertData(0, auxIngredient);
                }
            }
            auxRecipe.setIngredientList(ingList);
            iName = "";

            stepList.deleteAll();

            cout <<  "\nPreparación: (Ingrese '0' para salir)..." << endl;
            while (steps != "0")
            {
                cout << "  " << cont+1 << ".- "; getline(cin, steps);
                if (steps != "0")
                {
                    stepList.insertData(cont, steps);
                }
                cont++;
            }
            auxRecipe.setStepsList(stepList);
            steps = "";
            cont = 0;

            cout << "\nIngrese la posición donde desea insertar: ";
            cin  >> pos;
            recipeBook.insertData(pos, auxRecipe);
            cout << "Receta añadida correctamente." << endl;
            cout << "Presione enter para continuar..." << endl;
            getline(cin, data);
            system("cls");
            break;

        case 3:
            system("cls");
            cout << "=============== BUSCAR RECETAS ===============" << endl;

            if (recipeBook.isEmpty()) {
                cout << "Recetario vacío" << endl;
                cout << "Presione enter para continuar..." << endl;
                getline(cin, data); getline(cin, data);
                system("cls");
                break;
            }

            wasFound = false;
            cout << "1.- Buscar por nombre " << endl;
            cout << "2.- Buscar por categoria " << endl;
            cout <<  "Seleccione una opción: "; cin >> op2;

            if (op2 == 1)
            {
                recipeBook.quickSort(Recipe::compareByName);
                cout << "\nNombre del platillo: ";
                getline(cin, recName); getline(cin, recName);
                auxRecipe.setName(recName);

                if (recipeBook.findData(auxRecipe, Recipe::compareByName) != -1)
                {
                    pos = recipeBook.findData(auxRecipe, Recipe::compareByName);
                    auxRecipe = recipeBook.retrieve(pos);
                    cout << "Receta encontrada: \n\n " << auxRecipe.showAll() << endl;
                    wasFound = true;
                } else
                {
                    cout << "No se encontró la receta." << endl;
                }

            } else if (op2 == 2)
            {
                recipeBook.quickSort(Recipe::compareByType);
                cout << "\nSeleccione la categoria: " << endl;
                cout << " 1.- Desayuno \n 2.- Comida \n 3.- Cena " << endl;
                cout << "Seleccione una opción: "; cin >> type;

                if (type == 1)
                {
                    auxType = "Desayuno";
                } else if (type == 2)
                {
                    auxType = "Comida";
                } else if (type == 3)
                {
                    auxType = "Cena";
                }

                auxRecipe.setType(auxType);

                if (recipeBook.findData(auxRecipe, Recipe::compareByType) != -1)
                {
                    pos = recipeBook.findData(auxRecipe, Recipe::compareByType);
                    auxRecipe = recipeBook.retrieve(pos);
                    cout << "Receta\n\n " << auxRecipe.showAll() << endl;
                    wasFound = true;
                } else
                {
                    cout << "Receta no encontrada." << endl;
                }
            }

            op3 = 0;
            if (wasFound == true)
            {
                cout << " \n 1.- Finalizar busqueda. \n 2.- Modificar \n Selecciona una opción: ";
                cin >> op3;
            }

            if (op3 == 2)
            {
                cout << "========== MODIFICAR ==========" << endl;
                cout << "  1.- Añadir ingrediente." << endl;
                cout << "  2.- Eliminar ingrediente." << endl;
                cout << "  3.- Modificar la cantidad del ingrediente." << endl;
                cout << "  4.- Añadir pasos." << endl;
                cout << "  5.- Eliminar pasos." << endl;
                cout << "  6.- Cancelar." << endl;
                cout << "Seleccione una opción: ";
                cin >> op4;

                switch (op4)
                {
                    case 1:
                        cout << "Nombre del ingrediente a añadir: ";
                        getline(cin, iName); getline(cin, iName);
                        cout << "Cantidad: ";
                        cin >> iQuantity;
                        cout << "Medida: ";
                        cin.ignore(); getline(cin, iMeasurement);

                    auxIngredient.setName(iName);
                    auxIngredient.setQuantity(iQuantity);
                    auxIngredient.setMeasurement(iMeasurement);

                    ingList = auxRecipe.getIngredientList();
                    ingList.insertData(0, auxIngredient);

                    auxRecipe.setIngredientList(ingList);

                    recipeBook.deleteData(pos);
                    recipeBook.insertData(pos, auxRecipe);

                    break;

                case 2:
                    cout << "Ingrediente: ";
                    getline(cin, iName); getline(cin, iName);
                    auxIngredient.setName(iName);

                    ingList = auxRecipe.getIngredientList();

                    if (ingList.findData(auxIngredient, Ingredient::compareByName) != -1)
                    {
                        pos2 = ingList.findData(auxIngredient, Ingredient::compareByName);

                        ingList.deleteData(pos2);
                        auxRecipe.setIngredientList(ingList);

                        recipeBook.deleteData(pos);
                        recipeBook.insertData(pos, auxRecipe);

                        cout << "Ingrediente eliminado correctamente." << iName << endl;
                    } else
                    {
                        cout << "No se encontro el ingrediente a eliminar." << endl;
                    }
                    break;

                case 3:
                    cout << "Ingrediente a modificar: ";
                    getline(cin, iName); getline(cin, iName);
                    auxIngredient.setName(iName);

                    ingList = auxRecipe.getIngredientList();

                    if (ingList.findData(auxIngredient, Ingredient::compareByName) != -1)
                    {
                        pos2 = ingList.findData(auxIngredient, Ingredient::compareByName);

                        auxIngredient = ingList.retrieve(pos2);

                        cout << "Información del ingrediente:" << endl;
                        cout << "  " << auxIngredient.toString();
                        cout << "Nueva cantidad: ";
                        cin >> iQuantity;
                        auxIngredient.setQuantity(iQuantity);
                        ingList.insertData(pos2, auxIngredient);
                        auxRecipe.setIngredientList(ingList);
                        recipeBook.deleteData(pos);
                        recipeBook.insertData(pos, auxRecipe);
                    }
                    else
                    {
                        cout << "No se encontró el ingrediente." << endl;
                    }
                    break;

                case 4:
                    cout << "\nNúmero del nuevo paso: ";
                    cin >> pos2;
                    cout << "Escriba el paso: ";
                    getline(cin, steps); getline(cin, steps);
                    stepList = auxRecipe.getStepsList();
                    stepList.insertData(pos2 - 1, steps);
                    auxRecipe.setStepsList(stepList);
                    recipeBook.deleteData(pos);
                    recipeBook.insertData(pos, auxRecipe);
                    break;

                case 5:
                    cout << "\nPaso a eliminar: ";
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
                    cout << "Ingrese una opción válida." << endl;
                    break;
                }
            }
            else { }

            cout << "Presione enter para continuar..." << endl;
            getline(cin, data);
            system("cls");
            break;

        case 4:
            system("cls");
            cout << "=============== ELIMINAR RECETA ===============" << endl;
            if (recipeBook.isEmpty())
            {
                cout << "Recetario vacío." << endl;
                cout << "Presione enter para continuar..." << endl;
                getline(cin, data); getline(cin, data);
                system("cls");
                break;
            }

            recipeBook.quickSort(Recipe::compareByName);

            cout << "Receta a eliminar: ";
            getline(cin, recName); getline(cin, recName);

            auxRecipe.setName(recName);

            if (recipeBook.findData(auxRecipe, Recipe::compareByName) != -1)
            {
                pos = recipeBook.findData(auxRecipe, Recipe::compareByName);
                recName = recipeBook.retrieve(pos).getName();
                recipeBook.deleteData(pos);
                cout << "Receta eliminada." << recName << endl;
            } else
            {
                cout << "No existe dicha receta." << endl;
            }
            cout << "Presione enter para continuar..." << endl;
            getline(cin, data);
            system("cls");
            break;

        case 5:
            system("cls");
            cout << "=============== ELIMINAR TODO EL RECETARIO ===============" << endl;
            cout << "¿Desea eliminar todo el recetario?" << endl;
            cout << " 1.- Si \n 2.- No \n Ingrese una opción: " << endl;
            cin >> op2;

            if (op2 == 1)
            {
                recipeBook.deleteAll();
                cout << "Recetario eliminado correctamente.";
                getline(cin, data); getline(cin, data);
            } else if (op2 == 2)
            {
                cout << "Operación cancelada.";
                getline(cin, data); getline(cin, data);
            }
            cout << "Presione enter para continuar..." << endl;
            getline(cin, data);
            system("cls");
            break;

        case 6:
            system("cls");
            cout << "=============== ORDENAR RECETARIO ===============" << endl;
            if (recipeBook.isEmpty())
            {
                cout << "Recetario vacío." << endl;
                cout << "Presione enter para continuar..." << endl;
                getline(cin, data); getline(cin, data);
                system("cls");
                break;
            }

            cout << " 1.- Ordenar por nombre." << endl;
            cout << " 2.- Ordenar por categoria." << endl;
            cout << " 3.- Ordenar por tiempo de preparación." << endl;
            cout << " Seleccione una opción: "; cin >> op2;

            if (op2 == 1)
            {
                recipeBook.quickSort(Recipe::compareByName);
            } else if (op2 == 2)
            {
                recipeBook.quickSort(Recipe::compareByType);
            } else if (op2 == 3)
            {
                recipeBook.quickSort(Recipe::compareByPrepTime);
            }
            cout << "Lista ordenada, presione enter para continuar." << endl;
            getline(cin, data); getline(cin, data);
            system("cls");
            break;

        case 7:
            system("cls");
            cout << "=============== GUARDAR RECETARIO A DISCO ===============" << endl;

            if (recipeBook.isEmpty()) {
                cout << "Recetario vacío." << endl;
                cout << " \nPresione enter para regresar..." << endl;
                getline(cin, data);getline(cin, data);
                system("cls");
                break;
            }

            recipeBook.writeToDisk("recetario.txt");
            cout << "Recetario guardado correctamente." << endl;
            cout << " \nPresione enter para regresar..." << endl;
            getline(cin, data);getline(cin, data);
            system("cls");
            break;

        case 8:
            system("cls");
            cout << "=============== LEER RECETARIO DEL DISCO ===============" << endl;
            recipeBook.readFromDisk("recetario.txt");
            cout << "Contenido del recetario: " << endl;
            while (i <= recipeBook.getLastPos())
            {
                cout << recipeBook.retrieve(i).toString() << endl;
                i++;
            }
            i = 0;
            cout << " \nPresione enter para regresar..." << endl;
            getline(cin, data); getline(cin, data);
            system("cls");
            break;

        case 9:
            cout << " Saliendo del programa..." << endl;
            break;

        default:
            cout << "Ingrese una opción válida." << endl;
            cout << "Presione enter para continuar..." << endl;
            break;
        }
    }
    return 0;
}
