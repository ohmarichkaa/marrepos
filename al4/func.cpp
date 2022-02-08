#include "func.h"

void input_array(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "/nenter please array["<< i+1 <<"]: ";
        cin >> array[i];
    }
}


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
    size = 0;
    while(fscanf(data,"%d", &x)!= EOF)
    {
        size++;
        array[i] = x;
        i++;
    }
    fclose(data);
    return size;
}


void random_input(int* array, int size)
{
    for (int i = 0; i < size; i++)
        array[i] = rand() % 10;
}


void descending(int* array, int size);
{
    for (int i = 0; i < size; i++)
        array[i] = size - i;
}


void ascending (int* array, int size);
{
    for (int i = 0; i < size; i++)
        array[i] = i;
}


int mergersort(int* array, int size, int a, int b)
{
    int cont = 0;
    if (right == left)
        return;
    if (right — left == 1)
    {
        if (array[right] < array[left])
        {
            swap(array[right], array[left]);
            cont++;
        }
        return;
    }
    int m = (right + left) / 2;

   cont += mergesort(array, size, left, m);
    mergesort(array, size, m + 1, right);
    int buf[size];
    int xl = left;
    int xr = m + 1;
    int cur = 0;
    while (right — left + 1 != cur)
    {
        if (xl > m)
        {
            buf[cur++] = array[xr++];
            cont++;
        }
        else if (xr > right)
        {
             buf[cur++] = array[xl++];
             cont++;
        }
        else if (array[xl] > array[xr])
        {
            buf[cur++] = array[xr++];
            cont++;
        }
        else
        {
            buf[cur++] = array[xl++];
            cont++;
        }
    }
    for (int i = 0; i < cur; i++)
        array[i + l] = buf[i];

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
    int decimal = 10;
    for (int i = 0; i < mr; i++)
    {
        for (int u = 0; u < 10; u++)
        {
            size1 = 0;
            for (int z = 0; z < size; z++)
            {
                if(array[z] % decimal == u)
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
        decimal *= 10;
    }
    return cont;
}


int quicksort(int* array, int size, int a, int b);
{
    int cont = 0;

  int left = 0, right = size - 1;
  int mid = array[(left + right) / 2];
  while (left <= right)
  {
    while (array[left] < mid)
      left++;

    while (array[right] > mid)
      right--;

    if (left <= right)
    {
         swap (array[left++], array[right--]);
         cont++;
    }

  }
  if (0 < right)
   cont = cont + quicksort (array, size, 0, right);
  if (size - 1 > left)
   cont = cont + quicksort (array, size, left, size - 1);
    return cont;
}
