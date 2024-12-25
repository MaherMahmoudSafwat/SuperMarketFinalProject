#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsDrawScreenHeader.h"
#include "clsUtil.h"
#include "clsAddNewProductScreen.h"
#include "clsFindProductScreen.h"
#include "clsUpdateProductScreen.h"
#include "clsDeleteProductScreen.h"
#include "clsViewAllProductsScreen.h"

using namespace std;

template <typename T>

class clsManageProductsScreen:protected clsDrawScreenHeader<string>
{
private:
	enum enAdminChoices { AddNewProduct = 1, FindProduct = 2, UpdateProduct = 3, DeleteProduct = 4, ViewAllProducts = 5, Exit = 6 };
	static void _AddNewProductScreen()
	{
		system("cls");
		clsAddNewProductScreen<void>::ShowAddNewProductScreen();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Admin Main Menu.\n";
		system("pause > 0");
	}
	static void _FindProductScreen()
	{
		system("cls");
		clsFindPoductScreen<void>::ShowFindProductScreen();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Admin Main Menu.\n";
		system("pause > 0");
	}
	static void _UpdateProductScreen()
	{
		system("cls");
		clsUpdateProductScreen<void>::ShowUpdateProductScreen();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Admin Main Menu.\n";
		system("pause > 0");
	}
	static void _DeleteProductScreen()
	{
		system("cls");
		clsDeleteProductScreen<void>::ShowDeleteProductScreen();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Admin Main Menu.\n";
		system("pause > 0");
	}
	static void _ViewAllProductsScreen()
	{
		system("cls");
		clsViewAllProductsScreen<void>::ViewAllProductsScreen();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Admin Main Menu.\n";
		system("pause > 0");
	}
	static void _PerformOperationsOnManageProductsChoices(enAdminChoices AdminChoices)
	{
		switch (AdminChoices)
		{
		case enAdminChoices::AddNewProduct:
			_AddNewProductScreen();
			ShowManageProductsScreenMainMenu();
			break;
		case enAdminChoices::FindProduct:
			_FindProductScreen();
			ShowManageProductsScreenMainMenu();
			break;
		case enAdminChoices::UpdateProduct:
			_UpdateProductScreen();
			ShowManageProductsScreenMainMenu();
			break;
		case enAdminChoices::DeleteProduct:
			_DeleteProductScreen();
			ShowManageProductsScreenMainMenu();
			break;
		case enAdminChoices::ViewAllProducts:
			_ViewAllProductsScreen();
			ShowManageProductsScreenMainMenu();
			break;
		case enAdminChoices::Exit:
			break;
		}
	}
public:
	static void ShowManageProductsScreenMainMenu()
	{
		string Number = "";
		do
		{
			system("cls");
			DrawHeaderScreen("Manage Products Screen", "", 6);
			cout << clsUtil<string>::NumberOfTabs(5) << "------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Please Choose one of the following.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "1-Add New Product.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "2-Find Product.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "3-Update Product.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "4-Delete Product.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "5-View All Products.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "6-Exit.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			Number = clsInputValidate<string>::ReadString();
		} while (!clsInputValidate<bool>::ValidateInputNumber(1, 6, Number));
		_PerformOperationsOnManageProductsChoices(enAdminChoices(stoi(Number)));
	}
};

