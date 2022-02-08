#include <iostream>

using namespace std;


struct node
{
    char data;
    node* next;
    node* prev;
};


struct clist
{
    node* first;
    node* last;
    int size;
    clist(): first(NULL), last(NULL), size(0) {}

    void add_node(char n)
    {
        size = size + 1;
        node *tmp = new node;
        tmp->data = n;
        tmp ->next = first;
        tmp-> prev = last;
        if(first == NULL)
        {
            first = tmp;
            last = tmp;
        }
        else
        {
            last->next = tmp;
            tmp -> prev = last;
            last = last -> next;
            last -> next = first;
        }
    }


        void create(int u)
    {
        char x;
        if (u == 0)
        {
            cout << " введите количество элементов в создаваемом списке  ";
            int size;
            cin >> size;
            cout << "\n введите элементы списка";
            for (int i = 0; i < size; i++)
            {
                cin >> x;
                add_node(x);
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
            while(fscanf(data,"%c", &x)!= EOF)
            {
                add_node(x);
            }
            fclose(data);
        }
    }


    void clear()
    {
        node* p = first;
        node* x = p->next;
        while (x != last)
        {
            p->next = x->next;
            delete(x);
            x = p->next;

        }
        first = NULL;
        last = NULL;
        cout << "cписок очищен!!!";
    }


void delete_el(int u)

    {
        node* p = first;
        if (u == 1)
        {
            first = p -> next;
            last ->next = first;
            delete(p);
        }
        else
        {
            while (u > 2)
            {
                p = p->next;
                u--;
            }
            node* x = p ->next;
            p->next->prev = p->next;
            p->next = x->next;
            delete(x);
        }
        size--;
    }


        int count()
    {

        return size;
    }



        void print()
    {
        if (last == NULL) return;
        node* p = first;
        int u = size;
        while (u != 0)
        {
            cout << p->data << " ";
            p = p->next;
            u--;
        }
        cout << endl;
    }


        void swap(int u)
    {
        char z;
        node* p = first;
        while (u != 1)
        {
            p = p->next;
            u--;
        }
        node* x = p ->next;
        z = p -> data;
        p-> data = x -> data;
        x -> data = z;
    }


    void merger(clist a, clist b)
    {
        int u;
        cout << " если хотите:\n считать данные из файла - введите 1\n ввести вручную - введите 0\n";
        cin >> u;
        a.create(u);
        cout << "\n необходимо создать второй список для объединения\n";
        b.create(0);
        clist c;

        int size_a = a.count();
        int size_b = b.count();
        node* aa = a.first;
        node* bb = b.first;

        for (int i = 0; i < size_a; i++)
        {
            c.add_node(aa->data);
            aa = aa-> next;
        }

        for (int i = 0; i < size_b; i++)
        {
            c.add_node(bb->data);
            bb = bb-> next;
        }

        c.print();
    }

        void menu ()
    {
        int u;
        print();
        cout << "\n выберите действие:\n";
        cout << " 1 - очистить список;\n";
        cout << " 2 - добавить элемент в конец списка;\n";
        cout << " 3 - удалить указанный элемент из списка;\n";
        cout << " 4 - определить количество элементов в списке;\n";
        cout << " 5 - поменять местами два соседних элемента;\n";
        cout << " 6 - объединить два списка в новый.\n";

        cin >> u;

        switch (u)
        {
        case 1:
        {
            clear();
            print();
            break;
        }
        case 2:
        {
            char l;
            cin >> l;
            add_node(l);
            print();
            break;
        }
        case 3:
        {
            cout << "\nвведите номер удаляемого элемента ";
            int l;
            cin >> l;
            delete_el(l);
            print();
            break;
        }
        case 4:
        {
            cout << "количество элементов = " << count() << endl;
            break;
        }
        case 5:
        {
            cout << "\nвведите позицию элемента который ближе к началу списка ";
            int l;
            cin >> l;
            swap(l);
            print();
            break;
        }
             case 6:
             {
                 clist a;
                 clist b;
                 merger(a, b);
                 break;
             }
        }

        cout << "\n хотите закончить работу с этим списком? \n 1 - да.\n ";
        cin >> u;
        if (u != 1)
        {
            menu();
        }
    }

};


int main()
{
    setlocale(LC_ALL, "Rus");
    clist cll;
    int u;
    cout << " работа с кольцевым списком\n";
    cout << " если хотите:\n считать данные из файла - введите 1\n ввести вручную - введите 0\n";
    cin >> u;
    cll.create(u);
    cll.print();
    cll.menu();
    return 0;
}
