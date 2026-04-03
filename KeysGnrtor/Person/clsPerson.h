#pragma once
 #include<iostream>
 #include"stAddress.h"
 using namespace std;
 class clsPerson:public stAddress
 {
    struct St_Preson
    {
    string _FirstName ="";
    string _LastName = "";
    string _Email ="";
    string _Phone ="";
    };

     /// first  , last Email  , phone  , country  , city  ,  street 
     St_Preson _Person;
public:
  clsPerson( string First , string  Last , string  Email , string phone  ,string  Country , string City , string Street  ):stAddress(Country , City , Street)
  {
  _Person._FirstName = First;
  _Person._LastName = Last;
  _Person._Email = Email;
  _Person._Phone = phone;
  }

 void SetFirstName(string  F1st)
 {
_Person._FirstName = F1st;
 } 

 string GetFirstName()
 {
return _Person._FirstName ;

 }

void SetLastName(string L2d )
{
_Person._LastName = L2d;
}
string GetLastName()
{
return _Person._LastName;
}
void SetEmail(string Em )
{

_Person._Email = Em;
}
 
string GetEmail()
{

return _Person._Email;
}

void SetPhone (string Ph )
{
_Person._Phone = Ph;
}

string GetPhone ()
{
return _Person._Phone;
}

string FullNaem()
{

   return (_Person._FirstName+_Person._LastName);
}
 };