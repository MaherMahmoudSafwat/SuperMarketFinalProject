#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsDrawScreenHeader.h"
#include "clsProductInventoryBusinessLogic.h"
#include "clsUtil.h"

using namespace std;

template <typename T>

class clsViewInventory:protected clsDrawScreenHeader<string>
{
private:
	static void _ShowProductInfoData(clsProductBusinessLogic ProductInfo)
	{
		cout << "| " << left << setw(15) << ProductInfo.ProductID;
		cout << "| " << left << setw(47) << ProductInfo.ProductName;
		cout << "| " << left << setw(26) << clsProductInventoryBusinessLogic::ProductStatus(ProductInfo.ProductID);
		cout << "| " << left << setw(22) << ProductInfo.ProductQuantity;
		cout << " |" << endl;
		cout << "_______________________________________________________________________________________________";
		cout << "_________________________\n";
	}
public:
	static void ShowInventoryScreen()
	{
		system("cls");
		DrawHeaderScreen("Inventory Screen", "", 6);
		vector <clsProductBusinessLogic> AllProductsInfo = clsProductBusinessLogic::GetAllProductInfoData();
		cout << "_______________________________________________________________________________________________";
		cout << "_________________________\n";
		cout << "| " << left << setw(15) << "Product ID";
		cout << "| " << clsUtil<string>::NumberOfSpaces(19) << left << setw(28) << "Product Name";
		cout << "| " << clsUtil<string>::NumberOfSpaces(6) << left << setw(20) << "Product Status";
		cout << "| " << clsUtil<string>::NumberOfSpaces(4) << left << setw(18) << "Product Quantity";
		cout << " |" << endl;
		cout << "_______________________________________________________________________________________________";
		cout << "_________________________\n";
		if (AllProductsInfo.size() == 0)
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "No products are avaliable.\n";
		}
		else
		{
			for (clsProductBusinessLogic & ProductInfo : AllProductsInfo)
			{
				_ShowProductInfoData(ProductInfo);
			}
		}
	}
};

