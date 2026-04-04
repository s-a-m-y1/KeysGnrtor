#include<iostream>
#include"C:/Programing_For_Projects/KeysGnrtor/LogicalLeyer/clsKeygeneration.h"
using namespace std;
#pragma once
class clsAddNew 
{
    private:
    static void ReadAdd(clsKeygeneration& Key)
    {
        cout<<"Enter First Name : ";
        Key.SetFirstName(clsInputValidate::ReadString());
        cout<<"Enter Last Name : ";
        Key.SetLastName(clsInputValidate::ReadString());
        cout<<"Enter Email : ";
        Key.SetEmail(clsInputValidate::ReadString());
        cout<<"Enter Phone : ";
        Key.SetPhone(clsInputValidate::ReadString());
        cout<<"Enter Country : ";
        Key.SetCounrty(clsInputValidate::ReadString());
        cout<<"Enter City : ";
        Key.SetCity(clsInputValidate::ReadString());
        cout<<"Enter Street : ";
        Key.SetStreet(clsInputValidate::ReadString());
        
    }

    static void Show( clsKeygeneration& Key)
    {
        cout<<"============================================\n";
         cout<<"Key : "<<Key.GetKey()<<endl;
        cout<<"First Name : "<<Key.GetFirstName()<<endl;
        cout<<"Last Name : "<<Key.GetLastName()<<endl;
        cout<<"Email : "<<Key.GetEmail()<<endl;
        cout<<"Phone : "<<Key.GetPhone()<<endl;
        cout<<"Country : "<<Key.GetCoutry()<<endl;
        cout<<"City : "<<Key.GetCity()<<endl;
        cout<<"Street : "<<Key.GetStreet()<<endl;
        cout<<"DateTime : "<<Key.GetDateTime()<<endl;
        cout<<"Password : "<<Key.Getpassword()<<endl;
        cout<<"============================================\n";
    }
    public:
    static void AddNewKey()
    {
        cout<<"Please Enter  Password : ";
        string Passowrd = clsInputValidate::ReadString();
        while (clsKeygeneration::IsExist(Passowrd))
        {
          cout<<"Try again  Enter  Password : ";
        string Passowrd = clsInputValidate::ReadString();
        }
     clsKeygeneration AddKey =  clsKeygeneration ::GetAdd(Passowrd);
     ReadAdd(AddKey);
 clsKeygeneration::SaveMods SaveMode;

    SaveMode = AddKey.Save();

    switch (SaveMode)
    {
    case clsKeygeneration::SaveMods::svFaildEmptyObject:
    {
        cout<<"Error This operation : "<<endl;/// the End line this Empty Pufer
       return;
    }
     case clsKeygeneration::SaveMods::svFaildKeyExists :
    {
        cout<<" Sorry This Password Is Exist : "<<endl;/// the End line this Empty Pufer
       return;
    }
    case clsKeygeneration::SaveMods::svSucceeded:
    {
        cout<<"Save This operation Is succeeded : "<<endl;
        cout<<"This Result :-) "<<endl;
         Show(AddKey);
        return;
    }
    }
           
     }
     
    // save 
   

    
};