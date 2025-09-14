#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsShowCurrencyListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsShowCurrencyUpdateScreen.h"
#include "clsShowCurrencyCulculateScreen.h"
using namespace std;
class clsShowCurrencyExchangeScreen : protected clsScreen
{
private:
    enum enCurrencyExchangeOption {
        eList = 1, eFind = 2, eUpdate = 3, eCulculate = 4, eExit = 5
    };
    static short _ReadNemuber() {
        cout << setw(37) << left << "" << "Enter a Nember between 1 , 5 : ";
        short num = clsInputValidate::ReadIntNumberBetween(1, 5, "This is out of range enter anether : ");
        return num;
    }
    static void _GoBackToCurrencyExchange() {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to CurrenycEcxchagne Menue...\n";

        system("pause");
        ShowCurrencyExchange();
    }
    static void _ShowCurrencyListScreen() {
        clsShowCurrencyListScreen::ShowClientsList();
    }
    static void _ShowCurrencyFindScreen() {
        clsFindCurrencyScreen::ShowFindCurrentyScreen();
    }
    static void _ShowCurrencyUpdateScreen() {
        clsShowCurrencyUpdateScreen::ShowUpdateCurrencyScreen();
    }
    static void _ShowCurrencyCulculateScreen() {
        clsShowCurrencyCulculateScreen::ShowCalculaterScreen();
    }
    static void _ReadcurretyOption(enCurrencyExchangeOption num){
        switch (num) {
            case enCurrencyExchangeOption::eList:
            {
                system("cls");
                _ShowCurrencyListScreen();
                _GoBackToCurrencyExchange();
                break;
            }
            case enCurrencyExchangeOption::eFind:
            {
                system("cls");
                _ShowCurrencyFindScreen();
                _GoBackToCurrencyExchange();
                break;
            }
            case enCurrencyExchangeOption::eUpdate:
            {
                system("cls");
                _ShowCurrencyUpdateScreen();
                _GoBackToCurrencyExchange();
                break;
            }
            case enCurrencyExchangeOption::eCulculate:
            {
                system("cls");
                _ShowCurrencyCulculateScreen();
                _GoBackToCurrencyExchange();
                break;
            }
            case enCurrencyExchangeOption::eExit:
            {
                //emty mean end this class and back to mian meny
            }
        }
    }
public :
	static void ShowCurrencyExchange() {
        system("cls");
		_DrawScreenHeader("\tCurrencyExchange");
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrency Exchange\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencys\n";
        cout << setw(37) << left << "" << "\t[2] Find Currencys\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate\n";
        cout << setw(37) << left << "" << "\t[4] cCurrency Culculate\n";
        cout << setw(37) << left << "" << "\t[5] Main menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _ReadcurretyOption((enCurrencyExchangeOption)_ReadNemuber());
	}
};

