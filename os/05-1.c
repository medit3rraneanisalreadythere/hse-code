#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
  int     fd;
  size_t  size;
  char    *info;

  if ((fd = open("myfile", O_RDONLY)) < 0) {
    printf("Can\'t open file\n");
    exit(-1);
  }
  
  size = read(fd, info, 10);

  printf("%s", info);

  if (close(fd) < 0) {
    printf("Can\'t close file\n");
  }

  return 0;
}
