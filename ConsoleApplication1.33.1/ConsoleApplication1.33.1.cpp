// ConsoleApplication1.33.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 31.Задача 1. Реализация "умного" указателя.

#include <iostream>
#include <string>
using namespace std;


class Toy {
	string name;
public:
	Toy(string _name):name(_name) {};
	Toy() :name("Bone") {};
};

class Counter {
	int counter;
public:
	void setCounter(int _counter) {
		counter = _counter;
	}
	int getCounter() {
		return counter;
	}
	void addCounter() {
		counter++;
	}
	void reduceCounter() {
		counter--;
	}
};

class shared_ptr_toy {
	Toy* obj;
	Counter *count;
public:
	shared_ptr_toy() {
		obj = new Toy();
		count = new Counter();
		count->setCounter(1);
	}
	shared_ptr_toy(string name) {
		obj = new Toy(name);
		count = new Counter();
		count->setCounter(1);
	}
	shared_ptr_toy(const shared_ptr_toy& oth) {
		obj = new Toy(*oth.obj);
		count = oth.count;
		oth.count->addCounter();
		cout << "(" << count->getCounter() << ")";
	}
	shared_ptr_toy& operator=(const shared_ptr_toy(& oth)) {
		if (this == &oth) {
			return*this;
		}
		if (obj != nullptr) {
			count->reduceCounter();
			cout << "(" << count-> getCounter() << ")";
			if (count->getCounter() == 0) {
				delete count;
			}
			delete obj;
		}
		obj = new Toy(*oth.obj);
		count = oth.count;
		oth.count->addCounter();
		cout << "(" << count->getCounter() << ")";
		return*this;
	}
	~shared_ptr_toy() {
		count->reduceCounter();
     if (count->getCounter() == 0) {
		 cout << "\ndelete count. ";
			 delete count;
		}
		cout << "\ndelete lovelyToy. ";
		delete obj;
	}
};

//void make_shared_toy(string toyName, shared_ptr_toy *lovelyToy) {
	//*lovelyToy = toyName;
//}

class Dog {
        int age;
		string name, toyName;
       shared_ptr_toy lovelyToy;
public:
	Dog(string _name, string _toyName, int _age) : name(_name), toyName(_toyName), lovelyToy(toyName){
		if (_age >= 0 && age < 30) { age = _age; };
	};
	Dog() : Dog("Druzhok", "Bone", 2) {};
	Dog(string _name) : Dog(_name, "Bone", 2) {};
};

int main()
{
	Dog e("Muha", "stick", 3);
	Dog a(e);
	Dog d;
	Dog b(d);
	Dog f = e;
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
