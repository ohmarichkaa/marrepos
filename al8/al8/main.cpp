#include "Graph.h"
#include "Functions.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
    
    int start;
    int graph[SIZE][SIZE]
 = {        
0,2,5,0,0,10,0,0,0,0,0,0,0,0,
0,0,0,5,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,7,0,0,0,0,0,0,0,0,0,
0,0,0,0,12,0,0,0,12,0,0,0,0,0,
0,0,0,0,0,0,8,5,0,0,0,0,0,0,
0,0,0,0,6,0,0,0,0,0,11,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,12,
0,0,0,0,0,4,2,0,0,9,0,0,0,7,
0,0,0,0,0,0,0,0,0,0,0,0,0,9,
0,0,0,0,0,0,0,0,0,0,0,0,2,0,
0,0,0,0,0,0,0,0,0,0,0,6,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0
    };

    while (true)
    {
        int n;
        int start;

        cout << "1. ����������� �������"<< endl;
       
        cout << "2. �������� ��������" << endl;
        cout << "3. �������� ������" << endl;
        cout << "4. �������� ������� � ����"<< endl;
        cout << "5. ������� ������� �� �����"<< endl;
        cout << "6. ������ ����� ��������" << endl;
        cout << "0. �����"<< endl;
        cin >> n;

        if (n == 1)
        {
            cout << "������� ���������" << endl;
            PrintMatrix(graph, SIZE, SIZE);
        }
        else if (n == 2)
        {
            cout << "������� ���������� ����� ��������" << endl;
            Dijkstra(graph);
        }
        else if (n == 3)
        {
            cout << "������� ���������� ����� ������" << endl;
            FU(graph);
        }
        else if (n == 4)
        {
            FwriteMatrix("Data.txt", graph, SIZE, SIZE);
            cout << "��������" << endl;
        }
        else if (n == 5)
        {
            FreadMatrix("Data.txt", graph, SIZE, SIZE);
            cout << "�������" << endl;
        }
        else if (n == 6)
        {
            cout << "��������� ������� >> "; 
            cin >> start;
            Dijkstra_v(graph, start);
        }
        else if (n == 0)
        {
            exit(0);
        }
        else
            cout << "��� ������ ������ ����" << endl;
    }

}