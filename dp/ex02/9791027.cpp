#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> loja;
vector<vector<int>> pd;
int M, C, K;

int MAX(int A, int B){
	if(A > B) return A;
	else return B;
}

int compra(int gasto, int curr){

	int valor = -1;

	if(gasto < 0) return valor;
	if(curr == C) return M-gasto;

	if(pd[gasto][curr] != -1) return pd[gasto][curr]; // caso já tenha passado por aquele teste.

	for(int i=1; i<loja[curr][0]+1; ++i) // roda para todos os itens e pega aquele cuja gasto seja maior
		valor = MAX(valor, compra(gasto-loja[curr][i], curr+1));
	pd[gasto][curr] = valor;
	
	return valor;
}

int main(){

	int N, aux;
	cin >> N;

	for(int i=0; i<N; ++i){

		cin >> M >> C; // lendo o dinheiro e o numero de itens para comprar
		loja.resize(C); // aloco C linhas correspondentes ao numero de categorias
	
		for(int j=0; j<C; ++j){
			cin >> K; // leio o numero de itens em determinada categoria
			loja[j].push_back(K); // coloco ele na posicao 0 do vetor

			for(int l=1; l<K+1; ++l){
				cin >> aux;
				loja[j].push_back(aux); // leio os itens de uma categoria
			}
		}

		pd.resize(M+1);
		for(int j=0; j<M+1; ++j)
			for(int l=0; l<C; ++l)
				pd[j].push_back(-1);

		aux = compra(M, 0);
		if(aux < 0) cout << "no solution" << endl;
		else cout << aux << endl;

		loja.clear();
		pd.clear();
	}

return 0;
}