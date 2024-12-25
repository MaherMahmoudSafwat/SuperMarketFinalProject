#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsDrawScreenHeader.h"
#include "clsUtil.h"
#include "clsAddProductScreen.h"
#include "clsDeleteProductFromCartScreen.h"
#include "clsViewAllProductsAddedToCart.h"

using namespace std;

template <typename T>

class clsAddProductToCartScreen:protected clsDrawScreenHeader<string>
{
private:
	enum enCustomerChoices { AddProductToCart = 1, DeleteProductFromCart = 2, ViewAllProductsAddedToCart = 3, Exit = 4 };
	static void _AddProductToCartScreen()
	{
		system("cls");
		clsAddProductScreen<void>::AddProductToCartScreen();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Customer Main Menu.\n";
		system("pause > 0");
	}
	static void _DeleteProductFromCartScreen()
	{
		system("cls");
		clsDeleteProductFromCartScreen<void>::DeleteFromCartScreen();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Customer Main Menu.\n";
		system("pause > 0");
	}
	static void _ViewAllProductsAddedToCartScreen()
	{
		system("cls");
		clsViewAllProductsAddedToCart<void>::ViewAllAddedToCartScreen();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Customer Main Menu.\n";
		system("pause > 0");
	}
	static void _PerformOperationsOnCustomerChoices(enCustomerChoices CustomerChoices)
	{
		switch (CustomerChoices)
		{
		case enCustomerChoices::AddProductToCart:
			_AddProductToCartScreen();
			ShowAddProductsToCart();
			break;
		case enCustomerChoices::DeleteProductFromCart:
			_DeleteProductFromCartScreen();
			ShowAddProductsToCart();
			break;
		case enCustomerChoices::ViewAllProductsAddedToCart:
			_ViewAllProductsAddedToCartScreen();
			ShowAddProductsToCart();
			break;
		case enCustomerChoices::Exit:
			break;
		}
	}
public:
	static void ShowAddProductsToCart()
	{
		string Number = "";
		do
		{
			system("cls");
			DrawHeaderScreen("Add Products To Cart", "", 6);
			cout << clsUtil<string>::NumberOfTabs(5) << "------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Please Choose one of the following.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "1-Add Product To Cart.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "2-Delete Product From Cart.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "3-View All Products Added To Cart.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "4-Exit.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "------------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			Number = clsInputValidate<string>::ReadString();
		} while (!clsInputValidate<bool>::ValidateInputNumber(1, 4, Number));
		_PerformOperationsOnCustomerChoices(enCustomerChoices(stoi(Number)));
	}
};

