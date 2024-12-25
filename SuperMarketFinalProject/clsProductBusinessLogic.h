#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "clsProduct.h"
#include "clsUtil.h"

using namespace std;

string ProductFile = "Products.txt";

class clsProductBusinessLogic:public clsProduct
{
private:
	static string _ConvertProductInfoObjectToLine(clsProduct ProductInfoObjet, string Separator = "#//#")
	{
		string ProductInfoLine = "";
		ProductInfoLine += to_string(ProductInfoObjet.GetProductID()) + Separator;
		ProductInfoLine += ProductInfoObjet.GetProductName() + Separator;
		ProductInfoLine += to_string(ProductInfoObjet.GetProductPrice()) + Separator;
		ProductInfoLine += to_string(ProductInfoObjet.GetProductQuantity());
		return ProductInfoLine;
	}
	static clsProductBusinessLogic _ConvertProductInfoLineToObject(string Line)
	{
		vector<string>ProductInfoData;
		ProductInfoData = clsUtil<string>::SplitString(Line);
		return clsProductBusinessLogic(stoi(ProductInfoData[0]), ProductInfoData[1], stoi(ProductInfoData[2]), stoi(ProductInfoData[3]));
	}
public:
	clsProductBusinessLogic(int ProductID, string ProductName, float ProductPrice, int PriceQuantity) :clsProduct
	(ProductID, ProductName, ProductPrice, PriceQuantity) {};
	void AddNewProductToFile()
	{
		fstream NewFile;
		NewFile.open(ProductFile, ios::out | ios::app);
		if (NewFile.is_open())
		{
			NewFile << _ConvertProductInfoObjectToLine(*this) << endl;
		}
		NewFile.close();
	}
	static vector <clsProductBusinessLogic> GetAllProductInfoData()
	{
		fstream NewFile;
		string Line = "";
		vector < clsProductBusinessLogic> ProductsInfo;
		clsProductBusinessLogic ProductInfo(0, "", 0, 0);
		NewFile.open(ProductFile, ios::in);
		if (NewFile.is_open())
		{
			while (getline(NewFile, Line))
			{
				ProductInfo = _ConvertProductInfoLineToObject(Line);
				ProductsInfo.push_back(ProductInfo);
			}
		}
		NewFile.close();
		return ProductsInfo;
	}
	static bool IsProductIdExists(int ProductID)
	{
		vector<clsProductBusinessLogic>AllProductsInfo = GetAllProductInfoData();
		for (clsProductBusinessLogic& ProductInfo : AllProductsInfo)
		{
			if (ProductInfo.GetProductID() == ProductID)
				return true;
		}
		return false;
	}
	void UpdateProduct()
	{
		string Line = "";
		fstream NewFile;
		vector<clsProductBusinessLogic>AllProductsInfo = GetAllProductInfoData();
		clsProductBusinessLogic UpdateProductInfo = *this;
		NewFile.open(ProductFile, ios::out);
		if (NewFile.is_open())
		{
			for (clsProductBusinessLogic& ProductInfo : AllProductsInfo)
			{
				if (UpdateProductInfo.GetProductID() == ProductInfo.ProductID)
				{
					NewFile << _ConvertProductInfoObjectToLine(UpdateProductInfo) << endl;
					continue;
				}
				NewFile << _ConvertProductInfoObjectToLine(ProductInfo) << endl;
			}
		}
		NewFile.close();
	}
	void DeleteProduct()
	{
		string Line = "";
		fstream NewFile;
		vector<clsProductBusinessLogic>AllProductsInfo = GetAllProductInfoData();
		clsProductBusinessLogic DeleteProductInfo = *this;
		NewFile.open(ProductFile, ios::out);
		if (NewFile.is_open())
		{
			for (clsProductBusinessLogic& ProductInfo : AllProductsInfo)
			{
				if (DeleteProductInfo.GetProductID() == ProductInfo.ProductID)
				{
					continue;
				}
				NewFile << _ConvertProductInfoObjectToLine(ProductInfo) << endl;
			}
		}
		NewFile.close();
	}
	static clsProductBusinessLogic FindProduct(int ProductID)
	{
		string Line = "";
		fstream NewFile;
		vector<clsProductBusinessLogic>AllProductsInfo = GetAllProductInfoData();
		NewFile.open(ProductFile, ios::in);
		if (NewFile.is_open())
		{
			for (clsProductBusinessLogic& ProductInfo : AllProductsInfo)
			{
				if (ProductInfo.ProductID == ProductID)
					return ProductInfo;
			}
		}
		return clsProductBusinessLogic(0, "", 0, 0);
	}
};
