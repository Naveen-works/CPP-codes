#include <iostream>
#include <list>
using namespace std;

struct Mobile
{
    string brand_name;
    int price;
    int ram;
    int rom;
    string processor_name;
    string network;
    list<string> models;

    // Function to initialize Mobile object
    void con_struct_mob(string m_br_name, int m_price, int m_ram, int m_rom, string m_proc_name, string m_network)
    {
        brand_name = m_br_name;
        price = m_price;
        ram = m_ram;
        rom = m_rom;
        processor_name = m_proc_name;
        network = m_network;
    }

    // Function to print the information of the Mobile object
    void print_info_mob() const
    {
        cout << "Mobile name: " << brand_name << endl;
        cout << "Mobile Price: " << price << endl;
        cout << "Mobile RAM: " << ram << "GB" << endl;
        cout << "Mobile ROM: " << rom << "GB" << endl;
        cout << "Mobile Processor: " << processor_name << endl;
        cout << "Mobile Network: " << network << endl;
        cout << "List of models available: ";
        for (const string& mod : models)
        {
            cout << mod << " | ";
        }
        cout << endl;
    }
};

struct Person
{
    string name;
    int age;
    Mobile mob;

    // Function to initialize Person object
    void con_struct_person(string p_name, int p_age, const Mobile& p_mob)
    {
        name = p_name;
        age = p_age;
        mob = p_mob;
    }

    // Function to print the information of the Person object
    void print_info_person() const
    {
        cout << "Person name: " << name << endl;
        cout << "Person age: " << age << endl;
        cout << "Person smartphone: " << endl;
        mob.print_info_mob();
    }
};

int main()
{
    Mobile mob1; // Structure declaration
    mob1.models.push_back("12 Pro Max");
    mob1.models.push_back("13 Pro Max");
    mob1.con_struct_mob("Apple", 130000, 16, 512, "A14 Bionic", "5G");
    mob1.print_info_mob();

	cout <<endl <<endl;

    Person p;
    p.con_struct_person("Patrick", 26, mob1);
    p.print_info_person();

    return 0;
}


/*
#include <iostream>
using namespace std;

struct Person {
    string name;
    int age;
    double height;
};

void printPerson(Person p) {
    cout << "Name: " << p.name << endl;
    cout << "Age: " << p.age << endl;
    cout << "Height: " << p.height << " feet" << endl;
}

Person createPerson(string name, int age, double height) {
    Person p;
    p.name = name;
    p.age = age;
    p.height = height;
    return p;
}

int main() {
    Person person1 = createPerson("John Doe", 30, 5.9);
    printPerson(person1);

    return 0;
}
*/

