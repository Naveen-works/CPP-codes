#include <iostream>
#include <list>
using namespace std;

class Mobile{
	private:
		
		string brand_name;                 //DECLARATION AS PRIVATE FOR DATA SECURITY BY ENCAPSULATION
		int price;
		int ram;
		int rom;
		string processor_name;
		string network;
		list<string> models;
		
		
		
	public:										//ACCESSING CONSTRUCTOR AND METHOD AS PUBLIC FOR ACCESS OUTSIDE FUNCTION
	Mobile(string m_br_name,int m_price,int m_ram,int m_rom,string m_proc_name,string m_network)
	{
		 brand_name=m_br_name;
		 price=m_price;							//CONSTRUCTOR
		 ram=m_ram;
		 rom=m_rom;
		 processor_name=m_proc_name;
		 network=m_network;
	}
	
	void models_insert(string model)
	{
		models.push_back(model);					//INSERTING VALUES TO LIST BY ENCAPSULATION
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
	
	string  ret_brand_name()
	{
		return brand_name;								//GETTING VALUE NAME BY ENCAPSULATION
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
	mob1.models_insert("15 Pro max");
	mob1.models_insert("12 Pro max");
	mob1.print_info();
												//CALLING FUNCTION USING OBJECT
	cout << mob1.ret_brand_name();
	cout << endl << endl;
	
	Mobile mob3=mob1;											//ASSIGNMENT OF COPY CONSTRUCTOR
	mob3.print_info();
	
	cout << endl << endl;
	
	Mobile mob2("Samsung",13000,4,64,"Snap dragon","4G");
	mob2.models_insert("Galaxy M31");
	mob2.models_insert("Galaxy M11");
	mob2.print_info();
	
	
	return 0;
}


/*
#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string accNum, double initialBalance) {
        accountNumber = accNum;
        balance = initialBalance;
    }

    // Public methods to access and modify private members
    string getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit of $" << amount << " successful." << endl;
        } else {
            cout << "Invalid amount for deposit." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            cout << "Withdrawal of $" << amount << " successful." << endl;
        } else {
            cout << "Insufficient funds or invalid amount for withdrawal." << endl;
        }
    }
};

int main() {
    // Create an object of BankAccount
    BankAccount acc("123456789", 1000.0);

    // Accessing private members through public methods
    cout << "Account Number: " << acc.getAccountNumber() << endl;
    cout << "Balance: $" << acc.getBalance() << endl;

    // Perform transactions
    acc.deposit(500.0);
    cout << "New Balance after deposit: $" << acc.getBalance() << endl;

    acc.withdraw(200.0);
    cout << "New Balance after withdrawal: $" << acc.getBalance() << endl;

    return 0;
}

*/
