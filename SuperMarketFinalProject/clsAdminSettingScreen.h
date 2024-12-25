#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsDrawScreenHeader.h"
#include "clsAdminLoginBusinessLogic.h"
#include "clsUtil.h"

using namespace std;

template <typename T>

class clsAdminSettingScreen:protected clsDrawScreenHeader<string>
{
private:
	static void _ChangeAdminPassword(string Password = "")
	{
		string ConfirmPassword = "";
		bool IsPasswordsTheSame = true;
		do
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter the your new Admin Password ?. \n";
			cout << clsUtil<string>::NumberOfTabs(5);
			Password = clsInputValidate<string>::ReadString();
			cout << clsUtil<string>::NumberOfTabs(5) << "Please confirm your new Admin Password ?. \n";
			cout << clsUtil<string>::NumberOfTabs(5);
			ConfirmPassword = clsInputValidate<string>::ReadString();
			IsPasswordsTheSame = !(Password == ConfirmPassword);
			if (IsPasswordsTheSame)
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "Passwords aren't the same , Please try again.\n";
				system("pause > 0");
			}
		} while (IsPasswordsTheSame);
		clsAdminLoginBusinessLogic<void>::ChangeAdminPassword(Password);
	}
public:
	static void UpdateAdminPassword()
	{
		system("cls");
		DrawHeaderScreen("Update Admin Settings Screen", "", 6);
		char Answer = 'Y';
		string Password = "";
		bool IsPasswordCorrect = true;
		do
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter your admin current password ? .\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			Password = clsInputValidate<string>::ReadString();
			IsPasswordCorrect = !clsAdminLoginBusinessLogic<bool>::IsAdminPasswordCorrect(Password);
			if (IsPasswordCorrect)
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "Invalid Password, Please try again.\n";
				system("pause > 0");
			}
		} while (IsPasswordCorrect);
		cout << clsUtil<string>::NumberOfTabs(5) << "Are you sure you want to change your the Admin Password ? Y/N ?.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			_ChangeAdminPassword(Password);
			cout << clsUtil<string>::NumberOfTabs(5) << "Admin Password has been changed Successfully :-) . \n";
		}
	}
};

