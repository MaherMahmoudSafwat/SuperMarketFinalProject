#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "clsDrawScreenHeader.h"
#include "clsProductCartBusinessLogic.h"
#include "clsPurchaseProductBusinessLogic.h"
#include "clsUtil.h"

using namespace std;

class clsViewProductsSoldScreen:protected clsDrawScreenHeader<string>
{
private:
	static void _ShowSoldProductsInfo(string ProductsSoldInfo)
	{
		cout << "| " << left << setw(13) << clsProductCartBusinessLogic::_ReturnProductID(ProductsSoldInfo);
		cout << "| " << left << setw(76) << clsPurchaseProductBusinessLogic::_ReturnProductName(ProductsSoldInfo);
		cout << "| " << left << setw(24) << clsPurchaseProductBusinessLogic::_ReturnQuantiySold(ProductsSoldInfo); 
		cout << "|\n";
	}
public:
	static void ShowProductsSoldScreen()
	{
		vector <string> GetAllProductsSoldInfo = clsPurchaseProductBusinessLogic::GetAllProductsSoldInfoInFile();
		string Subtitle = "Number of product(s) sold is " + to_string(GetAllProductsSoldInfo.size()) + " Product(s).\n";
		DrawHeaderScreen("View All Sold Products Screen", Subtitle, 6);
		cout << "----------------------------------------------------------------------------------------------------";
		cout << "--------------------\n";
		cout << "| " << left << setw(13) << "Product ID";
		cout << "| " << clsUtil<string>::NumberOfSpaces(31) << left << setw(45) << "Product Name";
		cout << "| " << left << setw(15) << "Number Of Products Sold ";
		cout << "|\n";
		cout << "----------------------------------------------------------------------------------------------------";
		cout << "--------------------\n";
		if (GetAllProductsSoldInfo.size() == 0)
		{
			cout << clsUtil<string>::NumberOfTabs(5) << "There are no Products Found or Avaliable.\n";
		}
		else
		{
			for (string& ProductsSoldInfo : GetAllProductsSoldInfo)
			{
				_ShowSoldProductsInfo(ProductsSoldInfo);
				cout << "----------------------------------------------------------------------------------------------------";
				cout << "--------------------\n";
			}
		}
	}
};

