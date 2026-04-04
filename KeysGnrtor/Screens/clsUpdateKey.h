#include<iostream>
#pragma once
#include <iomanip>
#include<vector>
using namespace std;
#include"C:/Programing_For_Projects/KeysGnrtor/LogicalLeyer/clsKeygeneration.h"
class  clsUpdateKey
{
      static void Read(clsKeygeneration& Key)
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
    static void UpdateScreen()
    {
      string Password;
      cout<<"Enter Password : ";
      Password = clsInputValidate::ReadString();

       while (!clsKeygeneration::IsExist(Password))
       {
        cout<<"Try Again :) "<<endl;
        cout<<"Enter  Password ";
        Password = clsInputValidate::ReadString();
       }
       clsKeygeneration Keysave  = clsKeygeneration::FindKey(Password);
       Show(Keysave);
       char Anser = 'n';
       cout<<"Are Sure Update This Item : { Y  / N } : ";
       cin>>Anser;
       if (Anser=='y'||Anser=='Y')
       {
         
         clsKeygeneration::SaveMods Sav ;
         Sav = Keysave.Save(); 


         switch (Sav)
         {
         case  clsKeygeneration::SaveMods::svFaildEmptyObject :
         {
            cout<<"This Object Is Empty Sorry : "<<endl;
            return;
         }
         case clsKeygeneration::SaveMods::svFaildKeyExists:
         {
            cout<<"This Item Is Exist : "<<endl;
            return;
         }
         case clsKeygeneration::SaveMods::svSucceeded:
         {
              Read(Keysave);
            cout<<"Update Succeeded:) "<<endl;
            cout<<"Detals "<<endl;
            Show(Keysave);
         }
         default:
         return;
     
         }
       }
       else
       {
        cout<<"Don't:"<<endl;
       }
    

    }

};