#ifndef INGREDIENT_HPP
#define INGREDIENT_HPP


#include <iostream>
#include <sstream>
#include <fstream>

class Ingredient {
private:
    std::string name;
	std::string measurement;
	float quantity;

public:
    Ingredient();
	Ingredient(const Ingredient&);
	Ingredient(std::string, std::string, float);

	void setName(std::string);
	void setMeasurement(std::string);
	void setQuantity(float);

	std::string getName();
	std::string getMeasurement();
	float getQuantity();

	std::string toString();

	static int compareByName(const Ingredient&, const Ingredient&);

	// Operador de asignación =
	Ingredient& operator= (const Ingredient&);

	// Operadores relacionales
	bool operator== (const Ingredient&);
	bool operator!= (const Ingredient&);
	bool operator < (const Ingredient&);
	bool operator<= (const Ingredient&);
	bool operator > (const Ingredient&);
	bool operator>= (const Ingredient&);

	// Sobrecarga de operadores de flujo
	friend std::ostream& operator<<(std::ostream&, const Ingredient&);	// Salida
	friend std::istream& operator>>(std::istream&, Ingredient&);		// Entrada
};

#endif // INGREDIENT_HPP
