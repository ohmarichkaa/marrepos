#include "Graph.h"

void Graph::MatrixAdjCreate(int temp)
{
    int value[3];
    int index = 0;
    int i = 0;
    for (int i = 0; i < R; i++)
    {
        cout << "Введите вершины и длину ребра между ними" << endl;
        for (int i = 0; i < 3; i++)
            cin >> value[i];
        index = 0;
        if (temp == 0)
        {
            matrix_adj[value[0]][value[1]] = value[2];
            matrix_adj[value[1]][value[0]] = value[2];
        }
        else
        {
            matrix_adj[value[0]][value[1]] = value[2];
        }
        i++;
    }
    cout << "Done\n";
 }

void Graph::MatrixAdjReadFile(string name, int temp)
{
    ifstream out;
    out.open(name, ios::in);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            out >> matrix_adj[i][j];
    out.close();
}

void Graph::MatrixInchiCreate(int temp)
{
    string s1;
    int value[3];
    int i = 0;
    for (int i = 0; i < R; i++)
    {
        cout << "Введите вершины и длину ребра между ними" << endl;
        for (int i = 0; i < 3; i++)
            cin >> value[i];

        if (temp == 0)
        {
            matrix_inchi[value[0]][i] = value[2];
            matrix_inchi[value[1]][i] = value[2];
        }
        else
        {
            matrix_inchi[value[0]][i] = -value[2];
            matrix_inchi[value[1]][i] = value[2];
        }
    }
}

void Graph::MatrixInchiReadFile(string name, int temp)
{
    ifstream out;
    int value[3];
    out.open(name, 'r');
    int i = 0;
    for (int i = 0; i < R; i++)
    {
        for (int i = 0; i < 3; i++)
            out >> value[i];

        if (temp == 0)
        {
            matrix_inchi[value[0]][i] = value[2];
            matrix_inchi[value[1]][i] = value[2];
        }
        else
        {
            matrix_inchi[value[0]][i] = -value[2];
            matrix_inchi[value[1]][i] = value[2];
        }
    }
    out.close();
}

void Graph::SpisokReberCreate(int temp)
{
    int value[3];
    for (int i = 0; i < R; i++)
    {
        cout << "Введите вершины и длину ребра между ними" << endl;
        for (int i = 0; i < 3; i++)
            cin >> value[i];

        if (temp == 0)
        {
            if (head == nullptr)
            {
                head = new SpisokReber;
                head->begin = value[0];
                head->end = value[1];
                head->weight = value[2];
                head->next = nullptr;
                SpisokReber* temp = new SpisokReber;
                temp->begin = value[1];
                temp->end = value[0];
                temp->weight = value[2];
                temp->next = nullptr;
                head->next = temp;
            }
            else
            {
                SpisokReber* current = head;
                while (current->next != nullptr)
                {
                    current = current->next;
                }
                SpisokReber* temp = new SpisokReber;
                temp->begin = value[0];
                temp->end = value[1];
                temp->weight = value[2];
                temp->next = nullptr;
                current->next = temp;
                SpisokReber* temp1 = new SpisokReber;
                temp1->begin = value[1];
                temp1->end = value[0];
                temp1->weight = value[2];
                temp1->next = nullptr;
                temp->next = temp1;
            }

        }
        else
        {
            if (head == nullptr)
            {
                head = new SpisokReber;
                head->begin = value[0];
                head->end = value[1];
                head->weight = value[2];
                head->next = nullptr;
            }
            else
            {
                SpisokReber* current = head;
                while (current->next != nullptr)
                {
                    current = current->next;
                }
                SpisokReber* temp = new SpisokReber;
                temp->begin = value[0];
                temp->end = value[1];
                temp->weight = value[2];
                temp->next = nullptr;
                current->next = temp;
            }
        }
    }
}

void Graph::SpisokReberReadFile(string name, int temp)
{
    ifstream out;
    out.open(name, 'r');
    int value[3];
    for (int i = 0; i < R; i++)
    {
        for (int i = 0; i < 3; i++)
            out >> value[i];

        if (temp == 0)
        {
            if (head == nullptr)
            {
                head = new SpisokReber;
                head->begin = value[0];
                head->end = value[1];
                head->weight = value[2];
                head->next = nullptr;
                SpisokReber* temp = new SpisokReber;
                temp->begin = value[1];
                temp->end = value[0];
                temp->weight = value[2];
                temp->next = nullptr;
                head->next = temp;
            }
            else
            {
                SpisokReber* current = head;
                while (current->next != nullptr)
                {
                    current = current->next;
                }
                SpisokReber* temp = new SpisokReber;
                temp->begin = value[0];
                temp->end = value[1];
                temp->weight = value[2];
                temp->next = nullptr;
                current->next = temp;
                SpisokReber* temp1 = new SpisokReber;
                temp1->begin = value[1];
                temp1->end = value[0];
                temp1->weight = value[2];
                temp1->next = nullptr;
                temp->next = temp1;
            }

        }
        else
        {
            if (head == nullptr)
            {
                head = new SpisokReber;
                head->begin = value[0];
                head->end = value[1];
                head->weight = value[2];
                head->next = nullptr;
            }
            else
            {
                SpisokReber* current = head;
                while (current->next != nullptr)
                {
                    current = current->next;
                }
                SpisokReber* temp = new SpisokReber;
                temp->begin = value[0];
                temp->end = value[1];
                temp->weight = value[2];
                temp->next = nullptr;
                current->next = temp;
            }
        }
    }
    out.close();
}

void Graph::SpisokSmejCreate(int temp)
{
    string s1;
    int value[3];
    for (int i = 0; i < R; i++)
    {
        cout << "Введите вершины и длину ребра между ними" << endl;
        for (int i = 0; i < 3; i++)
            cin >> value[i];

        if (temp == 0)
        {
            if (smej[value[0]] == nullptr)
            {
                SpisokSmej* temp = new SpisokSmej;
                temp->ver = value[1];
                temp->weight = value[2];
                temp->next = nullptr;
                smej[value[0]] = temp;
                if (smej[value[1]] == nullptr)
                {
                    SpisokSmej* temp1 = new SpisokSmej;
                    temp1->ver = value[0];
                    temp1->weight = value[2];
                    temp1->next = nullptr;
                    smej[value[1]] = temp1;
                }
                else
                {
                    SpisokSmej* val = smej[value[1]];
                    while (val->next != nullptr)
                    {
                        val = val->next;
                    }
                    SpisokSmej* temp2 = new SpisokSmej;
                    temp2->ver = value[0];
                    temp2->weight = value[2];
                    temp2->next = nullptr;
                    val->next = temp2;
                }
            }
            else
            {
                SpisokSmej* val = smej[value[0]];
                while (val->next != nullptr)
                {
                    val = val->next;
                }
                SpisokSmej* temp = new SpisokSmej;
                temp->ver = value[1];
                temp->weight = value[2];
                temp->next = nullptr;
                val->next = temp;
                if (smej[value[1]] == nullptr)
                {
                    SpisokSmej* temp1 = new SpisokSmej;
                    temp1->ver = value[0];
                    temp1->weight = value[2];
                    temp1->next = nullptr;
                    smej[value[1]] = temp1;
                }
                else
                {
                    SpisokSmej* val = smej[value[1]];
                    while (val->next != nullptr)
                    {
                        val = val->next;
                    }
                    SpisokSmej* temp2 = new SpisokSmej;
                    temp2->ver = value[0];
                    temp2->weight = value[2];
                    temp2->next = nullptr;
                    val->next = temp2;
                }
            }
        }
        else
        {
            if (smej[value[0]] == nullptr)
            {
                SpisokSmej* temp = new SpisokSmej;
                temp->ver = value[1];
                temp->weight = value[2];
                temp->next = nullptr;
                smej[value[0]] = temp;
            }
            else
            {
                SpisokSmej* val = smej[value[0]];
                while (val->next != nullptr)
                {
                    val = val->next;
                }
                SpisokSmej* temp = new SpisokSmej;
                temp->ver = value[1];
                temp->weight = value[2];
                temp->next = nullptr;
                val->next = temp;

            }
        }
    }
}

void Graph::SpisokSmejReadFile(string name, int temp)
{
    ifstream out(name, 'r');
    int value[3];
    int i = 0;
    for (int i = 0; i < R; i++)
    {
        for (int i = 0; i < 3; i++)
            out >> value[i];

        if (temp == 0)
        {
            if (smej[value[0]] == nullptr)
            {
                SpisokSmej* temp = new SpisokSmej;
                temp->ver = value[1];
                temp->weight = value[2];
                temp->next = nullptr;
                smej[value[0]] = temp;
                if (smej[value[1]] == nullptr)
                {
                    SpisokSmej* temp1 = new SpisokSmej;
                    temp1->ver = value[0];
                    temp1->weight = value[2];
                    temp1->next = nullptr;
                    smej[value[1]] = temp1;
                }
                else
                {
                    SpisokSmej* val = smej[value[1]];
                    while (val->next != nullptr)
                    {
                        val = val->next;
                    }
                    SpisokSmej* temp2 = new SpisokSmej;
                    temp2->ver = value[0];
                    temp2->weight = value[2];
                    temp2->next = nullptr;
                    val->next = temp2;
                }
            }
            else
            {
                SpisokSmej* val = smej[value[0]];
                while (val->next != nullptr)
                {
                    val = val->next;
                }
                SpisokSmej* temp = new SpisokSmej;
                temp->ver = value[1];
                temp->weight = value[2];
                temp->next = nullptr;
                val->next = temp;
                if (smej[value[1]] == nullptr)
                {
                    SpisokSmej* temp1 = new SpisokSmej;
                    temp1->ver = value[0];
                    temp1->weight = value[2];
                    temp1->next = nullptr;
                    smej[value[1]] = temp1;
                }
                else
                {
                    SpisokSmej* val = smej[value[1]];
                    while (val->next != nullptr)
                    {
                        val = val->next;
                    }
                    SpisokSmej* temp2 = new SpisokSmej;
                    temp2->ver = value[0];
                    temp2->weight = value[2];
                    temp2->next = nullptr;
                    val->next = temp2;
                }
            }
        }
        else
        {
            if (smej[value[0]] == nullptr)
            {
                SpisokSmej* temp = new SpisokSmej;
                temp->ver = value[1];
                temp->weight = value[2];
                temp->next = nullptr;
                smej[value[0]] = temp;
            }
            else
            {
                SpisokSmej* val = smej[value[0]];
                while (val->next != nullptr)
                {
                    val = val->next;
                }
                SpisokSmej* temp = new SpisokSmej;
                temp->ver = value[1];
                temp->weight = value[2];
                temp->next = nullptr;
                val->next = temp;

            }
        }
        i++;
    }
    out.close();
}

void Graph::PrintMatrixAdj()
{
    cout << endl << "Матрица смежности выглядит следующим образом >>" << endl;
    for (int i = 0; i < N; i++)
    {
        if (i == 0) cout << setw(4);
        for (int j = 0; j < N; j++)
        {
            cout << setw(4) << matrix_adj[i][j];
        }
        cout << endl;
    }
}
void Graph::PrintMatrixInchi()
{
    cout << endl << "Матрица инцидентности выглядит следующим образом >>" << endl;
    for (int i = 0; i < N; i++)
    {
        if (i == 0) cout << setw(4);
        for (int j = 0; j < R; j++)
        {
            cout << setw(4) << matrix_inchi[i][j];
        }
        cout << '\n';
    }
}
void Graph::PrintSpisokReber()
{
    cout << endl << "Список ребер выглядит следующим образом >>" << endl;
    SpisokReber* temp = head;
    while (temp != nullptr)
    {
        cout << "Начало: " << temp->begin << " Конец: " << temp->end << " Вес: " << temp->weight << endl;
        temp = temp->next;
    }
}
void Graph::PrintSpisokSmej()
{
    cout << endl << "Список смежности выглядит следующим образом >>" << endl;
    SpisokSmej* current = smej[0];
    for (int i = 0; i < N; i++)
    {
        cout << i << ":";
        while (current != nullptr)
        {
            cout << " --> " << "вершина: " << current->ver << " вес: " << current->weight;
            current = current->next;
        }
        cout << endl;
		current = smej[i];
    }
}

void Graph::writeFile(string name)
{
    ofstream out;
    out.open(name, 'w');
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            out << setw(4) << matrix_adj[i][j];
        }
        out << endl;
    }
    out << endl;
    out << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < R; j++)
        {
            out << setw(4) << matrix_inchi[i][j];
        }
        out << endl;
    }
    out << endl;
    out << endl;
    SpisokReber* temp = head;
    while (temp != nullptr)
    {
        out << temp->begin << '\t' << temp->end << '\t' << temp->weight << endl;
        temp = temp->next;
    }
    out << endl;
    out << endl;
    SpisokSmej* current;
    for (int i = 0; i < N; i++)
    {
        current = smej[i];
        while (current != nullptr)
        {
            out << current->ver << '\t' << current->weight << endl;
            current = current->next;
        }
    }
    out.close();
}

void Graph::MatrixAdjToMatrixInchi(int temp)
{
    int len = N;
    bool Prov[N][N];
    int sumvar = 0;
    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++) {
            Prov[i][j] = false;
            if (matrix_adj[i][j] != 0) sumvar++;
        }
    if (temp == 0)
        sumvar /= 2;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < R; j++)
        {
            matrix_inchi[i][j] = 0;
        }
    }
    int k = -1;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (matrix_adj[i][j] != 0) {
                if (temp != 0) {
                    k++;
                    matrix_inchi[i][k] = matrix_adj[i][j] * (-1);
                    matrix_inchi[j][k] = matrix_adj[i][j];
                }
                else if (Prov[i][j] == false) {
                    k++;
                    matrix_inchi[i][k] = matrix_inchi[j][k] = matrix_adj[i][j];
                    Prov[j][i] = true;
                }
            }
        }
    }
    cout << endl << "Результат выглядит следующим образом >>" << endl;
    for (int i = 0; i < N; i++)
    {
        if (i == 0) cout << setw(4);
        for (int j = 0; j < R; j++)
        {
            cout << matrix_inchi[i][j] << setw(4);
        }
        cout << endl;
    }
}

void Graph::MatrixInchiToSpisokReber(int temp)
{
    head = nullptr;
    int start = 0;
    int finish = 0;
    int ves = 0;
    for (int j = 0; j < R; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if (matrix_inchi[i][j] != 0)
            {
                if (start == 0)
                {
                    start = i; ves = matrix_inchi[i][j];
                }
                else
                {
                    finish = i;
                }
            }
        }
        if (temp == 0)
        {
            if (head == nullptr)
            {
                head = new SpisokReber; head->begin = start;
                head->end = finish; head->weight = ves;
                head->next = nullptr; SpisokReber* temp = new SpisokReber;
                temp->begin = finish; temp->end = start;
                temp->weight = ves; temp->next = nullptr;
                head->next = temp;
            }
            else
            {
                SpisokReber* current = head;
                while (current->next != nullptr)
                {
                    current = current->next;
                }
                SpisokReber* temp = new SpisokReber;
                temp->begin = start; temp->end = finish;
                temp->weight = ves; temp->next = nullptr;
                current->next = temp; SpisokReber* temp1 = new SpisokReber;
                temp1->begin = finish; temp1->end = start;
                temp1->weight = ves; temp1->next = nullptr;
                temp->next = temp1;
            }

        }
        else
        {
            if (ves < 0)
            {
                ves = ves * (-1);
            }
            else
            {
                swap(start, finish);
            }
            if (head == nullptr)
            {
                head = new SpisokReber; head->begin = start;
                head->end = finish; head->weight = ves;
                head->next = nullptr;
            }
            else
            {
                SpisokReber* current = head;
                while (current->next != nullptr)
                {
                    current = current->next;
                }
                SpisokReber* temp = new SpisokReber;
                temp->begin = start; temp->end = finish;
                temp->weight = ves; temp->next = nullptr;
                current->next = temp;
            }
        }
        start = 0;
        finish = 0;
        ves = 0;

    }
    cout << endl << "Результат выглядит следующим образом >>" << endl;
    SpisokReber* print = head;
    while (print != nullptr)
    {
        cout << "Начало: " << print->begin << " Конец: " << print->end << " Вес: " << print->weight << endl;
        print = print->next;
    }
}

void Graph::MatrixAdjToSpisokSmej()
{
    for (int i = 0; i < N; i++)
    {
        smej[i] = nullptr;
    }
    int start = 0; int finish = 0; int ves = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (matrix_adj[i][j] != 0)
            {
                start = i; finish = j; ves = matrix_adj[i][j];
                if (smej[start] == nullptr)
                {
                    SpisokSmej* temp = new SpisokSmej;
                    temp->ver = finish; temp->weight = ves;
                    temp->next = nullptr; smej[start] = temp;
                }
                else
                {
                    SpisokSmej* val = smej[start];
                    while (val->next != nullptr)
                    {
                        val = val->next;
                    }
                    SpisokSmej* temp = new SpisokSmej;
                    temp->ver = finish; temp->weight = ves;
                    temp->next = nullptr; val->next = temp;
                }
            }
        }
    }
    cout << endl << "Результат выглядит следующим образом >>" << endl;
    SpisokSmej* print = smej[0];
    for (int i = 0; i < N; i++)
    {
        cout << i << ":";
        while (print != nullptr)
        {
            cout << " --> " << "вершина: " << print->ver << " вес: " << print->weight;
            print = print->next;
        }
        cout << endl;
        if (i == 12) {
            break;
        }
        else {
            print = smej[i + 1];
        }
    }
}
void Graph::MatrixInchiToMatrixAdj(int temp)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            matrix_adj[i][j] = 0;
        }
    }
    int start = 0; int finish = 0; int ves = 0;
    for (int j = 0; j < R; j++)
    {
        for (int i = 0; i < N; i++)
        {
            if (matrix_inchi[i][j] != 0)
            {
                if (start == 0)
                {
                    start = i;
                    ves = matrix_inchi[i][j];
                }
                else
                {
                    finish = i;
                }
            }
        }
        if (temp == 0)
        {
            matrix_adj[start][finish] = ves;
            matrix_adj[finish][start] = ves;
        }
        else
        {
            if (ves < 0)
            {
                ves = ves * (-1);
            }
            else
            {
                swap(start, finish);
            }

            matrix_adj[start][finish] = ves;
        }
        start = 0; finish = 0; ves = 0;
    }
    cout << endl << "Результат выглядит следующим образом >>" << endl;
    for (int i = 0; i < N; i++)
    {
        if (i == 0) cout << setw(4);
        for (int j = 0; j < N; j++)
        {
            cout << matrix_adj[i][j] << setw(4);
        }
        cout << endl;
    }
}

void Graph::DFS(int n, bool visited[])
{
    visited[n] = true;
    cout << n << endl;
    SpisokSmej* temp = smej[n];
    while (temp != nullptr)
    {
        int node = temp->ver;
        if (visited[node] == false)
            DFS(node, visited);
        temp = temp->next;
    }
}

void Graph::BFS(int n, bool visited[])
{
    queue<int> q;
    q.push(n);
    visited[n] = true;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        cout << temp << endl;
        SpisokSmej* spis = smej[temp];
        while (spis != nullptr)
        {
            int node = spis->ver;
            if (visited[node] == false)
            {
                visited[node] = true;
                q.push(node);
            }
            spis = spis->next;
        }
    }
}
