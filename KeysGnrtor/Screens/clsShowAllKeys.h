#include<iostream>
#pragma once
#include <iomanip>
#include<vector>
using namespace std;
#include"C:/Programing_For_Projects/KeysGnrtor/LogicalLeyer/clsKeygeneration.h"
class clsShowAllKeys
{
      static void _Print(clsKeygeneration KeyPass)
    {

        cout << setw(8) << left << "" << "| " << left << setw(11) << KeyPass.GetFirstName();
        cout << "| " << setw(12) << left << KeyPass.GetLastName() ;
        cout << "| " << setw(20) << left << KeyPass.GetEmail();
        cout << "| " << setw(12) << left << KeyPass.GetPhone() ;
        cout << "| " << setw(10) << left << KeyPass.GetCoutry() ;
        cout << "| " << setw(10) << left << KeyPass.GetCity() ;
        cout << "| " << setw(15) << left << KeyPass.GetStreet() ;
        cout << "| " << setw(25) << left << KeyPass.GetKey() ;
        cout << "| " << setw(25) << left << KeyPass .GetDateTime() ;
        cout << "| " << setw(20) << left << KeyPass.Getpassword() ;

    }

   

    
   public:
    static void ShowAllKeys()
    {
        ///   First,  Last,  Email,  phone, Country,  City,  Street,  Key,  Password) 
        vector<clsKeygeneration>V_Key =clsKeygeneration::GetAllKeys();
          cout << setw(45) << left << "" << "===========================================\n";
        cout << setw(40) << left << "" << "\t\t\tAll\n";
        cout << setw(45) << left << "" << "===========================================\n";
        system("Color 4"); 
        cout <<" " << "\n\t______________________________________________________________________________________________________________";
        cout<<"__________________________________________________________\n" << endl;

       cout << setw(8) << left << "" << "| " << left << setw(11) << "First";
        cout << "| " << left << setw(12) << "Last";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(10) << "Country";
        cout << "| " << left << setw(10) << "City";
        cout << "| " << left << setw(15) << "Street";
        cout << "| " << left << setw(25) << "Key";
         cout << "| " << setw(25) << left << "DateTime" ;
        cout << "| " << left << setw(20) << "Password";
        cout << " " << "\n\t______________________________________________________________________________________________________________";
            cout<<"__________________________________________________________\n" << endl;
        if(V_Key.empty())
        {
         cout<< setw(37) << left << "No Keys To Show " << endl;
           
        }
        else
        {
            for(clsKeygeneration KeyPass : V_Key)
            {
                _Print(KeyPass);
                cout<<endl;
            }

        }
        
        cout << setw(8) << left << "| " << "\n\t______________________________________________________________________________________________________________";
        cout<<"__________________________________________________________\n" << endl;
       
    }






};

