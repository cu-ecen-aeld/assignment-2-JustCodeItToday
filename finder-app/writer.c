#include <stdio.h>

int main(int argc, char** argv)
{
    if (argc < 3) 
    {
        printf("Input arguments missing!\n");
        return 1;
    }

    const char* writefile = argv[1];
    const char* writestr = argv[2];
    printf("writefile: %s, writestr: %s\n", writefile, writestr);

    FILE* fileptr = fopen(writefile, "w");
    if (fileptr == NULL)
    {
        printf("Failed to open file %s", writefile);
        return 1;
    }

    int rc = fputs(writestr, fileptr);
    if (rc == EOF)
    {
        printf("Failed to write string %s to file %s\n", writestr, writefile);
        return 1;
    }

    printf("String %s successfully written to file %s\n", writestr, writefile);

    return 0;
}