#include "builtin.h"

void    pwd_builtin(void)
{
    char    *path;

    path = getwd(NULL);
    printf("%s\n", path);
    free(path);
}