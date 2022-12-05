// ConsoleApplication1.33.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 31.Задача 1. Реализация "умного" указателя.

#include <iostream>
#include <string>
using namespace std;

class Toy {
	string name;
public:
	string getName() {
		return name;
	}
	Toy(const string _name) :name(_name) {
		cout << "\nToy: " << getName();
	};
	Toy() :name("Bone") {};
};

Toy make_shared_toy(const string toyName);

class shared_ptr_toy {
	Toy* lovetoy;
	int *counter;
public:
	shared_ptr_toy(const string toyName){
		 make_shared_toy(toyName);
		counter=new int(1);
	}
	shared_ptr_toy(const shared_ptr_toy& oth) {
		*lovetoy = *oth.lovetoy;
		counter = oth.counter;
		++* counter;
	}
	shared_ptr_toy& operator=(const shared_ptr_toy(&oth)) {
		if (this == &oth) {
			return*this;
		}
		--* counter;
		if(*counter==0){
			cout << "\n delete lovelyToy. ";
				delete lovetoy;
				delete counter;
			}
	lovetoy = oth.lovetoy;
	counter = oth.counter;
	++*counter;
		return*this;
	}
	int getCounter() {
		return *counter;
	}
	~shared_ptr_toy() {
		if (*counter > 1) {
			--* counter;
		}
		else {
			cout << "\ndelete lovetoy. ";
			delete lovetoy;
			delete counter;	
		}
	cout<< "\ndelete ptr. " << "Counter after deleting an object " << *counter;
	}
};

class Dog {
	Toy toy;
	int age = 0;
	string name;
	shared_ptr_toy loveToy;
public:
	int getage() {
		return age;
	}
	string getname() {
		return name;
	}
	void copyLovelyToy(const Dog &oth) {
		loveToy = oth.loveToy;
		cout << "\nDog: " << getname() << " " << getage() << " " << toy.getName();
		cout << "\n counter " << toy.getName() << " after assignment constructer = " << loveToy.getCounter()<<"\n";
	}
	Dog(const string _name, const string toyName, int _age) : name(_name), loveToy(toyName){
		if (_age >= 0 && age < 30) { age = _age; };
		cout << "\nDog: " << getname() << " " << getage() << " " << toy.getName();
		cout << "\n counter " << toy.getName() << " after string name constructer = " << loveToy.getCounter();
	};
	Dog() : Dog("Druzhok", "Bone", 2) {};
	Dog(const string _name) : Dog(_name, "Bone", 2) {};
	Dog(const Dog& oth):loveToy(oth.loveToy) {
		name = oth.name;
		age = oth.age;
		cout << "\nDog: " << getname() << " " << getage() << " " << toy.getName();
		cout << "\n counter " << toy.getName() << " after copy constructer = " << loveToy.getCounter();
	}
	~Dog() {
		cout << "\ndelete dog "<<getname();
	}
};

Toy make_shared_toy(const string toyName) {
	Toy* toy = new Toy(toyName);
	return *toy;
}; 

int main()
{
	Dog e("Muha", "Stick", 3);
	Dog a(e);
	Dog d;
	Dog b(d);
	Dog q = e;
	Dog f("Belka");
	 f.copyLovelyToy(d);
	Dog g(e);
	e.copyLovelyToy(b);
	g.copyLovelyToy(b);
	return 0;
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
