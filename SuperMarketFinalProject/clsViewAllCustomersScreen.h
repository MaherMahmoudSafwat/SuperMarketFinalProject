#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "clsDrawScreenHeader.h"
#include "clsUtil.h"
#include "clsCustomerLoginBusinessLogic.h"

using namespace std;

template <typename T>

class clsViewAllCustomersScreen:protected clsDrawScreenHeader<string>
{
private:
	static void _ViewAllCustomersInfo(clsCustomerLoginBusinessLogic AllCustomersInfo)
	{
		cout << "| " << left << setw(7) << AllCustomersInfo.CustomerID;
		cout << "| " << left << setw(28) << AllCustomersInfo.CustomerName;
		cout << "| " << left << setw(30) << AllCustomersInfo.CustomerPassword;
		cout << "| " << left << setw(29) << AllCustomersInfo.CustomerEmail;
		cout << "| " << left << setw(15) << AllCustomersInfo.CustomerPhoneNumber;
		cout << "|" << endl;
		cout << "--------------------------------------------------------------------------------------------------------";
		cout << "----------------";
	}
public:
	static void ShowViewAllCustomersScreen()
	{
		system("cls");
		vector <clsCustomerLoginBusinessLogic> GetAllCustomersData = clsCustomerLoginBusinessLogic::GetAllCustomerInfoData();
		string Subtitle = "Number of Avaliable Customer(s) is " + to_string(GetAllCustomersData.size()) + " Customer(s)";
		DrawHeaderScreen("View All Customers Screen", Subtitle, 5);
		cout << "--------------------------------------------------------------------------------------------------------";
		cout << "----------------";
		cout << "| " << left << setw(7) << "ID";
		cout << "| " << clsUtil<string>::NumberOfSpaces(12) << left << setw(16) << "Name";
		cout << "| " << clsUtil<string>::NumberOfSpaces(12) << left << setw(18) << "Password";
		cout << "| " << clsUtil<string>::NumberOfSpaces(12) << left << setw(17) << "Email";
		cout << "| " << left << setw(15) << "Phone Number";
		cout << "|" << endl;
		cout << "--------------------------------------------------------------------------------------------------------";
		cout << "----------------";
		if (GetAllCustomersData.size() == 0)
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "There are no Avaliable Users in the system.\n";
		}
		else
		{
			for (clsCustomerLoginBusinessLogic& CustomerData : GetAllCustomersData)
			{
				_ViewAllCustomersInfo(CustomerData);
			}
		}
	}
};

