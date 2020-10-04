#include <stdio.h>
#include <stdlib.h>

int main(){

	FILE *fptr=fopen("a1.txt","r");

	char ch;

	do{

		ch=fgetc(fptr);

		putchar(ch);

	}while(ch!=EOF);

	fclose(fptr);

	return 0;

}
