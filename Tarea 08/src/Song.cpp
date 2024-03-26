#include "Song.hpp"
#include <sstream>

using namespace std;

string Song::formatData(string data)
{
    data = data.substr(0, 30);
    while (data.length() < 30)
    {
        data += " ";
    }
    return data;
}

Song::Song() : name(""), mp3Name(""), author(""), interpreter("") { }

Song::Song(string name, string mp3Name, string author, string interpreter)
{
    this->name = formatData(name);
    this->mp3Name = formatData(mp3Name);
    this->author = formatData(author);
    this->interpreter = formatData(interpreter);
}

void Song::setName(string name)
{
    this->name = formatData(name);
}

void Song::setMP3Name(string mp3Name)
{
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

string Song::toString()
{
    stringstream writtenSong;
    writtenSong << "Ranking: " << this->ranking << " | Nombre: " << this->name << " | Autor: " << this->author << " | Intérprete: " << this->interpreter << " | Archivo: " << this->mp3Name << endl;
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
    } else
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
    } else {
        return -1;
    }
}

