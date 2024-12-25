#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsDrawScreenHeader.h"
#include "clsViewProductsSoldScreen.h"
#include "clsDeleteAllSoldProductsInfo.h"
#include "clsUtil.h"

using namespace std;

template <typename T>

class clsViewAllSoldProductsMenu :protected clsDrawScreenHeader<string>
{
private:
	enum enAdminChoices { ViewAllProductsSoldInfo = 1, DeleteAllSoldProductsInfo = 2, Exit = 3 };
	static void _ViewAllSoldProductsInfo()
	{
		system("cls");
		clsViewProductsSoldScreen::ShowProductsSoldScreen();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Admin Main Menu.\n";
		system("pause > 0");
	}
	static void _DeleteAllSoldProductsInfo()
	{
		system("cls");
		clsDeleteAllSoldProductsInfo::ShowDeleteAllSoldProductsInfo();
		cout << clsUtil<string>::NumberOfTabs(5) << "Press Any Key, to go back to Admin Main Menu.\n";
		system("pause > 0");
	}
	static void _PerformOperationsOnAdminChoices(enAdminChoices AdminChoices)
	{
		switch (AdminChoices)
		{
		case enAdminChoices::ViewAllProductsSoldInfo:
			_ViewAllSoldProductsInfo();
			ViewAllSoldProductsInfo();
			break;
		case enAdminChoices::DeleteAllSoldProductsInfo:
			_DeleteAllSoldProductsInfo();
			ViewAllSoldProductsInfo();
			break;
		case enAdminChoices::Exit:
			break;
		}
	}
public:
	static void ViewAllSoldProductsInfo()
	{
		string Number = "";
		do
		{
			system("cls");
			DrawHeaderScreen("View All Sold Products Info ","",6);
			cout << clsUtil<string>::NumberOfTabs(5) << "-----------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "Choose one of the following.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "-----------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "1-View All Sold Products.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "2-Delete All Sold Products Info.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "3-Exit.\n";
			cout << clsUtil<string>::NumberOfTabs(5) << "-----------------------------------------\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			Number = clsInputValidate<string>::ReadString();
		} while (!clsInputValidate<bool>::ValidateInputNumber(1, 5, Number));
		_PerformOperationsOnAdminChoices(enAdminChoices(stoi(Number)));
	}
};
