/******************************************************************************
programbased on files
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *filePointer;  
    char filename[] = "example.txt";
    char data[] = "Hello, World!\nThis is a test file.\n";
    filePointer = fopen(filename, "w");
    if (filePointer == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return 1;
    }

    
    fprintf(filePointer, "%s", data);
    fclose(filePointer);
    filePointer = fopen(filename, "r");
    if (filePointer == NULL) {
        fprintf(stderr, "Error opening file for reading.\n");
        return 1;
    }

    char buffer[100];  
    printf("File contents:\n");
    while (fgets(buffer, sizeof(buffer), filePointer) != NULL) {
        printf("%s", buffer);
    }
    fclose(filePointer);

    return 0;
}
