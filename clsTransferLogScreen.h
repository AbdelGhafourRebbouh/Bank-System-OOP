#pragma once
#include <iosTream>
#include "clsScreen.h"
#include <iomanip>
#include <vector>
#include "clsBankClient.h"
using namespace std;
class clsTransferLogScreen : protected clsScreen
{
private:
    static void _PrintTransaferRegisterRecordLine(clsBankClient::stTransactionLog LoginRegisterRecord)
    {

        cout << setw(8) << left << "" << "| " << setw(20) << left << LoginRegisterRecord.DateTime;
        cout << "| " << setw(10) << left << LoginRegisterRecord.AccountNumberSender;
        cout << "| " << setw(10) << left << LoginRegisterRecord.AccountNumberResevir;
        cout << "| " << setw(10) << left << LoginRegisterRecord.amount;
        cout << "| " << setw(10) << left << LoginRegisterRecord.balanceSender;
        cout << "| " << setw(10) << left << LoginRegisterRecord.balanceResivar;
        cout << "| " << setw(10) << left << LoginRegisterRecord.UserName;
    }
public:
    static void ShowTransferLogScreen() {
        vector<clsBankClient::stTransactionLog> vTranactionAllLog;
        vTranactionAllLog = clsBankClient::GetAllTheTransferLogList();

        string Title = "\tTranafer Register List Screen";
        string SubTitle = "\t\t(" + to_string(vTranactionAllLog.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Date/Time";
        cout << "| " << left << setw(10) << "S AccNum";
        cout << "| " << left << setw(10) << "R AccNum";
        cout << "| " << left << setw(10) << "Amount";
        cout << "| " << left << setw(10) << "S Balanc";
        cout << "| " << left << setw(10) << "R Balanc";
        cout << "| " << left << setw(10) << "UserName";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vTranactionAllLog.size() == 0)
            cout << "\t\t\t\tNo Transafre Available In the System!";
        else

            for (clsBankClient::stTransactionLog Record : vTranactionAllLog)
            {

                _PrintTransaferRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

