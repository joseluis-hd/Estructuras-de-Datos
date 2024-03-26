#include "List.hpp"

using namespace std;

void List::copyAll(const List& l)
{
    int i(0);
    while (i <= l.last)
    {
        data[i]= l.data[i];
        i++;
    }
    last = l.last;
}

bool List::isValidPos(const int&u)
{
    return u >= 0 and u <= last;
}

List::List() : last(-1) {}

List::List(const List& l)
{
    copyAll(l);
}

bool List::isEmpty()
{
    return last == -1;
}

bool List::isFull()
{
    return last == (size-1);
}

void List::insertData(const int& u, const int& p)
{
    if (isFull())
    {
         throw listException("Lleno");
    }
    if (u !=-1 and !isValidPos(u))
    {
         throw listException("Posición inválida");
    }
    int i(last);
    while (i>u)
    {
        data[i+1]=data[i];
        i--;
    }
    data[u + 1]= p;
    last++;
}

void List::deleteData(const int&u)
{
    if(isEmpty())
    {
        throw listException("Vacio");
    }
    if(!isValidPos(u))
    {
        throw listException("Posicion invalida");
    }
    int i(u);
    while (i<last)
    {
       data[i]=data[i+1];
       i++;
    }
    last--;
}

int List::getFirstPos()
{
    if(isEmpty())
    {
        return -1;
    }
    return 0;
}

int List::getLastPos()const
{
    return last;
}

int List::getPrevPos(const int&u)
{
    if(u==0 or !isValidPos(u))
    {
        return -1;
    }
    return u-1;
}

int List::getNextPos(const int&u)
{
     if(u==last or !isValidPos(u))
    {
        return -1;
    }
    return u+1;
}

int List::recupera(const int&u)
{
    if (!isValidPos(u))
    {
        throw listException("Posición inválida");
    }
    return data[u];
}

string List::toString()const
{
    string resultado;
    int i(0);

    while (i <= last)
    {
        resultado += to_string(data[i]) + " \n";
        i++;
    }
    resultado+= " \n";
    return resultado;
}

void List::deleteAll()
{
    last=-1;
}

List& List::operator=(const List& l)
{
    copyAll(l);
    return *this;
}

void List::swapData(int& a, int& b)
{
    int aux(a);
    a = b;
    b = aux;
}

void List::bubbleSort()
{
    int i(last), j;
    bool bandera;
    do
    {
        bandera=false;
        j=0;
        while(j<i)
        {
            if(data[j]>data[j+1])
            {
                swapData(data[j], data[j+1]);
                bandera=true;
            }
        j++;
        }
    i--;
    }
    while(bandera);
}

void List::insertSort()
{
    int i(1), j;
    int aux;

    while(i <= last)
    {
        aux = data[i];
        j=i;
        while(j > 0 and aux < data[j-1])
        {
            data[j] = data[j-1];
            j--;
        }
        if(i != j)
        {
            data[j] = aux;
        }
    i++;
    }
}

void List::selectSort()
{
    int i(0), j, m;
    while(i < last)
    {
        m = i;
        j = i + 1;
        while(j <= last)
        {
            if(data[j] < data[m])
            {
                m=j;
            }
        j++;
        }
        if(i != m)
        {
            swapData(data[i], data[m]);
        }
        i++;
    }
}

void List::shellSort()
{
    int series []= {510774, 227011, 100894, 44842, 19930, 8858, 3937, 1750, 701, 301, 132, 57, 23, 10, 4, 1, 0};
    int pos(0), dif(series[pos]), i, j;
    while(dif > 0)
    {
        i=dif;
        while(i <= last)
        {
            j=i;
            while(j >= dif and data[j - dif] > data[j])
            {
                swapData(data[j-dif], data[j]);
                j-=dif;
            }
        i++;
        }
    dif = series [++pos];
    }
}

bool List::isSorted() const
{
    int i(0);
    while(i < last)
    {
        if (data[i]> data[i+1])
        {
            return false;
        }
        i++;
    }
    return true;
}

void List::sortMerge(const int& leftEdge, const int& rightEdge)
{
    if(leftEdge>=rightEdge)
    {
        return;
    }
    int m((leftEdge + rightEdge) / 2);

    sortMerge(leftEdge, m);
    sortMerge(m +1, rightEdge);

    static int temp[size];
    int x(leftEdge);

    while(x<= rightEdge)
    {
        temp[x]= data[x];
        x++;
    }

    int i (leftEdge), j(m+1);
    x=leftEdge;

    while(i<= m and j<=rightEdge)
    {
        while(i<= m and temp[i] <= temp[j])
            {
                data[x++]=temp[i++];
            }
        if(i<= m)
        {
            while(j<= rightEdge and temp[j] <= temp[i])
            {
                data[x++]=temp[j++];
            }
        }
    }

    while(i<=m)
    {
        data[x++]=temp[i++];
    }
    while(j<=rightEdge)
    {
        data[x++]=temp[j++];
    }
}

void List::sortQuick(const int& left, const int& right)
{
    if(left >= right)
    {
        return;

    }
    int i(left), j(right);
    while(i<j)
    {
        while(i<j and data[i] <= data[right])
        {
            i++;
        }
        while(i<j and data[j]>= data[right])
        {
            j--;
        }
        if (i != j)
        {
            swapData(data[i], data[j]);
        }
    }
    if (i!=right)
    {
        swapData(data[i], data[right]);
    }
    sortQuick(left, i -1);
    sortQuick(i+1, right);
}

void List::sortDataMerge()
{
    sortMerge(0, last);
}

void List::sortDataQuick()
{
    sortQuick(0, last);
}
