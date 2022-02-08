#pragma once
#include <iostream>
#include <istream>
#include <iomanip>
#include <string>
#include <sstream>
#include <queue>
#include <stdio.h>
#include <fstream>

using namespace std;

#define ORIENT
//#define NEORIENT

const int N = 12;
const int R = 21;

class Graph
{
public:
	Graph() {};
	void MatrixAdjCreate(int temp);
	void MatrixAdjReadFile(string name, int temp);
	void PrintMatrixAdj();
	void MatrixInchiCreate(int temp); 
	void MatrixInchiReadFile(string name, int temp);
	void PrintMatrixInchi();
	void SpisokReberCreate(int temp);
	void SpisokReberReadFile(string name, int temp);
	void PrintSpisokReber();
	void SpisokSmejCreate(int temp);
	void SpisokSmejReadFile(string name, int temp);
	void PrintSpisokSmej();
	void writeFile(string name);
	void MatrixAdjToMatrixInchi(int temp);
	void MatrixInchiToSpisokReber(int temp);
	void MatrixAdjToSpisokSmej();
	void MatrixInchiToMatrixAdj(int temp);
	void DFS(int n, bool visited[]); 
	void BFS(int n, bool visited[]);

private:
	int matrix_adj[N][N];
	int matrix_inchi[N][R];

	struct SpisokReber
	{
		int begin;
		int end;
		int	weight;
		SpisokReber* next;
	};

	SpisokReber* head;

	struct SpisokSmej
	{
		int	ver;
		int weight;
		SpisokSmej* next;
	};

	SpisokSmej* smej[N];
};

