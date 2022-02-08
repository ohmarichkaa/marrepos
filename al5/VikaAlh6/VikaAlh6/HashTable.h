#pragma once
#include "Functions.h"

//---------------------------------------------------------------TYPE OF HASHTABLE-------------------------------------------------------------------------------
#define DIRECT
//#define CLOSED
//#define OPEN

//---------------------------------------------------------------TYPE OF OPEN HASHTABLE-------------------------------------------------------------------------------
//#define LINE
//#define SQRT
//#define DOUBLE

using namespace std;

#ifdef DIRECT
class HashTable
{
private:
	class Item
	{
	public :

		int key;
		int value;

		Item()
		{
			key = -1;
			value = 0;
		}
		Item(int key, int value)
		{
			this->key = key;
			this->value = value;
		}
	};

public:
	HashTable() {};

	int size = 20;
	Item* data = new Item[size];

	int Hash(int value);
	
	void Add(int value);
	void Remove(int value);
	string Find(int value);

	void Print();

	void WriteFile();
	void ReadFile();
}; 
#endif

#ifdef CLOSED
class HashTable
{
private:
	class Item
	{
	public:

		int key;
		int value;
		Item* pNext;

		Item() 
		{
			key = -1;
			value = int();
			pNext = nullptr;
		}
		Item(int key, int value, Item* pNext = nullptr)
		{
			this->key = key;
			this->value = value;
			this->pNext = pNext;
		}
	};

public:
	HashTable() {};

	int size = 9;
	Item* data = new Item[size];

	int Hash(int value);

	void Add(int value);
	void Remove(int value);
	string Find(int value);

	void Print();

	void WriteFile();
	void ReadFile();
};
#endif

#ifdef OPEN
class HashTable
{
private:
	class Item
	{
	public:

		int key;
		int value;

		Item()
		{
			key = -1;
			value = 0;
		}
		Item(int key, int value)
		{
			this->key = key;
			this->value = value;
		}
	};

public:
	HashTable() {};

	//-----------------------------------------------------------Линейное пробирование----------------------------------------------------
#ifdef LINE

	int size = 11;
	Item* data = new Item[size];

	int Hash(int value);

	void Add(int value);
	void Remove(int value);
	string Find(int value);

#endif

	//-----------------------------------------------------------Квадратичное пробирование----------------------------------------------------
#ifdef SQRT

	int size = 11;
	Item* data = new Item[size];
	int step1 = 1, step2 = 3;

	int Hash(int value, int numb);

	void Add(int value);
	void Remove(int value);
	string Find(int value);

#endif 

	//-----------------------------------------------------------Двойное хеширование----------------------------------------------------
#ifdef DOUBLE

	int size = 11;
	Item* data = new Item[size];

	int Hash(int value);
	int Hash2(int value);
	int MainHash(int firstHash, int secondHash, int numb);

	void Add(int value);
	void Remove(int value);
	string Find(int value);

#endif 
	void Print();

	void WriteFile();
	void ReadFile();
};
#endif