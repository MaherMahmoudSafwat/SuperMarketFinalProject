#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsDrawScreenHeader.h"
#include "clsPurchaseProductBusinessLogic.h"
#include "clsUtil.h"

using namespace std;

class clsDeleteAllSoldProductsInfo:protected clsDrawScreenHeader<string>
{
public:
	static void ShowDeleteAllSoldProductsInfo()
	{
		system("cls");
		DrawHeaderScreen("Delete All Sold Products Info Screen", "", 5);
		char Answer = 'Y';
		cout << clsUtil<string>::NumberOfTabs(5) << "Are you sure you want to delete all the products Sold info data ? Y/N ? \n";
		cout << clsUtil<string>::NumberOfTabs(5);
		cin >> Answer;
		if (Answer == 'Y' || Answer == 'y')
		{
			clsPurchaseProductBusinessLogic::DeleteAllProductsSoldInfo();
			cout << clsUtil<string>::NumberOfTabs(5) << "All Products Sold Info has been deleted Successfully.\n";
		}
	}
};

