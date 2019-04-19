#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
string anagram;
bool flag = false;

void getSolution(string word, int pos){

    int len = anagram.length();
    int len2 = word.length();
    char aux;
    string aux2;

    if(len == pos){
        cout << word << endl;
        return;
    }

    else{

        aux = anagram[pos];

        for(int i=0; i<len2+1; ++i){
            aux2 = word;
            aux2.insert(aux2.begin()+i,aux);
            getSolution(aux2, pos+1);
        }
    }

return;
}

int main(){

    string pattern;
 
    while(cin >> anagram){
        
        pattern.push_back(anagram[0]);

        if(flag == 0) flag = true;
        else if(flag != 0) cout << endl;
        
        getSolution(pattern, 1);
        pattern.erase();
    }

return 0;
}