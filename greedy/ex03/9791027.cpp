#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool compare(pair<int, int> a, pair<int, int> b){
	return a.second < b.second;
}

//////////////////////////////////////////////////////////////
int main(){

	ios :: sync_with_stdio(false);

	int t, n, s, e, counter;
	vector<pair<int, int>>tasks;

	cin >> t;

	for(int j=0; j<t; j++){
		cin >> n;

		for(int i=0; i<n; ++i){
			cin >> s >> e;
			tasks.push_back(make_pair(s, e));	// criação do vetor de pares com tempo de inicio e termino
		}
			
		sort(tasks.begin(),tasks.end(), compare); // ordenação do vetor

		for(int i=0; i<n; i++){
			e = counter = 0;
			for(int i=0; i<n; ++i)
				if(tasks[i].first >= e){
					e = tasks[i].second;
					counter++;
				}
		}
	
		cout << counter << endl;
		tasks.clear();
	}


return 0;
}