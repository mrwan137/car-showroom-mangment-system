#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int loginAccountId = 1;
static fstream file;



////////////////////////
// function
		   //////////////////////adidas//////////////////////
void Register();
void Login();
void ShowPreviousProcess();


//////////////////////sharb//////////////////////
void Search();
void List(int);

//////////////////////omar//////////////////////
void BuyOrRent();
void BookService();

//////////////////////pop//////////////////////
void Add();
void Update();
void Delete();


//////////////////////////////////////////
// 
class service {
	// classes
		//static int id;

public:

	int ID;
	int price = 0;
	string name = "null";
	int garageId = 0;/*

	service () {
		id++;
		ID = id;
	};*/
};

class serviceProcces {
	//static int id;

public:

	int ID;
	int price = 0;
	int custid = 0;
	string date = "null";
	service chossenService;
	int serviceId = 0;


	//serviceProcces() {
	//	id++;
	//	ID = id;
	//};
};

class car {
	//static int id;

public:

	int ID;
	int price = 0;
	string make = "null";
	string model = "null";
	string year = "null";
	string installment = "null";
	bool isAvilable = true;
	int showroomId = 0;

	//car() {
	//	id++;
	//	ID = id;
	//};
};

class garage {

	//static int id;

public:

	int ID;
	string name = "null";
	string location = "null";
	string phoneNumber = "null";
	vector<service> listOfService;

	//garage() {
	//	id++;
	//	ID = id;
	//};
};

class showroom {

	//static int id;

public:

	int ID;
	string name = "null";
	string location = "null";
	string phoneNumber = "null";
	vector<car> listOfCars;

	//showroom() {
	//	id++;
	//	ID = id;
	//};
};

class buyProssess {
	//static int id;

public:

	int ID;
	int custId = 0;
	int price = 0;
	string date = "null";
	car choosenCar;
	int carId = 0;

	//buyProssess() {
	//	id++;
	//	ID = id;
	//};
};

class person
{
	//static int id;

public:

	int ID;
	string UserName = "null";
	string password = "null";
	bool isCustomer = 1;

	//person() {
	//	id++;
	//	ID = id;
	//};
};


// // initialize static variable
//int person::id = 0;
//int car::id = 0;
//int buyProssess::id = 0;
//int showroom::id = 0;
//int service::id = 0;
//int serviceProcces::id = 0;
//int garage::id = 0;


//////////////////////////////////
//  lists
vector<person> accounts;
vector<service> services;
vector<serviceProcces> serviceProccess;
vector<car> cars;
vector<buyProssess> buyRentProsess;
vector<showroom> showrooms;
vector<garage> garages;


//////////////////////////////////
// files function

// 1. get data

void getAccountsFile() {
	file.open("accounts.txt");
	accounts.clear();

	person in;

	while (file >> in.ID)
	{
		file >> in.UserName >> in.password >> in.isCustomer;
		accounts.push_back(in);
	}
	file.close();
}

void getGarageFile() {
	file.open("garage.txt");
	garages.clear();

	garage in;

	while (file >> in.ID)
	{
		file >> in.name >> in.location >> in.phoneNumber;
		garages.push_back(in);
	}
	file.close();
}

void getShowroomFile() {
	file.open("showroom.txt");
	showrooms.clear();

	showroom in;

	while (file >> in.ID)
	{
		file >> in.name >> in.location >> in.phoneNumber;
		showrooms.push_back(in);
	}
	file.close();
}

void getServiceFile() {
	file.open("service.txt");
	services.clear();

	service in;

	while (file >> in.ID)
	{
		file >> in.name >> in.price >> in.garageId;
		services.push_back(in);
	}
	file.close();
}

void getCarFile() {
	file.open("car.txt");
	cars.clear();

	car in;

	while (file >> in.ID)
	{
		file >> in.price >> in.make >> in.model >> in.year >> in.installment >> in.isAvilable >> in.showroomId;
		cars.push_back(in);
	}
	file.close();

}

void getBuyproccesFile() {
	file.open("buyprocces.txt");
	buyRentProsess.clear();

	buyProssess in;

	while (file >> in.ID)
	{
		file >> in.custId >> in.price >> in.date >> in.carId;
		for (car c : cars)
		{
			if (c.ID == in.carId)
			{
				in.choosenCar = c;
			}
		}
		buyRentProsess.push_back(in);
	}
	file.close();
}

void getServiceproccesFile() {
	file.open("serviceprosis.txt");
	serviceProccess.clear();

	serviceProcces in;

	while (file >> in.ID)
	{
		file >> in.custid >> in.price >> in.date >> in.serviceId;

		for (service serv : services)
		{
			if (serv.ID == in.serviceId)
			{
				in.chossenService = serv;
			}
		}


		serviceProccess.push_back(in);
	}
	file.close();

}

// 2. return data

void returnAccountsFile() {
	ifstream File;
	File.open("accounts.txt", ifstream::out | ifstream::trunc);
	File.close();

	file.open("accounts.txt");
	for (int i = 0; i < accounts.size(); i++)
	{
		file << accounts[i].ID << ' ' << accounts[i].UserName << ' ' << accounts[i].password << ' '
			<< accounts[i].isCustomer << endl;
	}
	file.close();
}

void returnGarageFile() {
	ifstream File;
	File.open("garage.txt", ifstream::out | ifstream::trunc);
	File.close();

	file.open("garage.txt");
	for (int i = 0; i < garages.size(); i++)
	{
		file << garages[i].ID << ' ' << garages[i].name << ' ' << garages[i].location << ' '
			<< garages[i].phoneNumber << endl;
	}
	file.close();

}

void returnShowroomFile() {
	ifstream File;
	File.open("showroom.txt", ifstream::out | ifstream::trunc);
	File.close();

	file.open("showroom.txt");
	for (int i = 0; i < showrooms.size(); i++)
	{
		file << showrooms[i].ID << ' ' << showrooms[i].name << ' ' << showrooms[i].location << ' '
			<< showrooms[i].phoneNumber << ' ' << endl;
	}
	file.close();
}

void returnServiceFile() {
	ifstream File;
	File.open("service.txt", ifstream::out | ifstream::trunc);
	File.close();

	file.open("service.txt");
	for (int i = 0; i < services.size(); i++)
	{
		file << services[i].ID << ' ' << services[i].name << ' ' << services[i].price << ' '
			<< services[i].garageId << endl;
	}
	file.close();
}

void returnCarFile() {
	ifstream File;
	File.open("car.txt", ifstream::out | ifstream::trunc);
	File.close();

	file.open("car.txt");
	for (int i = 0; i < cars.size(); i++)
	{
		file << cars[i].ID << ' ' << cars[i].price << ' ' << cars[i].make << ' '
			<< cars[i].model << ' ' << cars[i].year << ' ' << cars[i].installment << ' '
			<< cars[i].isAvilable << ' ' << cars[i].showroomId << endl;
	}
	file.close();
}

void returnBuyproccesFile() {
	ifstream File;
	File.open("buyprocces.txt", ifstream::out | ifstream::trunc);
	File.close();

	file.open("buyprocces.txt");
	for (int i = 0; i < buyRentProsess.size(); i++)
	{
		file << buyRentProsess[i].ID << ' ' << buyRentProsess[i].custId << ' ' << buyRentProsess[i].price << ' '
			<< buyRentProsess[i].date << ' ' << buyRentProsess[i].carId << endl;
	}
	file.close();
}

void returnServiceproccesFile() {
	ifstream File;
	File.open("serviceprosis.txt", ifstream::out | ifstream::trunc);
	File.close();

	file.open("serviceprosis.txt");
	for (int i = 0; i < serviceProccess.size(); i++)
	{
		file << serviceProccess[i].ID << ' ' << serviceProccess[i].custid << ' ' << serviceProccess[i].price << ' '
			<< serviceProccess[i].date << ' ' << serviceProccess[i].serviceId << endl;
	}
	file.close();
}

///////

void getData() {
	getServiceFile();
	getServiceproccesFile();
	getCarFile();
	getGarageFile();
	getShowroomFile();
	getBuyproccesFile();
	getAccountsFile();

	for (int i = 0; i < garages.size(); i++) {

		for (int j = 0; j < services.size(); j++)
		{
			if (garages[i].ID == services[j].garageId) {
				garages[i].listOfService.push_back(services[j]);
			}

		}
	}

	for (int i = 0; i < showrooms.size(); i++) {

		for (int j = 0; j < cars.size(); j++)
		{
			if (showrooms[i].ID == cars[j].showroomId) {
				showrooms[i].listOfCars.push_back(cars[j]);
			}

		}
	}


}

void returnData() {
	returnAccountsFile();
	returnGarageFile();
	returnShowroomFile();
	returnServiceFile();
	returnCarFile();
	returnBuyproccesFile();
	returnServiceproccesFile();
}



////////////////////
// menue function

int menue() {
	int choise;

	if (loginAccountId == 1) {

		cout << "------------------Admin Page---------------------\n";
		cout << "Please press your process number:\n";
		cout << "1_Add\n";
		cout << "2_Remove\n";
		cout << "3_Update\n";
		cout << "4_show previous process for a customer\n";
		cout << "5_exit\n";
	}
	else {
		cout << "------------------User Page---------------------\n";
		cout << "Please press your process number:\n";
		cout << "1_search\n";
		cout << "2_list garages/ showrooms\n";
		cout << "3_buy or rent\n";
		cout << "4_book a service\n";
		cout << "5_show previous process\n";
		cout << "6_exit\n";
	}

	cin >> choise;

	return choise;
}

/*
int main()
{
	getData();



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
				//ShowPreviousProcess();
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
				//Search();
				break;
			case 2:
				//List();
				break;
			case 3:
				//BuyOrRent();
				break;
			case 4:
				//BookService();
				break;
			case 5:
				//ShowPreviousProcess();
				break;
			default:
				cout << "invalid choise\n";
			}
		}
		choise = menue();
	}
	returnData();
}
*/