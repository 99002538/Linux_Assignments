#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <fcntl.h>

int main(){
int fd = shm_open("shmname", O_CREAT, O_RDWR);
ftruncate(fd, sizeof(sem_t));
sem_t *sem = mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE,
    MAP_SHARED, fd, 0);

sem_init(sem, 1, 1);

}
