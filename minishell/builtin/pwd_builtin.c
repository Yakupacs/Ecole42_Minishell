#include "builtin.h"

void    pwd(void)
{
    char    *path;

    path = getwd(NULL);
    printf("%s\n", path);
    free(path);
}