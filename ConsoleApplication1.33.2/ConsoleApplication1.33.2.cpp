// ConsoleApplication1.33.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 31. Задача 2. Реализация класса графа.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Graph {
public:
    virtual void AddEdge(int from, int to) = 0; // Метод принимает вершины начала и конца ребра и добавляет ребро
    virtual int VerticesCount() const = 0; // Метод должен считать текущее количество вершин
    virtual void GetNextVertices(int vertex,vector<int>& vertices) const = 0; //  метод выводит  все вершины, в которые можно дойти по ребру из данной
    virtual void GetPrevVertices(int vertex, vector<int>& vertices) const = 0; //  метод выводит все вершины, из которых можно дойти по ребру в данную
    Graph(Graph* _oth) {};
    Graph() {};
    virtual ~Graph() {}
};

class ListGraph: public Graph {
public:
    virtual void AddEdge(int from, int to) {

    }
};

class MatrixGraph : public Graph {
public:
    virtual void AddEdge(int from, int to) {
    
    };
};

int main()
{
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
