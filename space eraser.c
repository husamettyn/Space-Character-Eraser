#include <stdio.h>
#define N 5000
int main(void){
    FILE *fp; 
    char text[N]; 
	int i=0, j=0, k=0, spaceCounter=0, wordCounter=0;
	
    if ((fp = fopen ("soru.txt", "r")) == NULL){
         printf("File Error!"); 
         return 1; 
    }
    fgets(text, N-1, fp);
	
	while(text[i] != '\0'){
		if(text[i] == ' '){
			wordCounter = wordCounter + 1;
		}
		if(text[i] == ' ' && text[i+1] == ' '){
			j = i+2;
			spaceCounter = 1;
			while(text[j] == ' '){
				j++;
				spaceCounter = spaceCounter + 1;
			}
			k = i+1;
			while(text[k] != '\0'){
			text[k] = text[k+spaceCounter];
			if(text[k] == '\0' && text[k-1] == ' '){
				text[k-1] = text[k];
			}
			k = k + 1;
			}
			j = 0;
		}
		i = i + 1;
	}
	printf(">>New Situation Of .txt File:\n\n%s\n\n", text);
	printf(">>Number Of Words = %d\n", wordCounter+1);
	fclose(fp);
    return 0; 	
}
