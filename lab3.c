#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int plus_memory (char ** line, int  * count, char * some_letter) {
	*count += strlen(some_letter);
	*line = realloc(*line, *count);
	
	return 0;
}

int line_processing (char * line) {
	char a;
	char b;
	int clone = 1;

	for (int i = 0; i < strlen(line); i++) {
		a = line[i];
		b = line[i + 1];
	
		if (a == b  && a != ' ' && a != '\t') clone += 1;
		else {
		
			if (clone > 1) {
			
				for (int j = 0; j < clone; j++) printf("%c", a);
				
				printf(" ");
				clone = 1;		
			}
			
		}
		
	}
	
	printf("\n");
	
	return 0;
}

int clear_memory (char ** line, int  * count) {
	free(*line);
	*count = 1;
	*line = malloc(*count);
	
	return 0;
}

int main () {
	char some_letter[11];
	int count = 1;
	int sc = 1;
	char * line = malloc(count);	
	
	do {
		sc = scanf("%10[^\n]", some_letter);
		
		if (sc == -1) break;
		else if (sc == 1) {
			plus_memory(&line, &count, some_letter);
			strcat(line, some_letter);
			
		} else {
			scanf("%*c");
			line_processing(line);
			clear_memory(&line, &count);
		}
		
	} while (sc != -1);
	
	return 0;
}
