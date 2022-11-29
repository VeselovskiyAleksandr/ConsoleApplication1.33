// ConsoleApplication1.33.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 31.Задача 1. Реализация "умного" указателя.

#include <iostream>
#include <string>
///* #define THROW */
///* #define MAKE_SHARED */
using namespace std;


class Toy {
	const string name;
public:
	string getName() {
		return name;
	}
	Toy(const string&_name):name(_name) {
		cout << "\nToy";
	};
	Toy() :name("Bone") {};
};

class Counter {
	int counter=0;
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
	
		counter--; cout << getCounter();
	}
	Counter() {
		cout << "\nCounter";
	};
};


pair<Toy, Counter> make_shared_toy(const string toyName) {
	Toy* lovetoy;
	Counter* count;
	lovetoy = new Toy(toyName);
	 count = new Counter();
	return make_pair(* lovetoy, * count);
}


class shared_ptr_toy {
	Toy *lovetoy;
	Counter* count;
	shared_ptr_toy *pointer;
public:
	shared_ptr_toy(string toyName) {
	//	cout << "(" << count->getCounter() << ")";
		pair<Toy, Counter> pointer=make_shared_toy(toyName);
		//*lovetoy = pointer.first;
		*count = pointer.second;

		count->addCounter();
		cout <<"("<< count->getCounter()<<")";
	}
	shared_ptr_toy(const shared_ptr_toy& oth) {
		pointer = new shared_ptr_toy(*oth.pointer);
		//*lovetoy =* oth.lovetoy;
		*count = *oth.count;
		oth.count->addCounter();
		cout << "(" << count->getCounter() << ")";
	}
	shared_ptr_toy& operator=(const shared_ptr_toy(& oth)) {
		if (this == &oth) {
			return*this;
		}
		if (lovetoy != nullptr) {
			count->reduceCounter();
			cout << "(" << count-> getCounter()<<"red"<< ")";
			if (count->getCounter() == 0) {
				delete count;
			}
			delete lovetoy;
		}
		//obj = new Toy(*oth.obj);
		 pointer = new shared_ptr_toy(*oth.pointer);
		 //*lovetoy = *oth.lovetoy;
		*count = *oth.count;
		oth.count->addCounter();
		cout << "(" << count->getCounter()<<"add" << ")";
		return*this;
	}
	~shared_ptr_toy() {
		cout << "(" << count->getCounter() << "add" << ")";
		count->reduceCounter();
     if (count->getCounter() == 0) {
		 cout << "\ndelete count. ";
			 delete count;
		}
		cout << "\ndelete lovelyToy. ";
		delete lovetoy;
	}
};


	//   void  make_shared_toy(Toy &otherToy) {
	//	   Toy* toy;
	//	   toy = new Toy(otherToy.getName());
	 //  }


class Dog {
        int age;
		string name, toyName;
       shared_ptr_toy *loveToy;
public:
	void copyLovelyToy(const Dog& oth) {
		loveToy = oth.loveToy;
	}
	Dog(string _name, string toyName, int _age) : name(_name) {
		if (_age >= 0 && age < 30) { age = _age; };
		//shared_ptr_toy*loveToy = new shared_ptr_toy(toyName);
	};
	Dog() : Dog ("Druzhok",toyName, 2) {};
	Dog(string _name) : Dog ( _name, toyName, 2) {};
};

class Right {
public:
	Right(const std::string& str) {
		std::cout << "C-tor Right:" << str << " \n";
	}
	~Right() {
		std::cout << "D-tor Right\n";
	}
};

class Left {
public:
	Left(const std::string& str) {
#ifdef THROW
		throw str;
#endif
		std::cout << "C-tor Left:" << str << " \n";
	}
	~Left() {
		std::cout << "D-tor Left\n";
	}
};

void foo(const std::shared_ptr<Left>& lhs, const std::shared_ptr<Right>& rhs) {

}

int main()
{
	Toy* lovelytoy;
	Counter* count;
//	make_shared_toy("Stick");
	//Counter* count=nullptr;
//shared_ptr_toy point (Toy*lovelytoy, Counter *count, string toyname);
	//pair<Toy, Counter> pointer =make_shared_toy("Stick");
	//Toy lovelytoy= pointer.first;
	//Counter count = pointer.second;
	//cout << lovelytoy->getName();
	//shared_ptr_toy ("Stick" );
	//make_shared_toy("Bone");
	//shared_ptr_toy *bone;
	try {
#ifdef MAKE_SHARED
		foo(std::make_shared<Left>("foo"), std::make_shared<Right>("bar"));
#else
		foo(std::shared_ptr<Left>(new Left("foo")), std::shared_ptr<Right>(new Right("bar")));
#endif
	}
	catch (...) {
		int i;
		std::cin >> i;
	}

	Dog e("Muha","Stick", 3);

	Dog a(e);
	//Dog d;
	//Dog b(d);
    Dog f = e;
//f.copyLovelyToy(d);
	Dog g(e);
	return 0;
}





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
	//	
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
