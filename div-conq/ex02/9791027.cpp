#include <iostream>
#include <vector>

using namespace std;

bool fill(vector<int> vessels, int max, int m){

	int container_size = 0;

	for(int i=0; i< (int) vessels.size(); ++i){
		if(vessels[i] > max) 
			return false;
		
		if(container_size + vessels[i] > max)
			container_size = 0;
		
		if(!container_size)
			m--;

		if(m<0)
			return false;

		container_size += vessels[i];
	
	}

return true;
}


int funcion(vector<int>vessels, int min, int max, int ideal, int m){
	
	if(min > max) return ideal;

	int middle = (min+max)/2;

	if(fill(vessels, middle, m))
		return funcion(vessels, min, middle-1, middle, m);

	else 
		return funcion(vessels, middle+1, max, ideal, m);
}


int main(){

	int n, m, aux, max;
	vector <int> vessels;

	while(cin >> n >> m){
		max = 0;

		for(int i=0; i<n; ++i){
			cin >> aux;
			vessels.push_back(aux);
			max += aux;
		}

		cout << funcion(vessels, 1, max, max+1, m) << endl;
		vessels.clear();
	}


return 0;
}