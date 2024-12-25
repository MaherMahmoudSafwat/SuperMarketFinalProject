#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsDrawScreenHeader.h"
#include "clsCustomerLoginBusinessLogic.h"
#include "clsUtil.h"

using namespace std;

template <typename T>

class clsCustomerSignUpScreen:protected clsDrawScreenHeader<string>
{
private:
	static void _SetCustomerID(clsCustomer & AddNewCustomer)
	{
		AddNewCustomer.SetCustomerID(clsUtil<int>::GetRandomNumber(1000000, 2000000));
		while (clsCustomerLoginBusinessLogic::IsCustomerIdExists(AddNewCustomer.GetCustomerID()))
		{
			AddNewCustomer.SetCustomerID(clsUtil<int>::GetRandomNumber(1000000, 2000000));
		}
	}
	static void _SetCustomerName(clsCustomer& AddNewCustomer)
	{
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter UserName.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		AddNewCustomer.SetCustomerName(clsInputValidate<string>::ReadString());
	}
	static void _SetCustomerPassword(clsCustomer& UpdateCustomerInfo)
	{
		string ConfirmPassword = "";
		do
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter New Password.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			UpdateCustomerInfo.SetCustomerPassword(clsInputValidate<string>::ReadString());
			cout << clsUtil<string>::NumberOfTabs(5) << "Please Confirm Your Password.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			ConfirmPassword = clsInputValidate<string>::ReadString();
			if (ConfirmPassword != UpdateCustomerInfo.CustomerPassword)
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "Passwords don't match , Please try again.\n";
			}
		} while (ConfirmPassword != UpdateCustomerInfo.CustomerPassword);
	}
	static void _SetCustomerEmail(clsCustomer& AddNewCustomer)
	{
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Email.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		AddNewCustomer.SetCustomerEmail(clsInputValidate<string>::ReadString());
		while (clsCustomerLoginBusinessLogic::IsCustomerEmailExists(AddNewCustomer.GetCustomerEmail()))
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "This Email Already Exists, Please enter another one.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			AddNewCustomer.SetCustomerEmail(clsInputValidate<string>::ReadString());
		}
	}
	static void _SetCustomerPhoneNumber(clsCustomer& AddNewCustomer)
	{
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter PhoneNumber.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		AddNewCustomer.SetCustomerPhoneNumber(clsInputValidate<string>::ReadString());
		while (clsCustomerLoginBusinessLogic::IsCustomerPhoneNumberExists(AddNewCustomer.GetCustomerPhoneNumber()))
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "This Phone Number Already Exists, Please enter another one.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			AddNewCustomer.SetCustomerPhoneNumber(clsInputValidate<string>::ReadString());
		}
	}
public:
	static void ShowCustomerSignUpScreen()
	{
		system("cls");
		DrawHeaderScreen("Customer Sign Up Screen", "", 6);
		clsCustomerLoginBusinessLogic AddNewCustomer(0, "", "", "", "");
		_SetCustomerID(AddNewCustomer);
		_SetCustomerName(AddNewCustomer);
		_SetCustomerPassword(AddNewCustomer);
		_SetCustomerEmail(AddNewCustomer);
		_SetCustomerPhoneNumber(AddNewCustomer);
		AddNewCustomer.AddNewCustomerLoginSignUp();
		cout << clsUtil<void>::NumberOfTabs(5) << "Account has been created successfully.\n";
	}
};

