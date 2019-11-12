#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

struct Node
{
   string name;
   int x;
   int y;
   bool operator==(const string & name) const
   {
      return this->name == name;
   }
};

int main()
{
   array<Node, 4> nodeInfo = { {{"A",0,1}, {"B",-1,0}, {"C",0,-1}, {"D",1,0} } };
   array<array<string, 2>, 10> edgeInfo = {{{"A","B"}, {"A","D"} ,{"B","A"},{"B","C"},{"B","D"}, {"C","B"},{"C","D"},{"D","A"}, {"D","B"},{"D","C"} } };

   vector<vector<Node>> graph;
   for (const auto inode : nodeInfo)
   {
      vector<Node> tvec(1, inode);
      graph.push_back(tvec);
   }
   for (int i = 0; i < graph.size(); i++)
   {
      for (auto & iedge : edgeInfo)
      {
         if (graph[i][0].name == iedge[0])
         {
            graph[i].push_back(*find(nodeInfo.begin(), nodeInfo.end(), iedge[1]));
         }
      }
   }
}
