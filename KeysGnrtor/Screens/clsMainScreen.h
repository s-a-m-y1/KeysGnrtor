#pragma once 
#include<iostream>
using namespace std;
#include <iomanip>
#include"C:/Programing_For_Projects/KeysGnrtor/LogicalLeyer/clsKeygeneration.h"
#include"C:/Programing_For_Projects/KeysGnrtor/Librarys/clsInputValidate.h"
#include"C:/Programing_For_Projects/KeysGnrtor/Screens/clsShowAllKeys.h"
#include"C:/Programing_For_Projects/KeysGnrtor/Screens/clsAddNew.h"
#include"C:/Programing_For_Projects/KeysGnrtor/Screens/clsUpdateKey.h"
class  clsMainScreen
{
    enum En_oprethons{En_ShowMain =1, En_AddNewPerson =2 , En_UPdatePerson = 3,  En_FindPerson =4,  En_DeletePerson  = 5 ,mainMew  =6};
 
  static  short ReadMain()
    {
          cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6 ? ");
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
        clsAddNew::AddNewKey();
        //cout << "\nAdd New Client Screen Will be here...\n";
    
    }
      static void _ShowUpdateScreen()
    {
        clsUpdateKey::UpdateScreen();
        //cout <pdate Client Screen Will be here...\n";
    
    }
    static void _ShowFindScreen()
    {
    
    }

    static void _ShowDeleteScreen()
    {
     
        //cout << "\nDelete Client Screen Will be here...\n";
      
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
            case En_oprethons::En_UPdatePerson:
            system("cls");
           _ShowUpdateScreen();
            _GoBackToMainMenue();
            break;

        case En_oprethons::En_DeletePerson :
            system("cls");
            _ShowDeleteScreen();
            _GoBackToMainMenue();
            break;

      case En_oprethons::En_FindPerson :
            system("cls");
           _ShowFindScreen();
            _GoBackToMainMenue();
            break;

        case En_oprethons::mainMew :
            system("cls");
            
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
        cout << setw(37) << left << "" << "\t[5] Delete .\n";
        cout << setw(37) << left << "" << "\t[6] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromMainMenueOption((En_oprethons)ReadMain());
    }

};