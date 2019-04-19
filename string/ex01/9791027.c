#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ispalindrome(char *string, int end){

	for(int i=0, j=end; i<j; ++i, --j)
		if(string[i] != string[j])
			return 0;

return 1;
}

void reorder(char *string, int end, int end_default){

	for(int i=end; i>end_default; --i)
		string[i+1] = string[i];
}

void complete(char *string, int end){

	int start = 0;

	for(int i=0; i<=end; ++i){
		string[end+1] = string[start++];
		if (ispalindrome(string, end+i+1)) return;
			else reorder(string, end+i+1, end);
	}
}

int main(){

	char *string = NULL;

	while(scanf("%ms", &string) != EOF){

		if(!ispalindrome(string, strlen(string)-1))
			complete(string, strlen(string)-1);
		printf("%s\n", string);

		free(string);
	}

return 0;
}