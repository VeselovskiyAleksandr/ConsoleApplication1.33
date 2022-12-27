// ConsoleApplication1.33.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 31 Пример реализации "умного" указателя.


#include <iostream>
//#include <string>
using namespace std;
//#define MY_SHARED_PTR_REALIZATION

class Toy
{
    std::string name;
public:
    Toy(std::string name) : name(name) {

    };
    Toy() : Toy("SomeToy") {

    };
    const std::string get_name()
    {
        return name;
    }

    ~Toy() {
        std::cout << "D-tor Toy" << std::endl;
    }
};

class shared_ptr_Toy
{
    Toy* obj;
    int* counter;
public:
    shared_ptr_Toy() /* I default. C-tor */
    {
        std::cout << "shared_ptr_Toy::shared_ptr_Toy default C-tor" << std::endl;
        obj = new Toy("SomeToy");
        counter = new int(1);
    }

    shared_ptr_Toy(std::string name)
    {
        std::cout << "shared_ptr_Toy::shared_ptr_Toy string C-tor" << std::endl;
        obj = new Toy(name);
        counter = new int(1);
    }

    shared_ptr_Toy(Toy* toy)
    {
        std::cout << "shared_ptr_Toy::shared_ptr_Toy Toy C-tor" << std::endl;
        obj = toy;
        counter = new int(1);
    }

    shared_ptr_Toy(const shared_ptr_Toy& oth) /* II. Copy C-tor */
    {
        std::cout << "shared_ptr_Toy::shared_ptr_Toy Copy C-tor" << std::endl;
        obj = oth.obj;
        counter = oth.counter;
        ++* counter;
    }

    shared_ptr_Toy& operator=(const shared_ptr_Toy& oth) { /* III. Copy assignment */
        std::cout << "shared_ptr_Toy::operator= Copy assignment C-tor" << std::endl;
        /* TODO Сделать копирующий конструктор */
    }

    int use_count() {
        return *counter;
    }

    ~shared_ptr_Toy()
    {
        std::cout << "~shared_ptr_Toy D-tor" << std::endl;
        /* TODO Сделать деструктор */
    }
};

shared_ptr_Toy make_shared_toy(std::string name)
{
    shared_ptr_Toy spt(name);
    return spt;
}



int main() {
#ifdef MY_SHARED_PTR_REALIZATION
    shared_ptr_Toy ptr = make_shared_toy("Ball");
    std::cout << "Counter after make_shared = " << ptr.use_count() << std::endl;
    shared_ptr_Toy ptr2(ptr);
    std::cout << "Counter after copy C-tor = " << ptr.use_count() << std::endl;
    shared_ptr_Toy ptr3;
    ptr3 = ptr2;
    std::cout << "Counter after assignment = " << ptr.use_count() << std::endl;
#else
    std::shared_ptr<Toy> ptr = std::make_shared<Toy>("Ball");
    std::cout << "Counter after make_shared = " << ptr.use_count() << std::endl;
    std::shared_ptr<Toy> ptr2(ptr);
    std::cout << "Counter after copy C-tor = " << ptr.use_count() << std::endl;
    std::shared_ptr<Toy> ptr3;
    ptr3 = ptr2;
    std::cout << "Counter after assignment = " << ptr.use_count() << std::endl;
#endif
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
