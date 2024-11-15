#include <iostream>

using namespace std;

int** createG(int n)
{
	int** G = NULL;
	G = new int* [n];
	for (int i = 0; i < n; i++)
	{
		G[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			G[i][j] = rand() % 2;
			G[j][i] = G[i][j];
			if (i == j) G[i][j] = 0;
		}
	}
	return G;
}

void printG(int** G, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << G[i][j] << " ";
		}
		cout << endl;
	}
}

void dfs(int** G, int size, int s, int* vis)
{
	vis[s] = 1;
	cout << s + 1 << " ";
	for (int i = 0; i < size; i++)
	{
		if (G[s][i] == 1 && vis[i] == 0)
		{
			dfs(G, size, i, vis);
		}
	}
}
int main() {
	setlocale(LC_ALL, "");
	int n1, n2;
	int nG1 = 3;
	cout << "Кол-во вершин 1 графа" << endl;
	cin >> nG1;
	int** G1 = createG(nG1);
	cout << "1 граф" << endl;
	printG(G1, nG1);
	int* vis = new int[nG1];
	for (int i = 0; i < nG1; i++)
	{
		vis[i] = 0;
	}
	dfs(G1, nG1, 0, vis);
}