#include "Song.hpp"
#include "List.hpp"

using namespace std;

std::string Song::formatData(std::string data)
{
    if (data.length() > 25)
    {
        data = data.substr(0, 25);
    }

    while (data.length() < 25)
    {
        data += " ";
    }

    return data;
}

std::string Song::formatData(int value)
{
    std::string data = std::to_string(value);

    while (data.length() < 3)
    {
        data = "0" + data;
    }

    return data;
}


Song::Song() :ranking(0), name(""), mp3Name(""), author(""), interpreter("") { }

Song::Song(int ranking, string name, string mp3Name, string author, string interpreter) : name(formatData(name)), mp3Name(formatData(mp3Name)), author(formatData(author)), interpreter(formatData(interpreter)) { }

void Song::setName(string name)
{
	this->name = formatData(name);
}

void Song::setMP3Name(string mp3Name)
{
	mp3Name += ".mp3";
	this->mp3Name = formatData(mp3Name);
}

void Song::setAuthor(string author)
{
	this->author = formatData(author);
}

void Song::setInterpreter(string interpreter)
{
	this->interpreter = formatData(interpreter);
}

void Song::setRanking(int ranking)
{
 this->ranking = ranking;
}

string Song::getName()
{
	return name;
}

string Song::getMP3Name()
{
	return mp3Name;
}

string Song::getAuthor()
{
	return author;
}

string Song::getInterpreter()
{
	return interpreter;
}

int Song::getRanking() const
{
    return ranking;
}

string Song::toString() {
    stringstream writtenSong;
    writtenSong << "Ranking: ";
    if (ranking < 10) {
        writtenSong << "  " << ranking << " | ";
    } else if (ranking < 100) {
        writtenSong << " " << ranking << " | ";
    } else {
        writtenSong << ranking << " | ";
    }
    writtenSong << "Nombre: " << this->name << " | Autor: " << this->author << " | Interprete: " << this->interpreter << " | Archivo: " << this->mp3Name << endl;
    return writtenSong.str();
}

int Song::compareBySongName(const Song& A, const Song& B)
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

int Song::compareByInterpreter(const Song& A, const Song& B)
{
	if (A.interpreter > B.interpreter)
    {
		return 1;
	} else if (A.interpreter == B.interpreter)
	{
		return 0;
	} else if (A.interpreter < B.interpreter)
	{
		return -1;
	}
}
