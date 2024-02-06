#include "DataType.h"

#include <iostream>
#include <limits>

using namespace std;

void DataType::showData()
{
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"\tTipo de dato\t\tBits\t\tValor mínimo\t\tValor máximo"<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
    cout<<"Caracter con signo      \t"<<sizeof(char)<<"\t\t"<<CHAR_MIN<<"\t\t\t"<<CHAR_MAX<<endl;
    cout<<"Caracter sin signo      \t"<<sizeof(unsigned char)<<"\t\t0\t\t\t"<<UCHAR_MAX<<endl;
    cout<<"Entero corto con signo  \t"<<sizeof(short int)<<"\t\t"<<SHRT_MIN<<"\t\t\t"<<SHRT_MAX<<endl;
    cout<<"Entero corto sin signo  \t"<<sizeof(unsigned short int)<<"\t\t0\t\t\t"<<USHRT_MAX<<endl;
    cout<<"Entero largo con signo  \t"<<sizeof(long int)<<"\t"<<LONG_MIN<<"\t\t"<<LONG_MAX<<endl;
    cout<<"Entero largo sin signo  \t"<<sizeof(unsigned long int)<<"\t\t0\t\t\t"<<ULONG_MAX<<endl;
    cout<<"Real de precisión simple\t"<<sizeof(float)<<"\t"<< -numeric_limits<float>::max()<<"\t\t"<<numeric_limits<float>::max()<<endl;
    cout<<"Real de doble precisión \t"<<sizeof(double)<<"\t"<<-numeric_limits<double>::max()<<"\t\t"<<numeric_limits<double>::max()<<endl;
    cout<<"---------------------------------------------------------------------------------------"<<endl;
}
