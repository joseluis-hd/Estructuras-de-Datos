#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <Date.hpp>

class Product
{
    private:
      std::string barCode;
      std::string name;
      float weight;
      float mayoreo;
      float menudeo;
      int existence;
      Date fecha;

     public:
      std::string getBarCode() const;
      std::string getName() const;
      float getWeight() const;
      float getMayoreo() const;
      float getMenudeo() const;
      int getExistence() const;
      Date getFecha() const;


      void setBarCode(const std::string&);
      void setName(const std::string&);
      void setWeight(const float&);
      void setMayoreo(const float&);
      void setMenudeo(const float&);
      void setExistence(const int&);
      void setFecha(const Date&);

};

#endif // PRODUCT_HPP
