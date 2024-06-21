#include "Ingredient.hpp"

using namespace std;

Ingredient::Ingredient() : name(""), measurement(""), quantity(0.0) { }

Ingredient::Ingredient(const Ingredient& B)
{
	*this = B;
}

Ingredient::Ingredient(string name, string measurement, float quantity) :
	name(name), measurement(measurement), quantity(quantity) { }

void Ingredient::setName(string name)
{
	this->name = name;
}

void Ingredient::setMeasurement(string measurement)
{
	this->measurement = measurement;
}

void Ingredient::setQuantity(float quantity)
{
	this->quantity = quantity;
}

string Ingredient::getName()
{
	return name;
}

string Ingredient::getMeasurement()
{
	return measurement;
}

float Ingredient::getQuantity()
{
	return quantity;
}

string Ingredient::toString()
{
	stringstream writtenIngredient;
	writtenIngredient << "  " << name << " --- " << quantity << " " << measurement << "\n";
	return writtenIngredient.str();
}

int Ingredient::compareByName(const Ingredient &A, const Ingredient &B)
{
	if (A.name > B.name)
    {
		return 1;
	} else if (A.name == B.name)
	{
		return 0;
	} else if (A.name < B.name)
	{
		return -1;
	}
}

Ingredient& Ingredient::operator= (const Ingredient& B)
{
	if (this != &B)
    {
		name = B.name;
		measurement = B.measurement;
		quantity = B.quantity;
	}
	return *this;
}

bool Ingredient::operator== (const Ingredient& B)
{
	return name == B.name;
}

bool Ingredient::operator!= (const Ingredient& B)
{
	return name != B.name;
}

bool Ingredient::operator < (const Ingredient& B)
{
	return name < B.name;
}

bool Ingredient::operator<= (const Ingredient& B)
{
	return name <= B.name;
}

bool Ingredient::operator > (const Ingredient& B)
{
	return name > B.name;
}

bool Ingredient::operator>= (const Ingredient& B)
{
	return name >= B.name;
}

std::ostream& operator<<(std::ostream& os, const Ingredient& i)
{
	os << i.name << endl;
	os << i.quantity << endl;
	os << i.measurement;
	return os;
}

istream& operator>>(istream& is, Ingredient& i)
{
	string myStr;

	getline(is, i.name);
	getline(is, myStr);
	i.quantity = atof(myStr.c_str());
	getline(is, i.measurement);

	return is;
}
