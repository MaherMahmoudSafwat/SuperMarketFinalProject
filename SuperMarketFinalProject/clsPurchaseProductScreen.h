#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsViewAllProductsScreen.h"
#include "clsDrawScreenHeader.h"
#include "clsPurchaseProductBusinessLogic.h"
#include "clsUtil.h"
#include "clsDate.h"

using namespace std;

class clsPurchaseProductScreen:protected clsDrawScreenHeader<string>,public clsViewAllProductsScreen<void>
{
public:
	static void ShowPurchaseProductScreen()
	{
		system("cls");
		DrawHeaderScreen("Purchase Product Screen", "", 6);
		ViewAllProductsScreen();
		float Price = clsPurchaseProductBusinessLogic::PurchaseProduct();
		if (Price != 0)
		{
			cout << "Date : " << clsDate::ConvertDateToString() << endl;
			cout << "Time : " << clsDate::ConvertTimeToString() << endl;
			cout << "Total Bill is " << Price << endl;
			cout << "Thank you for buying from Supermarket :-) .\n";
		}
		else
		{
			cout << "Date : " << clsDate::ConvertDateToString() << endl;
			cout << "Time : " << clsDate::ConvertTimeToString() << endl;
			cout << "Thank you for visiting our Supermarket :-).\n";
		}
	}
};

