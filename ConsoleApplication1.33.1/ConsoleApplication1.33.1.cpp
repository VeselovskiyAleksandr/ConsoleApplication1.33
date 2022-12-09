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
		cout << "\nToy: " << name;
	};
	Toy() :name("Bone") {
		cout << "\nToy: ";
	};
	~Toy() {
		cout << "\ndelete toy: " << getName();
	}
};

Toy make_shared_toy(const string toyName);

class shared_ptr_toy {
	Toy* lovetoy;
	int* counter;
public:
	Toy* getToy() {
		return lovetoy;
	}
	shared_ptr_toy(Toy* toy) {
		lovetoy = toy;
			counter = new int(1);
		cout << "\n shared_ptr_Toy Toy constructor. Toy: " << lovetoy->getName() << ", counter: " << getCounter();
	}
	shared_ptr_toy(string toyName) {
			lovetoy = new Toy(toyName);
			counter = new int(1);
		cout << "\n shared_ptr_Toy string constructor. Toy: " << lovetoy->getName() << ", counter: " << getCounter();
	}
	shared_ptr_toy(const shared_ptr_toy& oth) {
		lovetoy = oth.lovetoy;
		counter = oth.counter;
		++* counter;
		cout << "\n shared_ptr_Toy copy constructor. Toy: " << lovetoy->getName() << ", counter: " << getCounter();// ;
	}
	shared_ptr_toy& operator=(const shared_ptr_toy(&oth)) {
		if (this == &oth) {
			return*this;
		}
			--* counter;
		if (*counter == 0) {
			cout << "\n delete lovelyToy " << lovetoy->getName() << ", delete counter"; 
			delete lovetoy;
			delete counter;
		}
		lovetoy = oth.lovetoy;
		counter = oth.counter;
		++* counter;
		cout << "\n Copy assignment constructor. Toy: " << lovetoy->getName() << ", counter: " << getCounter();
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
			delete counter;
			cout << "\ndelete counter ";
		}
		cout << "\ndelete ptr " << lovetoy->getName() << ", counter after deleting an object " << getCounter();
	}
};

Toy make_shared_toy(string toyName) {
	Toy toy(toyName);
	return toy;
};

class Dog {
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
	void copyLovelyToy(const Dog& oth) {
		loveToy = oth.loveToy;
		cout << "\nDog: " << getname() << " " << getage() << " " << loveToy.getToy()->getName();
		cout << "\n counter " << " after assignment constructer = " << loveToy.getCounter() << "\n";
	}
	Dog(const string _name, const string toyName, int _age) : name(_name), loveToy(toyName) {
		if (_age >= 0 && age < 30) { age = _age; };
		cout << "\nDog: " << getname() << " " << getage() << " " << loveToy.getToy()->getName();
		cout << "\n counter " << " after string name constructer = " << loveToy.getCounter();
	};
	Dog(string _name, Toy* toy, int _age) :loveToy(toy), name(_name) {
		if (_age >= 0 && age < 30) { age = _age; };
		cout << "\nDog: " << getname() << " " << getage() << " " << loveToy.getToy()->getName();
		cout << "\n counter " << " after string name constructer = " << loveToy.getCounter();
	};
	Dog(string _name, shared_ptr_toy _loveToy, int _age) :loveToy(_loveToy), name(_name) {
		if (_age >= 0 && age < 30) { age = _age; };
		cout << "\nDog: " << getname() << " " << getage() << " " << loveToy.getToy()->getName();
		cout << "\n counter " << " after string name constructer = " << loveToy.getCounter();
	};
	Dog() : Dog("Druzhok", "Bone", 2) {};
	Dog(const string _name) : Dog(_name, "Bone", 2) {};
	Dog(const Dog& oth):loveToy(oth.loveToy) {
		name = oth.name;
		age = oth.age;
		cout << "\nDog: " << getname() << " " << getage() << " " << loveToy.getToy()->getName();
		cout << "\n counter " << " after copy constructer = " << loveToy.getCounter();
	}
	~Dog() {
		cout << "\n delete dog " << getname();
	}
};


int main()
{
	Toy Ball = make_shared_toy("Ball");
	shared_ptr_toy spt0(&Ball);
	cout << "\n Counter after Toy constructor = " << spt0.getCounter();
	shared_ptr_toy spt1("Stick");
	cout << "\n Counter after string constructor = " << spt1.getCounter();
	shared_ptr_toy spt2("Bone");
	cout << "\n Counter after string constructor = " << spt2.getCounter();
	shared_ptr_toy spt3(spt2);
	cout << "\n Counter after copy constructor = " << spt3.getCounter();
	shared_ptr_toy spt4(spt0);
	cout << "\n Counter after Toy constructor = " << spt4.getCounter();
	Dog Muha("Muha", "Stick", 3);
	Dog Muha1(Muha);
	Dog Druzhok;
	Dog Belka("Belka");
	Belka.copyLovelyToy(Druzhok);  //Теперь у Белки и Дружка одна общая игрушка bone.
	Belka.copyLovelyToy(Muha);
	Dog Sharik("Sharik", &Ball, 4);
	Dog Pushok("Pushok", spt0, 3);
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
