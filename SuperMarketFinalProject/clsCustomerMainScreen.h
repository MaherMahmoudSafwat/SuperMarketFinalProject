#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsDrawScreenHeader.h"
#include "clsUtil.h"
#include "clsCustomerSignUpScreen.h"
#include "clsShowCustomerSignInScreen.h"

using namespace std;

template <typename T>

class clsCustomerMainScreen:protected clsDrawScreenHeader<void>
{
private:
	enum enCustomerChoices { CustomerSignIn = 1, CustomerSignUp = 2, Exit = 3 };
	static void _ShowCustomerSignInScreen()
	{
		system("cls");
		clsShowCustomerSignInScreen<void>::ShowCustomerSignInScreen();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Main Menu.\n";
		system("pause > 0");
	}
	static void _ShowCustomerSignUpScreen()
	{
		system("cls");
		clsCustomerSignUpScreen<void>::ShowCustomerSignUpScreen();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Main Menu.\n";
		system("pause > 0");
	}
	static void _PerformOperationsOnCustomerChoices(enCustomerChoices CustomerChoices)
	{
		switch (CustomerChoices)
		{
		case enCustomerChoices::CustomerSignIn:
			_ShowCustomerSignInScreen();
			ShowCustomerLoginScreen();
			break;
		case enCustomerChoices::CustomerSignUp:
			_ShowCustomerSignUpScreen();
			ShowCustomerLoginScreen();
			break;
		case enCustomerChoices::Exit:
			break;
		}
	}
public:
	static void ShowCustomerLoginScreen()
	{
		string Number = "";
		do
		{
			system("cls");
			DrawHeaderScreen("Customer Login Screen", "", 6);
			cout << clsUtil<string>::NumberOfTabs(5) << "------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Please Choose one of the following.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "1-Sign In.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "2-Sign Up.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "3-Exit.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			Number = clsInputValidate<string>::ReadString();
		} while (!clsInputValidate<bool>::ValidateInputNumber(1,3,Number));
		_PerformOperationsOnCustomerChoices(enCustomerChoices(stoi(Number)));
	}
};

