#include <stdio.h>
#include <unistd.h>
#include <dirent.h>

int main() {
  char currentDirectoryString[4096];
  DIR *pDir;
  struct dirent *pDirent;
  getcwd(currentDirectoryString,4096);
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



  printf("\n");
  printf("THE END GOODBYE\n");
  sleep(0xFFFFFFFF);
  return 0;
}
