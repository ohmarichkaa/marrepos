#include <iostream>
#include <ctime>
#include <fstream>
#include <cstring>
#include <vector>
# define NO_OF_CHARS 256
using namespace std;


int maxrad(int* array, int size)
{
    int temp = array[0];
    for (int i = 1; i < size; i++)
    {
        if(temp < array[i])
            temp = array[i];
    }
    int count = 1;
    while(temp / 10 != 0)
    {
        temp /= 10;
        count++;
    }
    return count;
}


int radixsort(int* array, int size)
{
    int cont = 0;
    int mr = maxrad(array, size);
    int size1 = 0;
    int * buff = new int[size];
    int decimal1 = 10, dec2 = 1;
    for (int i = 0; i < mr; i++)
    {
        size1 = 0;
        for (int u = 0; u < 10; u++)
        {
            for (int z = 0; z < size; z++)
            {
                if(array[z] % decimal1 / dec2 == u)
                {
                    buff[size1] = array[z];
                    size1++;
                    cont++;
                }

            }
        }
        for (int i = 0; i < size; i++)
        {
            array[i] = buff[i];
        }
        decimal1 *= 10;
        dec2 *= 10;
    }
    return cont;
}



int smmenu()
{
    cout << "\n1. создание/чтение из файла" << endl;
    cout << "2. вывод" << endl;
    cout << "3. поиск" << endl;
    cout << "4. запись в файл" << endl;
    cout << "5. выход" << endl;
    int u;
    cin >> u;
    return u;
}


int arrmenu()
{
    cout << "\n1 - ввод с клавиатуры; " << endl;
    cout << "2 - рандомное заполнение; " << endl;
    cout << "3 - упорядоченное заполнение (по возрастанию);" << endl;
    cout << "4 - считать из файла." << endl;
    int u;
    cin >> u;
    return u;
}

input_arr(int* array)
{
    cout << "\nвведите размер массива:\n";
    int size;
    cin >> size;
    int tmp;
    for ( int i = 0; i < size; i++)
    {
        cin >> tmp;
        array[i] = tmp;
    }
//    cin >> array[i];
    return size;
}

int create_arr(int* array, int u)
{
    cout << "\nвведите размер массива:\n";
    int size;
    cin >> size;
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        if (u == 1)
        {
            array[i] = rand()%100;
        }
        else
        {
            array[i] = i + 1;
        }
    }
    return size;
}


int read_arr(int* array)
{
    int size = 0;
    FILE *data = fopen("data.txt", "r");
    if (data == NULL)
    {
        cout << "Error of opening of a output-file";
        exit;
    }
    int i = 0;
    while(fscanf(data,"%d", &array[i])!= EOF)
    {
        i++;
        size++;
    }
    fclose(data);
    return size;
}


void write_arr(int* array, int size)
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
        fprintf(data1,"%d ", array[i]);
        i++;
    }
    fclose(data1);
}


void output_arr (int* array, int size)
{
    for ( int i = 0; i < size; i++)
        cout << array[i] << " ";
}


int strmenu()
{
    cout << "\n1 - ввод с клавиатуры; " << endl;
    cout << "2 - рандомное заполнение; " << endl;
    cout << "3 - считать из файла." << endl;
    int u;
    cin >> u;
    return u;
}



int create_str(string* str)
{
    srand(time(0));
    cout << "введите размер строки:/n";
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    *str += 'a'+rand() % 26;
    return size;
}



int read_str(string* str)
{
    string tmp;
    int size = 0;
    FILE *data11 = fopen("data11.txt", "r");
    if (data11 == NULL)
    {
        cout << "Error of opening of a output-file";
        exit;
    }
    int i = 0;
    while(fscanf(data11,"%c", &tmp)!= EOF)
    {
        *str += tmp;
        size++;
    }
    fclose(data11);
    return size;
}



void write_str(string str)
{
    FILE *data12 = fopen("data12.txt", "w");
    if (data12 == NULL)
    {
        cout << "Error of opening of a output-file";
        exit;
    }

    fprintf(data12,"%s", str);
    fclose(data12);
}


int lin_search(int* array, int size)
{
    //output_arr(array, size);
    cout << "введите ключ ";
    int key;
    int u = 0;
    cin >> key;
    for (int i = 0; i < size; i++)
    {
        u = u + 1;
        if(array[i] == key)
        {
            cout << "\nключ " << key << " находится в ячейке " << i;
             u = u + 1;
        }
    }
    return u;
}



int bar_search(int* array, int size)
{
    cout << "введите ключ ";
    int key;
    int u = 0;
    cin >> key;
    array[size] = key;
   int i = 0;
    for(; array[i] != key; i++){u++;}

    cout << "\nключ " << key << " находится в ячейке " << i;
    return u;

}


int bin_search(int* array, int size, int key)
{
    int first = 0;
    int last = size;
    int mid = first + (last - 1) / 2;
    int u = 0;
    while(first <= last)
    {
        mid = first + (last - 1) / 2;
        u++;
        if (array[mid] < key)
        {
            u++;
            first = mid + 1;
        }

        if (array[mid] > key)
        {
            u++;
            last = mid - 1;
        }
        if (array[mid] == key)
        {
            cout << "\nключ " << key << " находится в ячейке " << mid;
            return u;
        }

    }

return u;
}


//прямой поиск подстроки
size_t StraightSearch(const string str, const string substr)
{
	int count_S = 1;

	for (int i = 0; i < str.length(); i++, count_S +=5)
		if (str[i] == substr[0])
			for (int j = 0; j < substr.length(); j++, count_S += 6)
			{
				if (str[i + j] != substr[j])
					break;

				if (j == substr.length() - 1)
					return i;

			}
}

// алгоритм Кнута Морриса Пратта
size_t KMP(const string s, const string p)
{
        int count_S = 4;

		int i, j, N, M;
		N = s.length();
		M = p.length();


		int* d = new int[M * sizeof(int)];

		d[0] = 0;
		for (i = 1, j = 0; i < M; i++, count_S +=7)
		{
			while (j > 0 && p[j] != p[i])
				j = d[j - 1], count_S+=2;
			if (p[j] == p[i])
				j++, count_S +=1;
			d[i] = j;
		}

		for (i = 0, j = 0; i < N; i++, count_S+=7)
		{
			while (j > 0 && p[j] != s[i])
				j = d[j - 1], count_S+=2;
			if (p[j] == s[i])
				j++, count_S+=1;
			if (j == M)
			{

				delete[] d;
				return i - j + 1;
			}
		}
		delete[] d;
}

 //  Бойера Мура
void badCharHeuristic(string str, int badchar[NO_OF_CHARS])
{
     int count_S = 0;
	for (int i = 0; i < NO_OF_CHARS; i++, count_S+=5)
		badchar[i] = -1;

	for (int i = 0; i < str.length(); i++, count_S+=5)
		badchar[(int)str[i]] = i;
}

size_t BM_Search(string str, string substring)
{
	int  sl = str.length();
	int ssl = substring.length();

	int count_S = 1;
		int  i, Pos;
		int  BMT[256];
		for (i = 0; i < 256; i++, count_S = 5)
			BMT[i] = ssl;
		for (i = ssl - 1; i >= 0; i--, count_S+=6)
			if (BMT[(short)(substring[i])] == ssl)
				BMT[(short)(substring[i])] = ssl - i - 1, count_S++;
		Pos = ssl - 1, count_S+=2;
		while (Pos < sl)
		{
			count_S += 2;
			if (substring[ssl - 1] != str[Pos])
				Pos = Pos + BMT[(short)(str[Pos])], count_S+=2;
			else
				for (i = ssl - 2; i >= 0; i--, count_S+=6) {
					if (substring[i] != str[Pos - ssl + i + 1]) {
						Pos += BMT[(short)(str[Pos - ssl + i + 1])] - 1, count_S+=2;
						break;
					}
					else
					{
						count_S++;
						if (i == 0)
							return Pos - ssl + 1;
					}
				}
		}
}

//Рабина Карпа
size_t rabinKarpSearch(string t, string s)
{
	int count_S = 3;

	const int p = 31;
	vector<long long> p_pow(max(s.length(), t.length()));
	p_pow[0] = 1;
	for (size_t i = 1; i < p_pow.size(); ++i, count_S+=5)
		p_pow[i] = p_pow[i - 1] * p;

	vector<long long> h(t.length());
	for (size_t i = 0; i < t.length(); ++i, count_S+=6)
	{
		h[i] = (t[i] - 'a' + 1) * p_pow[i];
		if (i)  h[i] += h[i - 1];
	}

	long long h_s = 0;

	for (size_t i = 0; i < s.length(); ++i,count_S+=4)
		h_s += (s[i] - 'a' + 1) * p_pow[i];

	for (size_t i = 0; i + s.length() - 1 < t.length(); ++i, count_S+=6)
	{
		long long cur_h = h[i + s.length() - 1];
		if (i)  cur_h -= h[i - 1];
		if (cur_h == h_s * p_pow[i])
			return i;
	}
}


void barrmenu(int* array, int size)
{
    switch(smmenu())
    {
    case 1:
        {
            switch(arrmenu())
            {
            case 1:
                {
                   size = input_arr(array);
                   barrmenu(array, size);
                    break;
                }
            case 2:
                {
                   size = create_arr(array, 1);
                   barrmenu(array, size);
                    break;
                }
            case 3:
                {
                    size = create_arr(array, 2);
                    barrmenu(array, size);
                    break;
                }
            case 4:
                {
                    size = read_arr(array);
                    barrmenu(array, size);
                    break;
                }
            }
        }
            case 2:
                {
                   output_arr(array, size);
                   barrmenu(array, size);
                   break;
                }
            case 3:
                {
                    cout << size;

                    cout << "\n\n2 - линейный поиск: ";
                    int d = lin_search(array, size);


                    cout << "\n\n3 - поиск с барьером: ";
                    d = bar_search(array, size);



                    cout << "\n1 - бинарный поиск: ";
                    cout << "введите ключ ";
                    int key;
                    cin >> key;

                    radixsort(array, size);
                    d = bin_search(array, size, key);


                    barrmenu(array, size);
                    break;
                }
            case 4:
                {
                    write_arr(array, size);
                    barrmenu(array, size);
                    break;
                }
                case 5:
                    break;

    }
}


void bstrmenu(string str)
{
    int size;
    switch(smmenu())
    {
    case 1:
        {
            switch(strmenu())
            {
            case 1:
                {
                   cin >> str;
                   bstrmenu(str);
                    break;
                }
            case 2:
                {
                    size = create_str(&str);
                    bstrmenu(str);
                    break;
                }
            case 3:
                {
//                    str.clear;
                    size = read_str(&str);
                    bstrmenu(str);
                    break;
                }
            }
        }
            case 2:
                {
                    cout << endl << str << endl;
                    bstrmenu(str);
                   break;
                }
            case 3:
                {
                    string str1;
                    cout << "\n введите подстроку: ";
                    cin >> str1;
                    cout << "\n1 - прямой поиск: " << StraightSearch(str, str1);
                    cout << endl;
                    cout << "\n2 - алгоритм кнута-морриса-прата: " << KMP(str, str1); cout << endl;
                    cout << "\n3 - алгоритм бойера-мура: " << BM_Search(str, str1); cout << endl;
                    cout << "\n4 - алгоритм рабина-карпа: " <<rabinKarpSearch(str, str1); cout << endl;
                    bstrmenu(str);
                    break;
                }
            case 4:
                {
                    write_str(str);
                    bstrmenu(str);
                    break;
                }
                case 5: exit;
    }
}


void total_menu(int u)
{
    string str;
    int* array = new int;
    int size;
    if (u == 1)
    {
       //cout << 11;
        barrmenu(array, size);
    }
    else
        bstrmenu(str);
    return;
}



int main()
{
    setlocale(LC_ALL, "Rus");
    cout << "1 - работа с массивом;  \n2 - работа co строкой. \n" << endl;
    int u;
    cin >> u;
    total_menu(u);
    return 0;
}







