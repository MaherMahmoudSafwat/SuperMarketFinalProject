#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "clsInputValidate.h"
#include "clsProductBusinessLogic.h"
#include "clsProductCartBusinessLogic.h"
#include "clsDrawScreenHeader.h"
#include "clsUtil.h"

using namespace std;

template <typename T>

class clsViewAllProductsAddedToCart :protected clsDrawScreenHeader<string>
{
private:
	static void _ShowAllProductsInfo(clsProductBusinessLogic ProductInfo)
	{
		string ProductPrice = to_string(ProductInfo.ProductPrice) + " L.E.";
		cout << "| " << left << setw(15) << ProductInfo.GetProductID();
		cout << "| " << left << setw(47) << ProductInfo.ProductName;
		cout << "| " << left << setw(26) << ProductPrice;
		cout << "| " << left << setw(22) << ProductInfo.ProductQuantity;
		cout << " |" << endl;
		cout << "______________________________________________________________________________________________";
		cout << "__________________________\n";
	}
public:
	static void ViewAllAddedToCartScreen()
	{
		system("cls");
		vector <clsProductBusinessLogic> AllProductsInfo = clsProductCartBusinessLogic::ViewAllProductsAddedToCart();
		string subtitle = "Number of Product(s) is " + to_string(AllProductsInfo.size()) + " Product(s) Added to cart ";
		DrawHeaderScreen("View all Added products to cart screen", subtitle, 6);
		cout << "______________________________________________________________________________________________";
		cout << "__________________________\n";
		cout << "| " << left << setw(15) << "Product ID";
		cout << "| " << clsUtil<string>::NumberOfSpaces(19) << left << setw(28) << "Product Name";
		cout << "| " << clsUtil<string>::NumberOfSpaces(6) << left << setw(20) << "Product Price";
		cout << "| " << clsUtil<string>::NumberOfSpaces(4) << left << setw(18) << "Product Quantity";
		cout << " |" << endl;
		cout << "______________________________________________________________________________________________";
		cout << "__________________________\n";
		if (AllProductsInfo.size() == 0)
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "There are no products added to cart avaliable.\n";
		}
		else
		{
			for (clsProductBusinessLogic& ProductInfo : AllProductsInfo)
			{
				_ShowAllProductsInfo(ProductInfo);
			}
		}
	}
};
