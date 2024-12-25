#pragma once
#include <iostream>

using namespace std;

class clsProduct
{
private:
	int _ProductID = 0;
	string _ProductName = "";
	float _ProductPrice = 0;
	int _ProductQuantity = 0;
public:
	clsProduct(int ProductID, string ProductName, float ProductPrice, int ProductQuantity)
	{
		_ProductID = ProductID;
		_ProductName = ProductName;
		_ProductPrice = ProductPrice;
		_ProductQuantity = ProductQuantity;
	}
	void SetProductID(int ProductID)
	{
		_ProductID = ProductID;
	}
	int GetProductID()
	{
		return _ProductID;
	}
	_declspec(property(put = SetProductID, get = GetProductID))int ProductID;
	void SetProductName(string ProductName)
	{
		_ProductName = ProductName;
	}
	string GetProductName()
	{
		return _ProductName;
	}
	_declspec(property(put = SetProductName, get = GetProductName))string ProductName;
	void SetProductPrice(float ProductPrice)
	{
		_ProductPrice = ProductPrice;
	}
	float GetProductPrice()
	{
		return _ProductPrice;
	}
	_declspec(property(put = SetProductPrice, get = GetProductPrice))float ProductPrice;
	void SetProductQuantity(int ProductQuantity)
	{
		_ProductQuantity = ProductQuantity;
	}
	int GetProductQuantity()
	{
		return _ProductQuantity;
	}
	_declspec(property(put = SetProductQuantity, get = GetProductQuantity))int ProductQuantity;
};

