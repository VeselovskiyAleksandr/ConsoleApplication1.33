// ConsoleApplication1.33.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
using namespace std;

class Toy
{
    string name;
public:
    Toy(string name) : name(name) {
    };
    Toy() : Toy("Bone") {
    };
    const string get_name() {
        return name;
    }
    ~Toy() {
        cout << "\n1111111 Delete toy";
    }
};

class shared_ptr_Toy {
    Toy* loveleToy;
    int* counter;
public:
    shared_ptr_Toy(){ /* I default. C-tor */
    //   cout << "\n shared_ptr_Toy default constructor";
       loveleToy = new Toy("Bone");
        counter = new int(1);
    }

    shared_ptr_Toy(string name) {
    //    cout << "\n shared_ptr_Toy string constructor";
        loveleToy = new Toy(name);
        counter = new int(1);
    }

  //  shared_ptr_Toy(Toy* toy) {
     //  cout << "\n shared_ptr_Toy Toy constructor";
  //     loveleToy = toy;
 //       counter = new int(1);
 //   }

    shared_ptr_Toy(const shared_ptr_Toy& oth) { /* II. Copy C-tor */
     //   cout << "\n shared_ptr_Toy copy constructor";
        loveleToy = oth.loveleToy;
        counter = oth.counter;
        ++* counter;
    }

    shared_ptr_Toy& operator=(const shared_ptr_Toy& oth) { /* III. Copy assignment */
      //  cout << "\n Copy assignment constructor";
        /* TODO Сделать копирующий конструктор */
        if (this == &oth) {
            return*this;
        }
   //     if (loveleToy != nullptr) {
           --*counter;
 
        //    if (*counter == 0) {
         //       delete counter;
         //       delete loveleToy;
         //   }
     //   }
        loveleToy = oth.loveleToy;
        counter = oth.counter;
        return*this;
    }

    int Counter() {
        return *counter;
    }

    ~shared_ptr_Toy(){
    //    cout << "\n ~shared_ptr_Toy D-tor";
        /* TODO Сделать деструктор */
        --* counter;
        if (*counter == 0) {
            delete counter;
            delete loveleToy;

            cout << "\ndelete ptr. ";
        }
    }
};

shared_ptr_Toy make_shared_toy(string name){
    shared_ptr_Toy spt(name);
    return spt;
}

class Dog {
    Toy lovelytoy;
    int age = 0;
    string name;
    shared_ptr_Toy loveToy;
public:
    int getage() {
        return age;
    }
    string getname() {
        return name;
    }
  //  string getToyName() {
 //       return toyName;
 //   }
    void copyLovelyToy(const Dog& oth) {
        //	loveToy.reduceCounter();
   //    --* lovetoy.counter;///////////////////		
   //     lovelytoy = oth.lovelytoy;
     //   loveToy = oth.loveToy;
        //	loveToy.addCounter();
     //   ++* loveToy.counter;/////////////////
    //	cout << "\n" << getname() << " " << getage() << " " << getToyName() << " " << " counter= " << loveToy.getCounter();
        cout << "\n" << getname() << " " << getage() << " " << lovelytoy.get_name() << " " << " counter= " << loveToy.Counter();///////////
    }
    Dog(const string _name, shared_ptr_Toy toy, int _age) : name(_name) {
        if (_age >= 0 && age < 30) { age = _age; };
        //		cout << "\n" << getname() << " " << getage() << " " << toyName << " " << " counter= " << loveToy.getCounter();
        cout << "\n" << getname() << " " << getage() << " " << lovelytoy.get_name() << " " << " counter= " << loveToy.Counter();///////////
    };
    Dog() : Dog("Druzhok", make_shared_toy("bone"), 2) {};
    Dog(const string _name) : Dog(_name, make_shared_toy("Bone"), 2) {};
    Dog(const Dog& oth): loveToy(oth.loveToy) {
        name = oth.name;
        age = oth.age;
        lovelytoy = oth.lovelytoy;
        //	cout << "\n" << getname() << " " << getage() << " " << toyName << " " << " counter= " << loveToy.getCounter();
        cout << "\n" << getname() << " " << getage() << " " << lovelytoy.get_name() << " " << " counter= " << loveToy.Counter();///////////
    }
};


int main()
{
  //  shared_ptr_Toy ball_1 = make_shared_toy("Ball");
 //   shared_ptr_Toy Stick = make_shared_toy("Stick");
 //   shared_ptr_Toy bone = make_shared_toy("bone");
 //   cout << "\n Counter after make_shared = " << ball_1.Counter();
   // shared_ptr_Toy ball_2(ball_1);
   // cout << "\n Counter after copy constructor = " << ball_1.Counter();
   // shared_ptr_Toy ball_3;
  //  ball_3 = ball_2;
 // cout << "\n Counter after assignment = " << ball_1.Counter();
 //   Dog e("Muha", Stick, 3);
//    Dog a(e);
   Dog d;
 //   Dog b(d);
 //   Dog q = e;
 //   Dog f("Belka");
 //   f.copyLovelyToy(e);
 //   Dog g(e);
  //  e.copyLovelyToy(b);
 //   g.copyLovelyToy(b);
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
