#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>

int main()
{
    struct stat dummy;

    if (stat("makefile", &dummy) == 0)
    {
        printf("file size: %d\n", dummy.st_size);
        printf("file mode: %d\n", dummy.st_mode);
        printf("time of last access: %s\n", ctime(&dummy.st_atime));
        int fileSize = dummy.st_size;
        int fileSizeGB = fileSize / 1073741824;
        fileSize %= 1073741824;
        int fileSizeMB = fileSize / 1048576;
        fileSize %= 1048576;
        int fileSizeKB = fileSize / 1024;
        fileSize %= 1024;
        int fileSizeB = fileSize;
        char buffer[50];
        sprintf(buffer, "human-readable file size: %d GB, %d MB, %d KB, %d B\n", fileSizeGB, fileSizeMB, fileSizeKB, fileSizeB);
        printf("%s\n", buffer);
        printf("file permissions in ls -l form: ");
        printf((dummy.st_mode & S_IRUSR) ? "r" : "-");
        printf((dummy.st_mode & S_IWUSR) ? "w" : "-");
        printf((dummy.st_mode & S_IXUSR) ? "x" : "-");
        printf((dummy.st_mode & S_IRGRP) ? "r" : "-");
        printf((dummy.st_mode & S_IWGRP) ? "w" : "-");
        printf((dummy.st_mode & S_IXGRP) ? "x" : "-");
        printf((dummy.st_mode & S_IROTH) ? "r" : "-");
        printf((dummy.st_mode & S_IWOTH) ? "w" : "-");
        printf((dummy.st_mode & S_IXOTH) ? "x" : "-");
    }

    return 0;
}