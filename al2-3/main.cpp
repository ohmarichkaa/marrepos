#include <iostream>
#include <cstdio>
using namespace std;


struct node
{
    short int data;
    node *next;
    node* prev;
};

struct decque
{
    node *first;
    node *last;

    decque():first(NULL), last(NULL) {}


    void start_add(short int n)
    {
        node *tmp = new node;
        tmp->data = n;

        if(first == NULL)
        {
            first = tmp;
            last = tmp;
        }
        else
        {
            last->next = tmp;
            tmp->prev = last;
            last = tmp;
        }
    }


    void end_add(short int u)
    {
        node *tmp = new node;
        tmp->data = u;

        if(first == NULL)
        {
            first = tmp;
            last = tmp;
        }
        else
        {
            tmp->next = first;
            first->prev = tmp;
            first = tmp;
        }
    }


    void create(int u)
    {
        short int x;
        if (u == 0)
        {
            cout << " ������� ���������� ��������� � ����������� ������  ";
            int size;
            cin >> size;
            cout << "\n ������� �������� ������ ";
            for (int i = 0; i < size; i++)
            {
                cin >> x;
                start_add(x);
            }
        }
        else
        {
            FILE *data = fopen("data.txt", "r");
            if (data == NULL)
            {
                cout << "Error of opening of a output-file";
                exit;
            }
            while(fscanf(data,"%hi", &x)!= EOF)
            {
                start_add(x);
            }
            fclose(data);
        }
    }

    void print()
    {
        if (first == NULL) return;
        node* p = first;
        while (p)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    void clear()
    {
        node* p = first;
        while (p != last)
        {
            first = first->next;
            delete(p);
            p = first;
        }

        first = NULL;
        last = NULL;
        cout << "��� ������!!!";
    }


    void read(int u, int a)
    {
        node* p = first;
        if (a == 1)
        {
            while (u!= 1)
            {
                p = p->next;
                u--;
            }

        }
        else
        {
            p = last;
            while (u!= 1)
            {
                p = p->prev;
                u--;
            }
        }

        cout << p->data <<endl;
    }


    void delete_el(int u)
    {
        if (u == 0)
        {
            node* p = first;
            first = first->next;
            first -> prev = NULL;
            delete(p);
        }
        else
        {
            node* p = last;
            last = last->prev;
            last->next = NULL;
            delete(p);
        }
    }


    void insert_start(short int u, int a)
    {
        node* p = first;
        node *x = new node;
        x->data = u;

        while (a>= 2)
        {
            p = p->next;
            a--;
        }
        p->prev->next = x;
        p->prev = x;
        x->next = p;
    }


    void insert_end(short int u, int a)
    {
        node* p = last;
        node *x = new node;
        x->data = u;
        if (a == 0)
        {
            while (a>= 2)
            {
                p = p->prev;
                a++;
            }
            p->next->prev = x;
            p->next = x;
            x->prev = p;
        }

    }

    bool dempty()
    {
        return first == 0 || last == 0;
    }


    int count()
    {
        node* p = first;
        int u = 1;
        while (p != last)
        {
            p= p->next;
            u = u + 1;

        }
        return u;
    }


    void menu ()
    {
        int u;

        cout << "\n �������� ��������:\n";
        cout << " 1 - �������� ���;\n";
        cout << " 2 - ��������� ��� �� �������;\n";
        cout << " 3 - �������� ������� � ������;\n";
        cout << " 4 - �������� ������� � �����;\n";
        cout << " 5 - ������� ������� � ������;\n";
        cout << " 6 - ������� ������� � �����;\n";
        cout << " 7 - ��������� ������ �������;\n";
        cout << " 8 - ��������� ��������� �������;\n";
        cout << " 9 - �������� ������ �������;\n";
        cout << " 10 - �������� ��c������ �������.\n";


        cin >> u;

        switch (u)
        {
        case 1:
        {
            clear();
            break;
        }
        case 2:
        {
            if (!dempty())
                cout << "\n ��� �������� ������!";
            else
                cout <<"\n ��� ������. ";
            break;
        }
        case 3:
        {
            cout << "\n ������� �������: ";
            short int x;
            cin >> x;
            start_add(x);
            break;
        }
        case 4:
        {
            cout << "\n ������� �������: ";
            short int x;
            cin >> x;
            end_add(x);
            break;
        }
        case 5:
        {
            delete_el(0);
            break;
        }
        case 6:
        {
            delete_el(1);
            break;
        }

        case 7:
        {
            cout << "\n �� �����e ���������� ������� � ����� ��� � ������?\n 1 - � ������; 2 - � �����.";
            cin >> u;
            read(6, u);
            break;
        }
        case 8:
        {
            cout << "\n �� �����e ���������� ������� � ����� ��� � ������?\n 1 - � ������; 2 - � �����.";
            cin >> u;
            read(count(), u);
            break;
        }
        case 9:
        {
            cout << "\n �� �����e �������� ������� � ����� ��� � ������?\n 1 - � ������; 2 - � �����.";
            cin >> u;
            switch (u)
            {
            case 1:
            {
                cout << "\n ������� �������: ";
                short int x;
                cin >> x;
                insert_start(x, 3);
                break;
            }
            case 2:
            {
                {
                    cout << "\n ������� �������: ";
                    short int x;
                    cin >> x;
                    insert_end(x, 3);
                    break;
                }
            }
            }
            print();
            break;
        }
        case 10:
        {
             cout << "\n �� �����e �������� ������� � ����� ��� � ������?\n 1 - � ������; 2 - � �����.";
            cin >> u;
            switch (u)
            {
            case 1:
            {
                cout << "\n ������� �������: ";
                short int x;
                cin >> x;
                insert_start(x, count());
                break;
            }
            case 2:
            {
                {
                    cout << "\n ������� �������: ";
                    short int x;
                    cin >> x;
                    insert_end(x, count());
                    break;
                }
            }
            }
            print();
            break;
        }
        }

        cout << "\n ������ ���������� ������? \n 1 - ��;    2 - ���.\n ";
        cin >> u;
        if (u == 1)
        {
            menu();
        }
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");
    decque d;
    int u;
    cout << " ������ � �����\n";
    cout << " ���� ������:\n ������� ������ �� ����� - ������� 1\n ������ ������� - ������� 0\n";
    cin >> u;
    d.create(u);
    d.print();
    d.menu();
    system("pause");
}
