#pragma once

#include <fstream>
#include <iostream>
#include <random>
#include <iomanip>

int mergersort(int* array, int size, int a, int b);
int radixsort(int* array, int size);
int quicksort(int* array, int size, int a, int b);
void input_array(int* array, int size);
void output_array(int* array, int size);
int read_array(int* array);
void random_input(int* array, int size);
void descending(int* array, int size);
void ascending(int* array, int size);
int maxrad(int* array, int size);
