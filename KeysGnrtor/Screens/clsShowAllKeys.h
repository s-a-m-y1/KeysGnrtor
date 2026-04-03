#include<iostream>
#pragma once
#include <iomanip>
#include<vector>
using namespace std;
#include"C:/Programing_For_Projects/KeysGnrtor/LogicalLeyer/clsKeygeneration.h"
class clsShowAllKeys
{

    static void Print(clsKeygeneration KeyPass  )
    {
      
     cout << setw(8) << left << "" << left << setw(12) <<KeyPass.GetKey() ;
        cout<< setw(10) << left <<KeyPass.GetFirstName();
        cout<< setw(10) << left <<KeyPass.GetLastName() ;
        cout<< setw(10) << left <<KeyPass.GetEmail() ;
        cout<< setw(10) << left <<KeyPass.GetPhone() ;
        cout<< setw(10) << left <<KeyPass.GetCoutry() ;
        cout<< setw(10) << left <<KeyPass.GetCity() ;
        cout<< setw(10) << left <<KeyPass.GetStreet() ;
        cout<< setw(10) << left <<KeyPass.GetDateTime() ;
        cout<< setw(10) << left <<KeyPass.Getpassword() ;

    }

    
   public:
    static void ShowAllKeys()
    {
        /// step one load data from file
        vector<clsKeygeneration>V_Key =clsKeygeneration::GetAllKeys();

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tAll Keys\n";
        cout << setw(37) << left << "" << "===========================================\n";
           cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
        cout << setw(8) << left << "" << left << setw(12) << "Key";
        cout<<setw(10)<<left << "First Name" ;
        cout<<setw(10)<<left<< "Last Name" ;
        cout<<setw(10)<<left << "Email" ;
        cout<<setw(10) <<left<< "Phone" ;
        cout<<setw(10) <<left<< "Country" ;
        cout<<setw(10) <<left<< "City" ;
        cout<<setw(10) <<left<< "Street" ;
        cout<<setw(10) <<left<< "Date Time" ;
        cout<<setw(10) <<left<< "Password" ;
          cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
        if(V_Key.empty())
        {
         cout<< setw(37) << left << "No Keys To Show " << endl;
           
        }
        else
        {
            for(clsKeygeneration KeyPass : V_Key)
            {
                Print(KeyPass);
                cout<<endl;
            }

        }
        
         cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

       
    }






};