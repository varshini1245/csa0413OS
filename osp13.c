#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 20

struct file {
    char name[MAX_FILENAME_LENGTH];
    int size;
};

struct directory {
    char name[MAX_FILENAME_LENGTH];
    struct file files[MAX_FILES];
    int num_files;
};

void add_file(struct directory *dir, char *filename, int size) {
    if (dir->num_files >= MAX_FILES) {
        printf("Directory is full.\n");
        return;
    }

  
    for (int i = 0; i < dir->num_files; i++) {
        if (strcmp(dir->files[i].name, filename) == 0) {
            printf("File already exists in directory.\n");
            return;
        }
    }

 
    struct file new_file;
    strncpy(new_file.name, filename, MAX_FILENAME_LENGTH);
    new_file.size = size;
    dir->files[dir->num_files] = new_file;
    dir->num_files++;

    printf("File '%s' added to directory '%s'.\n", filename, dir->name);
}

int main() {
  
    struct directory cse_directory;
    strncpy(cse_directory.name, "CSE", MAX_FILENAME_LENGTH);
    cse_directory.num_files = 0;

    add_file(&cse_directory, "A", 100);
    add_file(&cse_directory, "B", 200);
    add_file(&cse_directory, "C", 300);

    return 0;
}
