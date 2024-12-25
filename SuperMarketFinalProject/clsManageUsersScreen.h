#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsDrawScreenHeader.h"
#include "clsUtil.h"
#include "clsCustomerSignUpScreen.h"
#include "clsFindUserScreen.h"
#include "clsShowUpdateUserSettingScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsViewAllCustomersScreen.h"

using namespace std;

template <typename T>

class clsManageUsersScreen:protected clsDrawScreenHeader<string>
{
private:
	enum enAdminChoices { AddNewCustomer = 1, FindCustomer = 2, UpdateCustomer = 3, DeleteCustomer = 4, ViewAllCustomers = 5, Exit = 6 };
	static void _AddNewCustomerScreen()
	{
		system("cls");
		clsCustomerSignUpScreen<void>::ShowCustomerSignUpScreen();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Admin Main Menu.\n";
		system("pause > 0");
	}
	static void _FindCustomerScreen()
	{
		system("cls");
		clsFindUserScreen<void>::ShowFindUserScreen();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Admin Main Menu.\n";
		system("pause > 0");
	}
	static void _UpdateCustomerScreen()
	{
		system("cls");
		clsShowUpdateUserSettingScreen<void>::UpdateUserSettingsScreen();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Admin Main Menu.\n";
		system("pause > 0");
	}
	static void _DeleteCustomerScreen()
	{
		system("cls");
		clsDeleteUserScreen<void>::ShowFindUserScreen();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Admin Main Menu.\n";
		system("pause > 0");
	}
	static void _ViewAllCustomersScreen()
	{
		system("cls");
		clsViewAllCustomersScreen<void>::ShowViewAllCustomersScreen();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Admin Main Menu.\n";
		system("pause > 0");
	}
	static void _PerformOperationsOnManageCustomersChoices(enAdminChoices AdminChoices)
	{
		switch (AdminChoices)
		{
		case enAdminChoices::AddNewCustomer:
			_AddNewCustomerScreen();
			ShowManageUsersScreenMainMenu();
			break;
		case enAdminChoices::FindCustomer:
			_FindCustomerScreen();
			ShowManageUsersScreenMainMenu();
			break;
		case enAdminChoices::UpdateCustomer:
			_UpdateCustomerScreen();
			ShowManageUsersScreenMainMenu();
			break;
		case enAdminChoices::DeleteCustomer:
			_DeleteCustomerScreen();
			ShowManageUsersScreenMainMenu();
			break;
		case enAdminChoices::ViewAllCustomers:
			_ViewAllCustomersScreen();
			ShowManageUsersScreenMainMenu();
			break;
		case enAdminChoices::Exit:
			break;
		}
	}
public:
	static void ShowManageUsersScreenMainMenu()
	{
		string Number = "";
		do
		{
			system("cls");
			DrawHeaderScreen("Manage Users Screen", "", 6);
			cout << clsUtil<string>::NumberOfTabs(5) << "------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Please Choose one of the following.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "1-Add New Customer.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "2-Find Customer.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "3-Update Customer.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "4-Delete Customer.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "5-View All Customers.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "6-Exit.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			Number = clsInputValidate<string>::ReadString();
		} while (!clsInputValidate<bool>::ValidateInputNumber(1, 6, Number));
		_PerformOperationsOnManageCustomersChoices(enAdminChoices(stoi(Number)));
	}
};

