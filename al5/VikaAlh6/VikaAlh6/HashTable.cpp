#include "HashTable.h"

#ifdef DIRECT
int HashTable::Hash(int value)
{
	return value % size;
}

void HashTable::Add(int value)
{
	data[Hash(value)] = Item(Hash(value), value);
}

void HashTable::Remove(int value)
{
	if(data[Hash(value)].value != NULL)
		data[Hash(value)] = Item();
}

string HashTable::Find(int value)
{
	string s = string();
	s.append("Key = ").append(to_string(data[Hash(value)].key)).append("    Value = ").append(to_string(data[Hash(value)].value)).append("\n");
	return s;
}

void HashTable::Print()
{
	for (int i = 0; i < size; i++)
		if (data[i].key != -1)
			cout << "Key = " << data[i].key
			  	 << "    Value = " << data[i].value
				 << endl;
}

void HashTable::WriteFile()
{
	fstream file;
	file.open("data.txt", fstream::in |
						  fstream::out |
					      fstream::trunc);

	file << size << endl;
	for (int i = 0; i < size; i++)
		if(data[i].key != -1)
			file << data[i].key << " " << data[i].value << endl;

	file.close();
}

void HashTable::ReadFile()
{
	fstream file;
	file.open("data.txt", fstream::in |
						  fstream::out);

	int key, value;

	file >> size;	
	data = new Item[size];
	while (!file.eof())
	{
		file >> key;
		file >> value;
		data[Hash(value)] = Item(Hash(value), value);
	}

	file.close();
}
#endif

#ifdef CLOSED
int HashTable::Hash(int value)
{
	return value % size;
}

void HashTable::Add(int value)
{
	if(data[Hash(value)].key == -1)
		data[Hash(value)] = Item(Hash(value), value);
	else
	{
		Item* current = &data[Hash(value)];

		while (current->pNext != nullptr)
			current = current->pNext;

		current->pNext = new Item(Hash(value), value);
	}
}

void HashTable::Remove(int value)
{
	if (data[Hash(value)].key != -1)
	{
		if (data[Hash(value)].pNext != nullptr)
		{
			Item* current = &data[Hash(value)];

			while (current->pNext->pNext != nullptr)
				current = current->pNext;

			current->pNext = nullptr;
		}
		else
			data[Hash(value)] = Item();
	}
}

string HashTable::Find(int value)
{
	string s = string();

	if (data[Hash(value)].key != -1)
	{
		if (data[Hash(value)].pNext != nullptr)
		{
			Item* current = &data[Hash(value)];
		
			do
			{
				if(value == current->value)
					s.append("Key = ").append(to_string(current->key)).append("    Value = ").append(to_string(current->value)).append("\n");
				current = current->pNext;
			} while (current->pNext != nullptr);
		}
		else
			if(value == data[Hash(value)].value)
				s.append("Key = ").append(to_string(data[Hash(value)].key)).append("    Value = ").append(to_string(data[Hash(value)].value)).append("\n");
	}
	return s;
}

void HashTable::Print()
{
	for (int i = 0; i < size; i++)
	{
		if (data[i].key != -1)
		{
			if (data[i].pNext != nullptr)
			{
				Item* current = &data[i];

				while (current != nullptr)
				{
					cout << "Index = " << setw(14) << left << i
						<< "Key = " << setw(5) << left << current->key
						<< "Value = " << setw(5) << left << current->value
						<< endl;

					current = current->pNext;
				}
			}
			else
			{
				cout << "Index = " << setw(14) << left << i
				<< "Key = " << setw(5) << left << data[i].key
				<< "Value = " << setw(5) << left << data[i].value
				<< endl;
			}
		}
	}
}

void HashTable::WriteFile()
{
	fstream file;
	file.open("data.txt", fstream::in |
						  fstream::out |
					      fstream::trunc);

	file << size << endl;
	for (int i = 0; i < size; i++)
	{
		if (data[i].key != -1)
		{
			if (data[i].pNext != nullptr)
			{
				Item* current = &data[i];

				while (current != nullptr)
				{				
					file << current->key << " " << current->value << endl;

					current = current->pNext;
				}	
			}
			else
			{
				file << data[i].key << " " << data[i].value << endl;
			}
		}
	}

	file << -1;

	file.close();
}

void HashTable::ReadFile()
{
	fstream file;
	file.open("data.txt", fstream::in |
						  fstream::out);

	int key, value;

	file >> size;	
	data = new Item[size];
	while (!file.eof())
	{
		file >> key;
		file >> value;
		if(key != -1)
			Add(value);
	}

	file.close();
}
#endif

#ifdef OPEN
	#ifdef LINE

	int HashTable::Hash(int value)
	{
		return value % size;
	}

	void HashTable::Add(int value)
	{
		if (data[Hash(value)].key == -1)
			data[Hash(value)] = Item(Hash(value), value);
		else
		{
			for (int i = Hash(value), counter = 1; counter < size; counter++)
			{
				if (data[Hash(value + counter)].key == -1)
				{
					data[Hash(value + counter)] = Item(Hash(value), value);
					return;
				}
			}
		}
	}

	void HashTable::Remove(int value)
	{
		int hashValue = Hash(value);
		if (data[Hash(value)].key != -1 )
		{
			if (data[Hash(value)].value == value)
			{
				data[hashValue] = Item();
			}
			else		
				for (int counter = 1; counter < size; counter++)
				{
					if (data[Hash(value + counter)].key == -1)
						return;
					if (data[Hash(value + counter)].value == value)
					{
						data[Hash(value + counter)] = Item();
						break;
					}
				}

			Item* temp = new Item[size];
			for (int i = 0, counter = 0; i < size; i++)	
				if(data[i].key != -1)
					temp[counter++] = data[i];
		
			data = new Item[size];

			for (int i = 0; temp[i].key != -1; i++)
				Add(temp[i].value);
		}
		else
			return;
	}

	string HashTable::Find(int value)
	{
		int hashValue = Hash(value);
		string s = string();
		if (data[hashValue].key != -1)
		{
			if(data[hashValue].value == value)
				return s.append("Key = ").append(to_string(data[Hash(value)].key)).append("    Value = ").append(to_string(data[Hash(value)].value)).append("\n");
			else
			{
				for (int counter = 1; counter < size; counter++)
				{
					if (data[hashValue + counter].key == -1)
						return "Елемент не найден.";
					if (data[hashValue + counter].value == value)
						return s.append("Key = ").append(to_string(data[hashValue + counter].key)).append("    Value = ").append(to_string(data[hashValue + counter].value)).append("\n");
				}
			}
		}
		return "Елемент не найден.";
	}
	#endif

	#ifdef SQRT

		int HashTable::Hash(int value, int numb)
		{
			return (value % size + step1 * numb + step2 * numb * numb) % size;
		}

		void HashTable::Add(int value)
		{
			int hashValue = Hash(value, 0);

			if (data[hashValue].key == -1)
				data[hashValue] = Item(hashValue, value);
			else
			{
				for (int i = hashValue, counter = 1; counter < size; counter++)
				{
					if (data[Hash(value, counter)].key == -1)
					{
						data[Hash(value, counter)] = Item(hashValue, value);
						return;
					}
				}
			}
		}

		void HashTable::Remove(int value)
		{
			int hashValue = Hash(value, 0);

			if (data[hashValue].key != -1)
			{
				if (data[hashValue].value == value)
				{
					data[hashValue] = Item();
				}
				else
					for (int counter = 1; counter < size; counter++)
					{
						if (data[Hash(value, counter)].key == -1)
							return;
						if (data[Hash(value, counter)].value == value)
						{ 
							data[hashValue] = Item();						
							break;
						}
					}

				Item* temp = new Item[size];
				for (int i = 0, counter = 0; i < size; i++)
					if (data[i].key != -1)
						temp[counter++] = data[i];

				data = new Item[size];

				for (int i = 0; temp[i].key != -1; i++)
					Add(temp[i].value);
			}
			else
				return;
		}

		string HashTable::Find(int value)
		{
			int hashValue = Hash(value, 0);
			string s = string();
			if (data[hashValue].key != -1)
			{
				if (data[hashValue].value == value)
					return s.append("Key = ").append(to_string(data[hashValue].key)).append("    Value = ").append(to_string(data[hashValue].value)).append("\n");
				else
				{
					for (int counter = 1; counter < size; counter++)				
						if (data[Hash(value, counter)].value == value)
							return s.append("Key = ").append(to_string(data[Hash(value, counter)].key)).append("    Value = ").append(to_string(data[Hash(value, counter)].value)).append("\n");
				}
			}
			return "Елемент не найден.\n";
		}
	#endif

	#ifdef DOUBLE

		int HashTable::Hash(int value)
		{
			return value % size;
		}

		int HashTable::Hash2(int value)
		{
			return 1 + (value % (size - 1));
		}

		int HashTable::MainHash(int firstHash, int secondHash, int numb)
		{
			if (size != 0)
			{
				return (firstHash + numb * secondHash) % size;
			}
			else
			{
				return 0;
			}
		}

		void HashTable::Add(int value)
		{
			int firstHashValue = Hash(value);
			int secondHashValue = Hash2(value);
			int hashValue = MainHash(firstHashValue, secondHashValue, 0);

			if (data[hashValue].key == -1)
				data[hashValue] = Item(hashValue, value);
			else
			{
				for (int i = Hash(value), counter = 1; counter < size; counter++)
				{
					hashValue = MainHash(firstHashValue, secondHashValue, counter);
					if (data[Hash(hashValue)].key == -1)
					{
						data[Hash(hashValue)] = Item(Hash(value), value);
						return;
					}
				}
			}
		}

		void HashTable::Remove(int value)
		{
			int firstHashValue = Hash(value);
			int secondHashValue = Hash2(value);
			int hashValue = MainHash(firstHashValue, secondHashValue, 0);

			if (data[Hash(value)].key != -1)
			{
				if (data[Hash(value)].value == value)				
					data[hashValue] = Item();			
				else
					for (int counter = 1; counter < size; counter++)
					{
						hashValue = MainHash(firstHashValue, secondHashValue, counter);

						if (data[hashValue].key == -1)
							return;
						if (data[hashValue].value == value)
						{ 
							data[hashValue] = Item();
							break;
						}
					}

				Item* temp = new Item[size];
				for (int i = 0, counter = 0; i < size; i++)
					if (data[i].key != -1)
						temp[counter++] = data[i];

				data = new Item[size];

				for (int i = 0; temp[i].key != -1; i++)
					Add(temp[i].value);
			}
			else
				return;
		}

		string HashTable::Find(int value)
		{
			int firstHashValue = Hash(value);
			int secondHashValue = Hash2(value);
			int hashValue = MainHash(firstHashValue, secondHashValue, 0);

			string s = string();
			if (data[hashValue].key != -1)
			{
				if (data[hashValue].value == value)
					return s.append("Key = ").append(to_string(data[Hash(value)].key)).append("    Value = ").append(to_string(data[Hash(value)].value)).append("\n");
				else
				{
					for (int counter = 1; counter < size; counter++)
					{
						hashValue = MainHash(firstHashValue, secondHashValue, counter);

						if (data[hashValue].key == -1)
							return "Елемент не найден.";
						if (data[hashValue].value == value)
							return s.append("Key = ").append(to_string(data[hashValue].key)).append("    Value = ").append(to_string(data[hashValue].value)).append("\n");
					}
				}
			}
			return "Елемент не найден.";
		}
	#endif

void HashTable::Print()
{
	for (int i = 0; i < size; i++)
		if (data[i].key != -1)
			cout << "Index = " << setw(14) << left << i
			     << "Key = " << setw(5) << left << data[i].key
			  	 << "Value = " << setw(5) << left << data[i].value
				 << endl;
}

void HashTable::WriteFile()
{
	fstream file;
	file.open("data.txt", fstream::in |
						  fstream::out |
					      fstream::trunc);

	file << size << endl;
	for (int i = 0; i < size; i++)
		if(data[i].key != -1)
		file << data[i].key << " " << data[i].value << endl;

	file << -1;

	file.close();
}

void HashTable::ReadFile()
{
	fstream file;
	file.open("data.txt", fstream::in |
						  fstream::out);

	int key, value;

	file >> size;
	data = new Item[size];
	while (!file.eof())
	{
		file >> key;
		file >> value;
		if(key != -1)
			Add(value);
	}

	file.close();
}
#endif