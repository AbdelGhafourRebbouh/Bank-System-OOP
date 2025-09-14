#pragma once
#include <iostream>
#include "clsCurrency.h"
#include <iomanip>
#include "clsScreen.h"
using namespace std;
class clsShowCurrencyListScreen : protected clsScreen
{

private:
    static void PrintClientRecordLine(clsCurrency Client)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << Client.Country();
        cout << "| " << setw(4) << left << Client.CurrencyCode();
        cout << "| " << setw(40) << left << Client.CurrencyName();
        cout << "| " << setw(7) << left << Client.Rate();
      

    }

public:

    static void ShowClientsList()
    {

       

        vector <clsCurrency> vClients = clsCurrency::GetCurrenciesList();
        string Title = "\t  Currency List Screen";
        string SubTitle = "\t    (" + to_string(vClients.size()) + ") Currency(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(4) << "Code";
        cout << "| " << left << setw(40) << "Name";
        cout << "| " << left << setw(7) << "Rate(1$)";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vClients.size() == 0)
            cout << "\t\t\t\tNo Currenty Available In the System!";
        else

            for (clsCurrency Client : vClients)
            {

                PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

