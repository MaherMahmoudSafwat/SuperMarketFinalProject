#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsCustomerLoginBusinessLogic.h"
#include "clsProductBusinessLogic.h"
#include "clsUtil.h"
#include "clsCustomerGlobal.h"

using namespace std;

string ProductCartFile = "ProductCart.txt";

class clsProductCartBusinessLogic:public clsProductBusinessLogic,public clsCustomerLoginBusinessLogic
{
private:
	static string _ConvertObjectToLine(int ProductID, int CustomerID, string Separator = "#//#")
	{
		string Line = "";
		Line += to_string(ProductID) + Separator;
		Line += to_string(CustomerID) + Separator;
		return Line;
	}
	static int _ReturnProductID(string Line)
	{
		vector<string>ProductID;
		ProductID = clsUtil<vector<string>>::SplitString(Line);
		return stoi(ProductID[0]);
	}
	static int _ReturnCustomerID(string Line)
	{
		vector<string>CustomerID;
		CustomerID = clsUtil<vector<string>>::SplitString(Line);
		return stoi(CustomerID[1]);
	}
public:
	static void AddProductToCart(int ProductID)
	{
		fstream NewFile;
		NewFile.open(ProductCartFile, ios::out | ios::app);
		if (NewFile.is_open())
		{
			NewFile << _ConvertObjectToLine(ProductID,Customer.CustomerID) << endl;
		}
		NewFile.close();
	}
	static vector<clsProductBusinessLogic> ViewAllProductsAddedToCart()
	{
		fstream NewFile;
		string Line = "";
		vector <clsProductBusinessLogic> AllProductsInfoAddedToCustomerCart;
		NewFile.open(ProductCartFile, ios::in);
		if (NewFile.is_open())
		{
			while (getline(NewFile, Line))
			{
				if (_ReturnCustomerID(Line) == Customer.CustomerID)
				{
					AllProductsInfoAddedToCustomerCart.push_back(FindProduct(_ReturnProductID(Line)));
				}
			}
		}
		NewFile.close();
		return AllProductsInfoAddedToCustomerCart;
	}
	static vector <string> GetAllInfoAddedToCart()
	{
		vector<string>GetAllInfo;
		string Line = "";
		fstream NewFile;
		NewFile.open(ProductCartFile, ios::in);
		if (NewFile.is_open())
		{
			while (getline(NewFile, Line))
			{
				GetAllInfo.push_back(Line);
			}
		}
		NewFile.close();
		return GetAllInfo;
	}
	static void DeleteProductAddedToCart(int ProductID)
	{
		fstream NewFile;
		string Line = "";
		vector <string> GetAllProductsAddedToCartInfo = GetAllInfoAddedToCart();
		NewFile.open(ProductCartFile, ios::out);
		if (NewFile.is_open())
		{
			for (string & ProductInfo : GetAllProductsAddedToCartInfo)
			{
				if (_ReturnProductID(ProductInfo) == ProductID)
					continue;
				else
					NewFile << ProductInfo << endl;
			}
		}
		NewFile.close();
	}
	friend class clsPurchaseProductBusinessLogic;
	friend class clsViewProductsSoldScreen;
};

