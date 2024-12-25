#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsDrawScreenHeader.h"
#include "clsProductBusinessLogic.h"
#include "clsProductCartBusinessLogic.h"
#include "clsUtil.h"
#include "clsCustomerGlobal.h"

using namespace std;

template <typename T>

class clsAddProductScreen:protected clsDrawScreenHeader<string>
{
private:
	static void _ShowProductInfo(clsProductBusinessLogic ProductInfo)
	{
		string ProductPrice = to_string(ProductInfo.ProductPrice) + " L.E.";
		cout << clsUtil<string>::NumberOfTabs(5) << "------------------------------------------------------------------------------\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Product Info\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "------------------------------------------------------------------------------\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Product ID       : " << ProductInfo.ProductID << "\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Product Name     : " << ProductInfo.ProductName << "\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Product Price    : " << ProductPrice << "\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "Product Quantity : " << ProductInfo.ProductQuantity << "\n";
		cout << clsUtil<string>::NumberOfTabs(5) << "------------------------------------------------------------------------------\n";
	}
public:
	static void AddProductToCartScreen()
	{
		clsProductBusinessLogic FindProduct(0, "", 0, 0);
		int ProductId = 0;
		char Answer = 'Y';
		do
		{
			system("cls");
			DrawHeaderScreen("Add Product To Cart Screen", "", 6);
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Product ID you want to Add to cart ? \n";
			cout << clsUtil<string>::NumberOfTabs(5);
			ProductId = clsInputValidate<int>::ReadNumber();
			if (!clsProductBusinessLogic::IsProductIdExists(ProductId))
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "This Product Doesn't Exists , Please try again.\n";
				system("pause > 0");
			}
		} while (!clsProductBusinessLogic::IsProductIdExists(ProductId));
		FindProduct = clsProductBusinessLogic::FindProduct(ProductId);
		_ShowProductInfo(FindProduct);
		cout << clsUtil<string>::NumberOfTabs(5) << "Are you sure you want to add this product to cart ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			clsProductCartBusinessLogic::AddProductToCart(ProductId);
			cout << clsUtil<string>::NumberOfTabs(5) << "Product has been added to cart successfully.\n";
		}
	}
};

