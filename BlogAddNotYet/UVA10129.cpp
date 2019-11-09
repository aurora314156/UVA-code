#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
const int maxn = 26;
bool connected = true;
int Graph[maxn][maxn], Indegree[maxn], Outdegree[maxn], vis[maxn];

void dfs(int start){
	vis[start] = 1;
	for (int end = 0; end < maxn; ++end){
		if(Graph[start][end] && !vis[end])
			dfs(end);
	}
}

int main()
{
	// T = amount of program running, N = word numbers
	int T = 0, N = 0;
	cin >> T;
	while(T--)
	{
		// initital word numbers and graph, in-degree and out-degree 
		cin >> N;
		string word;
		connected = true;
		memset(Graph, 0, sizeof(Graph));
		memset(Indegree, 0, sizeof(Indegree));
		memset(Outdegree, 0, sizeof(Outdegree));
		memset(vis, 0, sizeof(vis));

		while(N--){
			cin >> word;
			// if a, b has connection, then draw a line on the graph
			Graph[word[0] - 'a'][word[word.length()-1] - 'a'] = 1;
			Indegree[word[word.length()-1] - 'a']++;
			Outdegree[word[0] - 'a']++;
		}
		// check all node connected situation
		// 1. All nodes in-degree equals out-degree except start and end node.
		// 2. At least one node in-degree bigger than out-degree, which is start node.
		// 3. At least one node out-degree bigger than in-degree, which is end node.
		int startNode = 0, endNode = 0;
		for (int i = 0; i < maxn; ++i){
			if (!connected) break;
			// according to condition 1, node degree not equals must be start or end node.
			if (Indegree[i] != Outdegree[i]){
				// accumulate condition 2.
				if(Indegree[i] == Outdegree[i] + 1)
				{
					++startNode;
				}
				// accumulate condition 3.
				else if(Indegree[i] + 1 == Outdegree[i]){
					++endNode;
				}
				// according to condition 1.
				// ex: ok, ok, cd, cd
				else{
					connected = false;
					break;
				}
			}
		}
		// according to condition 1.
		if (startNode && endNode && (endNode + startNode)>2) {
			connected = false;
		}
		if (connected){
			// dfs graph
			for (int node = 0; node < maxn; ++node){
				if (Outdegree[node]){
					dfs(node);
					break;
				}
			}
			// if any node was not visited graph must be unconnected
			for (int i = 0; i < maxn; ++i){
				if((Indegree[i] && !vis[i]) || (Outdegree[i] && !vis[i]))
                {
                    connected = false;
                    break;
                }
			}
		}
		if (!connected){
			cout << "The door cannot be opened." << endl;
		}
		else{
			cout << "Ordering is possible." << endl;
		}
	}
	return 0;
}
/*
3
2
acm
ibm
3
acm
malform
mouse
2
ok
ok

*/