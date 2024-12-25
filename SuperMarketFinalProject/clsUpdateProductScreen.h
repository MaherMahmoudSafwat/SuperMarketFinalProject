#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsDrawScreenHeader.h"
#include "clsProductBusinessLogic.h"
#include "clsUtil.h"

using namespace std;

template <typename T>

class clsUpdateProductScreen :protected clsDrawScreenHeader<string>
{
private:
	static void _SetProductName(clsProductBusinessLogic & UpdateProduct)
	{
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Product Name.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		UpdateProduct.SetProductName(clsInputValidate<string>::ReadString());
	}
	static void _SetProductPrice(clsProductBusinessLogic & UpdateProduct)
	{
		cout << clsUtil<string>::NumberOfTabs(5) << "Please Product Price.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		UpdateProduct.SetProductPrice(clsInputValidate<float>::ReadFloatNumber());
	}
	static void _SetProductQuantity(clsProductBusinessLogic & UpdateProduct)
	{
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Product Qunatity.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		UpdateProduct.SetProductQuantity(clsInputValidate<float>::ReadFloatNumber());
	}
public:
	static void ShowUpdateProductScreen()
	{
		system("cls");
		DrawHeaderScreen("Update Product Screen", "", 6);
		clsProductBusinessLogic UpdateProduct(0, "", 0, 0);
		int ProductId = 0;
		char Answer = 'Y';
		do
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Product ID you want to Update ? \n";
			cout << clsUtil<string>::NumberOfTabs(5);
			ProductId = clsInputValidate<int>::ReadNumber();
			if (!clsProductBusinessLogic::IsProductIdExists(ProductId))
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "This Product Doesn't Exists , Please try again.\n";
				system("pause > 0");
			}
		} while (!clsProductBusinessLogic::IsProductIdExists(ProductId));
		UpdateProduct = clsProductBusinessLogic::FindProduct(ProductId);
		cout << clsUtil<string>::NumberOfTabs(5) << "Do you want to update product name ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			_SetProductName(UpdateProduct);
		}
		cout << clsUtil<string>::NumberOfTabs(5) << "Do you want to update product Price ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			_SetProductPrice(UpdateProduct);
		}
		cout << clsUtil<string>::NumberOfTabs(5) << "Do you want to update product Avaliable Quantity ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			_SetProductQuantity(UpdateProduct);
		}
		cout << clsUtil<string>::NumberOfTabs(5) << "Are you sure you want to update product info ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			UpdateProduct.UpdateProduct();
		}
		cout << clsUtil<void>::NumberOfTabs(5) << "Product has been Added successfully.\n";
	}
};
