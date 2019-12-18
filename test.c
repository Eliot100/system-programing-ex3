# include <stdio.h>
# define LINE 256
# define NUM_OF_LINES 252
# define WORD 30

int main() {
	char text_file[NUM_OF_LINES*LINE];

	do {
//		char[WORD] The_word = {'\0'};  
//		scanf(" %s", &text_file);
//		char buffer[NUM_OF_LINES*LINE];
		fgets(text_file, NUM_OF_LINES*LINE , stdin);
		scanf(" %s", &text_file);
		
		
	} while(0);
	return 0;
}