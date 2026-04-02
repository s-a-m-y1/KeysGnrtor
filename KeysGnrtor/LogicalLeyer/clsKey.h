#pragma once 
#include<iostream>
#include"C:/Programing_For_Projects/KeysGnrtor/Librarys/clsUtile.h"
#include<string>
using namespace std;
class clsKey
{
private:
string _Key ="";

public:

clsKey()
{

_Key = clsUtile::GenerateKey(clsUtile::enCharType::MixChars);
    
}

string GetKey()
{
    return _Key;
}

};
