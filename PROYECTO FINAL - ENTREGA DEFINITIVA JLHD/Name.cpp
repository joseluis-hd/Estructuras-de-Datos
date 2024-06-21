#include "Name.hpp"

using namespace std;

Name::Name() : name(""), lastName("") { }

Name::Name(const Name &B)
{
	*this = B;
}

Name::Name(string name, string lastName) : name(name), lastName(lastName) { }

void Name::setName(string name)
{
	this->name = name;
}

void Name::setLastName(string lastName)
{
	this->lastName = lastName;
}

string Name::getName()
{
	return name;
}

string Name::getLastName()
{
	return lastName;
}

string Name::toString()
{
	stringstream fullName;
	fullName << name << " " << lastName;
	return fullName.str();
}

Name& Name::operator= (const Name& B)
{
	if (this != &B)
    {
		name = B.name;
		lastName = B.lastName;
	}
	return *this;
}

bool Name::operator== (Name& B)
{
	return this->toString() == B.toString();
}

bool Name::operator!= (Name& B)
{
	return this->toString() != B.toString();
}

bool Name::operator < (Name& B)
{
	return this->toString() < B.toString();
}

bool Name::operator<= (Name& B)
{
	return this->toString() <= B.toString();
}

bool Name::operator > (Name& B)
{
	return this->toString() > B.toString();
}

bool Name::operator>= (Name& B)
{
	return this->toString() >= B.toString();
}

ostream& operator<<(ostream& os, const Name& n)
{
	os << n.name << endl;
	os << n.lastName;
	return os;
}

istream& operator>>(istream &is, Name &n)
{
	getline(is, n.name);
	getline(is, n.lastName);
	return is;
}
