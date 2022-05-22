#include "mainData.h"


#pragma region omar_ashraf

void Register()
{
	person p1;

	cout << "Enter username : ";
	cin >> p1.UserName;
	cout << "Enetr password : ";
	cin >> p1.password;



	for (int i = 0; i < accounts.size(); i++)
	{
		if (p1.UserName == accounts[i].UserName)
		{
			cout << "This username already exist !!!" << endl;
			cout << "Enter valid username : ";
			cin >> p1.UserName;
			i = -1;
		}
	}
	p1.ID = accounts.size() + 1;


	accounts.push_back(p1);
	cout << "\n\n************************************************************************\n";
	cout << "*                                                                      *\n";
	cout << "*                    you register successfully                         *\n";
	cout << "*                                                                      *\n";
	cout << "************************************************************************\n\n";

}
void Login()
{
	person p1;

	cout << "Enter username : ";
	cin >> p1.UserName;
	cout << "Enetr password : ";
	cin >> p1.password;


	for (int i = 0; i < accounts.size(); i++)
	{
		if (p1.UserName == accounts[i].UserName)
		{
			if (p1.password == accounts[i].password)
			{
				loginAccountId = accounts[i].ID;
				cout << "\n\n************************************************************************\n";
				cout << "*                                                                      *\n";
				cout << "*                    you login successfully                            *\n";
				cout << "*                                                                      *\n";
				cout << "************************************************************************\n\n";
				return;
			}
			else
			{
				while (p1.password != accounts[i].password)
				{
					cout << "Invalid password !!!" << endl << "Re-enter password : ";
					cin >> p1.password;
				}
				loginAccountId = accounts[i].ID;
				return;
			}
		}
		if (i + 1 >= accounts.size())
		{
			cout << "Invalid username !!!" << endl << "Re-enter username : ";
			cin >> p1.UserName;
			i = -1;
		}
	}
}

void ShowPreviousProcess()
{

	int counter = 0;
	if (loginAccountId == 1)
	{
		int custid = 0;
		cout << "Enter ID for the customer : ";
		cin >> custid;
		for (int i = 0; i < serviceProccess.size(); i++)
		{

			if (custid == serviceProccess[i].custid)
			{
				counter++;
				cout << "Process " << counter << " : " << endl;

				cout << "ID : " << serviceProccess[i].ID << "  , Customed ID : " << serviceProccess[i].custid;

				cout << "  , Price : " << serviceProccess[i].price << "  , Date : " << serviceProccess[i].date;

				cout << "  , Service ID : " << serviceProccess[i].serviceId << "  , Service name: " << serviceProccess[i].chossenService.name;

				cout << "  , Garage ID : " << serviceProccess[i].chossenService.garageId << endl << endl;
			}
		}
		for (int i = 0; i < buyRentProsess.size(); i++)
		{
			if (custid == buyRentProsess[i].custId)
			{
				counter++;
				cout << "Process " << counter << " : " << endl;

				cout << "ID : " << buyRentProsess[i].ID << "  , Customed ID : " << buyRentProsess[i].custId;

				cout << "  , Price : " << buyRentProsess[i].price << "  , Date : " << buyRentProsess[i].date;

				cout << "  , Car ID : " << buyRentProsess[i].carId << endl << endl;
			}
		}

		if (counter == 0)
			cout << "There are no previous processes !" << endl << endl;
	}

	else
	{
		for (int i = 0; i < serviceProccess.size(); i++)
		{

			if (loginAccountId == serviceProccess[i].custid)
			{
				counter++;
				cout << "Process " << counter << " : " << endl;

				cout << "ID : " << serviceProccess[i].ID << "  , Customed ID : " << serviceProccess[i].custid;

				cout << "  , Price : " << serviceProccess[i].price << "  , Date : " << serviceProccess[i].date;

				cout << "  , Service ID : " << serviceProccess[i].serviceId << "  , Service name: " << serviceProccess[i].chossenService.name;

				cout << "  , Garage ID : " << serviceProccess[i].chossenService.garageId << endl << endl;
			}
		}
		for (int i = 0; i < buyRentProsess.size(); i++)
		{
			if (loginAccountId == buyRentProsess[i].custId)
			{
				counter++;
				cout << "Process " << counter << " : " << endl;

				cout << "ID : " << buyRentProsess[i].ID << "  , Customed ID : " << buyRentProsess[i].custId;

				cout << "  , Price : " << buyRentProsess[i].price << "  , Date : " << buyRentProsess[i].date;

				cout << "  , Car ID : " << buyRentProsess[i].carId << endl << endl;
			}
		}
		if (counter == 0)
			cout << "There are no previous processes !" << endl << endl;
	}

}

#pragma endregion
#pragma region omar_ayman








//#include <ctime>
//
//
//string CurrentTime()
//{
//	time_t now = time(0); // get current dat/time with respect to system  
//
//	string dt = ctime(&now); // convert it into string  
//
//	return dt; // print local date and time  
//
//
//}
void BuyOrRent()
{
	int requiredCarId;
	int choosenProcces;
	bool carExists = false;

	cout << "1.buy\n2.rent \n";
	cin >> choosenProcces;
	if (choosenProcces == 2)
	{
		int requiredPeriod;
		cout << "enter the period of renting \n";
		cin >> requiredPeriod;
	}

	cout << "please enter the id of the required car :\n";

	cin >> requiredCarId;

	for (int i = 0; i < cars.size(); i++)
	{
		if (requiredCarId == cars[i].ID)
		{
			carExists = true;

			if (cars[i].isAvilable)
			{
				cars[i].isAvilable = false;

				buyProssess newBuy;

				newBuy.ID = buyRentProsess.back().ID + 1;
				newBuy.custId = loginAccountId;
				newBuy.price = cars[i].price;
				string currentdate;
				cout << "enter today's date\n";
				cin >> currentdate;
				newBuy.date = currentdate;
				newBuy.choosenCar = cars[i];
				newBuy.carId = cars[i].ID;

				buyRentProsess.push_back(newBuy);

				cout << "\nthe process is completed Successfully \n";

				break;
			}
			else
			{
				cout << "\nSorry! ... the required car is not available :\n";

				break;
			}
		}
	}
	if (!carExists)
	{
		cout << "\nSorry! ... you have entered a wrong car id :\n";
	}
}

void BookService()
{
	int requiredServiceId;
	bool exists = false;

	cout << " please enter the id of the required service :\n";
	cin >> requiredServiceId;

	for (int i = 0; i < services.size(); i++)
	{
		if (requiredServiceId == services[i].ID)
		{
			exists = true;

			serviceProcces newProcces;

			newProcces.ID = serviceProccess.back().ID + 1;
			newProcces.price = services[i].price;
			newProcces.custid = loginAccountId;

			string currentdate;
			cout << "enter today's date\n";
			cin >> currentdate;
			newProcces.date = currentdate;

			newProcces.chossenService = services[i];
			newProcces.serviceId = services[i].ID;

			serviceProccess.push_back(newProcces);
			cout << "\nthe process is completed Successfully \n\n";

			break;
		}
	}
	if (!exists)
	{
		cout << "\nSorry! ... you have entered a wrong service id :\n";
	}

}



//void Reserve_Car()
//{
//	int requiredCarId;
//	bool carExists = false;
//
//	cout << "please enter the id of yuor required car :\n";
//	cin >> requiredCarId;
//
//	for (int i = 0; i < cars.size(); i++)
//	{
//		if (requiredCarId == cars[i].ID)
//		{
//			carExists = true;
//
//			if (cars[i].isAvilable)
//			{
//				cars[i].isAvilable = false;
//				
//				break;
//			}
//			else
//			{
//				cout << "Sorry! ... the required car is not available :\n";
//
//				break;
//			}
//		}
//	}
//	if (!carExists)
//	{
//		cout << "Sorry! ... you have entered a wrong car id :\n";
//	}
//}











#pragma endregion
#pragma region ali_sharb
void Search()
{
	string s;
	int x = 0;
	bool flag = false;
	cout << "****************************************************************************\n";
	cout << "****\t\t\t\t\t\t\t\t\t****\n\n";
	cout << "----------------------welcome to search menu-------------------------------\n\n";

	cout << "Please press your process number:\n";
	cout << "1_Search for car\n";
	cout << "2_Search for Garage\n";
	cout << "3_Search for Showroom\n";
	cout << "4_Search for service\n";



	cin >> x;
	switch (x)
	{

	case 1:

		cout << "please Enter car name\n";
		cin >> s;
		cout << "\n\n" << " ~" << "*id*" << "\t ~" << "*make*" << "\t ~" << "*model*" << "\t ~" << "*year*" << "\t ~" << "*installment*" << " \t~" << "*price*" << " \t~" << "*showroomId*" << "\n\n";



		for (int i = 0; i < cars.size(); i++)
		{
			if (cars[i].isAvilable == true && s.compare(cars[i].make) == 0)
			{
				cout << "\t" << cars[i].ID << "\t|\t" << cars[i].make << "\t|\t" << cars[i].model << "\t|\t" << cars[i].year << "\t|\t" << cars[i].installment << "\t|\t";
				cout << cars[i].price << "\t|\t" << cars[i].showroomId << "\t|\n";
				flag = true;
			}

		}
		if (flag == false)
		{
			cout << "\n\n\t\t----------------------------Invalid Data--------------------------------\n\n\n";
		}

		break;

	case 2:cout << "1_ Search by location\n2_Show all Garages\n";
		cin >> x;
		if (x == 1)
		{


			cout << "please Enter location \n";
			cin >> s;
			cout << "\n\n" << "\t ~" << "*id*" << "\t ~" << "*name*" << "\t ~" << "*location*" << "\t ~" << "*phoneNumber*" << "\n\n";

			for (int i = 0; i < garages.size(); i++)
			{
				if (s.compare(garages[i].location) == 0)
				{

					cout << "\t" << garages[i].ID << "\t|\t" << garages[i].name << "\t|\t" << garages[i].location << "\t|\t" << garages[i].phoneNumber << "\t|\n";
					cout << "**this Garage provides services**";
					for (int j = 0; j < garages[i].listOfService.size(); j++)
					{
						cout << "\t**" << garages[i].listOfService[j].name << "**\n";
					}
					flag = true;
				}
			}

			if (flag == false)
			{
				cout << "\n\n\t\t----------------------------Invalid Data--------------------------------\n\n\n";
			}

		}
		else if (x == 2)
		{
			List(1);

		}



		break;
	case 3:
		cout << "1_ Search by Location\n2_Show all Showrooms\n";
		cin >> x;
		if (x == 1)
		{



			cout << "please Enter Location \n";
			cin >> s;

			for (int i = 0; i < showrooms.size(); i++)
			{
				if (s.compare(showrooms[i].location) == 0)
				{
					cout << "\n\n" << " ~" << "*id*" << "\t ~" << "*name*" << "\t ~" << "*location*" << "\t ~" << "*phoneNumber*" << "\n\n";
					cout << "\t" << showrooms[i].ID << "\t|\t" << showrooms[i].name << "\t|\t" << showrooms[i].location << "\t|\t" << showrooms[i].phoneNumber << "\t|\n";

					cout << "\t****  List of cars   ****\n\n";
					cout << "\n\n" << " ~" << "*id*" << "\t ~" << "*make*" << "\t ~" << "*model*" << "\t ~" << "*year*" << " \t~" << "*installment*" << " \t~" << "*price*" << "\t ~" << "*showroomId*" << "\n\n";
					for (int j = 0; j < showrooms[i].listOfCars.size(); j++)
					{
						cout << "\t" << showrooms[i].listOfCars[j].ID << "\t|\t" << showrooms[i].listOfCars[j].make << "\t|\t" << showrooms[i].listOfCars[j].model << "\t|\t" << showrooms[i].listOfCars[j].year << "\t|\t" << showrooms[i].listOfCars[j].installment << "\t|\t";
						cout << showrooms[i].listOfCars[j].price << "\t|\t" << showrooms[i].listOfCars[j].showroomId << "\t|\n";
					}
					flag = true;
				}
			}
			if (flag == false)
			{

				cout << "\n\n\t\t----------------------------Invalid Data--------------------------------\n\n\n";
			}
		}
		else
		{
			List(2);
		}


		break;
	case 4:
		cout << "please Enter service Name\n";
		cin >> s;
		cout << " \t~" << "*name*" << "\t ~" << "*price*";
		for (int i = 0; i < services.size(); i++)
		{
			if (s.compare(services[i].name) == 0)
			{
				cout << "\t" << services[i].name << "\t|\t" << services[i].price << "\t|\t" << " \nGarage Id provides this service\n" << services[i].garageId << "\n\n";
				flag = true;
			}

		}
		if (flag == false)
		{
			cout << "\n\n\t\t----------------------------Invalid Data--------------------------------\n\n\n";
		}


		break;
	default:
		cout << "\t\t\n\n------------------------Invalid Number------------------------------\n\n\n";
		break;
	}




}
void List(int x)
{
	bool f = false;

	cout << " * ******************************************************************************************************\n";
	cout << " * ******************************************************************************************************\n\n";

	if (x == 1)
	{
		cout << "\n\n" << "\t ~" << "*id*" << "\t ~" << "*name*" << "\t ~" << "*location*" << "\t ~" << "*phoneNumber*" << "\n\n";
		for (int i = 0; i < garages.size(); i++)
		{
			cout << "\t" << garages[i].ID << "\t|\t" << garages[i].name << "\t|\t" << garages[i].location << "\t|\t" << garages[i].phoneNumber << "\t|\n";
			f = true;

		}

		if (f == false)
		{
			cout << "\n\n\t\t----------------------------Invalid Data--------------------------------\n\n\n";
		}
	}
	else if (x == 2)
	{
		cout << "\n\n" << " ~" << "*id*" << "\t ~" << "*name*" << "\t ~" << "*location*" << "\t ~" << "*phoneNumber*" << "\n\n";

		for (int i = 0; i < showrooms.size(); i++)
		{

			cout << "\t" << showrooms[i].ID << "\t|\t" << showrooms[i].name << "\t|\t" << showrooms[i].location << "\t|\t" << showrooms[i].phoneNumber << "\t|\n";

			f = true;
		}
		if (f == false)
		{
			cout << "\n\n\t\t----------------------------Invalid Data--------------------------------\n\n\n";
		}
	}
	else
	{

		cout << "Try again";

	}
}




#pragma endregion
#pragma region mohamed_mahmoud
/*---------------------------------------------------------------------------------------------------------*/
/* function to save*/
void Save() {
	returnData();
	cout << "************************************\n";
	cout << "*                                  *\n";
	cout << "*   Your data successfully saved   *\n";
	cout << "*                                  *\n";
	cout << "************************************\n";
}
/*---------------------------------------------------------------------------------------------------------*/
/* Function to Add car in list of cars*/
void add_car_in_list_of_cars() {
	car c;
	cout << "------------------ Add Car ---------------------\n";
	if (cars.empty() == 1) {
		c.ID = 1;
		cout << "Enter car price \n";
		cin >> c.price;
		cout << "Enter car make \n";
		cin >> c.make;
		cout << "Enter car model \n";
		cin >> c.model;
		cout << "Enter car year \n";
		cin >> c.year;
		cout << "Enter car installment \n";
		cin >> c.installment;
		c.isAvilable = true;
	}
	else {
		c.ID = cars.back().ID + 1;
		cout << "Enter car price \n";
		cin >> c.price;
		cout << "Enter car make \n";
		cin >> c.make;
		cout << "Enter car model \n";
		cin >> c.model;
		cout << "Enter car year \n";
		cin >> c.year;
		cout << "Enter car installment \n";
		cin >> c.installment;
		c.isAvilable = true;
	}
	cars.push_back(c);
	cout << "************************************\n";
	cout << "*                                  *\n";
	cout << "*   Successfully added a new car   *\n";
	cout << "*                                  *\n";
	cout << "************************************\n";
}
/* Function to Add service in list of servise*/
void add_service_in_list_of_services() {
	cout << "----------------- Add Service -------------------\n";
	service s;
	if (services.empty() == 1) {
		s.ID = 1;
		cout << "Enter service price\n";
		cin >> s.price;
		cout << "Enter service name\n";
		cin >> s.name;
	}
	else {
		s.ID = services.back().ID + 1;
		cout << "Enter service price\n";
		cin >> s.price;
		cout << "Enter service name\n";
		cin >> s.name;
	}
	services.push_back(s);
	cout << "****************************************\n";
	cout << "*                                      *\n";
	cout << "*   Successfully added a new service   *\n";
	cout << "*                                      *\n";
	cout << "****************************************\n";
}
/*  function to add car  */
void add_car() {
	car c;
	int showroom_id;
	cout << "------------------ Add Car ---------------------\n";
	if (cars.empty() == 1) {


		c.ID = 1;
		cout << "Enter car price \n";
		cin >> c.price;
		cout << "Enter car make \n";
		cin >> c.make;
		cout << "Enter car model \n";
		cin >> c.model;
		cout << "Enter car year \n";
		cin >> c.year;
		cout << "Enter car installment \n";
		cin >> c.installment;
		c.isAvilable = true;
		if (showrooms.empty() == 1) {
			c.showroomId = 0;
			cout << "your showroom id is '0'\n";
		}
		else {
			cout << "Enter showroom id\n";
			cin >> showroom_id;
			for (int i = 0; i < showrooms.size(); i++) {
				if (showrooms.at(i).ID == showroom_id) {
					showrooms.at(i).listOfCars.push_back(c);
					c.showroomId = showroom_id;
				}
			}
		}
	}
	else {

		c.ID = cars.back().ID + 1;
		cout << "Enter car price \n";
		cin >> c.price;
		cout << "Enter car make \n";
		cin >> c.make;
		cout << "Enter car model \n";
		cin >> c.model;
		cout << "Enter car year \n";
		cin >> c.year;
		cout << "Enter car installment \n";
		cin >> c.installment;
		c.isAvilable = true;
		if (showrooms.empty() == 1) {
			c.showroomId = 0;
			cout << "your showroom id is '0'\n";
		}
		else {
			cout << "Enter showroom id\n";
			cin >> showroom_id;
			for (int i = 0; i < showrooms.size(); i++) {
				if (showrooms.at(i).ID == showroom_id) {
					showrooms.at(i).listOfCars.push_back(c);
					c.showroomId = showroom_id;
				}
			}
		}
	}
	cars.push_back(c);
	cout << "************************************\n";
	cout << "*                                  *\n";
	cout << "*   Successfully added a new car   *\n";
	cout << "*                                  *\n";
	cout << "************************************\n";
}
/*  function to add service  */
void add_service() {
	cout << "----------------- Add Service -------------------\n";
	service s;
	int garage_id;
	if (services.empty() == 1) {
		s.ID = 1;
		cout << "Enter service price\n";
		cin >> s.price;
		cout << "Enter service name\n";
		cin >> s.name;
		if (garages.empty() == 1) {
			s.garageId = 0;
			cout << "your garage id is '0'\n";
		}
		else {
			cout << "Enter garage id\n";
			cin >> garage_id;
			for (int i = 0; i < showrooms.size(); i++) {
				if (garages.at(i).ID == garage_id) {
					garages.at(i).listOfService.push_back(s);
					s.garageId = garage_id;
				}
			}
		}
	}
	else {
		s.ID = services.back().ID + 1;
		cout << "Enter service price\n";
		cin >> s.price;
		cout << "Enter service name\n";
		cin >> s.name;
		if (garages.empty() == 1) {
			s.garageId = 0;
			cout << "your garage id is '0'\n";
		}
		else {
			cout << "Enter garage id\n";
			cin >> garage_id;
			for (int i = 0; i < garages.size(); i++) {
				if (garages.at(i).ID == garage_id) {
					garages.at(i).listOfService.push_back(s);
					s.garageId = garage_id;
				}
			}
		}
	}
	services.push_back(s);
	cout << "****************************************\n";
	cout << "*                                      *\n";
	cout << "*   Successfully added a new service   *\n";
	cout << "*                                      *\n";
	cout << "****************************************\n";
}
/*  function to add showroom  */
void add_showroom() {
	int size;
	showroom s;
	cout << "----------------- Add Showroom -------------------\n";
	if (showrooms.empty() == 1) {
		s.ID = 1;
		cout << "Enter showroom name\n";
		cin >> s.name;
		cout << "Enter showroom location\n";
		cin >> s.location;
		cout << "Enter showroom phone number\n";
		cin >> s.phoneNumber;
		cout << "Enter how many car you wnt to add \n";
		cin >> size;
		for (int i = 1; i <= size; i++) {
			add_car_in_list_of_cars();
			car c = cars.back();
			c.showroomId = s.ID;
			cars.pop_back();
			cars.push_back(c);
			s.listOfCars.push_back(c);
		}
	}
	else {
		s.ID = showrooms.back().ID + 1;
		cout << "Enter showroom name\n";
		cin >> s.name;
		cout << "Enter showroom location\n";
		cin >> s.location;
		cout << "Enter showroom phone number\n";
		cin >> s.phoneNumber;
		cout << "Enter how many car you want to add \n";
		cin >> size;
		for (int i = 1; i <= size; i++) {
			add_car_in_list_of_cars();
			car c = cars.back();
			c.showroomId = s.ID;
			cars.pop_back();
			cars.push_back(c);
			s.listOfCars.push_back(c);
		}
	}
	showrooms.push_back(s);
	cout << "*****************************************\n";
	cout << "*                                       *\n";
	cout << "*   Successfully added a new showroom   *\n";
	cout << "*                                       *\n";
	cout << "*****************************************\n";
}
/*  function to add Garage  */
void add_garage() {
	cout << "----------------- Add Garage -------------------\n";
	garage g;
	int size;
	if (garages.empty() == 1) {
		g.ID = 1;
		cout << "Enter garage name\n";
		cin >> g.name;
		cout << "Enter garage location\n";
		cin >> g.location;
		cout << "Enter garage phone number\n";
		cin >> g.phoneNumber;
		cout << "How many services do you want to add \n";
		cin >> size;
		for (int i = 1; i <= size; i++) {
			add_service_in_list_of_services();
			service s = services.back();
			s.garageId = g.ID;
			services.pop_back();
			services.push_back(s);
			g.listOfService.push_back(s);
		}
	}
	else {
		g.ID = garages.back().ID + 1;
		cout << "Enter garage name\n";
		cin >> g.name;
		cout << "Enter garage location\n";
		cin >> g.location;
		cout << "Enter garage phone number\n";
		cin >> g.phoneNumber;
		cout << "How many services do you want to add \n";
		cin >> size;
		for (int i = 1; i <= size; i++) {
			add_service_in_list_of_services();
			service s = services.back();
			s.garageId = g.ID;
			services.pop_back();
			services.push_back(s);
			g.listOfService.push_back(s);
		}
	}
	garages.push_back(g);
	cout << "***************************************\n";
	cout << "*                                     *\n";
	cout << "*   Successfully added a new garage   *\n";
	cout << "*                                     *\n";
	cout << "***************************************\n";
}
/* Function to Add*/
void Add() {
	bool Exit = false;
	int choise;
	while (!Exit) {
		cout << "------------------Add ---------------------\n";
		cout << "Please press the category number you want to add in:\n";
		cout << "1_Showrooms \n";
		cout << "2_Garage \n";
		cout << "3_Car \n";
		cout << "4_Servece \n";
		cout << "5_Save \n";
		cout << "6_Back \n";
		cin >> choise;
		if (choise == 1) {
			add_showroom();
		}
		else if (choise == 2) {
			add_garage();
		}
		else if (choise == 3) {
			add_car();
		}
		else if (choise == 4) {
			add_service();
		}
		else if (choise == 5) {
			Save();
		}
		else if (choise == 6) {
			Exit = true;
		}
		else {
			cout << "invalid choise\n";
		}
	}
}
/*--------------------------------------------------------------------------------------------------------*/
/*function to Delete from services*/
void delete_service() {
	cout << "----------------- Delete Service -------------------\n";
	int service_id;
	bool is_found = false;
	if (services.empty() == 1) {
		cout << "There is no service to delete\n";
	}
	else {
		cout << "Enter servive id you want to Delete\n";
		cin >> service_id;
		for (int i = 0; i < services.size(); i++) {
			if (services.at(i).ID == service_id) {
				services.erase(services.begin() + i);
				is_found = true;
				break;
			}
		}
		if (is_found == true) {
			for (int i = 0; i < garages.size(); i++) {
				for (int j = 0; j < garages.at(i).listOfService.size(); j++) {
					if (garages.at(i).listOfService.at(j).ID == service_id) {
						garages.at(i).listOfService.erase(garages.at(i).listOfService.begin() + j);
						cout << "******************************\n";
						cout << "*                            *\n";
						cout << "*   Successfully deleted     *\n";
						cout << "*                            *\n";
						cout << "******************************\n";
						break;
					}
				}
			}
		}
		else {
			cout << "Not founded\n";
		}
	}

}
/*function to Delete from cars*/
void delete_car() {
	cout << "----------------- Delete Car -------------------\n";
	int car_id;
	bool is_found = false;
	if (cars.empty() == 1) {
		cout << "There is no car to delete\n";
	}
	else {
		cout << "Enter car id you want to Delete\n";
		cin >> car_id;
		for (int i = 0; i < cars.size(); i++) {
			if (cars.at(i).ID == car_id) {
				cars.erase(cars.begin() + i);
				is_found = true;
				break;
			}
		}
		if (is_found == true) {
			for (int i = 0; i < showrooms.size(); i++) {
				for (int j = 0; j < showrooms.at(i).listOfCars.size(); j++) {
					if (showrooms.at(i).listOfCars.at(j).ID == car_id) {
						showrooms.at(i).listOfCars.erase(showrooms.at(i).listOfCars.begin() + j);
						cout << "******************************\n";
						cout << "*                            *\n";
						cout << "*   Successfully deleted     *\n";
						cout << "*                            *\n";
						cout << "******************************\n";
						break;
					}
				}
			}
		}
		else {
			cout << "Not founded\n";
		}
	}
}
/*function to Delete from garages*/
void delete_garage() {
	cout << "----------------- Delete Garage -------------------\n";
	int garage_id;
	bool is_found = false;
	if (garages.empty() == 1) {
		cout << "There is no garage to delete\n";
	}
	else {
		cout << "Enter garage id you want to Delete\n";
		cin >> garage_id;
		for (int i = 0; i < garages.size(); i++) {
			if (garages.at(i).ID == garage_id) {
				for (int j = 0; j < garages.at(i).listOfService.size(); j++) {
					for (int k = 0; k < services.size(); k++) {
						if (garages.at(i).listOfService.at(j).ID == services.at(k).ID) {
							services.erase(services.begin() + k);
						}
					}
				}
				garages.erase(garages.begin() + i);
				is_found = true;
				break;
			}
		}
		if (is_found == true) {
			cout << "******************************\n";
			cout << "*                            *\n";
			cout << "*   Successfully deleted     *\n";
			cout << "*                            *\n";
			cout << "******************************\n";
		}
		else {
			cout << "Not founded\n";
		}
	}
}
/*function to Delete from showrooms*/
void delete_showroom() {
	cout << "----------------- Delete Showroom -------------------\n";
	int showroom_id;
	bool is_found = false;
	if (showrooms.empty() == 1) {
		cout << "There is no showroom to delete\n";
	}
	else {
		cout << "Enter showroom id you want to Delete\n";
		cin >> showroom_id;
		for (int i = 0; i < showrooms.size(); i++) {
			if (showrooms.at(i).ID == showroom_id) {
				for (int j = 0; j < showrooms.at(i).listOfCars.size(); j++) {
					for (int k = 0; k < cars.size(); k++) {
						if (showrooms.at(i).listOfCars.at(j).ID == cars.at(k).ID) {
							cars.erase(cars.begin() + k);
						}
					}
				}
				showrooms.erase(showrooms.begin() + i);
				is_found = true;
				break;
			}
		}
		if (is_found == true) {
			cout << "******************************\n";
			cout << "*                            *\n";
			cout << "*   Successfully deleted     *\n";
			cout << "*                            *\n";
			cout << "******************************\n";

		}
		else {
			cout << "Not founded\n";
		}
	}
}
/* function to Delete*/
void Delete() {
	bool Exit = false;
	int choise;
	while (!Exit) {
		cout << "------------------Delete ---------------------\n";
		cout << "Please press the category number you want to delete from it:\n";
		cout << "1_Showrooms \n";
		cout << "2_Garage \n";
		cout << "3_Car \n";
		cout << "4_Servece \n";
		cout << "5_Save \n";
		cout << "6_Back \n";
		cin >> choise;
		if (choise == 1) {
			delete_showroom();
		}
		else if (choise == 2) {
			delete_garage();
		}
		else if (choise == 3) {
			delete_car();
		}
		else if (choise == 4) {
			delete_service();
		}
		else if (choise == 5) {
			Save();
		}
		else if (choise == 6) {
			Exit = true;
		}
		else {
			cout << "invalid choise\n";
		}
	}
}
/*---------------------------------------------------------------------------------------------------------*/
/*functions to Update Services*/
void update_service_price(int serviceid) {
	for (int i = 0; i < services.size(); i++) {
		if (services.at(i).ID == serviceid) {
			cout << "Enter the new price\n";
			cin >> services.at(i).price;
			cout << "**********************************\n";
			cout << "*                                *\n";
			cout << "*   Successfully Updated price   *\n";
			cout << "*                                *\n";
			cout << "**********************************\n";
		}
	}
}
void update_service_name(int serviceid) {
	for (int i = 0; i < services.size(); i++) {
		if (services.at(i).ID == serviceid) {
			cout << "Enter the new name\n";
			cin >> services.at(i).name;
			cout << "**********************************\n";
			cout << "*                                *\n";
			cout << "*   Successfully Updated name    *\n";
			cout << "*                                *\n";
			cout << "**********************************\n";
		}
	}
}
void update_service_garage_id(int serviceid) {
	int garageid;
jump:
	cout << "Enter the new garage ID\n";
	cin >> garageid;
	for (int i = 0; i < services.size(); i++) {
		if (services.at(i).ID == serviceid) {
			/*loob to find the new garage*/
			for (int j = 0; j < garages.size(); j++) {
				if (garages.at(j).ID == garageid) {
					/*succesfully add the service in the new garage lis of service*/
					garages.at(j).listOfService.push_back(services.at(i));
					break;
				}
				else {
					cout << "garage ID not found\n";
					goto jump;
				}
			}
			/*for loob to remove the service from the old garage list of service*/
			for (int j = 0; j < garages.size(); j++) {
				for (int k = 0; k < garages.at(j).listOfService.size(); k++) {
					if (services.at(i).garageId == garages.at(j).listOfService.at(k).garageId) {
						garages.at(j).listOfService.erase(garages.at(j).listOfService.begin() + k);
						break;
					}
				}
			}
			services.at(i).garageId = garageid;
		}
	}
	cout << "**************************************\n";
	cout << "*                                    *\n";
	cout << "*   Successfully Updated garage ID   *\n";
	cout << "*                                    *\n";
	cout << "**************************************\n";
}
void UPDATE_SERVICES() {
	bool Exit = false;
	int service_id;
	int choise;
	cout << "------------------Update Services-------------------- - \n";
	cout << "Enter service ID\n";
	cin >> service_id;
	for (int i = 0; i < services.size(); i++) {
		if (services.at(i).ID == service_id) {
			while (!Exit) {
				cout << "------------------Update Services" << services.at(i).ID << "-------------------- - \n";
				cout << "Please press the attribute number you want to Update:\n";
				cout << "1_Price \n";
				cout << "2_Name \n";
				cout << "3_Garage ID \n";
				cout << "4_Back \n";
				cin >> choise;
				if (choise == 1) {
					update_service_price(service_id);
				}
				else if (choise == 2) {
					update_service_name(service_id);
				}
				else if (choise == 3) {
					update_service_garage_id(service_id);
				}
				else if (choise == 4) {
					Exit = true;
				}
				else {
					cout << "invalid choise\n";
				}
			}
		}
		else {
			cout << "This service is not found\n";
		}

		if (Exit)
			break;
	}
}
/*functions to Update Cars*/
void update_car_price(int carid) {
	for (int i = 0; i < cars.size(); i++) {
		if (cars.at(i).ID == carid) {
			cout << "Enter the new price\n";
			cin >> cars.at(i).price;
			cout << "**********************************\n";
			cout << "*                                *\n";
			cout << "*   Successfully Updated price   *\n";
			cout << "*                                *\n";
			cout << "**********************************\n";
		}
	}
}
void update_car_make(int carid) {
	for (int i = 0; i < cars.size(); i++) {
		if (cars.at(i).ID == carid) {
			cout << "Enter the new make\n";
			cin >> cars.at(i).make;
			cout << "**********************************\n";
			cout << "*                                *\n";
			cout << "*   Successfully Updated make    *\n";
			cout << "*                                *\n";
			cout << "**********************************\n";
		}
	}
}
void update_car_model(int carid) {
	for (int i = 0; i < cars.size(); i++) {
		if (cars.at(i).ID == carid) {
			cout << "Enter the new model\n";
			cin >> cars.at(i).model;
			cout << "**********************************\n";
			cout << "*                                *\n";
			cout << "*   Successfully Updated model   *\n";
			cout << "*                                *\n";
			cout << "**********************************\n";
		}
	}
}
void update_car_year(int carid) {
	for (int i = 0; i < cars.size(); i++) {
		if (cars.at(i).ID == carid) {
			cout << "Enter the new year\n";
			cin >> cars.at(i).year;
			cout << "**********************************\n";
			cout << "*                                *\n";
			cout << "*   Successfully Updated year    *\n";
			cout << "*                                *\n";
			cout << "**********************************\n";

		}
	}
}
void update_car_installment(int carid) {
	for (int i = 0; i < cars.size(); i++) {
		if (cars.at(i).ID == carid) {
			cout << "Enter the new installment\n";
			cin >> cars.at(i).installment;
			cout << "****************************************\n";
			cout << "*                                      *\n";
			cout << "*   Successfully Updated installment   *\n";
			cout << "*                                      *\n";
			cout << "****************************************\n";
		}
	}
}
void update_car_availability(int carid) {
	for (int i = 0; i < cars.size(); i++) {
		if (cars.at(i).ID == carid) {
			if (cars.at(i).isAvilable == true) {
				cars.at(i).isAvilable = false;
				cout << "**********************************************************\n";
				cout << "*                                                        *\n";
				cout << "*   Successfully Updated (The car is not avilable now)   *\n";
				cout << "*                                                        *\n";
				cout << "**********************************************************\n";
			}
			else {
				cars.at(i).isAvilable = true;
				cout << "******************************************************\n";
				cout << "*                                                    *\n";
				cout << "*   Successfully Updated (The car is avilable now)   *\n";
				cout << "*                                                    *\n";
				cout << "******************************************************\n";
			}
		}
	}
}
void update_car_showroom_id(int carid) {
	int showroomid;
jump:
	cout << "Enter the new showroom ID ID\n";
	cin >> showroomid;
	for (int i = 0; i < cars.size(); i++) {
		if (cars.at(i).ID == carid) {
			/*loob to find the new showroom*/
			for (int j = 0; j < showrooms.size(); j++) {
				if (showrooms.at(j).ID == showroomid) {
					/*succesfully add the car in the new garage lis of car*/
					showrooms.at(j).listOfCars.push_back(cars.at(i));
					break;
				}
				else {
					cout << "showroom ID not found\n";
					goto jump;
				}
			}
			/*for loob to remove the car from the old showroom list of cars*/
			for (int j = 0; j < showrooms.size(); j++) {
				for (int k = 0; k < showrooms.at(j).listOfCars.size(); k++) {
					if (cars.at(i).showroomId == showrooms.at(j).listOfCars.at(k).showroomId) {
						showrooms.at(j).listOfCars.erase(showrooms.at(j).listOfCars.begin() + k);
						break;
					}
				}
			}
			cars.at(i).showroomId = showroomid;
		}
	}
	cout << "****************************************\n";
	cout << "*                                      *\n";
	cout << "*   Successfully Updated showroom ID   *\n";
	cout << "*                                      *\n";
	cout << "****************************************\n";
}
void UPDATE_CARS() {
	bool Exit = false;
	int car_id;
	int choise;
	cout << "------------------Update Cars-------------------- - \n";
	cout << "Enter car ID\n";
	cin >> car_id;
	for (int i = 0; i < cars.size(); i++) {
		if (cars.at(i).ID == car_id) {
			while (!Exit) {
				cout << "------------------Update Car" << cars.at(i).ID << "-------------------- - \n";
				cout << "Please press the attribute number you want to Update:\n";
				cout << "1_Price \n";
				cout << "2_Make \n";
				cout << "3_Model \n";
				cout << "4_Year \n";
				cout << "5_Installment \n";
				cout << "6_Availability \n";
				cout << "7_Showroom ID \n";
				cout << "8_Back \n";
				cin >> choise;
				if (choise == 1) {
					update_car_price(car_id);
				}
				else if (choise == 2) {
					update_car_make(car_id);
				}
				else if (choise == 3) {
					update_car_model(car_id);
				}
				else if (choise == 4) {
					update_car_year(car_id);
				}
				else if (choise == 5) {
					update_car_installment(car_id);
				}
				else if (choise == 6) {
					update_car_availability(car_id);
				}
				else if (choise == 7) {
					update_car_showroom_id(car_id);
				}
				else if (choise == 8) {
					Exit = true;
				}
				else {
					cout << "invalid choise\n";
				}
			}
		}
		else {
			cout << "This car is not found\n";
		}

		if (Exit)
			break;
	}
}
/*functions to Update Garages*/
void update_garage_name(int garage_id) {
	for (int i = 0; i < garages.size(); i++) {
		if (garages.at(i).ID == garage_id) {
			cout << "Enter the new name\n";
			cin >> garages.at(i).name;
			cout << "**********************************\n";
			cout << "*                                *\n";
			cout << "*   Successfully Updated name    *\n";
			cout << "*                                *\n";
			cout << "**********************************\n";
		}
	}
}
void update_garage_location(int garage_id) {
	for (int i = 0; i < garages.size(); i++) {
		if (garages.at(i).ID == garage_id) {
			cout << "Enter the new location\n";
			cin >> garages.at(i).location;
			cout << "*************************************\n";
			cout << "*                                   *\n";
			cout << "*   Successfully Updated location   *\n";
			cout << "*                                   *\n";
			cout << "*************************************\n";
		}
	}
}
void update_garage_phone_number(int garage_id) {
	for (int i = 0; i < garages.size(); i++) {
		if (garages.at(i).ID == garage_id) {
			cout << "Enter the new phone number\n";
			cin >> garages.at(i).phoneNumber;
			cout << "*****************************************\n";
			cout << "*                                       *\n";
			cout << "*   Successfully Updated phone number   *\n";
			cout << "*                                       *\n";
			cout << "*****************************************\n";
		}
	}
}
void UPDATE_GARAGES() {
	bool Exit = false;
	int garage_id;
	int choise;
	cout << "------------------Update Garages -------------------- - \n";
	cout << "Enter garage ID\n";
	cin >> garage_id;
	for (int i = 0; i < garages.size(); i++) {
		if (garages.at(i).ID == garage_id) {
			while (!Exit) {
				cout << "------------------Update Garages " << garages.at(i).ID << "-------------------- - \n";
				cout << "Please press the attribute number you want to Update:\n";
				cout << "1_Name \n";
				cout << "2_Location \n";
				cout << "3_Phone Number \n";
				cout << "4_Back \n";
				cin >> choise;
				if (choise == 1) {
					update_garage_name(garage_id);
				}
				else if (choise == 2) {
					update_garage_location(garage_id);
				}
				else if (choise == 3) {
					update_garage_phone_number(garage_id);
				}
				else if (choise == 4) {
					Exit = true;
				}
				else {
					cout << "invalid choise\n";
				}
			}
		}
		else {
			cout << "This garage is not found\n";
		}

		if (Exit)
			break;
	}
}
/*functions to Update Showrooms*/
void update_showroom_name(int showroom_id) {
	for (int i = 0; i < showrooms.size(); i++) {
		if (showrooms.at(i).ID == showroom_id) {
			cout << "Enter the new name\n";
			cin >> showrooms.at(i).name;
			cout << "**********************************\n";
			cout << "*                                *\n";
			cout << "*   Successfully Updated name    *\n";
			cout << "*                                *\n";
			cout << "**********************************\n";
		}
	}
}
void update_showroom_location(int showroom_id) {
	for (int i = 0; i < showrooms.size(); i++) {
		if (showrooms.at(i).ID == showroom_id) {
			cout << "Enter the new location\n";
			cin >> showrooms.at(i).location;
			cout << "*************************************\n";
			cout << "*                                   *\n";
			cout << "*   Successfully Updated location   *\n";
			cout << "*                                   *\n";
			cout << "*************************************\n";
		}
	}
}
void update_showroom_phone_number(int showroom_id) {
	for (int i = 0; i < showrooms.size(); i++) {
		if (showrooms.at(i).ID == showroom_id) {
			cout << "Enter the new phone number\n";
			cin >> showrooms.at(i).phoneNumber;
			cout << "*****************************************\n";
			cout << "*                                       *\n";
			cout << "*   Successfully Updated phone number   *\n";
			cout << "*                                       *\n";
			cout << "*****************************************\n";
		}
	}
}
void UPDATE_SHOWROOMS() {
	bool Exit = false;
	int showroom_id;
	int choise;
	cout << "------------------Update showrooms -------------------- - \n";
	cout << "Enter showroom ID\n";
	cin >> showroom_id;
	for (int i = 0; i < showrooms.size(); i++) {
		if (showrooms.at(i).ID == showroom_id) {
			while (!Exit) {
				cout << "------------------Update Showrooms " << showrooms.at(i).ID << "-------------------- - \n";
				cout << "Please press the attribute number you want to Update:\n";
				cout << "1_Name \n";
				cout << "2_Location \n";
				cout << "3_Phone Number \n";
				cout << "4_Back \n";
				cin >> choise;
				if (choise == 1) {
					update_showroom_name(showroom_id);
				}
				else if (choise == 2) {
					update_showroom_location(showroom_id);
				}
				else if (choise == 3) {
					update_showroom_phone_number(showroom_id);
				}
				else if (choise == 4) {
					Exit = true;
				}
				else {
					cout << "invalid choise\n";
				}
			}
		}
		else {
			cout << "This showroom is not found\n";
		}

		if (Exit)
			break;
	}

}
/*function to Update*/
void Update() {
	bool Exit = false;
	int choise;
	while (!Exit) {
		cout << "------------------Update ---------------------\n";
		cout << "Please press the category number you want to Update:\n";
		cout << "1_Showrooms \n";
		cout << "2_Garage \n";
		cout << "3_Car \n";
		cout << "4_Servece \n";
		cout << "5_Save \n";
		cout << "6_Back \n";
		cin >> choise;
		if (choise == 1) {
			UPDATE_SHOWROOMS();
		}
		else if (choise == 2) {
			UPDATE_GARAGES();
		}
		else if (choise == 3) {
			UPDATE_CARS();
		}
		else if (choise == 4) {
			UPDATE_SERVICES();
		}
		else if (choise == 5) {
			Save();
		}
		else if (choise == 6) {
			Exit = true;
		}
		else {
			cout << "invalid choise\n";
		}
	}
}
/*---------------------------------------------------------------------------------------------------------*/


#pragma endregion





int main()
{

#pragma region salution
	cout << endl << endl;
	cout << "			************************************************************************\n";
	cout << "			*                                                                      *\n";
	cout << "			*       \\    /\\    /  ____  |       ____    ___    /\\    /\\     ____   *\n";
	cout << "			*        \\  /  \\  /  |____  |	   |       |   |  /  \\  /  \\   |____   *\n";
	cout << "			*         \\/    \\/   |____  |____  |____   |___| /    \\/    \\  |____   *\n";
	cout << "			*                                                                      *\n";
	cout << "			************************************************************************\n\n";

#pragma endregion

	getData();

start:
	cout << "------------------login / regester Page---------------------\n";
	cout << "Please press your process number:\n";
	cout << "1_Login\n";
	cout << "2_Regester\n";
	char operation;
	cin >> operation;
	if (operation != '1' && operation != '2')
	{
		cout << "enter a valid operation\n\n";
		goto start;
	}
	if (operation == '1') {

		Login();

		int choise = menue();

		while ((loginAccountId == 1 && choise != 5) || (loginAccountId != 1 && choise != 6))
		{
			if (loginAccountId == 1) {
				switch (choise)
				{
				case 1:
					Add();
					break;
				case 2:
					Delete();
					break;
				case 3:
					Update();
					break;
				case 4:
					ShowPreviousProcess();
					break;
				default:
					cout << "invalid choise\n";
				}
			}
			else
			{
				switch (choise)
				{
				case 1:
					Search();
					break;
				case 2:
					cout << "\n" << "1_Show all garages\n2_Show all Showrooms\n";
					int x;
					cin >> x;
					List(x);
					break;
				case 3:
					BuyOrRent();
					break;
				case 4:
					BookService();
					break;
				case 5:
					ShowPreviousProcess();
					break;
				default:
					cout << "invalid choise\n";
				}
			}

			choise = menue();
		}
	}
	else {
		Register();
		goto start;
	}
	returnData();
}