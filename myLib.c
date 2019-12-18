#define LINE 256
#define WORD 30
# include <stdio.h>

int getLineLength(char* const p){
	int i = 0; 
	int flag = 1;
	while(i < LINE && flag){
		if( *(p+i) == '\n'){
			flag = 0;
		}
		i++;
	}
	return i-1;
}

int getWordLength(char* const p){
	int i = 0; 
	int flag = 1;
	while(i < WORD && flag){
		if(*(p+i) == ' '|| *(p+i) == '\t'|| *(p+i) == '\n'|| *(p+i) == '\0'){
			flag = 0;
		} else i++;
	}
	return i;
}

int substring(char* const str1, char* const str2){
	int str1Size = getWordLength (str1);
	int str2Size = getWordLength (str2);
	for (int i = 0; i<str1Size-str2Size+1; i++){
		int flag = 0;
		for (int j = 0;j<str2Size;j++){
			if(*(str2+j) == *(str1+i+j)) {
				flag = 1;
			}
		}
		if (flag) return 1;
	}
	return 0;
}

int similar (char* s, int sSize, char* t, int tSize){// n>=0
	int DBAG = 0;
	int antiln = 0;
	if (DBAG) printf ("tempword: %s \ntSize = %d\n", t, tSize);
	if (sSize > tSize) {return 0;}
	else if (sSize == tSize){
		for(int i = 0; i<sSize; i++){
			if ( *(s+i) != *(t+i)) return 0;
		}
		return 1;
	} else if (sSize+1 == tSize){
		for(int i = 0; i<sSize+antiln; i++){
			if (*(t+i) != *(s+i-antiln)) {
				if(antiln == 0)
					antiln++;
				else return 0;
			}
		}
		return 1;
	} else return 0;
}

int wordInLine(char* line, int lineLength, char* theWord, int wordLength){
	int i = 0;
	for (; i< lineLength-wordLength+1;i++){
		int flag = 1;
		int j = 0;
		for (; j< wordLength && flag; j++){
			if(*(line+i+j) != *(theWord+j)){
				flag = 0;
			}
		}
		if(flag) return 1;
	}
	return 0;
}

void printLines(char* line, char* theWord, int wordLength){
	int DBAG = 0;
	if(*line != '\0'){
		int lineLength = getLineLength(line);
		if (DBAG) printf("lineLength: %d \n", lineLength);
		if(wordInLine(line, lineLength, theWord, wordLength)){
			printf("%s", line);
		}
		line += lineLength+2;
	}
}

void printSimilarWords(char* line, int lineLength, char* TheWord, int WordLength){
	int i = 0;
	while(*(line+i) != '\0' && *(line+i)!= '\n'){
		int tempLength = getWordLength(line+i);
		char tempWord[WORD] = {'\0'};
		for(int j =0; j<tempLength; j++){
			tempWord[j] = *(line+i+j);
		}
		i += tempLength+1;
		if(tempLength < WordLength+2 && tempLength >= WordLength){
			if (similar(TheWord, WordLength, tempWord, tempLength )) {
				printf("%s\n", tempWord);
			}
		}
	}
}