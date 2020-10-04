#include <stdio.h> 
#include <sys/resource.h> 
#include <string.h> 
#include <errno.h> 
#include <unistd.h> 
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h>
int main(){
struct rlimit old_limit,limit,new_limit;

if(getrlimit(RLIMIT_NOFILE,&old_limit)==0){

	printf("%ld %ld",old_limit.rlim_cur,old_limit.rlim_max);

}

else{

	fprintf(stderr,"%s",strerror(errno));

}

limit.rlim_cur=3;

limit.rlim_max=1024;

if(setrlimit(RLIMIT_NOFILE,&limit)==-1){

  fprintf(stderr,"%s",strerror(errno));
  }

if(getrlimit(RLIMIT_NOFILE,&new_limit)==0){
        
        printf("%ld %ld",new_limit.rlim_cur,old_limit.rlim_max);
        
}    

return 0;

}
