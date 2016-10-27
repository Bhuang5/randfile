#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

int rando(){
  int fd = open("/dev/random", O_RDONLY);
  int buf;
  read(fd, &buf, 4);
  close(fd);
  return buf;
}


int main(){
  umask(0000);

  int arr[10];
  int i;
  printf("Generating random numbers... \n");
  for (i = 0; i < 10; i++) {
    arr[i] = rando();
    printf("arr[%d]: %d\n", i, arr[i]);
  }
  printf("\n");

  printf("Writing to rand...\n\n");
  int fd = open("rand", O_CREAT | O_RDWR, 0666);
  int n = write(fd,arr,40);
  close(fd);

  printf("Reading rand into arr2...\n\n");
  int fd2 = open("rand", O_RDONLY);
  int arr2[10];
  read(fd2, arr2, 40);
  close(fd2);
  
  printf("Verifying values...\n");
  for (i = 0; i < 10; i++)
    printf("arr2[%d]: %d\n", i, arr2[i]);
 
  return 0;
}
