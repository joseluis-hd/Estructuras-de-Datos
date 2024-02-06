#include "Product.hpp"

void Product::setFecha(const Date& dat)
{
    fecha = dat;
}
void Product::setExistence(const int& exi)
{
  existence = existence + exi;
}
void Product::setMenudeo(const float& men)
{
    menudeo = men;
}
void Product::setMayoreo(const float& may)
{
     mayoreo = may;
}
void Product::setWeight(const float& w)
{
     weight = w;
}

void Product::setName(const std::string& n)
{
     name = n;
}
void Product::setBarCode(const std::string& c)
{
     barCode = c;
}
Date Product::getFecha() const
{
    return fecha;
}
int Product::getExistence() const
{
     return existence;
}
float Product::getMenudeo() const
{
     return menudeo;
}
float Product::getMayoreo() const
{
     return mayoreo;
}

float Product::getWeight() const
{
     return weight;
}
std::string Product::getName() const
{
     return name;
}
std::string Product::getBarCode() const
{
     return barCode;
}
