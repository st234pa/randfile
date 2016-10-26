#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int generateRandInt(){
  int fd = open("/dev/random", O_RDONLY);
  int randomBytes;
  int err = read(fd, &randomBytes, 4);

  //printf("read success: %d\n", err);
  //printf("random data: %d\n", randomBytes);
  close(fd);
  return randomBytes;  

}


int main(){
  int n;
  n = 10;
  int arr[n];
  
  for (n = 0; n < 10; n++){
    //* (arr + n) = 
    arr[n] = generateRandInt();
    printf("random number: %d\n", arr[n]);
    //printf("index %d: %d\n", n, * (arr + n) );
  }
  
  //  int fd = 
//generateRandInt();
  return 0;
}
