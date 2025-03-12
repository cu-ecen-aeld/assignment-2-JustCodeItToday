#include <stdio.h>
#include <syslog.h>

int main(int argc, char** argv)
{
    openlog(NULL, 0, LOG_USER);

    if (argc < 3) 
    {
        syslog(LOG_ERR, "Input arguments missing!");

        return 1;
    }

    const char* writefile = argv[1];
    const char* writestr = argv[2];

    syslog(LOG_DEBUG, "Writing %s to %s\n", writestr, writefile);
    
    FILE* fileptr = fopen(writefile, "w");
    if (fileptr == NULL)
    {
        syslog(LOG_ERR, "Failed to open file %s\n", writefile);
        return 1;
    }

    int rc = fputs(writestr, fileptr);
    if (rc == EOF)
    {
        syslog(LOG_ERR, "Failed to write string %s to file %s\n", writestr, writefile);
        return 1;
    }

    return 0;
}