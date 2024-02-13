#include "List.hpp"

#include <iostream>

List::List() : lastValue(-1) {}

bool List::isValidPos(const int& position)
{
    return (position > -1 && position <= MAX);
}

bool List::isEmpty()
{
    return lastValue == -1;
}

bool List::isFull()
{
    return lastValue == MAX - 1;
}

void List::insert(const Song& value, const int& position)
{
    if (position > lastValue + 1 || !isValidPos(position) || isFull())
        {
            throw std::out_of_range("Error: inserci�n no v�lida.");
        } else
        {
            for (int i = lastValue + 1; i > position; i--)
                {
                    songs[i] = songs[i - 1];
                }
            songs[position] = value;
            lastValue++;
        }
}

void List::remove(const int& position)
{
    if (isEmpty() || !isValidPos(position))
        {
            throw std::out_of_range("Error: eliminaci�n no v�lida.");
        } else
        {
            for (int i = position; i < lastValue; i++)
            {
                songs[i] = songs[i + 1];
            }
            lastValue--;
        }
}

int List::first()
{
    return (lastValue > -1) ? 0 : -1;
}

int List::last()
{
    return (lastValue > -1) ? lastValue : -1;
}

int List::previous(const int& position)
{
    return (isEmpty() || !isValidPos(position) || position == 0) ? -1 : position - 1;
}

int List::next(const int& position)
{
    return (isEmpty() || !isValidPos(position) || position == MAX - 1) ? -1 : position + 1;
}

int List::find(Song& value)
{
    for (int i = 0; i <= lastValue; i++)
        {
            if (songs[i].getName() == value.getName())
            {
                return i;
            }
        }
    return -1;
}

Song List::recover(const int& position)
{
    if (isEmpty() || !isValidPos(position))
        {
            throw std::out_of_range("Error: recuperaci�n no v�lida.");
        }
    return songs[position];
}

void List::print()
{
    if (isEmpty())
        {
            std::cout << "Lista vac�a." << std::endl;
        } else
        {
            for (int i = 0; i <= lastValue; i++)
            {
                std::cout << "Posici�n: " << i + 1 << " " << songs[i].toString() << std::endl;
            }
        }
}

void List::reset()
{
    lastValue = -1;
}
