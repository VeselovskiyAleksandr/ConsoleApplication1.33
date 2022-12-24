// ConsoleApplication1.33.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 31. Задача 2. Реализация класса графа.

#include <iostream>
#include <string>
#include <vector>
#include <clocale>
using namespace std;

class Graph {   
protected:
 int verticesNumber;
 vector<vector<int>>matrixList;
public:
    vector<int> vertices;
    virtual void setVector(vector<vector<int>>& matrixList, int _verticesNumber) = 0;
    virtual  vector<vector<int>>& getMatrixList() = 0;
   virtual void AddEdge( vector<vector<int>>& matrixList)=0; // Метод принимает вершины начала и конца ребра и добавляет ребро
    virtual int VerticesCount()=0; // Метод должен считать текущее количество вершин
    virtual void GetNextVertices(int vertex, vector<int>& vertices) =0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, в которые можно дойти по ребру из данной
    virtual void GetPrevVertices(int vertex, vector<int>& vertices) const=0; // Для конкретной вершины метод выводит в вектор “вершины” все вершины, из которых можно дойти по ребру в данную
    Graph() {};
   Graph(Graph& _oth) {};
    Graph(int _verticesNumber): verticesNumber(_verticesNumber) {};
    virtual ~Graph() {}
};

class ListGraph:  public Graph {
   vector<vector<int>>adjList;
public:
    virtual void AddEdge(int from, int to) {
        vector<vector<int>>adjList;
    }
};

class MatrixGraph :  public Graph {
protected:
  int verticesNumber;
    vector<vector<int>>matrixList;
public: 
    vector<int> nextVertices;
    vector<int> prevVertices;
    void setVector(vector<vector<int>>& matrixList, int _verticesNumber) {
         matrixList.resize(_verticesNumber);
        for (int i = 0; i < matrixList.size(); i++) {
            matrixList[i].resize(_verticesNumber);
            for (int j = 0; j < matrixList[i].size(); ++j) {
                matrixList[i][j] = 0;
            }
        }
 }
    vector<vector<int>>& getMatrixList() {
        return matrixList;
    }

    void AddEdge(vector<vector<int>>& matrixList) {
        int from=0, to = 0;
           cout << "\nВведите точки начала и конца ребра. Для завершения ввода введите любое отрицательное число.";
           do {
               cout << "\n";
               for (int i = 0; i < matrixList.size(); i++) {
                   for (int j = 0; j < matrixList[i].size(); ++j) {
                       cout  << matrixList[i][j] << " ";
                   }
                   cout << "\n";
               }
               cin >> from;
               if (from >= 0) {
                   cin >> to;
               }
               if (from >= 0 && to >= 0) {
                   matrixList[from][to] = 1;
               }
       } while (from >= 0 && to >= 0);
    }
    int VerticesCount(){
        int verticesNumber = 0;
        for (int i = 0; i < getMatrixList().size(); ++i) {
            for (int j = 0; j < getMatrixList()[i].size(); ++j) {
                if (getMatrixList()[i][j] == 1) {
                    verticesNumber++;
                }
            }
        }
        return verticesNumber;
   }
   void GetNextVertices(int vertex, vector<int>& vertices)  {
       int j = 0;
       do {
           
           for (int i = 0; i < getMatrixList().size(); i++) {
               if ((matrixList[vertex][i] == 1)){
                   nextVertices.push_back(i);
                   }
           }
           if (j < nextVertices.size()) {
               vertex = nextVertices[j];
           }
        ++j;
       } while (j-1< nextVertices.size());
       cout << "\n По ребру из данной можно пройти в следующие вершины: ";
       for (int i = 0; i < nextVertices.size(); ++i) {
           cout << nextVertices[i] << " ";
       }
   }
   void GetPrevVertices(int vertex, vector<int>& prevVertices) const {
       int j = 0;
       do {
           for (int i = 0; i < matrixList.size(); i != vertex, i++) {
               if ((matrixList[i][vertex] == 1) && (i != vertex)) {
                   prevVertices.push_back(i);
               }
           }
           if (j < prevVertices.size()) {
               vertex = prevVertices[j];
           }
           ++j;
       } while (j - 1 < prevVertices.size());
       cout << "\n По ребру в данную можно пройти из следующих вершин: ";
       for (int i = 0; i < prevVertices.size(); ++i) {
           cout << prevVertices[i] << " ";
       }
   }
   MatrixGraph(int _verticesNumber): verticesNumber(_verticesNumber){
       setVector(matrixList, _verticesNumber);
      AddEdge( matrixList);
    };
  
    MatrixGraph(MatrixGraph& oth) {
        verticesNumber = oth.verticesNumber;
      matrixList=oth.getMatrixList();
       nextVertices=oth.nextVertices;
      prevVertices=oth.prevVertices;
    };
~MatrixGraph() {
           matrixList.clear();
    }
};

    int main(){
        setlocale(LC_ALL, "rus");
    int verticesNum = 0, nextVertex=0, prevVertex=0;
    cout << "\n Укажите количество вершин графа";
    cin >> verticesNum;
     MatrixGraph a(verticesNum);
     MatrixGraph b(a);
   cout << "\n В графе связанных пар вершин - " << a.VerticesCount();
   cout << "\n Укажите вершину для начала обхода.";
   cin >> nextVertex;
   b.GetNextVertices(nextVertex, a.nextVertices);
   cout << "\n Укажите вершину конца обхода.";
   cin >> prevVertex;
   b.GetPrevVertices(prevVertex, a.prevVertices);
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
