#include "Song.hpp"

using namespace std;

Song::Song() : position(0) { }

Song::Song(const Song &song) : author(song.author), interpreter(song.interpreter), name(song.name), position(song.position), fileName(song.fileName) {}

string Song::getAuthor() const
{
    return author;
}

string Song::getInterpreter() const
{
    return interpreter;
}

string Song::getName() const
{
    return name;
}

string Song::getFileName() const
{
    return fileName;
}

int Song::getPosition() const
{
    return position;
}

void Song::setAuthor(const string &parameter)
{
    author = parameter;
}

void Song::setInterpreter(const string &parameter)
{
    interpreter = parameter;
}

void Song::setName(const string &parameter)
{
    name = parameter;
}

void Song::setFileName(const string &parameter)
{
    fileName = parameter;
}

void Song::setPosition(const int &parameter)
{
    position = parameter;
}

string Song::toString() const
{
    string song;
    song += " | Ranking: " + to_string(position);
    song += " | Nombre: " + name;
    song += " | Autor: " + author;
    song += " | Interprete: " + interpreter;
    song += " | Archivo: " + fileName;
    return song;

}

bool Song::operator==(const Song &value) const
{
    return value.fileName == fileName;
}

bool Song::operator!=(const Song &value) const
{
    return value.fileName != fileName;
}

bool Song::operator>(const Song &value) const
{
    return value.fileName > fileName;
}

bool Song::operator>=(const Song &value) const
{
    return value.fileName >= fileName;
}

bool Song::operator<(const Song &value) const
{
    return value.fileName < fileName;
}

bool Song::operator<=(const Song &value) const
{
    return value.fileName <= fileName;
}

std::ostream& operator << (std::ostream& os, const Song& song)
{
    os << song.toString();
    return os;

}

std::istream& operator >> (std::istream& is, Song& song)
{
    cout << "Ranking: ";
    is >> song.position;

    cout << "Nombre: ";
    is.ignore();
    getline(is, song.name);

    cout << "Autor: ";
    getline(is, song.author);

    cout << "Interprete: ";
    getline(is, song.interpreter);

    cout << "Archivo: ";
    getline(is, song.fileName);

    return is;

}
