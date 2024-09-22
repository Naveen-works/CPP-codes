
/*

//Method overloading -(static binding)

//complile time polymorphism
#include <iostream>
using namespace std;

class Addition
{
	public:
		Addition()
		{
			
		}
		
		int add(int x,int y)
		{
			return x+y;
		}
		
		int add(int x,int y, int z)
		{
			return x+y+z;
		}
};

int main()
{
	Addition ad;
	int result=ad.add(2,3,4);
	cout << result;
	return 0;
}

*/


/*

//operator overloading 
#include <iostream>
#include <list>
using namespace std;

class Animal
{
	private:
		string name;
		string type;
		string color;
		
	public:
		Animal(string n,string t,string c)
		{
			name=n;
			type=t;
			color=c;
		}
		friend ostream& operator<<(ostream& COUT,const Animal& ax);
		
		
};

ostream& operator<<(ostream& COUT,const Animal& ax)
		{
			COUT << "NAME: " << ax.name<<endl;
			COUT << "TYPE: " << ax.type<<endl;
			COUT << "COLOR: " << ax.color<<endl;
			return COUT;
		}
		
class collections
{
	private:
		list<Animal> collec;
		
	public:
		collections() {};
		
 collections& operator+=(const Animal& as)
    {
        collec.push_back(as);
        return *this;
    }
    
    friend ostream& operator<<(ostream& COUT,const collections& ac);
		
		
};
ostream& operator<<(ostream& COUT,const collections& ac)
		{
			for(const Animal& a: ac.collec)
			{
			COUT << a;
			}
			return COUT;
		}

int main()
{
	Animal a1("BUJJI","DOG","BLACK");
	cout << a1;
	Animal a2("PUPPY","DOG","BLACK");
	cout << a2;
	
	collections c1;
	c1+=a1;
	c1+=a2;
	cout << c1;
	return 0;
}
*/

/*
//Runtime polymorphism
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Animal makes a sound" << endl;
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Cat meows" << endl;
    }
};

void makeSound(Animal &a) {
    a.sound(); // Calls the appropriate overridden function
}

int main() {
    Dog d;
    Cat c;
    Animal a;
    
    a.sound();
	d.sound();
    makeSound(d); // Output: Dog barks
    makeSound(c); // Output: Cat meows

    return 0;
}
*/


/*
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Base class show function" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class show function" << endl;
    }
};

int main() {
    Base *b;
    Derived d;
    b=&d;
	b->show(); // Output: Derived class show function

    return 0;
}*/






