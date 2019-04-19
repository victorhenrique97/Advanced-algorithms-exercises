#include <vector>
#include <iostream>
#include <limits.h>

using namespace std;



int get_min(vector<vector<int>> m, int len){

	int aux = INT_MAX, pos = -1;

	for(int i=0; i<len; ++i)
		if(!m[i][0] && m[i][2] < aux){
			aux = m[i][2];
			pos = i;
		}

return pos;
}

int primm(vector<vector<pair<int, int>>> graph, int vertex){

	vector<vector<int>> m;
	int pos = -1;
	int weight = -1;
	int save = 0;

	m.resize(vertex);
	for(int i=0; i<vertex; ++i){
		m[i].resize(3);
		m[i][0] = 0;		//check
		m[i][1] = -1;		//pred
		m[i][2] = INT_MAX; // weight
	}

	m[0][2] = 0;

	while(1){
		pos = get_min(m, vertex); // pego o minimo
		if(pos == -1) break;
		weight = m[pos][2];
		save += weight;
		m[pos][0] = 1; 

		for(int i=0; i<(int)graph[pos].size(); i++){
			if(graph[pos][i].second  < m[graph[pos][i].first][2]){
				m[graph[pos][i].first][2] = graph[pos][i].second;
				m[graph[pos][i].first][1] = pos;
			}
		}
	}

	m.resize(0);

return save;
}

int main(){

	ios :: sync_with_stdio(false);

	int edges = -1, vertex = -1, start, end, weight, total_weight, save;
	vector<vector<pair<int, int>>> graph;

	while(1){
		save = total_weight = 0;

		cin >> vertex >> edges;
		if(!vertex && !edges) break;
		
		graph.resize(vertex);

		for(int i=0; i<edges; ++i){
			cin >> start >> end >> weight;
			graph[start].push_back(make_pair(end, weight));
			graph[end].push_back(make_pair(start, weight));
			total_weight += weight;
		}

		save = primm(graph, vertex);
		cout << total_weight - save << endl;

		graph.resize(0);
	}

	

return 0;
}