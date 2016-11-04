#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>

int main() {
  
  DIR *dir = opendir("./testdir");
  struct dirent *entry;
  int curtype = 0;
  int totalsize = 0;

  while ((entry = readdir(dir)) != NULL) {
    if (entry->d_type != curtype) {
      if (entry->d_type == 4) {
	printf("Directories:\n");
      } else if (entry->d_type == 8) {
	printf("Files:\n");
      }
      curtype = entry->d_type;
    }
    
    printf("    %s\n", entry->d_name);
    
    if (entry->d_type == 8) {
      struct stat buffer;
      stat(entry->d_name, &buffer);
      totalsize += buffer.st_size;
    }
  }
  printf("Sum of File Sizes: %d Bytes\n", totalsize);
  closedir(dir);
}
