#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main (void){
    size_t count = 0;
    struct dirent *res;
    struct stat sb;
    const char *path = "/home/rinadanwar/practice";

    if (stat(path, &sb) == 0 && S_ISDIR(sb.st_mode)){
        DIR *folder = opendir ( path );

        if (access ( path, F_OK ) != -1 ){
            if ( folder ){
                while ( ( res = readdir ( folder ) ) ){
                    if ( strcmp( res->d_name, "." ) && strcmp( res->d_name, ".." ) ){
                        printf("%zu) - %s\n", count + 1, res->d_name);
                        count++;
                    }
                }

                closedir ( folder );
            }else{
                perror ( "Could not open the directory" );
                exit( EXIT_FAILURE);
            }
        }

    }

    printf( "\n\tFound %zu Files\n", count );
}
