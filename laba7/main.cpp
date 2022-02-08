#include <iostream>

using namespace std;

/*1. Ввод с экрана и запись в файл.
2.  Ввод случайным образом и запись в файл.
3. Добавить запись в начало файла.
4. Добавить запись в конец файла.
5. Печать одной записи из файла по номеру.
6. Чтение всех структур последовательно из файла и печать.
7. Выход из программы.*/

struct processor
{
    string cpu;
    int freaq;
    char type;
};


void menu(processor a, int n);


int main()
{
     setlocale(LC_ALL, "Rus");
    int n;
    cout << " Введите количество данных:  ";
    cin >> n;
    processor info;
    menu(info, n);

}
