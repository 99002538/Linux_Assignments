#include <stdio.h>
#include <stdlib.h>

int main(){

	FILE *fp;

	fp=fopen("a1.txt","r");

	if(fp==NULL){

		exit(EXIT_FAILURE);

	}

	char ch;

	int characters=0,words=0,lines=0;

	while((ch=fgetc(fp))!=EOF){

	characters++;

	if(ch==' ' || ch=='\t' || ch=='\n'||ch=='\0'){

		words++;

		}

	if(ch=='\n' ||ch=='\0'){

		lines++;

	}

	}

/*	if(characters>0){

		words++;
		lines++;

	}*/

	printf("characters = %d\n",characters);

	printf("words=%d\n",words);

	printf("lines=%d\n",lines);

	return 0;

}
