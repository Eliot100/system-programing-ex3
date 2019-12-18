# include <stdio.h>
# include "myLib.h"
# define LINE 256
# define NUM_OF_LINES 252
# define WORD 30

int main() {
	int DBAG = 0;
	char text_file[NUM_OF_LINES+2][LINE]= {0};
	int k = 0;
	while (k < NUM_OF_LINES+2 && !feof(stdin)){
		fgets(text_file[k], LINE, stdin);
		if (DBAG) printf("%s", text_file[k]);
		k++;
	}
	char* p = NULL;
	char TheWord[WORD] = {0};
	p = text_file[0];
	int i = 0;
	while (*(p+i) != ' '){
		TheWord[i] = *(p+i);
		i++;
	}
	if (DBAG) printf("\nThe Word: %s\n", TheWord);
	int WordLength = getWordLength(p);
	if (DBAG) printf("Word Length: %d\n", WordLength);
	char TheAction = *(p+WordLength+1);
	if (DBAG) printf("The Action: %c\n", TheAction);
	if (TheAction == 'a'){
		if (DBAG) printf("printLines:\n");
		for(int j =2; j<k; j++){
			p = text_file[j];
			printLines(p, TheWord, WordLength);
		}
	} else if (TheAction == 'b'){
		if (DBAG) printf("printSimilarWords:\n");
		for(int j =2; j<k; j++){
			p = text_file[j];
			int tempLineLen = getLineLength( p); 
			printSimilarWords(p, tempLineLen, TheWord, WordLength);
		}
	} else {
		if (DBAG) printf ("not a or b\n");
	}
	return 0;
}