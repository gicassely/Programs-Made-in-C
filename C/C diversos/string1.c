#include <stdio.h>
#include <string.h>

int mstrlen(char v[])
{
     int i;
     for (i=0; v[i] != 0; i++) ;
     return i; 
}  

int main()
{   
    char texto[200];
    gets(texto);
    mstrlen(texto [200]);
    printf("%d\n", i);
}
