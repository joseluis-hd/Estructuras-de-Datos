#include "Menu.hpp"

using namespace std;

List myListA;
List myListB;

Menu::Menu(){ }

int Menu::interfaz()
{
    setlocale(LC_CTYPE, "spanish");

    do
    {
        system("cls");
        MostrarMenu();
        if(opc==1)
        {
            addData();
        }
        else if(opc==2)
        {
            ordData();
        }
    }
    while(opc!=3);
    return 0;
}

void Menu::MostrarMenu()
{
    cout<<"\t\t\t\tNÚMEROS ALEATORIOS"<<endl;
    linea();cout<<endl;
    cout<<"\t\t\t\t\tMENU"<<endl;
    linea();cout<<endl;
    cout<<"1.- Insertar números aleatorios."<<endl;
    cout<<"2.- Ordenar numeros."<<endl;
    cout<<"3.- Salir."<<endl;
    linea();cout<<endl;
    cin>>opc;
    setOpc(opc);
}

void Menu::addData()
{
    int valor, i(0);

    default_random_engine generator (chrono::system_clock::now().time_since_epoch().count());
    uniform_int_distribution <int> distribution(0,1000000);
    auto dice = bind(distribution, generator);

    while(i<size)
    {
        valor = dice();
        myListA.insertData(myListA.getLastPos(), valor);
        i++;
    }
}

void Menu::ordData()
{
    unsigned timeA,timeB;
    int n;
    double time;

    linea();cout<<endl;
    myListB=myListA;
    timeA=clock();
    myListB.bubbleSort();
    timeB=clock();
    time = (double (timeB-timeA)/CLOCKS_PER_SEC);
    linea();cout<<endl;
    cout<<endl<<"BubbleSort: Tiempo de ejecución: "<< time <<" segundos."; isSorted(); cout<<endl;
    linea();cout<<endl;

    myListB=myListA;
    timeA=clock();
    myListB.insertSort();
    timeB=clock();
    linea();cout<<endl;
    time = (double (timeB-timeA)/CLOCKS_PER_SEC);
    cout<<endl<<"InsertSort: Tiempo de ejecución: "<< time <<" segundos."; isSorted(); cout<<endl;
    linea();cout<<endl;

    myListB=myListA;
    timeA=clock();
    myListB.selectSort();
    timeB=clock();
    linea();cout<<endl;
    time = (double (timeB-timeA)/CLOCKS_PER_SEC);
    cout<<endl<<"SelectSort: Tiempo de ejecución: "<< time <<" segundos."; isSorted(); cout<<endl;
    linea();cout<<endl;

    myListB=myListA;
    timeA=clock();
    myListB.shellSort();
    timeB=clock();
    linea();cout<<endl;
    time = (double (timeB-timeA)/CLOCKS_PER_SEC);
    cout<<endl<<"ShellSort: Tiempo de ejecución: "<< time <<" segundos."; isSorted(); cout<<endl;
    linea();cout<<endl;

    myListB=myListA;
    timeA=clock();
    myListB.sortDataMerge();
    timeB=clock();
    time = (double (timeB-timeA)/CLOCKS_PER_SEC);
    linea();cout<<endl;
    cout<<endl<<"MergeSort: Tiempo de ejecución: "<< time <<" segundos."; isSorted(); cout<<endl;
    linea();cout<<endl;

    myListB=myListA;
    timeA=clock();
    myListB.sortDataQuick();
    timeB=clock();
    linea();cout<<endl;
    time = (double (timeB-timeA)/CLOCKS_PER_SEC);
    cout<<endl<<"Quick: Tiempo de ejecución: "<< time <<" segundos."; isSorted(); cout<<endl;
    linea();cout<<endl;

    getch();
}

void Menu::isSorted()
{
    if(myListB.isSorted())
    {
        cout<<"\tList ordenada."<<endl;
    }
    else
    {
        cout<<"\tList no ordenada."<<endl;
    }
}



void Menu::linea()
{
    printf("==================================================================================");
}

int Menu::getOpc()
{
    return opc;
}

void Menu::setOpc(const int& o)
{
    opc= o;
}
