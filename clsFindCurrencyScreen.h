#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;
class clsFindCurrencyScreen : protected clsScreen
{
private:
	static void _PrintCurrencyCard(clsCurrency currency) {
		cout << "\n   Currenty Card    :\n";
		cout << "_________________________\n";
		cout << "coutnry : " << currency.Country() << endl; 
		cout << "code : " << currency.CurrencyCode() << endl;
		cout << "Name : " << currency.CurrencyName() << endl;
		cout << "Rate : " << currency.Rate() << endl;
		cout << "___________________________\n";
	}
public :
	static void ShowFindCurrentyScreen() {
		_DrawScreenHeader("FindCurrencyScreen");
		cout << "Do you need to search by Countyr [1] or code [2] : ";
		short tipeshearch = clsInputValidate::ReadShortNumberBetween(1, 2, "this is out of range enter anther: ");
		switch (tipeshearch) {
		case 1:
		{

			cout << "\nenter the Coutnry Name : ";
			string name = clsInputValidate::ReadString();
			clsCurrency TheCurrency = clsCurrency::FindByCountry(name);
			if (!(TheCurrency.IsEmpty())) {
				_PrintCurrencyCard(TheCurrency);
			}
			else {
				cout << "there isn't a code like this \n";
			}
			
			break;

		}
		case 2:
		{

			cout << "\nenter the Code : ";
			string code = clsInputValidate::ReadString();
			clsCurrency TheCurrencybycode = clsCurrency::FindByCode(code);
			if (!(TheCurrencybycode.IsEmpty())) {
				_PrintCurrencyCard(TheCurrencybycode);
			}
			else {
				cout << "there isn't a code like this ";
			}
			
			break;
		}
		}
		
	}
	
};

