/*
//Single level inheritance

#include <iostream>
using namespace std;

class Foods
{
	protected:
		string veg;
		string non_veg;
		
	public:
		Foods(string v,string nv)
		{
			veg=v;
			non_veg=nv;
		}
		
		void f_info()
		{
			cout<<"Base Food class"<<endl;
		}
	
};

class South_food :public Foods
{
	private:
		string place;
		
	public:
		South_food(string p,string v,string nv) :Foods(v,nv)
		{
			place=p;
		}
		
		void s_info()
		{
			cout << "Place: "<<place <<endl;
			cout << "VEG: "<< veg <<endl;
			cout <<"NON VEG: "<<non_veg<<endl;
			
		}
};



int main()
{
	Foods fa("sambar","parotta");
	fa.f_info();
	
	South_food sa("Madurai","sambar","parotta");
	sa.s_info();
	
	
	return 0;
}
*/



/*
//Multiple inheritance
#include <iostream>
using namespace std;

class Animal
{
	public:
		
		void eat()
		{
			cout <<"Animal is eating" << endl;
		}	
};

class Domestic_animal :public Animal
{
	public:
		void da()
		{
		cout << " Which is a domestic animal"<< endl;
		}
};

class Dog : public Domestic_animal 
{
	private:
		string p_name;
		
	public:
		Dog(string p)
		{
			p_name=p;
		}
		
		void dog_info()
		{
			cout <<"Oh! that\'s a dog"<< endl;
			cout <<"It\'s name is "<< p_name <<endl; 
		}
};

int main()
{
	Dog dp("unknown");
	dp.eat();
	dp.da();
	dp.dog_info();
	return 0;
}
*/


/*

//Hierarchical inheritance

#include <iostream>
using namespace std;

class shape
{
	protected:
		double width;
		double height;
	public:
		shape(double w,double h)
		{
			width=w;
			height=h;
		}
		
		void s_display()
		{
			cout << "It\'s a shape of "<<width<<" width and "<< height<<" height." <<endl;
		}
		
};

class Rectangle :public shape
{
public:
	 Rectangle(double w,double h) : shape(w, h)
	{
	}
	
	void r_area()
	{
		cout << "Area: " << width*height << endl;
	}
	
	
};

int main()
{
	Rectangle rec(5,7);
	rec.s_display();
	rec.r_area();
	return 0;
}
*/

/*
//Hybrid inheritance
#include <iostream>
using namespace std;

class Super_hero
{
	protected:
		string s_name;
	public:
		Super_hero(string s)
		{
			s_name=s;
		}
		
		
		void Super_hero_details()
		{
			cout << "He is a super hero! and his name is "<<s_name<<endl;
		}
};

class Super_power 
{
	protected:
		string s_pow;
		
	public:
		Super_power(string s_p)
		{
			s_pow=s_p;
		}
		
		
		void s_power_details()
		{
			cout <<"His super power is "<< s_pow<<endl;
		}
};

class spider_man :public Super_hero, public Super_power
{ 	private:
		string team;
	public:
		spider_man(string t,string s_n,string s_po) : Super_hero(s_n), Super_power(s_po)
		{
			team=t;
		}
		
		void Spidey_details()
		{
			cout <<"He is in a team of " << team<<endl;
		}
};



int main()
{
	Super_hero sa("peter parker");
	Super_power sp("Web shooters");
	sa.Super_hero_details();
	sp.s_power_details();
	spider_man sw("Avengers","peter parker","Web shooters");
	sw.Spidey_details();
	return 0;
}
*/



/*
#include <iostream>
using namespace std;

// Base class
class Animal {
protected:
    string type;

public:
    Animal(string t) : type(t) {}

    void setType(string t) {
        type = t;
    }

    void displayType() {
        cout << "Type of animal: " << type << endl;
    }
};

// Base class
class Sound {
protected:
    string sound;

public:
    Sound(string s) : sound(s) {}

    void setSound(string s) {
        sound = s;
    }

    void makeSound() {
        cout << "Sound made by animal: " << sound << endl;
    }
};

// Derived class inheriting from Animal and Sound
class Dog : public Animal, public Sound {
private:
    string breed;

public:
    Dog(string t, string s, string b) : Animal(t), Sound(s), breed(b) {}

    void displayBreed() {
        cout << "Breed of dog: " << breed << endl;
    }
};

// Derived class inheriting from Animal
class Cat : public Animal {
private:
    string color;

public:
    Cat(string t, string c) : Animal(t), color(c) {}

    void displayColor() {
        cout << "Color of cat: " << color << endl;
    }
};

int main() {
    // Creating objects and demonstrating hybrid inheritance
    Dog myDog("Mammal", "Bark", "Labrador");
    myDog.displayType();    // Accessing Animal's method
    myDog.makeSound();      // Accessing Sound's method
    myDog.displayBreed();   // Accessing Dog's method

    cout << endl;

    Cat myCat("Mammal", "Black");
    myCat.displayType();    // Accessing Animal's method
    myCat.displayColor();   // Accessing Cat's method

    return 0;
}
*/











/*
#include <iostream>
using namespace std;

// Base class
class Vehicle {
protected:
    int wheels;

public:
    Vehicle(int w) : wheels(w) {}

    void display() {
        cout << "I am a vehicle with " << wheels << " wheels." << endl;
    }
};

// Derived class inheriting from Vehicle
class Car : public Vehicle {
private:
    string brand;

public:
    Car(int w, string b) : Vehicle(w), brand(b) {}

    void showInfo() {
        cout << "Brand: " << brand << ", Wheels: " << wheels << endl;
    }
};

int main() {
    Car c(4, "Toyota");
    c.display();    // Accessing base class method
    c.showInfo();   // Accessing derived class method

    return 0;
}








*/
