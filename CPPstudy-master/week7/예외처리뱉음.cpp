#include<iostream>
#include<vector>
#include <string.h>
#include<fstream>

using namespace std;
int N, M, V;
bool visit[1001];//방문x 0 방문한 노드 1
vector<vector<int>> v(1001);
//찾으니까 인접행렬쓴코드가 널리고널려서 리스트로풀어봄

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
	}//인접리스트 
	//DFS깊이우선탐색
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
