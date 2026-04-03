#pragma once 
#include<iostream>
using namespace std;
#include <iomanip>
#include"C:/Programing_For_Projects/KeysGnrtor/LogicalLeyer/clsKeygeneration.h"
#include"C:/Programing_For_Projects/KeysGnrtor/Librarys/clsInputValidate.h"
#include"C:/Programing_For_Projects/KeysGnrtor/Screens/clsShowAllKeys.h"
class  clsMainScreen
{
    enum En_oprethons{En_ShowMain =1, En_AddNewPerson =2  , En_DeletePerson  = 3 , En_FindPerson =4 , En_UPdatePerson =5};
 
  static  short ReadMain()
    {
          cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5 ? ");
        return Choice;

    }


 static  void _GoBackToMainMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowMainMenue();
    }

       static void _ShowAllScreen()
    {
        //cout << "\nClient List Screen Will be here...\n";
        clsShowAllKeys::ShowAllKeys();
    }

    static void _ShowAddNewScreen()
    {
        //cout << "\nAdd New Client Screen Will be here...\n";
    
    }

    static void _ShowDeleteScreen()
    {
        //cout << "\nDelete Client Screen Will be here...\n";
      
    }

    static void _ShowUpdateScreen()
    {
        //cout << "\nUpdate Client Screen Will be here...\n";
       
    }

    static void _ShowFindScreen()
    {
        //cout << "\nFind Client Screen Will be here...\n";
    
    }

    static void _ShowEndScreen()
    {
        system("pause>0");
        cout << "\nEnd Screen Will be here...\n";

    }

    
static void _PerfromMainMenueOption( En_oprethons MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case En_oprethons::En_ShowMain :
        { 
            system("cls");
            _ShowAllScreen();
            _GoBackToMainMenue();
            break;
        }
        case En_oprethons::En_AddNewPerson :
            system("cls");
            _ShowAddNewScreen();
            _GoBackToMainMenue();
            break;

        case En_oprethons::En_DeletePerson :
            system("cls");
            _ShowDeleteScreen();
            _GoBackToMainMenue();
            break;

        case En_oprethons::En_FindPerson :
            system("cls");
           _ShowUpdateScreen();
            _GoBackToMainMenue();
            break;

        case En_oprethons::En_UPdatePerson:
            system("cls");
           _ShowFindScreen();
            _GoBackToMainMenue();
            break;
            
            
    }
}

public:
static void ShowMainMenue()
    {

        system("cls");   
           
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show  List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New .\n";
        cout << setw(37) << left << "" << "\t[3] Update  .\n";
        cout << setw(37) << left << "" << "\t[4] Find .\n";
        cout << setw(37) << left << "" << "\t[5] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((En_oprethons)ReadMain());
    }

};