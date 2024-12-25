#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "clsProductBusinessLogic.h"
#include "clsUtil.h"

using namespace std;

class clsProductInventoryBusinessLogic:public clsProductBusinessLogic
{
public:
	static int IsProductQuantityHigh(int ProductId)
	{
		clsProductBusinessLogic ProductInfo = FindProduct(ProductId);
		if (ProductInfo.ProductQuantity > 3)
			return 1;
		else if (ProductInfo.ProductQuantity <= 3 && ProductInfo.ProductQuantity > 0)
			return -1;
		else
			return 0;
	}
	static string ProductStatus(int ProductID)
	{
		int Number = IsProductQuantityHigh(ProductID);
		if (Number == 1)
			return "High";
		else if (Number == -1)
			return "Low";
		else
			return "Out Of The Stock";
	}
};

