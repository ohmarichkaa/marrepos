#include "HashTable.h"

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	HashTable hashtable;
	int mas[20];			
	int numb;

	while (true)
	{
		cout << "1. ��������." << endl;
		cout << "2. �������." << endl;
		cout << "3. �����." << endl;
		cout << "4. ������." << endl;
		cout << "5. ������ � ����." << endl;
		cout << "6. ����� �� �����." << endl;
		cout << "0. �����." << endl;
		cout << "������� �������� << ";
		cin >> numb;

		switch (numb)
		{
		case 1:
			cout << endl;

			cout << "������� ����� << ";
			cin >> numb;
			hashtable.Add(numb);

			cout << endl;
			break;
		case 2:					
			cout << endl;
			cout << "������� ����� << ";
			cin >> numb;

			hashtable.Remove(numb);

			cout << endl;
			break;
		case 3:			
			cout << endl;
			cout << "������� ����� << ";
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