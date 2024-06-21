#include "Recipe.hpp"

using namespace std;

string Recipe::formatData(string data)
{
	data.substr(0, 30);
	while (data.length() < 30)
    {
		data += " ";
	}
	return data;
}

Recipe::Recipe() : name (""), type(""), prepTime(0), author() { }

Recipe::Recipe(const Recipe& p)
{
	*this = p;
}

Recipe::Recipe(string name, string type, int prepTime, Name Author) : name(formatData(name)), type(formatData(type)), prepTime(prepTime), author(author) { }

void Recipe::setName(string name)
{
	this->name = formatData(name);
}

void Recipe::setType(string type)
{
	this->type = formatData(type);
}

void Recipe::setPrepTime(int prepTime)
{
	this->prepTime = prepTime;
}

void Recipe::setAuthor(Name author)
{
	this->author = author;
}

void Recipe::setIngredientList(List<Ingredient> ingList)
{
	ingList.quickSort(Ingredient::compareByName);
	this->ingList = ingList;
}

void Recipe::setStepsList(List<string> stepList)
{
	this->stepList = stepList;
}

string Recipe::getName()
{
	return name;
}

string Recipe::getType()
{
	return type;
}

int Recipe::getPrepTime()
{
	return prepTime;
}

Name Recipe::getAuthor()
{
	return author;
}

List<Ingredient> Recipe::getIngredientList()
{
	return ingList;
}

List<string> Recipe::getStepsList()
{
	return stepList;
}

string Recipe::toString()
{
	stringstream writtenRecipy;
	writtenRecipy << " Nombre: " << name << " | Categoria: " << type << " | Tiempo de preparacion: " << prepTime << " min \t" << " | Autor: " << author.toString();
	return writtenRecipy.str();
}

string Recipe::showAll()
{
	stringstream all;
	all << " Nombre: " << name << "\n  Categoria: " << type << "\n  Tiempo de preparacion: " << prepTime << " min \n  Autor: " << author.toString() << "\n\n" << "  Ingredientes: \n";
	int i(0);
	while (i <= ingList.getLastPos())
    {
		all << ingList.retrieve(i).toString();
		i++;
	}

	all << "\n\n  Procedimiento: \n";

	i = 0;
	while (i <= stepList.getLastPos())
    {
		all << "  " << i + 1 << ".- " << stepList.retrieve(i) << "\n";
		i++;
	}

	return all.str();
}

int Recipe::compareByName(const Recipe &A, const Recipe &p)
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

int Recipe::compareByType(const Recipe &A, const Recipe &p)
{
	if (A.type > p.type)
    {
		return 1;
	} else if (A.type == p.type)
	{
		return 0;
	} else if (A.type < p.type)
	{
		return -1;
	}
}

int Recipe::compareByPrepTime(const Recipe &A, const Recipe &p)
{
	if (A.prepTime > p.prepTime)
    {
		return 1;
	} else if (A.prepTime == p.prepTime)
	{
		return 0;
	} else if (A.prepTime < p.prepTime)
	{
		return -1;
	}
}

Recipe& Recipe::operator= (const Recipe& p)
{
	ingList = p.ingList;
	stepList = p.stepList;
	name = p.name;
	type = p.type;
	prepTime = p.prepTime;
	author = p.author;

	return *this;
}

ostream& operator<<(ostream &os, Recipe &r)
{
	os << r.name << endl;
	os << r.type << endl;
	os << r.prepTime << endl;
	os << r.author << endl;

	int i(0);
	os << r.ingList.getLastPos() << endl;
	while (i <= r.ingList.getLastPos())
    {
		os << r.ingList.retrieve(i) << endl;
		i++;
	}

	i = 0;
	os << r.stepList.getLastPos() << endl;
	while (i <= r.stepList.getLastPos())
    {
		if (i == r.stepList.getLastPos())
		{
			os << r.stepList.retrieve(i);
		} else
		{
			os << r.stepList.retrieve(i) << endl;
		}
		i++;
	}
	return os;
}

istream& operator>>(istream &is, Recipe &r)
{
	string myStr;

	getline(is, r.name);
	getline(is, r.type);
	getline(is, myStr);
	r.prepTime = atoi(myStr.c_str());
	is >> r.author;

	getline(is, myStr);
	int numIngredients = atoi(myStr.c_str());

	List<Ingredient> tempIngList;
	Ingredient tempIngredient;

	for (int i = 0; i <= numIngredients; i++)
    {
		is >> tempIngredient;
		tempIngList.insertData(i, tempIngredient);
	}
	r.ingList = tempIngList;

	getline(is, myStr);
	int numSteps = atoi(myStr.c_str());

	List<string> tempStepList;
	string tempStep;

	for (int i = 0; i <= numSteps; i++)
    {
		getline(is, tempStep);
		tempStepList.insertData(i, tempStep);
	}
	r.stepList = tempStepList;

	return is;
}
