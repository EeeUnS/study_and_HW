#include<iostream>
#include<string>
#include<vector>
#include<list>
struct node {
	std::string _name;
	int _x;
	int _y;
	node(std::string name, int x, int y):_name(name), _x(x),_y(y)
	{}
	void setter(std::string name, int x, int y)
	{
		_name = name; _x = x; _y = y;
	}

};
enum alpha
{
	A = 0,
	B,
	C,
	D
};

int main()
{
	node set[4]
	{ 
		{"A" , 1, 1},
		{"B", 0, 0},
		{"C" ,-1,-1 },
		{"D" , 2,0}
	};
	std::vector<std::vector<node>> adj_set(3);
	adj_set[A].push_back(set[B]);
	adj_set[A].push_back(set[D]); 

	adj_set[B].push_back(set[A]);
	adj_set[B].push_back(set[C]);
	adj_set[B].push_back(set[D]);

	adj_set[C].push_back(set[B]);
	adj_set[C].push_back(set[D]);
	
	adj_set[D].push_back(set[A]);
	adj_set[D].push_back(set[B]);
	adj_set[D].push_back(set[C]);


	return 0;
}
