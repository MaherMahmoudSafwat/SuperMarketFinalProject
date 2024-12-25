#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsDrawScreenHeader.h"
#include "clsProductBusinessLogic.h"
#include "clsUtil.h"

using namespace std;

template <typename T>

class clsAddNewProductScreen :protected clsDrawScreenHeader<string>
{
private:
	static void _SetProductID(clsProductBusinessLogic & AddNewProduct)
	{
		AddNewProduct.SetProductID(clsUtil<int>::GetRandomNumber(1000000, 2000000));
		while (clsProductBusinessLogic::IsProductIdExists(AddNewProduct.GetProductID()))
		{
			AddNewProduct.SetProductID(clsUtil<int>::GetRandomNumber(1000000, 2000000));
		}
	}
	static void _SetProductName(clsProductBusinessLogic & AddNewProduct)
	{
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Product Name.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		AddNewProduct.SetProductName(clsInputValidate<string>::ReadString());
	}
	static void _SetProductPrice(clsProductBusinessLogic& AddNewProduct)
	{
		cout << clsUtil<string>::NumberOfTabs(5) << "Please Product Price.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		AddNewProduct.SetProductPrice(clsInputValidate<float>::ReadFloatNumber());
	}
	static void _SetProductQuantity(clsProductBusinessLogic& AddNewProduct)
	{
		cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Product Qunatity.\n";
		cout << clsUtil<string>::NumberOfTabs(5);
		AddNewProduct.SetProductQuantity(clsInputValidate<float>::ReadFloatNumber());
	}
public:
	static void ShowAddNewProductScreen()
	{
		system("cls");
		DrawHeaderScreen("Add New Product Screen", "", 6);
		clsProductBusinessLogic AddNewProduct(0, "", 0, 0);
		_SetProductID(AddNewProduct);
		_SetProductName(AddNewProduct);
		_SetProductPrice(AddNewProduct);
		_SetProductQuantity(AddNewProduct);
		AddNewProduct.AddNewProductToFile();
		cout << clsUtil<void>::NumberOfTabs(5) << "Product has been Added successfully.\n";
	}
};
