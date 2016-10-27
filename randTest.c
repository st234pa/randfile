//Stephanie Yoon, Joel Ye

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

int generateRandInt(){
  
  int fd = open("/dev/random", O_RDONLY);
  if (fd == -1) printf("RandDev File opened incorrectly.");
  
  int randomBytes;

  int err = read(fd, &randomBytes, 4);
  if (err == -1) printf("Random data read incorrectly.");
  
  err = close(fd);
  if (err == -1) printf("RandDev File closed incorrectly.");

  return randomBytes;  

}


int main(){
  
  int n;
  int randNum = 10;
  int arr[randNum];

  printf("Generating random numbers:\n\n");
  
  for (n = 0; n < randNum; n++){
    arr[n] = generateRandInt();
    printf("Random Number: %d\n", arr[n]);
  }

  printf("\n");
  umask(0000);
  
  int fd = open("file", O_CREAT | O_WRONLY, 0644);
  if (fd == -1) printf("File created incorrectly.");
  
  for (n = 0; n < randNum; n++)
    write(fd, arr + n, 4);

  int err = close(fd);
  if (err == -1) printf("File closed incorrectly.");
  
  fd = open("file", O_RDONLY);
  if (fd == -1) printf("File read incorrectly.");
  
  int arrLoad[randNum];
  err = read(fd, arrLoad, 40);
  if (err == -1) printf("File closed incorrectly.");
  
  printf("Reading random numbers:\n\n");

  for (n = 0; n < randNum; n++){
    printf("Random Number: %d\n", arrLoad[n]);
  }
    
  return 0;
}
