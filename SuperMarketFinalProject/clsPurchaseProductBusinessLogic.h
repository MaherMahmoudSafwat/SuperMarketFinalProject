#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "clsInputValidate.h"
#include "clsProductBusinessLogic.h"
#include "clsViewAllProductsScreen.h"
#include "clsDrawScreenHeader.h"
#include "clsUtil.h"

using namespace std;

string ProductQuantitySoldFile = "ProductQuantitySold.txt";

class clsPurchaseProductBusinessLogic
{
private:
	static string _ConvertSoldProductInfoToLine(clsProductBusinessLogic ProductInfo, int QuantitySold, string Separator = "#//#")
	{
		string Line = "";
		Line += to_string(ProductInfo.ProductID) + Separator;
		Line += ProductInfo.ProductName + Separator;
		Line += to_string(QuantitySold);
		return Line;
	}
	static string _ReturnProductName(string Line)
	{
		vector <string> ProductInfoLine;
		ProductInfoLine = clsUtil<string>::SplitString(Line);
		return ProductInfoLine[1];
	}
	static int _ReturnQuantiySold(string Line)
	{
		vector <string> ProductInfoLine;
		ProductInfoLine = clsUtil<string>::SplitString(Line);
		return stoi(ProductInfoLine[2]);
	}
public:
	static vector<string> GetAllProductsSoldInfoInFile()
	{
		vector <string> ProductsSoldInfo;
		fstream NewFile;
		string Line = "";
		NewFile.open(ProductQuantitySoldFile, ios::in);
		if (NewFile.is_open())
		{
			while (getline(NewFile, Line))
			{
				ProductsSoldInfo.push_back(Line);
			}
		}
		NewFile.close();
		return ProductsSoldInfo;
	}
	static void AddNewSoldProductInfo(clsProductBusinessLogic ProductSoldInfo)
	{
		fstream NewFile;
		string Line = "";
		NewFile.open(ProductQuantitySoldFile, ios::out | ios::app);
		if (NewFile.is_open())
		{
			NewFile << _ConvertSoldProductInfoToLine(ProductSoldInfo, 1) << endl;
		}
		NewFile.close();
	}
	static void UpdateSoldProductInfo(clsProductBusinessLogic ProductInfo , int QuantitySold)
	{
		vector <string> GetAllProductsSoldInfo = GetAllProductsSoldInfoInFile();
		fstream NewFile;
		string Line = "";
		NewFile.open(ProductQuantitySoldFile, ios::out);
		if (NewFile.is_open())
		{
			for (string& ProductSoldInfo : GetAllProductsSoldInfo)
			{
				if (clsProductCartBusinessLogic::_ReturnProductID(ProductSoldInfo) == ProductInfo.ProductID)
					NewFile << _ConvertSoldProductInfoToLine(ProductInfo, QuantitySold) << endl;
				else
					NewFile << ProductSoldInfo << endl;
			}
		}
		NewFile.close();
	}
	static void DeleteAllProductsSoldInfo()
	{
		fstream NewFile;
		NewFile.open(ProductQuantitySoldFile, ios::out);
		if (NewFile.is_open()) {};
		NewFile.close();
	}
	static void StoreProductQuantitySold(clsProductBusinessLogic ProductInfo)
	{
		vector <string> GetAllProductsSoldInfo = GetAllProductsSoldInfoInFile();
		int Quantity = 0;
		for (string& ProductSoldInfo : GetAllProductsSoldInfo)
		{
			if (clsProductCartBusinessLogic::_ReturnProductID(ProductSoldInfo) == ProductInfo.ProductID)
			{
				Quantity = (_ReturnQuantiySold(ProductSoldInfo)) + 1;
				UpdateSoldProductInfo(ProductInfo, Quantity);
				return;
			}
		}
		AddNewSoldProductInfo(ProductInfo);
	}
	static void UpdateProductDatabase(clsProductBusinessLogic ProductInfo)
	{
		ProductInfo.ProductQuantity--;
		ProductInfo.UpdateProduct();
	}
	static float PurchaseProduct(string Input = "")
	{
		float Price = 0;
		cout << "Please enter the Product ID you want to purchase or press X to exit.\n";
		Input = clsInputValidate<string>::ReadString();
		while (Input != "X" && Input != "x")
		{
			clsProductBusinessLogic ProductInfo = clsProductBusinessLogic::FindProduct(stoi(Input));
			if (ProductInfo.ProductID == 0)
			{
				cout << "Product is not found, Please enter another one or press X to exit.\n";
				system("pause > 0");
				Input = clsInputValidate<string>::ReadString();
				continue;
			}
			else if (ProductInfo.ProductQuantity == 0)
			{
				cout << "Product is Out Of Stock :-( , Please enter another one or press X to exit.\n";
				system("pause > 0");
				Input = clsInputValidate<string>::ReadString();
				continue;
			}
			UpdateProductDatabase(ProductInfo);
			StoreProductQuantitySold(ProductInfo);
			Price += ProductInfo.ProductPrice;
			cout << "Please enter the Product ID you want to purchase or press X to exit.\n";
			Input = clsInputValidate<string>::ReadString();
		}
		return Price;
	}
	friend class clsViewProductsSoldScreen;
};

