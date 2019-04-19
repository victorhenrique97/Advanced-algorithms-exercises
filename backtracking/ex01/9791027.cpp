#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

vector<vector<int>> M;
vector<int> pos;
int min_mov = INT_MAX;

int compare(){

	/*for(int i=0; i<8; i++){
		for(int j=0; j<8; j++)
			cout << M[i][j] << " ";
		cout << endl;
	}*/

	int aux = -1;
	int mov = 0;

	for(int i=0; i<8; ++i){
		aux = pos[i];

		for(int j=0; j<8; ++j)
			if(M[i][j] && j!= aux)
				mov++;
				
	}

	//cout << "valor da distancia:" << mov<< endl;

return mov;
}

bool isvalid(int row, int col){

	for(int i=0; i<8; ++i){ // percorrendo as linhas
		if(M[row][i])
			return false;
	}

	for(int i=row+1, j=col+1; i<8 && j<8; ++i, j++){ // percorrendo diagonais decrescentes para direita
		if(M[i][j]) return false;
	}

	for(int i=row+1, j=col-1; i<8 && j>=0; i++, j--){ // percorrendo diagonais decrescentes para esquerda
		if(M[i][j]) return false;
	}

	for(int i=row-1, j=col+1; i>=0 && j<8; i--, j++){ // percorrendo diagonais crescentes para direita
		if(M[i][j]) return false;
	}

	for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){ // percorrendo diagonais crescentes para esquerda
		if(M[i][j]) return false;
	}

return true;
}

void generate_matrix(int col){

	if(col == 8){
		int mov = compare();

		if(mov < min_mov)
			min_mov = mov;

		return;
	}

	for(int i=0; i<8; ++i){

		if(isvalid(i, col)){

			int t = M[i][col];
			M[i][col] = 1;
			generate_matrix(col+1);
			M[i][col] = t;

		}
	}
}


int main(){

	int aux;
	int counter=1;

	M.resize(8);
	for(int i=0; i<8; ++i)
		M[i].resize(8);

	while(1){

		min_mov = INT_MAX;

		for(int i=0; i<8; ++i){
			if(cin.eof())
			return 0;
			cin >> aux;
			pos.push_back(aux-1);
		}

	generate_matrix(0);

	cout << "Case " << counter++ << ": "<<min_mov << endl;
	}

return 0;
}