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
	Toy(const string& _name) :name(_name) {
		cout << "\nToy: " << getName();
	};
	Toy() :name("Bone") {};
};

Toy make_shared_toy(const string toyName);

class shared_ptr_toy {
	Toy* lovetoy;
	int counter = 0;
public:
	int getCounter() {
		return counter;
	}
	void addCounter() {
		counter++;
	}
	void reduceCounter() {
		counter--;
	}
	shared_ptr_toy(const string toyName) {
		make_shared_toy(toyName);
		addCounter();
	}
	shared_ptr_toy(const shared_ptr_toy& oth) {
		*lovetoy = *oth.lovetoy;
		counter = oth.counter;
		addCounter();
	}
	shared_ptr_toy& operator=(const shared_ptr_toy(&oth)) {
		if (this == &oth) {
			return*this;
		}
		if (lovetoy != nullptr) {
			reduceCounter();
			if (getCounter() == 0) {
				cout << "\ndelete lovelyToy. ";
				delete lovetoy;
			}
		}
		addCounter();
		return*this;
	}
	~shared_ptr_toy() {
		reduceCounter();
		if (getCounter() == 0) {
			cout << "\ndelete lovetoy. ";
			delete lovetoy;
		}
		cout << "\ndelete ptr. ";
	}
};

class Dog {
	int age = 0;
	string name, toyName;
	shared_ptr_toy loveToy;
public:
	int getage() {
		return age;
	}
	string getname() {
		return name;
	}
	string getToyName() {
		return toyName;
	}
	void copyLovelyToy(const Dog& oth) {
		name = oth.name;
		age = oth.age;
		loveToy = oth.loveToy;
		toyName = oth.toyName;
		cout << " " << getToyName();
	}
	Dog(const string _name, const string toyName, int _age) : name(_name), loveToy(toyName) {
		if (_age >= 0 && age < 30) { age = _age; };
		cout << "\n" << getname() << " " << getage() << " " << toyName;
	};
	Dog() : Dog("Druzhok", "Bone", 2) {};
	Dog(const string _name) : Dog(_name, "Bone", 2) {};
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
	f.copyLovelyToy(e);
	Dog g(e);
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
