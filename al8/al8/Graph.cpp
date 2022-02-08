#include "Graph.h"
    
void Dijkstra(int GR[SIZE][SIZE])
{
    for (int st = 0; st < SIZE; st++)
    {
        int distance[SIZE], count, index, i, u, m = st + 1;
        bool visited[SIZE];
        for (i = 0; i < SIZE; i++)
        {
            distance[i] = INT_MAX; visited[i] = false;
        }
        distance[st] = 0;
        for (count = 0; count < SIZE - 1; count++)
        {
            int min = INT_MAX;
            for (i = 0; i < SIZE; i++)
                if (!visited[i] && distance[i] <= min)
                {
                    min = distance[i]; index = i;
                }
            u = index;
            visited[u] = true;
            for (i = 0; i < SIZE; i++)
                if (!visited[i] && GR[u][i] && distance[u] != INT_MAX &&
                    distance[u] + GR[u][i] < distance[i])
                    distance[i] = distance[u] + GR[u][i];
        }
        for (i = 0; i < SIZE; i++)
        {
            if (distance[i] != INT_MAX)
                cout << distance[i] << "\t";   
            else cout << "0" << "\t";
        }
        cout << endl;
    }
}

void FU(int GR[SIZE][SIZE])
{
    int D[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++)
         for (int j = 0; j < SIZE; j++)
            D[i][j] = GR[i][j];
     
    int k;
    for (int i = 0; i < SIZE; i++) D[i][i] = 0;

    for (k = 0; k < SIZE; k++)
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
                if (D[i][k] && D[k][j] && i != j)
                    if (D[i][k] + D[k][j] < D[i][j] || D[i][j] == 0)
                        D[i][j] = D[i][k] + D[k][j];



    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++) 
            cout << D[i][j] << "\t";
        cout << endl;
    }
}

void Dijkstra_v(int GR[SIZE][SIZE], int st)
{
    int distance[SIZE], count, index, i, u, m = st;
    bool visited[SIZE];
    for (i = 0; i < SIZE; i++)
    {
        distance[i] = INT_MAX; visited[i] = false;
    }
    distance[st] = 0;
    for (count = 0; count < SIZE - 1; count++)
    {
        int min = INT_MAX;
        for (i = 0; i < SIZE; i++)
            if (!visited[i] && distance[i] <= min)
            {
                min = distance[i]; index = i;
            }
        u = index;
        visited[u] = true;
        for (i = 0; i < SIZE; i++)
            if (!visited[i] && GR[u][i] && distance[u] != INT_MAX &&
                distance[u] + GR[u][i] < distance[i])
                distance[i] = distance[u] + GR[u][i];
    }
    cout << "Стоимость пути из начальной вершины до остальных:\t\n";
    for (i = 0; i < SIZE; i++) if (distance[i] != INT_MAX)
        cout << m << " > " << i << " = " << distance[i] << endl;
    else cout << m << " > " << i<< " = " << "Маршрут недоступен" << endl;
}