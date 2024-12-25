#pragma once
#include <iostream>
#include "clsDrawScreenHeader.h"
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsAdminMainScreen.h"
#include "clsCustomerMainScreen.h"

using namespace std;

template <typename T>

class clsMainScreenMenu :protected clsDrawScreenHeader<string>
{
private:
	enum enUserChoice {Admin = 1, Customer = 2};
	static void _ShowAdminScreen()
	{
		system("cls");
		clsAdminMainScreen<void>::ShowAdminMainScreen();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key , to go back to main menu.\n";
		system("pause > 0");
	}
	static void _ShowCustomerScreen()
	{
		system("cls");
		clsCustomerMainScreen<void>::ShowCustomerLoginScreen();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key , to go back to main menu.\n";
		system("pause > 0");
	}
	static void _UserChoice(enUserChoice UserChoice)
	{
		switch (UserChoice)
		{
		case enUserChoice::Admin:
			_ShowAdminScreen();
			ShowMainMenuScreen();
			break;
		case enUserChoice::Customer:
			_ShowCustomerScreen();
			ShowMainMenuScreen();
			break;
		}
	}
public:
	static void ShowMainMenuScreen()
	{
		string Number = "";
		do
		{
			system("cls");
			DrawHeaderScreen("Welcome To Supermarket Full Website", "", 5);
			cout << clsUtil<string>::NumberOfTabs(5) << "--------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Choose one of the following Roles :- \n";
			cout << clsUtil<string>::NumberOfTabs(5) << "--------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "1-Admin.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "2-Customer.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "--------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Choose between 1 or 2 :- ";
			Number = clsInputValidate<string>::ReadString();
		} while (!clsInputValidate<bool>::ValidateInputNumber(1,2,Number));
		_UserChoice(enUserChoice(stoi(Number)));
		system("pause > 0");
	}
};