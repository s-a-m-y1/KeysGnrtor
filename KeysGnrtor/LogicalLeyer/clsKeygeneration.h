#pragma once
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
//______________________________LiB_________________________________///
#include"C:/Programing_For_Projects/KeysGnrtor/Librarys/clsDate.h"
#include"C:/Programing_For_Projects/KeysGnrtor/Librarys/clsUtile.h"
#include"C:/Programing_For_Projects/KeysGnrtor/Librarys/clsInputValidate.h"
#include"C:/Programing_For_Projects/KeysGnrtor/Librarys/clsString.h"
//__________________________________________________________________///
//____________________________LogicalLeyer__________________________///
#include"C:/Programing_For_Projects/KeysGnrtor/LogicalLeyer/clsKey.h"
//__________________________________________________________________///
//____________________________Person__________________________///
#include"C:/Programing_For_Projects/KeysGnrtor/Person/clsPerson.h"
//__________________________________________________________________///
///________________________________________________________________________________________________//
class clsKeygeneration:public clsPerson
{
private:
enum E_Mode{E_empty = 0 , E_update =1 , E_add =2 };
E_Mode _Mode;
// __________________//
string _Key ="";
string _DateTime ="";
string  Password_Login ="";/// this is paas krey OOPo
bool Mark =false;
    static  clsKeygeneration _convertLinetoObject (string Line  , string Delimter  = "/##/") /// this is mood load date  from file and split this data and push to members
    {
        vector<string>VLine = clsString::Split(Line , Delimter);// consractor
              
          
          return  clsKeygeneration( E_Mode::E_update, VLine[0] , VLine[1],VLine[2] ,VLine[3] , VLine[4] , VLine[5] ,VLine[6]   ,VLine[7] , VLine[8] , VLine[9] );
    }
     static  clsKeygeneration GetEmptyToObject (    ) /// this is mood load date  from file and split this data and push to members
    {
              
          return clsKeygeneration( E_Mode::E_empty, "","","", "" ,"","","","" ,"" ,"");
    }
  static string _ConvertLineToFile(clsKeygeneration Key, string Delimter = "/##/")
{
    string Line = "";
    Line += Key.GetFirstName() + Delimter;
    Line += Key.GetLastName() + Delimter;
    Line += Key.GetEmail() + Delimter;
    Line += Key.GetPhone() + Delimter;
    Line += Key.GetCoutry() + Delimter;
    Line += Key.GetCity() + Delimter;
    Line += Key.GetStreet() + Delimter;
    Line += Key.GetKey() + Delimter; 
    Line += Key.Password_Login;
    
    return Line;
}

    static vector<clsKeygeneration> _LoadDataFromFile()//this Big O(n)
    {

        vector<clsKeygeneration>V_PersonOfKey;
        fstream Load ("Key.txt" , ios::in);//read mood 
        if (Load.is_open())
        {
            string Line ="";
            while (getline(Load , Line))/// this is read one line at start to end 
            {
                V_PersonOfKey.push_back(_convertLinetoObject(Line));
            }
            
            Load.close();
        }
         if (!V_PersonOfKey.empty())
          return V_PersonOfKey;

          return {};
    }
 
    static void  _SaveDataToFile(vector<clsKeygeneration>&V_Ket)// the Refrance IS consum 8 byte
    {
        if(V_Ket.empty())return;
        fstream Save("Key.txt" , ios::out);
        if (Save.is_open())
        {
            string LinePush ="";
            for(clsKeygeneration &Key :V_Ket )
            {
            if (Key.Mark!=true)
            {
            LinePush =  _ConvertLineToFile(Key);
            Save<<LinePush<<endl;
            }
            }
            Save.close();
        }
    } 

     void  _Update(  )
     {
        vector<clsKeygeneration>V_Key =_LoadDataFromFile();
        if (V_Key.empty())return;
        for(clsKeygeneration&KK:V_Key)
        {
            if (KK.Password_Login==Password_Login)
            {
                KK = *this;
            }
        }
        _SaveDataToFile(V_Key);
     }


    void _AddDateToFile(clsKeygeneration& key)/// this Big O(1)
    {
      
        fstream ADD  ("Key.txt" , ios::app|ios::out);
        if (ADD.is_open())
        {

           ADD<<_ConvertLineToFile(key)<<endl;
           ADD.close();
        }              
    }
    
    void _Add()
    {
  
      _Key = clsUtile::GenerateKey(clsUtile::enCharType::CapitalLetter);
      _DateTime = clsDate::DateAndTime();
    _AddDateToFile(*this);
    }
    
    
    public:
clsKeygeneration(E_Mode Mode, string First, string Last, string Email, string phone,string Country, string City, string Street, string Key,string DateTime, string Password) 
                 : clsPerson(First, Last, Email, phone, Country, City, Street)
{
    _Key = Key; 
    _DateTime = DateTime;
    Password_Login = Password;
    _Mode = Mode;
}
    void SetPAssword(string Password) 
    {
        Password_Login = Password;

    }
    string Getpassword()
    {
        return Password_Login;
    }
  
   
    string GetDateTime()
    {
        return _DateTime;
    }
    string GetKey()
    {
        return _Key;
    }
  
    bool IsEmpty()
    {
     return(_Mode==E_Mode::E_empty);   
    }

    static clsKeygeneration FindKey(string Password)
    {
        fstream Find("Key.txt" , ios::in);
        if(Find.is_open())
        {
            string LIne ="";
            while (getline(Find , LIne))
            {
            clsKeygeneration Key = _convertLinetoObject(LIne);
            if (Key.Password_Login==Password)
            {
            Find.close();
            return Key;
            }
            }
            Find.close();
        }
       return GetEmptyToObject();
    }
    static bool IsExist(string Password)
    {
        clsKeygeneration KK = FindKey(Password);
         return (!KK.IsEmpty());/// this to return true if KK IS Not Empty ;;;  
    }

    enum SaveMods{svFaildEmptyObject =0 , svSucceeded =1 , svFaildKeyExists  =2  };
     SaveMods Save()
     {
        switch (_Mode)// this real of var 
        {
            
            case E_Mode::E_empty:
            {
                if(IsEmpty()) 
                {
                return SaveMods::svFaildEmptyObject;
                }
               
                
            }
            case E_Mode::E_update: 
            {
               _Update();
               return SaveMods::svSucceeded;
                break;
            }
            case E_Mode::E_add:
            {
                if (IsExist(Password_Login)) return SaveMods::svFaildKeyExists;
                _Add();
                _Mode = E_Mode::E_update;
                return SaveMods::svSucceeded;
            }
                break;
        } 
     }
     
     bool Delete(string Pass )
     {
        vector<clsKeygeneration>Del = _LoadDataFromFile();
        if (Del.empty())return false;
        for(clsKeygeneration & KK  : Del)
        {
            if (Pass==KK.Password_Login)
            {
               KK.Mark=true;
               break;
            }
        }
        _SaveDataToFile(Del);
        *this = GetEmptyToObject();
        return true;
     }
    
     static clsKeygeneration GetAdd(string Pass )
     {
         return clsKeygeneration( E_Mode::E_add, "","","", "" ,"","","" ,"","",Pass);
     }
    static vector<clsKeygeneration> GetAllKeys()
    {
        return _LoadDataFromFile();
    }
    
};
