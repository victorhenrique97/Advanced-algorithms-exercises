#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValid(vector<int> places, vector<vector<int>>restritions){

	int m = restritions.size();
	int n = places.size();
	int A, B, a, b, c;

	for(int i=0; i<m; ++i){ // pegando do vetor as restrições

		A = B = -1;
		a = restritions[i][0];
		b = restritions[i][1];
		c = restritions[i][2];

		for(int i=0; i<n; ++i)
			if(places[i] == a){
				A = i;
				break;
			}

		for(int i=0; i<n; ++i)
			if(places[i] == b){
				B = i;
				break;
			}

		if(c > 0 && abs(A - B) > c)
			return false;

		else if(c < 0 && abs (A - B) < abs(c))
			return false;

	}

return true;
}


int main(){

	int m, n, a, b, c, counter;
	vector <int> places;
	vector<vector<int>>restritions;

	cin >> n >> m; // numero de pessoas e de restrições

	while(n || m){
	 	
	 	counter = 0;
		restritions.resize(m);
	
			for(int i=0; i<n; ++i) 	 // colocando em um vetor as pessoas ordenadas
				places.push_back(i);
	
			for(int i=0; i<m; ++i){		// criando um vetor com as restrições
				cin >> a >> b >> c;
				restritions[i].push_back(a);
				restritions[i].push_back(b);
				restritions[i].push_back(c);
			}
	
			do{	
				if(isValid(places, restritions))
					counter++;

			}while(next_permutation(places.begin(), places.end()));

		places.clear();
		restritions.clear();
		
		cout << counter << endl;
		cin >> n >> m; // numero de pessoas e de restrições

	}

}