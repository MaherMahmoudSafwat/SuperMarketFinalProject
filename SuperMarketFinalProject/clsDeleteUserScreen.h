#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsCustomerLoginBusinessLogic.h"
#include "clsDrawScreenHeader.h"
#include "clsUtil.h"

using namespace std;

template <typename T>

class clsDeleteUserScreen:protected clsDrawScreenHeader<string>
{
private:
	static void _ShowCustomerInfo(clsCustomerLoginBusinessLogic UpdateCustomerInfo)
	{
		cout << clsUtil<string>::NumberOfTabs(5) << "-----------------------------------------------------------------------------\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Customer Info.\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "-----------------------------------------------------------------------------\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Customer ID          : " << UpdateCustomerInfo.CustomerID << endl;
		cout << clsUtil<string>::NumberOfTabs(5) << "Customer Name        : " << UpdateCustomerInfo.CustomerName << endl;
		cout << clsUtil<string>::NumberOfTabs(5) << "Customer Password    : " << UpdateCustomerInfo.CustomerPassword << endl;
		cout << clsUtil<string>::NumberOfTabs(5) << "Customer Email       : " << UpdateCustomerInfo.CustomerEmail << endl;
		cout << clsUtil<string>::NumberOfTabs(5) << "Customer PhoneNumber : " << UpdateCustomerInfo.CustomerPhoneNumber << endl;
		cout << clsUtil<string>::NumberOfTabs(5) << "-----------------------------------------------------------------------------\n";
	}
public:
	static void ShowFindUserScreen()
	{
		char Answer = 'Y';
		int UserID = 0;
		do
		{
			system("cls");
			DrawHeaderScreen("Delete User Screen", "", 6);
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter User ID you want to delete ? \n";
			cout << clsUtil<string>::NumberOfTabs(5);
			UserID = clsInputValidate<int>::ReadNumber();
			if (!clsCustomerLoginBusinessLogic::IsCustomerIdExists(UserID))
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "This User Doesn't Exists , Please try again.\n";
				system("pause > 0");
			}
		} while (!clsCustomerLoginBusinessLogic::IsCustomerIdExists(UserID));
		clsCustomerLoginBusinessLogic FindCustomerInfo = clsCustomerLoginBusinessLogic::FindCustomerInfo(UserID);
		_ShowCustomerInfo(FindCustomerInfo);
		cout << clsUtil<string>::NumberOfTabs(5) << "Are you sure you want to delete this Customer User ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			FindCustomerInfo.DeleteCustomerInfo();
			cout << clsUtil<string>::NumberOfTabs(5) << "Customer Info has been deleted Successfully.\n";
		}
	}
};



