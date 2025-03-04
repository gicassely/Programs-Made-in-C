#include <stdio.h>
#include <math.h>

int main (int argc, char * argv[])
{
	int i; 
	int num =1;
	float pi;
	float Serie=0;

	for(i=0; i<50 ;i++)
	{
		Serie = Serie + (pow(-1, i) / (pow(num, 3)));
		num = (num + 2);
	}
	
	Serie = Serie * 32;
	pi = cbrt(Serie);
	printf("%f\n", pi);
}