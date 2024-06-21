#include "Ingredient.hpp"

using namespace std;

Ingredient::Ingredient() : name(""), measeure(""), quantity(0.0) { }

Ingredient::Ingredient(const Ingredient& p)
{
	*this = p;
}

Ingredient::Ingredient(string name, string measeure, float quantity) : name(name), measeure(measeure), quantity(quantity) { }

void Ingredient::setName(string name)
{
	this->name = name;
}

void Ingredient::setMeasurement(string measeure)
{
	this->measeure = measeure;
}

void Ingredient::setQuantity(float quantity)
{
	this->quantity = quantity;
}

string Ingredient::getName()
{
	return name;
}

string Ingredient::getMeasure()
{
	return measeure;
}

float Ingredient::getQuantity()
{
	return quantity;
}

string Ingredient::toString()
{
	stringstream writtenIngredient;
	writtenIngredient << "  " << name << " - " << quantity << " " << measeure << "\n";
	return writtenIngredient.str();
}

int Ingredient::compareByName(const Ingredient &A, const Ingredient &p)
{
	if (A.name > p.name)
    {
		return 1;
	} else if (A.name == p.name)
	{
		return 0;
	} else if (A.name < p.name)
	{
		return -1;
	}
}

Ingredient& Ingredient::operator = (const Ingredient& p)
{
	if (this != &p)
    {
		name = p.name;
		measeure = p.measeure;
		quantity = p.quantity;
	}
	return *this;
}

bool Ingredient::operator == (const Ingredient& p)
{
	return name == p.name;
}

bool Ingredient::operator != (const Ingredient& p)
{
	return name != p.name;
}

bool Ingredient::operator < (const Ingredient& p)
{
	return name < p.name;
}

bool Ingredient::operator <= (const Ingredient& p)
{
	return name <= p.name;
}

bool Ingredient::operator > (const Ingredient& p)
{
	return name > p.name;
}

bool Ingredient::operator >= (const Ingredient& p)
{
	return name >= p.name;
}

std::ostream& operator<<(std::ostream& os, const Ingredient& i)
{
	os << i.name << endl;
	os << i.quantity << endl;
	os << i.measeure;
	return os;
}

istream& operator>>(istream& is, Ingredient& i)
{
	string myStr;
	getline(is, i.name);
	getline(is, myStr);
	i.quantity = atof(myStr.c_str());
	getline(is, i.measeure);

	return is;
}
