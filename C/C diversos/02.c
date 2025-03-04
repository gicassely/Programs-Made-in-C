#include <stdio.h>

int main ()

{
    int a;
    short int b;
    long int c;
    float d;
    double e;
    char f;
    unsigned char g;

      a = sizeof(int);
      b = sizeof(short int);
      c = sizeof(long int);
      d = sizeof(float);
      e = sizeof(double);
      f = sizeof(char);
      g = sizeof(unsigned char);
     
      printf("%d\n", a);
      printf("%d\n", b);
      printf("%d\n", c);
      printf("%f\n", d);
      printf("%f\n", e);
      printf("%d\n", f);
      printf("%d\n", g);

}
