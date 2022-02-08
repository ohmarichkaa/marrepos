#include <fstream>
#include <iostream>
#include <random>
#include <iomanip>

using namespace std;


void output_array(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout <<  array[i] << " ";
    }
}


int read_array(int* array)
{
    FILE *data = fopen("data.txt", "r");
    if (data == NULL)
    {
        cout << "Error of opening of a output-file";
        exit;
    }
    int i = 0;
    int x;
    int size = 0;
    while(fscanf(data,"%d", &x)!= EOF)
    {
        size++;
        array[i] = x;
        i++;

    }
   fclose(data);
    return size;
}


void random_input(int* array, int size, int lon)
{
    for (int i = 0; i < size; i++)
        array[i] = rand() % lon;
}


void descending(int* array, int size, int lon)
{
    for (int i = 0; i < size; i++)
        array[i] = size * lon - i * lon;
}


void ascending (int* array, int size, int lon)
{
    for (int i = 0; i < size; i++)
        array[i] = i * lon;
}


int mergersort(int* array, int size)
{
    int cont = 0;
  int mid = size / 2; // ������� �������� ����������� ������������������
  if (size % 2 == 1)
    mid++;
  int h = 1; // ���
  // �������� ������ ��� ����������� ������������������
  int *c = (int*)malloc(size * sizeof(int));
  int step;
  while (h < size)
  {
    step = h;
    int i = 0;   // ������ ������� ����
    int j = mid; // ������ ������� ����
    int k = 0;   // ������ �������� � �������������� ������������������
    while (step <= mid)
    {
      while ((i < step) && (j < size) && (j < (mid + step)))
      { // ���� �� ����� �� ����� ����
        // ��������� ��������� ������� ����������� ������������������
        // ������� �� ���� ���������������
        if (array[i] < array[j])
        {
          c[k] = array[i];
          cont++;
          i++; k++;
        }
        else {
          c[k] = array[j];
          j++; k++; cont++;
        }
      }
      while (i < step)
      { // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
        c[k] = array[i];
        i++; k++; cont++;
      }
      while ((j < (mid + step)) && (j < size))
      {  // ������������ ���������� �������� ������� ���� (���� ������ �������� ������)
        c[k] = array[j];
        j++; k++; cont++;
      }
      step = step + h; // ��������� � ���������� �����
    }
    h = h * 2;
    // ��������� ������������� ������������������ (������������� �������) � �������� ������
    for (i = 0; i < size; i++)
      array[i] = c[i];
  }
    return cont;
}

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


int quicksort(int* array, int size, int left, int right)
{
    int cont = 0;

      int pivot; // ����������� �������
  int l_hold = left; //����� �������
  int r_hold = right; // ������ �������
  pivot = array[left];
  while (left < right) // ���� ������� �� ���������
  {
    while ((array[right] >= pivot) && (left < right))
      right--;

    while ((array[left] <= pivot) && (left < right))
      left++; // �������� ����� ������� ���� ������� [left] ������ [pivot]
    if (left != right) // ���� ������� �� ����������
    {
      swap(array[right], array[left]);
      cont++;// ���������� ������� [left] �� ����� [right]
      right--; // �������� ������ ������� ������
    }
  }
  swap(array[left], array[l_hold]);
  cont++; // ������ ����������� ������� �� �����
  pivot = left;
  left = l_hold;
  right = r_hold;
  if (left < pivot) // ���������� �������� ���������� ��� ����� � ������ ����� �������
   cont += quicksort(array, size, left, pivot - 1);
  if (right > pivot)
   cont += quicksort(array,size, pivot + 1, right);

   return cont;
}


void menu(int* array, int size)
{
    srand(time(NULL));

    printf("\n1. ������ �������.\n");
    printf("2. ���������� ������� ��������.\n");
    printf("3. ����������� ���������� �������.\n");
    printf("4. ������� ���������� �������.\n");
    printf("5. ������� �� �����.\n");
    printf("6. �������� � ����.\n");
    printf("0. ����� �� ���������.\n\n");

    int u;
    cin >> u;

    switch(u)
    {
    case 1:
    {
        output_array(array, size);
        break;
    }
    case 2:
    {
        random_input(array, size, 100);
        output_array(array, size);
        cout << "\n������ ����������.\n ���-�� ��������: " <<  mergersort(array, size) << endl;
        output_array(array, size);
        cout << endl;
        descending(array, size, 1);
        output_array(array, size);
        cout << "\n���������� �� ��������. ���-�� ��������: "  << mergersort(array, size) << endl;
        output_array(array, size);
        cout << endl;
        ascending(array, size, 1);
        output_array(array, size);
        cout << "\n���������� �� �����������. ���-�� ��������: " << mergersort(array, size) << endl << endl;
        output_array(array, size);
        cout << endl;
        break;
    }
    case 3:
    {
        random_input(array, size, 100000);
        output_array(array, size);
        cout << "\n������ ����������.\n ���-�� ��������: " << radixsort(array, size) << endl;
        output_array(array, size);
        cout << endl;
        descending(array, size, 15);
        output_array(array, size);
        cout << "\n���������� �� ��������. ���-�� ��������: "  << radixsort(array, size) << endl;
        output_array(array, size);
        cout << endl;
        ascending(array, size, 15);
        output_array(array, size);
        cout << "\n���������� �� �����������. ���-�� ��������: " << radixsort(array, size) << endl << endl;
        output_array(array, size);
        cout << endl;
        break;
    }
    case 4:
    {
        random_input(array, size, 100);
        output_array(array, size);
        cout << "\n������ ����������.\n ���-�� ��������: " << quicksort(array, size, 0, size - 1) << endl;
        output_array(array, size);
        cout << endl;
        descending(array, size, 1);
        output_array(array, size);
        cout << "\n���������� �� ��������. ���-�� ��������: "  << quicksort(array, size, 0, size - 1) << endl;
        output_array(array, size);
        cout << endl;
        ascending(array, size, 1);
        output_array(array, size);
        cout << "\n���������� �� �����������. ���-�� ��������: " << quicksort(array, size, 0, size - 1) << endl;
        output_array(array, size);
        cout << endl;
        break;
    }
    case 5:
        {
            size = read_array(array);
            break;
        }
    case 0:
        {
           system("pause");
        }
    }
    menu(array, size);


}


int main()
{
    setlocale(LC_ALL, "Rus");
    int size;
    int u;
    cout << "\n������� ������ �������: ";
    cin >> size;
    int * array = new int[size];
    menu(array, size);
}
