#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsDrawScreenHeader.h"
#include "clsUtil.h"
#include "clsManageUsersScreen.h"
#include "clsManageProductsScreen.h"
#include "clsViewInventory.h"
#include "clsViewAllSoldProductsMenu.h"
#include "clsAdminSettingScreen.h"

using namespace std;

template <typename T>

class clsShowAdminMainMenu:protected clsDrawScreenHeader<void>
{
private:
	enum enAdminChoices { ManageUsers = 1, ManageProducts = 2, ViewInventory = 3, ViewSalesProduct = 4, ChangeAdminPassword = 5, 
		Exit = 6 };
	static void _ManageUsersScreen()
	{
		system("cls");
		clsManageUsersScreen<void>::ShowManageUsersScreenMainMenu();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Admin Main Menu.\n";
		system("pause > 0");
	}
	static void _ManageProductsScreen()
	{
		system("cls");
		clsManageProductsScreen<void>::ShowManageProductsScreenMainMenu();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Admin Main Menu.\n";
		system("pause > 0");
	}
	static void _ViewInventoryScreen()
	{
		system("cls");
		clsViewInventory<void>::ShowInventoryScreen();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Admin Main Menu.\n";
		system("pause > 0");
	}
	static void _ViewSalesProduct()
	{
		system("cls");
		clsViewAllSoldProductsMenu<void>::ViewAllSoldProductsInfo();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Admin Main Menu.\n";
		system("pause > 0");
	}
	static void _ChangeAdminPassword()
	{
		system("cls");
		clsAdminSettingScreen<void>::UpdateAdminPassword();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Admin Main Menu.\n";
		system("pause > 0");
	}
	static void _PerformOperationsOnAdminChoices(enAdminChoices AdminChoices)
	{
		switch (AdminChoices)
		{
		case enAdminChoices::ManageProducts:
			_ManageProductsScreen();
			ShowAdminMainMenuScreen();
			break;
		case enAdminChoices::ManageUsers:
			_ManageUsersScreen();
			ShowAdminMainMenuScreen();
			break;
		case enAdminChoices::ViewInventory:
			_ViewInventoryScreen();
			ShowAdminMainMenuScreen();
			break;
		case enAdminChoices::ViewSalesProduct:
			_ViewSalesProduct();
			ShowAdminMainMenuScreen();
			break;
		case enAdminChoices::ChangeAdminPassword:
			_ChangeAdminPassword();
			ShowAdminMainMenuScreen();
			break;
		case enAdminChoices::Exit:
			break;
		}
	}
public:
	static void ShowAdminMainMenuScreen()
	{
		string Number = "";
		do
		{
			system("cls");
			DrawHeaderScreen("Admin Main Menu", "", 6);
			cout << clsUtil<string>::NumberOfTabs(5) << "---------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Choose one of the following :-\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "---------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "1-Manage Users.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "2-Manage Products.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "3-View Inventory.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "4-View Sales Product.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "5-Change Admin Password.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "6-Exit.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "---------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			Number = clsInputValidate<string>::ReadString();
		} while (!clsInputValidate<bool>::ValidateInputNumber(1,6,Number));
		_PerformOperationsOnAdminChoices(enAdminChoices(stoi(Number)));
	}
};

