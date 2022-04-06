#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>


int main(int argc, char const *argv[])
{
        const char* filename = "data.txt";
    FILE* pf;
    pf = fopen(filename,"r");
    if (!pf)
        exit(EXIT_FAILURE);

    struct stat sb;
    if (stat(filename, &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    char* file_contents = malloc(sb.st_size);
    fread(file_contents, sb.st_size, 1, pf);

    printf("%s\n", file_contents);

    fclose(pf);
    //free(file_contents);
    printf("%s\n", file_contents);

    exit(EXIT_SUCCESS);
    return 0;
}
