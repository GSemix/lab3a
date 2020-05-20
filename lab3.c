#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int plus_memory (char ** line, int  * count, char * some_letter) {
	*count += strlen(some_letter);
	*line = realloc(*line, *count * sizeof(char));
	
	return 0;
}

int line_processing (char * line, int count) {
	int start = 0;
	int clone = 1;
	int j = 0;
	char * res = calloc(count, sizeof(char));

	for (int i = 0; i < (count - 1); i++) {
	
		if (line[i] == line[i + 1] && line[i] != 9 && line[i] != 32) {
		
			if (clone == 1) start = i;
			
			clone += 1;
			
		} else {
		
			if (clone > 1) {
			
				strncpy(&res[j], &line[start], clone);
				strcat(res, " ");
				j += clone + 1;
				clone = 1;		
			}
			
		}
		
	}
	
	if (strlen(res) != 0) {
		//Как изменить размер line?
		res[j - 1] = '\0';
		strncpy(line, res, j);
	} else line[0] = '\0';
	
	free(res);
	
	return 0;
}

int clear_memory (char ** line, int  * count) {
	free(*line);
	*count = 1;
	*line = calloc(*count, sizeof(char));
	
	return 0;
}

int main () {
	char some_letter[11];
	int count = 1;
	int sc = 1;
	char * line = calloc(count, sizeof(char));
	
	do {
		sc = scanf("%10[^\n]", some_letter);
		
		if (sc == -1) break;
		else if (sc == 1) {
			plus_memory(&line, &count, some_letter);
			strcat(line, some_letter);
			memset(some_letter, 0, sizeof(some_letter)*sizeof(char));
			
		} else {
			scanf("%*c");
			line_processing(line, count);
			printf("$%s$\n\n", line);
			clear_memory(&line, &count);
		}
		
	} while (sc != -1);
	
	free(line);
	
	return 0;
}
