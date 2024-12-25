#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsDrawScreenHeader.h"
#include "clsUtil.h"

using namespace std;

template <typename T>

class clsShowUpdateUserSettingScreen:protected clsDrawScreenHeader<string>
{
private:
	static void _SetCustomerName(clsCustomer& UpdateCustomerInfo)
	{
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter your New UserName.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		UpdateCustomerInfo.SetCustomerName(clsInputValidate<string>::ReadString());
	}
	static void _SetCustomerPassword(clsCustomer& UpdateCustomerInfo)
	{
		string ConfirmPassword = "";
		do
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter New Password.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			UpdateCustomerInfo.SetCustomerPassword(clsInputValidate<string>::ReadString());
			cout << clsUtil<string>::NumberOfTabs(5) << "Please Confirm Password.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			ConfirmPassword = clsInputValidate<string>::ReadString();
			if (ConfirmPassword != UpdateCustomerInfo.CustomerPassword)
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "Passwords don't match , Please try again.\n";
			}
		} while (ConfirmPassword != UpdateCustomerInfo.CustomerPassword);
	}
	static void _SetCustomerEmail(clsCustomer& UpdateCustomerInfo)
	{
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter New Email.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		UpdateCustomerInfo.SetCustomerEmail(clsInputValidate<string>::ReadString());
		while (clsCustomerLoginBusinessLogic::IsCustomerEmailExists(UpdateCustomerInfo.GetCustomerEmail()))
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "This Email Already Exists, Please enter another one.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			UpdateCustomerInfo.SetCustomerEmail(clsInputValidate<string>::ReadString());
		}
	}
	static void _SetCustomerPhoneNumber(clsCustomer& UpdateCustomerInfo)
	{
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter New PhoneNumber.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		UpdateCustomerInfo.SetCustomerPhoneNumber(clsInputValidate<string>::ReadString());
		while (clsCustomerLoginBusinessLogic::IsCustomerPhoneNumberExists(UpdateCustomerInfo.GetCustomerPhoneNumber()))
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "This Phone Number Already Exists, Please enter another one.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			UpdateCustomerInfo.SetCustomerPhoneNumber(clsInputValidate<string>::ReadString());
		}
	}
	static void _ShowNewUpdatedCustomerInfo(clsCustomerLoginBusinessLogic UpdateCustomerInfo)
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
	static void UpdateUserSettingsScreen(bool IsUpdatedByAdmin = true , int UserID = 0)
	{
		char Answer = 'Y';
		clsCustomerLoginBusinessLogic UpdateCustomerInfo(0, "", "", "", "");
		if (IsUpdatedByAdmin)
		{
			do
			{
				system("cls");
				DrawHeaderScreen("Update User Screen", "", 6);
				cout << clsUtil<string>::NumberOfTabs(5) << "Please enter User ID you want to find ? \n";
				cout << clsUtil<string>::NumberOfTabs(5);
				UserID = clsInputValidate<int>::ReadNumber();
				if (!clsCustomerLoginBusinessLogic::IsCustomerIdExists(UserID))
				{
					cout << clsUtil<string>::NumberOfTabs(5) << "This User Doesn't Exists , Please try again.\n";
					system("pause > 0");
				}
			} while (!clsCustomerLoginBusinessLogic::IsCustomerIdExists(UserID));
			UpdateCustomerInfo = clsCustomerLoginBusinessLogic::FindCustomerInfo(UserID);
		}
		else
		{
			system("cls");
			DrawHeaderScreen("Update Customer Settings Screen", "", 6);
			UpdateCustomerInfo = clsCustomerLoginBusinessLogic::FindCustomerInfo(UserID);
		}
		cout << clsUtil<string>::NumberOfTabs(5) << "Are you sure you want to update User Name ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			_SetCustomerName(UpdateCustomerInfo);
		}
		cout << clsUtil<string>::NumberOfTabs(5) << "Are you sure you want to update User Password ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			_SetCustomerPassword(UpdateCustomerInfo);
		}
		cout << clsUtil<string>::NumberOfTabs(5) << "Are you sure you want to update User Personal Email ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			_SetCustomerEmail(UpdateCustomerInfo);
		}
		cout << clsUtil<string>::NumberOfTabs(5) << "Are you sure you want to update User Personal Phone Number ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			_SetCustomerPhoneNumber(UpdateCustomerInfo);
		}
		cout << clsUtil<string>::NumberOfTabs(5) << "Are you sure you want to update User Personal Information ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			UpdateCustomerInfo.UpdateCustomerPersonalInfo();
			cout << clsUtil<void>::NumberOfTabs(5) << "Account has been Updated successfully.\n";
			_ShowNewUpdatedCustomerInfo(UpdateCustomerInfo);
		}
	}
};

