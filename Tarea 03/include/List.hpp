#ifndef LIST_HPP
#define LIST_HPP

#include "Song.hpp"

#include <iostream>
#include <cstring>

#define MAX 50

class List
{
    private:
        Song songs[MAX];
        int lastValue;

        bool isValidPos(const int&);

    public:
        List();
        bool isEmpty();
        bool isFull();
        void insert(const Song&, const int&);
        void remove(const int&);
        int first();
        int last();
        int previous(const int&);
        int next(const int&);
        int find(Song&);
        Song recover(const int&);
        void sort();
        void print();
        void reset();
};

#endif // LIST_HPP
