#pragma once
#include <iostream>
#include "clsCurrency.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;
class clsShowCurrencyCulculateScreen : protected clsScreen
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
	static void ShowCalculaterScreen() {
		char answer;
		do{
			system("cls");
			_DrawScreenHeader("Culculater Currency");
			
			cout << "enter the Currenty code 1(from) : ";
			string CodeFrom = clsInputValidate::ReadString();
			clsCurrency CurrencyFrom = clsCurrency::FindByCode(CodeFrom);
			while (CurrencyFrom.IsEmpty()) {
				cout << "thre isn't a currenyc whit this naem enter an ehter : ";
				string CodeFrom = clsInputValidate::ReadString();
				clsCurrency CurrencyFrom = clsCurrency::FindByCode(CodeFrom);
			}
			cout << "\nenter the Currenty code 2(to) : ";
			string CodeTo = clsInputValidate::ReadString();
			clsCurrency CurrencyTo = clsCurrency::FindByCode(CodeTo);

			while (CurrencyTo.IsEmpty()) {
				cout << "thre isn't a currenyc whit this naem enter an ehter : ";
				string CodeTo = clsInputValidate::ReadString();
			}

			cout << "\nenter the amount : ";
			float amount = clsInputValidate::ReadFloatNumber();

			if (CurrencyTo.CurrencyCode() == "USD") {
				_PrintCurrencyCard(CurrencyFrom);
				cout << CurrencyFrom.CurrencyCode() << " To Usd : " << clsCurrency::FromCurrentyToUsd(amount, CurrencyFrom.Rate());
			}
			else {
				_PrintCurrencyCard(CurrencyFrom);
				float thenewamount = clsCurrency::FromCurrentyToUsd(amount, CurrencyFrom.Rate());
				cout << CurrencyFrom.CurrencyCode() << " To Usd : " << thenewamount ;
				cout << "\tUse To : ";
				_PrintCurrencyCard(CurrencyTo);
				cout << "From USD To : " << CurrencyTo.CurrencyCode() << " = " << clsCurrency::FromUsdToCurrenty(thenewamount, CurrencyTo.Rate());
			}
			
			cout << "\n do you want to do anether culculation (y,n) : ";
			cin >> answer; 

		} while (toupper(answer) == 'Y');
		
	}
};

