#ifndef LIST_HPP
#define LIST_HPP

#include <string.h>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <exception>
#include <fstream>

#define size 100000

class listException: public std::exception
{
    private:
    std::string msg;
    public:
    listException() noexcept;
    listException(const listException& ex) noexcept : msg(ex.msg) { }
    listException(const std::string& m) : msg(m) { }
    listException& operator = (const listException& ex) noexcept
    {
        msg = ex.msg;
    }
    virtual ~listException(){ }
    virtual const char* what() const noexcept
    {
        return msg.c_str();
    }
};

class List
{
private:

    int data[size];
    int last;

    bool isValidPos(const int&);
    void copyAll(const List&);

    void sortMerge(const int&, const int&);
    void sortQuick(const int&, const int&);

public:

    List();
    List(const List&);

    bool isEmpty();
    bool isFull();

    void insertData(const int&, const int&);
    void deleteData(const int&);

    int getFirstPos();
    int getLastPos()const;
    int getPrevPos(const int&);
    int getNextPos(const int&);

    std::string toString() const;

    int recupera(const int&);
    void deleteAll();
    bool isSorted() const;

    void swapData(int&, int&);

    void bubbleSort();
    void insertSort();
    void selectSort();
    void shellSort();

    void sortDataMerge();
    void sortDataQuick();

    List& operator=(const List&);
};

#endif // LIST_HPP
