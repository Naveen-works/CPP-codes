#include <iostream>
#include <list>
using namespace std;

class Mobile{
	public:
		
		string brand_name;                 //DECLARATION
		int price;
		int ram;
		int rom;
		string processor_name;
		string network;
		list<string> models;
		
		
		
		
	Mobile(string m_br_name,int m_price,int m_ram,int m_rom,string m_proc_name,string m_network)
	{
		 brand_name=m_br_name;
		 price=m_price;							//CONSTRUCTOR
		 ram=m_ram;
		 rom=m_rom;
		 processor_name=m_proc_name;
		 network=m_network;
	}
	
	Mobile ( const Mobile &obj)
	{
		 brand_name=obj.brand_name;
		 price=obj.price;								//COPY CONSTRUCTOR
		 ram=obj.ram;
		 rom=obj.rom;									
		 processor_name=obj.processor_name;
		 network=obj.network;
		 models=obj.models;
		
	}
	
	
	
	void print_info()
	{
		cout << "Mobile brand name: " << brand_name << endl;				//METHOD
	cout << "Mobile price: " << price << endl;
	cout << "Mobile RAM: "<< ram << "GB" <<endl;
	cout << "Mobile ROM: "<< rom << "GB" <<endl;
	cout << "Mobile processor: " << processor_name << endl;
	cout << "Mobile Network: "<<network << endl;
	cout << "List of models available -->  " ;
	for(string mod:models)
	{
		cout << mod << " | ";
	}
	
	}
};

int main()
{
	Mobile mob1("Apple",130000,16,512,"Oxygen_os","5G");			//PASSING VALUES FOR CONSTRUCTING OBJECT
	mob1.models.push_back("15 Pro max");
	mob1.models.push_back("12 Pro max");
	mob1.print_info();											//CALLING FUNCTION USING OBJECT
	
	cout << endl << endl;
	
	Mobile mob3=mob1;											//ASSIGNMENT OF COPY CONSTRUCTOR
	mob3.print_info();
	
	cout << endl << endl;
	
	Mobile mob2("Samsung",13000,4,64,"Snap dragon","4G");
	mob2.models.push_back("Galaxy M31");
	mob2.models.push_back("Galaxy M11");
	mob2.print_info();
	
	
	return 0;
}
