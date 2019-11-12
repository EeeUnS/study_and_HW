#include<iostream>
#include<vector>

using namespace std;
int N, M ,V;
bool visit[1001];//방문x 0 방문한 노드 1
vector<vector<int>> v(1001, 0) ;
//찾으니까 인접행렬쓴코드가 널리고널려서 리스트로풀어봄

void DFS(int i)
{
	for(int j = 1; j <= v.size() ; j++)
	{
		if(!visit[j])
		{
			cout << j <<" ";
			visit[j] == true;
			DFS(j);
		}
	}
}


void BFS(int i)
{
	for(int j = 1; j <= v.size() ; j++)
	{
		if(!visit[j])
		{
			visit[j] == true;
			cout << j <<" ";
		}
	}

	for(int j = 1; j <= v.size() ; j++)
	{
		if(!visit[j])
		{
			BFS(j);

		}
	}

}

int main()
{
	cin >> N >> M >> V ;
	for(int i = 1 ; i <= M ; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}//인접리스트 
	//DFS깊이우선탐색
	visit[V]=true;
	DFS(V);
	cout<<endl;
	//BFS
	BFS(V);

	return 0;
} 
