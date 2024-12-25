#pragma once
#include <iostream>
#include "clsInputValidate.h"
#include "clsDrawScreenHeader.h"
#include "clsAdminLoginBusinessLogic.h"
#include "clsShowAdminMainMenu.h"
#include "clsUtil.h"

using namespace std;

template <typename T>

class clsAdminMainScreen:protected clsDrawScreenHeader<void>
{
public :
	static void ShowAdminMainScreen()
	{
		bool IsPasswordCorrect = true;
		do
		{
			system("cls");
			DrawHeaderScreen("Admin Main Screen.", "", 6);
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter Admin password to login. \n";
			cout << clsUtil<string>::NumberOfTabs(5);
			IsPasswordCorrect = !clsAdminLoginBusinessLogic<bool>::IsAdminPasswordCorrect(clsInputValidate<string>::ReadString());
			if (IsPasswordCorrect)
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "Invalid Admin Password , Please try again.\n";
				system("pause > 0");
			}
		} while (IsPasswordCorrect);
		clsShowAdminMainMenu<void>::ShowAdminMainMenuScreen();
	}
};

