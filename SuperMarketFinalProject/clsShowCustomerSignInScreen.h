#include <iostream>
#include "clsInputValidate.h"
#include "clsDrawScreenHeader.h"
#include "clsCustomerLoginBusinessLogic.h"
#include "clsShowCustomerMainMenuScreen.h"
#include "clsUtil.h"
#include "clsCustomerGlobal.h"

using namespace std;

template <typename T>

class clsShowCustomerSignInScreen:protected clsDrawScreenHeader<string>
{
public:
	static void ShowCustomerSignInScreen()
	{
		string Email = "";
		string Password = "";
		bool IsEmailNotExists = true;
		bool IsPasswordNotExists = true;
		do
		{
			system("cls");
			DrawHeaderScreen("Sign in Customer screen", "", 6);
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter your Email.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			Email = clsInputValidate<string>::ReadString();
			IsEmailNotExists = !clsCustomerLoginBusinessLogic::IsCustomerEmailExists(Email);
			cout << clsUtil<string>::NumberOfTabs(5) << "Please enter your Password.\n";
			cout << clsUtil<string>::NumberOfTabs(5);
			Password = clsInputValidate<string>::ReadString();
			IsPasswordNotExists = !clsCustomerLoginBusinessLogic::IsCustomerPasswordExists(Password);
			if (IsEmailNotExists || IsPasswordNotExists)
			{
				cout << clsUtil<string>::NumberOfTabs(5) << "Invalid Email or Password, Please try again.\n";
				system("pause > 0");
			}
		} while (IsEmailNotExists || IsPasswordNotExists);
		Customer.CustomerID = clsCustomerLoginBusinessLogic::ReturnCustomerID(Email, Password);
		Customer = clsCustomerLoginBusinessLogic::FindCustomerInfo(Customer.CustomerID);
		clsShowCustomerMainMenuScreen<void>::ShowCustomerMainMenu();
	}
};
