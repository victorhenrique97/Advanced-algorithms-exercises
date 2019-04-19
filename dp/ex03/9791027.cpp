#include <iostream>
#include <vector>

#define MAX_PESO 31 // pois ngn carrega mais que 30, mas ela pode pegar 30 então 30+1

using namespace std;

typedef vector<pair<int, int>> vii;
vii loja;
vector<int> grupo;
vector<vector<int>>pd;

int N;

int MAX(int A, int B){

	if(A>=B) return A;

return B;
}
void compra(){

	for(int i=1; i<=N; ++i){
		for(int j=0; j<MAX_PESO; ++j){

			pd[i][j] = pd[i-1][j]; // o preço é inicialmente o mesmo do objeto anterior pois ainda não peguei o atual

			if(loja[i].second <= j) // caso o peso desse objeto seja menor que o peso restante (peso restante = j)
				pd[i][j] = MAX(pd[i][j], loja[i].first + pd[i-1][j-loja[i].second]); //pego o maximo entre o preço atual e o preço desse objeto + o preço dos objetos anteriores com o peso restante.
			
		}
	}
}

int main(){

	int T, P, W, G, MP, sum;
	cin >> T;

	for(int i=0; i<T; ++i){
		
		cin >> N;

		loja.push_back(make_pair(0,0));
		for(int j=1; j<=N; ++j){
			cin >> P >> W;
			loja.push_back(make_pair(P, W));
		}

		cin >> G;

		for(int j=0; j<G; ++j){
			cin >> MP;
			grupo.push_back(MP);
		}

		pd.resize(N+1);
		for(int j=0; j<N+1; ++j)
			for(int l=0; l<MAX_PESO; ++l)
				pd[j].push_back(0);

		compra();
		sum = 0;

		for(int j=0; j<G; ++j){
			sum += pd[N][grupo[j]];
		}

		cout << sum << endl;

		loja.clear();
		grupo.clear();

	}

return 0;
}