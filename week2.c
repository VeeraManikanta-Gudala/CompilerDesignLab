#include<stdio.h>
#include<string.h>

int main(int argc, char *argv[])
{

    char* filename = argv[1];
    FILE* file;
    char search[100], line[50];
    printf("Enter the word to be searched: ");
    scanf("%s", search);
    while(getchar() != '\n');

    file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    int found = 0;
    while(fgets(line, sizeof(line), file) != NULL)
    {
        if(strstr(line, search) != NULL)
        {
            printf("'%s' found in the line: %s", search, line);
            found = 1;
        }
    }

    if(!found)
        printf("'%s' not found in the file.\n", search);

    fclose(file);
    return 0;
}
