#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h> 
#include <time.h>

int main (void)
{
    DIR *directory;
    struct dirent *file;
    struct stat info;
    int entries = 0 ;
    const char *path = "/home/rinadanwar/practice";

    // entering the directory
    directory = opendir(path);

    if ( directory == NULL )
    {
        puts("the directory couldn't be accessed or does not exist");
        return(2);
    }


    printf("No   type         name              size           TimeStamp \n\n");

    while((file=readdir(directory))!= NULL)
    {

        entries++;

              //  problem : the stat is not working properly 

        if (stat(path, &info) == -1){
            printf("can't find %s\n", file->d_name);
            perror("ERROR");
           }
        // show the number of the entry
        printf("%2d  ",entries);

        // determine if file or directory
        if(S_ISDIR(info.st_mode))
            printf("Dir ");
        else

            printf("File");

        // display the name of the file
        printf("%20s",file->d_name);

        // display the size of the file
        printf("%10ld",info.st_size);

        // show the last modified time
        if(!(S_ISDIR(info.st_mode)))
            printf("%30s\n",ctime(&info.st_mtime));
        else puts("\n");

    }

    return(0);
}
