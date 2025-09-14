#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;
class clsShowCurrencyUpdateScreen : protected clsScreen
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

	static void ShowUpdateCurrencyScreen() {
		_DrawScreenHeader("UpdateScreen");
		cout << "enter the current Code : ";
		string code = clsInputValidate::ReadString();
		clsCurrency TheUpdated = clsCurrency::FindByCode(code);
		_PrintCurrencyCard(TheUpdated);
		cout << "\nare you sour to update this one(y, n) : ";
		char answer;
		cin >> answer;
		if (toupper(answer) == 'Y') {
			cout << "\n enter the new Rate : ";
			float newRate = clsInputValidate::ReadFloatNumber();
			TheUpdated.UpdateRate(newRate);
			cout << "\nUpdate is succsefoly ; \n";
			cout << "the update currentyr is thei : \n";
			_PrintCurrencyCard(TheUpdated);
		}
		else {
			cout << "\nUpdate is cunsel : \n";
		}

	}

};

