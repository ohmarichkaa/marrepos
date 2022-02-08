#include <iostream>
#include <ctime>
#include <fstream>
#include <cstring>

using namespace std;




struct hashtable
{
    private: struct item
{
    public:
    int key;
    int value;
    int size = 20;

		item()
		{
			key = -1;
			value = 0;
		}
		item(int key, int value)
		{
			key = key;
			value = value;
		}
};

    public:
        int size = 20;
        item* data = new item[size];


	int Hash(int value)
	{
	    return value % size;
	}


	void Add(int value)
	{
	    data[Hash(value)] = item(Hash(value), value);
	}


	void Remove(int value)
	{
	    if(data[Hash(value)].value != NULL)
		data[Hash(value)] = item();
	}

	string Find(int value)
	{
	    string s = string();
	s.append("Key = ").append(to_string(data[Hash(value)].key)).append("    Value = ").append(to_string(data[Hash(value)].value)).append("\n");
	return s;
	}

	void Print()
	{
	    for (int i = 0; i < size; i++)
		if (data[i].key != -1)
			cout << "Key = " << data[i].key << "    Value = " << data[i].value << endl;
	}

	void WriteFile()
	{
	    FILE *data1 = fopen("data1.txt", "w");
    if (data1 == NULL)
    {
        cout << "Error of opening of a output-file";
        exit;
    }
    int i = 0;
    while(i != size)
    {
        if (data[i].key != -1)
        fprintf(data1,"%d  &d", data[i].key, data[i].value);
        i++;
    }
    fclose(data1);
	}


	void ReadFile()
	{

	     FILE *file = fopen("data.txt", "r");

    if (data == NULL)
    {
        cout << "Error of opening of a output-file";
        exit;
    }
    int i = 0;
    int key, value;

	data = new item[size];
    while(file)
    {
        fscanf(file,"%d", &key);
        fscanf(file,"%d", &value);
        data[Hash(value)] = item(Hash(value), value);
    }
    fclose(file);
	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	hashtable hashtable;
	int mas[20];
	int numb;

	while (true)
	{
		cout << "1. Добавить." << endl;
		cout << "2. Удалить." << endl;
		cout << "3. Найти." << endl;
		cout << "4. Печать." << endl;
		cout << "5. Запись в файл." << endl;
		cout << "6. Вывод из файла." << endl;
		cout << "0. Выход." << endl;
		cout << "Введите значение << ";
		cin >> numb;

		switch (numb)
		{
		case 1:
			cout << endl;

			cout << "Введите число << ";
			cin >> numb;
			hashtable.Add(numb);

			cout << endl;
			break;
		case 2:
			cout << endl;
			cout << "Введите число << ";
			cin >> numb;

			hashtable.Remove(numb);

			cout << endl;
			break;
		case 3:
			cout << endl;
			cout << "Введите число << ";
			cin >> numb;

			cout << hashtable.Find(numb);

			cout << endl;
			break;
		case 4:
			cout << endl;
			hashtable.Print();
			cout << endl;
			break;
		case 5:
			hashtable.WriteFile();
			break;
		case 6:
			hashtable.ReadFile();
			break;
		case 0:
			return 0;
			break;
		default:
			break;
		}
	}

	return 0;
}
