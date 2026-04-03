#pragma once 
#include<iostream>
#include"C:/Programing_For_Projects/KeysGnrtor/Librarys/clsUtile.h"
#include"C:/Programing_For_Projects/KeysGnrtor/Librarys/clsDate.h"
#include<string>
using namespace std;
class clsKey
{//                                  this  Add if add new person  and key  
private:
string _Key ="";
string  _Date ="";
public:

clsKey(string Key , string DateTime)
{

_Key = Key;
_Date =DateTime;
}
clsKey( )
{


}

string GetKey()
{
    return _Key;
}

string GetDateTime()
{
    return _Date;
}

};
