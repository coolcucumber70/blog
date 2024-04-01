// file2.c


#include <stdio.h>
extern int myStaticVariable;
int main() {
    printf("myStaticVariable in file2.c: %d\n", myStaticVariable);
    return 0;
}
