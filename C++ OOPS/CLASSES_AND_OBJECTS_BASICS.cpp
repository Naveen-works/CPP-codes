#include <iostream>
#include <list>
using namespace std;

class Mobile{
	public:
		string brand_name;
		int price;
		int ram;								//DECLARATION
		int rom;
		string processor_name;
		string network;
		list<string> models;
};

int main()
{
	Mobile mob1;
	mob1.brand_name="APPLE";
	mob1.price=95000;
	mob1.ram=16;							//ASSIGNMENT OF VALUES
	mob1.rom=512;
	mob1.processor_name="oxygen_os";
	mob1.network="5G";
	mob1.models={"11 pro max","12 pro max","13 pro max","14 pro max","15 pro max"};
	cout << "Mobile brand name: " << mob1.brand_name << endl;
	cout << "Mobile price: " << mob1.price << endl;
	cout << "Mobile RAM: "<< mob1.ram << endl;							//PRINTING THE INFORMATION
	cout << "Mobile ROM: "<< mob1.rom << endl;
	cout << "Mobile processor: " << mob1.processor_name << endl;
	cout << "Mobile Network: "<< mob1.network << endl;
	cout << "List of models available -->  " ;
	for(string mod:mob1.models)
	{
		cout << mod << " | ";
	}
	return 0;
}

