#include "Song.hpp"

Song::Song() {}

Song::Song(const Song& song) : author(song.author), interpreter(song.interpreter), name(song.name), position(song.position) {}

std::string Song::getAuthor()
{
    return author;
}

std::string Song::getInterpreter()
{
    return interpreter;
}

std::string Song::getName()
{
    return name;
}

int Song::getPosition()
{
    return position;
}

void Song::setAuthor(const std::string& parameter)
{
    author = parameter;
}

void Song::setInterpreter(const std::string& parameter)
{
    interpreter = parameter;
}

void Song::setName(const std::string& parameter)
{
    name = parameter;
}

void Song::setPosition(const int& parameter)
{
    position = parameter;
}

std::string Song::toString()
{
    std::string song;
    song += " / Nombre: " + name;
    song += " / Autor: " + author;
    song += " / Interprete: " + interpreter;
    return song;
}
