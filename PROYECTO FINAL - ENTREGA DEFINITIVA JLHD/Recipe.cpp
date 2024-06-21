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

Recipe::Recipe(const Recipe& B)
{
	*this = B;
}

Recipe::Recipe(string name, string type, int prepTime, Name Author) : name(formatData(name)),
    type(formatData(type)), prepTime(prepTime), author(author) { }

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

void Recipe::setIngredientList(SimpleLinkedList<Ingredient> ingList)
{
    this->ingList.deleteAll();
	ingList.bubbleSort(Ingredient::compareByName);
	this->ingList = ingList;
}

void Recipe::setSteps(string steps)
{
    this->steps = steps;
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

SimpleLinkedList<Ingredient> Recipe::getIngredientList()
{
	return ingList;
}

string Recipe::getSteps()
{
	return steps;
}

string Recipe::toString()
{
	stringstream writtenRecipy;
	writtenRecipy << " Nombre: " << name << " | Categoria: " << type << " | Tiempo de preparacion: "
		<< prepTime << " min \t" << " | Autor: " << author.toString();
	return writtenRecipy.str();
}

string Recipe::showAll()
{
	stringstream all;
	all << " Nombre: " << name << "\n  Categoria: " << type << "\n  Tiempo de preparacion: " << prepTime << " min \n  Autor: " << author.toString() << "\n\n"
		<< "  Lista de Ingredientes: \n";

    all << ingList.toString();

	all << "\n\n  Procedimiento: \n  " << steps;

	return all.str();
}

int Recipe::compareByName(const Recipe &A, const Recipe &B)
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

int Recipe::compareByType(const Recipe &A, const Recipe &B)
{
	if (A.type > B.type)
    {
		return 1;
	} else if (A.type == B.type)
	{
		return 0;
	} else if (A.type < B.type)
	{
		return -1;
	}
}

int Recipe::compareByPrepTime(const Recipe &A, const Recipe &B)
{
	if (A.prepTime > B.prepTime)
    {
		return 1;
	} else if (A.prepTime == B.prepTime)
	{
		return 0;
	} else if (A.prepTime < B.prepTime)
	{
		return -1;
	}
}

Recipe& Recipe::operator= (const Recipe& B)
{
	ingList = B.ingList;
	steps = B.steps;
	name = B.name;
	type = B.type;
	prepTime = B.prepTime;
	author = B.author;

	return *this;
}

ostream& operator<<(ostream &os, const Recipe &r)
{
	os << r.name << endl;
	os << r.type << endl;
	os << r.prepTime << endl;
	os << r.author << endl;

	int i(0);
    SimpleLinkedList<Ingredient>::Position pos = r.ingList.getFirstPos();
	while (pos != nullptr)
    {
		i++;
		pos = r.ingList.getNextPos(pos);
	}
	os << i << endl;

    pos = r.ingList.getFirstPos();
	while (pos != nullptr)
    {
		os << r.ingList.retrieve(pos) << endl;
		pos = r.ingList.getNextPos(pos);
	}

	os << r.steps;

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

	SimpleLinkedList<Ingredient> tempIngList;
	Ingredient tempIngredient;

	for (int i = 0; i < numIngredients; i++)
    {
		is >> tempIngredient;
		tempIngList.insertData(nullptr, tempIngredient);
	}
	r.setIngredientList(tempIngList);
	getline(is, r.steps);
	return is;
}
