#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsDrawScreenHeader.h"
#include "clsUtil.h"
#include "clsViewAllProductsScreen.h"
#include "clsCustomer.h"
#include "clsAddProductToCartScreen.h"
#include "clsPurchaseProductScreen.h"
#include "clsShowUpdateUserSettingScreen.h"
#include "clsCustomerGlobal.h"

using namespace std;

clsCustomerLoginBusinessLogic FindCustomer(0, "", "", "", "");

template <typename T>

class clsShowCustomerMainMenuScreen:protected clsDrawScreenHeader<string>
{
private:
	enum enCustomerChoices { ViewProducts = 1, AddProductToCart = 2, PurchaseProduct = 3, UpdateUserSettings = 4, Exit = 5 };
	static void _ShowViewProductsScreen()
	{
		system("cls");
		clsViewAllProductsScreen<void>::ViewAllProductsScreen();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Admin Main Menu.\n";
		system("pause > 0");
	}
	static void _ShowAddProductToCartScreen()
	{
		system("cls");
		clsAddProductToCartScreen<void>::ShowAddProductsToCart();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Admin Main Menu.\n";
		system("pause > 0");
	}
	static void _ShowPurchaseProductScreen()
	{
		system("cls");
		clsPurchaseProductScreen::ShowPurchaseProductScreen();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Admin Main Menu.\n";
		system("pause > 0");
	}	
	static void _ShowUpdateUserSettingsScreen()
	{
		system("cls");
		clsShowUpdateUserSettingScreen<void>::UpdateUserSettingsScreen(false,Customer.GetCustomerID());
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Admin Main Menu.\n";
		system("pause > 0");
	}
	static void _PerformOperationsOnCustomerChoices(enCustomerChoices CustomerChoices)
	{
		switch (CustomerChoices)
		{
		case enCustomerChoices::ViewProducts:
			_ShowViewProductsScreen();
			ShowCustomerMainMenu();
			break;
		case enCustomerChoices::AddProductToCart:
			_ShowAddProductToCartScreen();
			ShowCustomerMainMenu();
			break;
		case enCustomerChoices::PurchaseProduct:
			_ShowPurchaseProductScreen();
			ShowCustomerMainMenu();
			break;
		case enCustomerChoices::UpdateUserSettings:
			_ShowUpdateUserSettingsScreen();
			ShowCustomerMainMenu();
			break;
		case enCustomerChoices::Exit:
			break;
		}
	}
public:
	static void ShowCustomerMainMenu()
	{
		string Number = "";
		string Subtitle = "";
		Subtitle = "Welcome " + Customer.CustomerName+ " To SuperMarket";
		do
		{
			system("cls");
			DrawHeaderScreen("Customer Main Menu",Subtitle,6);
			cout << clsUtil<string>::NumberOfTabs(5) << "-----------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Choose one of the following.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "-----------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "1-View All Products.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "2-Add Product To Cart.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "3-Purchase Product.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "4-Update User Settings.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "5-Exit.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "-----------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			Number = clsInputValidate<string>::ReadString();
		} while (!clsInputValidate<bool>::ValidateInputNumber(1, 5, Number));
		_PerformOperationsOnCustomerChoices(enCustomerChoices(stoi(Number)));
	}
};

