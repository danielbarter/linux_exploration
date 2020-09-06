#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <fcntl.h>

int printContentsOfCurrentDirectory() {
  char currentDirectoryString[4096];
  DIR *pDir;
  struct dirent *pDirent;
  char *errp;
  errp = getcwd(currentDirectoryString,4096);
  if (errp == NULL) {
    printf("Cannot get current directory");
    return 1;
  }

  printf("\n\n");
  printf("current directory: %s",currentDirectoryString);
  printf("\n\n");
  printf("files:\n");

  pDir = opendir(currentDirectoryString);
  if (pDir == NULL) {
    printf ("Cannot open directory '%s'\n", currentDirectoryString);
    return 1;
  }

  // Process each entry.

  while ((pDirent = readdir(pDir)) != NULL) {
    printf ("%s\n", pDirent->d_name);
  }
  return 0;
}

int main() {

  printContentsOfCurrentDirectory();
  if ( chdir("/dev") != 0) {
    printf("failed to change to /dev\n");
  }
  printContentsOfCurrentDirectory();

  char byte;
  int fd = open("/dev/console",O_RDWR);
  while (1) {
    ssize_t size_read = read(fd, &byte, 1);
    if (byte == 'X')
      break;
    printf("Read byte %c\n", byte);
  }

  printf("\n");
  printf("THE END GOODBYE\n\n\n");
  sleep(0xFFFF);
  return 0;
}
