#include <stdio.h>
#include <stdlib.h>
struct _sqlca {
    char sqlcaid[8];
    long sqlcabc;
    long sqlcode;
    struct {
        int sqlerrml;
        char sqlerrmc[256];
    } sqlerrm;
    char sqlerrp[8];
    long sqlerrd[6];
    char sqlwarn[8];
    char sqlext[8];
};
int main()
{
    struct _sqlca temp;
    printf("%d \n",sizeof(temp));
}
