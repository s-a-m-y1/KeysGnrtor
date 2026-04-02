#pragma once
#include<iostream>
using namespace std;
class stAddress
{
    private:
    struct st_Address 
    {
    string _Country = "";
    string _City = "";
    string _Street = "";
    };
    st_Address Adr;
    public:
    stAddress(string  Country , string City , string Street  )
    {

             Adr._Country = Country;
             Adr._City = City;
             Adr._Street = Street;
    }
    /// Encab;
    void  SetCounrty(string Contry)
    {
   Adr._Country = Contry;
    }
    void  SetCity(string City)
    {
        Adr._City = City;
    }
    void  SetStreet(string Street )
    {
        Adr._Street = Street;
    }
    string GetCoutry()
    {
    return Adr._Country;
    }
   string GetCity()
   {
    return   Adr._City; 
  }
    string GetStreet()
   {
     return Adr._Street;
   }


   
};