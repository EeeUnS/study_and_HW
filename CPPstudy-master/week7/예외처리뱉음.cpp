#include<iostream>
#include<vector>
#include <string.h>
#include<fstream>

using namespace std;
int N, M, V;
bool visit[1001];//�湮x 0 �湮�� ��� 1
vector<vector<int>> v(1001);
//ã���ϱ� ������ľ��ڵ尡 �θ���η��� ����Ʈ��Ǯ�

void DFS(int i)
{
	for (unsigned int j = 1; j <= v[i].size(); j++)
	{
		if (!visit[v[i][j-1]])
		{
			cout << v[i][j-1] << " ";
			visit[v[i][j-1]] = true;
			DFS(v[i][j - 1]);
		}
	}
}

void BFS(int i)
{
	for (unsigned int j = 1; j <= v[i].size(); j++)
	{
		if (!visit[v[i][j - 1]])
		{
			visit[v[i][j - 1]] = true;
			cout << v[i][j - 1] << " ";
		}
	}

	for (unsigned int j = 1; j <= v[i].size(); j++)
	{
			BFS(v[i][j - 1]);
	}
}

int main()
{
	ifstream file("input.txt");
	file >> N >> M >> V;
	for (int i = 1; i <= M; i++)
	{
		int x, y;
		file >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}//��������Ʈ 
	//DFS���̿켱Ž��
//visit[V] = true;

	visit[V] = true;
	cout << V << " ";
	DFS(V);
	cout << endl;
	//BFS
	memset(&visit, 0, N+1);
//	visit[V] = true;

	visit[V] = true;
	cout << V << " ";

	BFS(V);

	return 0;
}
