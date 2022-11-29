// ConsoleApplication1.33.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

class Toy {
	string name;
	int counter = 0;
public:
	string getName() {
		return name;
	}
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

		counter--; cout << getCounter();
	}
	Toy(const string& _name) :name(_name) {
		cout << "\nToy";
	};
	Toy() :name("Bone") {};
};

Toy make_shared_toy(const string toyName);

class shared_ptr_toy {
	Toy* lovetoy;
public:
	shared_ptr_toy(const string toyName) {
		*lovetoy = make_shared_toy(toyName);
		lovetoy->addCounter();
		cout << "(" << lovetoy->getCounter() << ")";
	}
	shared_ptr_toy(const shared_ptr_toy& oth) {
		*lovetoy = *oth.lovetoy;
		oth.lovetoy->addCounter();
		cout << "(" << lovetoy->getCounter() << ")";
	}
	shared_ptr_toy& operator=(const shared_ptr_toy(&oth)) {
		if (this == &oth) {
			return*this;
		}
		if (lovetoy != nullptr) {
			lovetoy->reduceCounter();
			cout << "(" << lovetoy->getCounter() << "red" << ")";
			if (lovetoy->getCounter() == 0) {
				delete lovetoy;
			}
		}
		*lovetoy = *oth.lovetoy;
		oth.lovetoy->addCounter();
		cout << "(" << lovetoy->getCounter() << "add" << ")";
		return*this;
	}
	~shared_ptr_toy() {
		cout << "(" << lovetoy->getCounter() << "add" << ")";
		lovetoy->reduceCounter();
		if (lovetoy->getCounter() == 0) {
			cout << "\ndelete count. ";
			cout << "\ndelete lovelyToy. ";
			delete lovetoy;
		}
	}
};

class Dog {
	int age = 0;
	const string name, toyName;
	shared_ptr_toy loveToy;
public:
	void copyLovelyToy(const Dog& oth) {
		loveToy = oth.loveToy;
	}
	Dog(const string _name, const string toyName, int _age) : name(_name), loveToy(toyName) {
		if (_age >= 0 && age < 30) { age = _age; };

	};
	Dog() : Dog("Druzhok", "Bone", 2) {};
	Dog(const string _name) : Dog(_name, toyName, 2) {};
};

Toy make_shared_toy(const string toyName) {
	Toy* toy = new Toy(toyName);
	return *toy;
};

//void foo(const shared_ptr<Toy>& lhs, const shared_ptr<Counter>& rhs) {};

int main()
{
	Dog e("Muha", "Stick", 3);
	//Dog a(e);
	//Dog d;
	//Dog b(d);
	Dog f = e;
	//f.copyLovelyToy(d);
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
