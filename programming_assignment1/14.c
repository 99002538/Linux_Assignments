#include<unistd.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <string.h>



int main()
{
	int ret,returni;
	int child1=fork();
	int child2;
	int child3;
	int child4;
	int child5;
	char *s;
	char *ss;
	ss="./s.out";
	s="s.out"; 
	if(child1<0||child2<0||child3<0)
	{
	perror("fork");
	exit(1);
	}
	if(child1==0)
	{ 
	execl("/bin/gcc","gcc","-c","test.c",NULL);
    	}
    	else
    	{
    	waitpid(child1, &returni, 0);
    	child2=fork();
    	}
	if(child2==0)
    	execl("/bin/gcc","gcc","-c","sum.c",NULL);
    	else
    	{waitpid(child2, &returni, 0);
    	child3=fork();}
	if(child3==0)
	execl("/bin/ar", "ar","rcs","libsum.a","sum.o", NULL); 
    	else
    	{
    	waitpid(child3, &returni, 0);
    	child4=fork();
	} 
	if(child4==0)
	//ar rcs mylib.a sum.o
	execl("/bin/gcc","gcc","test.o","-o",s,"-static","-L.","-lsum",NULL);
	else
	{
	  waitpid(child4, &returni, 0);
	  child5=fork();
	} 
	if(child5==0)
	execl("./s.out", "./s.out", NULL); 
    	else
    	{
    	waitpid(child5, &returni, 0);
	}	 
	exit(0);
}


