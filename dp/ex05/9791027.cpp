#include <iostream>
#include <vector>

using namespace std;

vector<int> weights;
vector<int> firstsCars;
vector<int> lastsCars;


/*Nessa funcao estou adcionando carros em ordem crescente, ou seja, a partir de um carro dado, estou montando um vetor com os carros que vem atras dele*/
void getLastsCar(int n_cars){

	int weight;
	int train_len;
	lastsCars.resize(n_cars);

	for(int i=0; i<n_cars; i++){
		train_len = 1;
		weight = weights[i];

		for(int j=0; j<i; j++)
			if(weight > weights[j] && lastsCars[j]+1 > train_len) // se o peso do carro for maior que o atual e a fila de carros começando por j + esse for maior que o atual eu adciono
				train_len = lastsCars[j]+1;

		lastsCars[i] = train_len;
	}
}

/*Nessa funcao estou adcionando carros em ordem decrescente, ou seja, a partir de um carro dado, estou montando um vetor com os carros que vem na frente dele*/
void getFirstsCar(int n_cars){

	int weight;
	int train_len;
	firstsCars.resize(n_cars);

	for(int i=0; i<n_cars; i++){
		train_len = 1;
		weight = weights[i];

		for(int j=0; j<i; j++)
			if(weight < weights[j] && firstsCars[j]+1 > train_len) // se o peso do carro for menor que o atual e a fila de carros começando por j + esse for maior que o atual eu adciono
				train_len = firstsCars[j]+1;

		firstsCars[i] = train_len;
	}

}

void getMax(int n_cars){

	int len_max = 0;
	for(int i=0; i<n_cars; i++)
		if(len_max+1 < firstsCars[i] + lastsCars[i])
			len_max = firstsCars[i] + lastsCars[i] - 1;


	cout << len_max << endl;
}

int main(){

	int N, n_cars, weight;

	cin >> N;
	for(int i=0; i<N; i++){
		cin >> n_cars;

		for(int j=0; j<n_cars; j++){
			cin >> weight;
			weights.push_back(weight);
		}

		getLastsCar(n_cars);
		getFirstsCar(n_cars);
		getMax(n_cars);

		weights.clear();
		firstsCars.clear();
		lastsCars.clear();

	} 
}