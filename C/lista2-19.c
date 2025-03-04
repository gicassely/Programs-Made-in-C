#include <stdio.h>
#include <math.h>
	
	
	int main()
	{
		float f,x;

		printf("Entre com o valor de x:");
		scanf("%f", &x);
		if (x > 4)
			{
				f= (int) (5*x + 3) / sqrt( pow(x,2) - 16);
				printf("O valor de f(x): %f", f);
			}
		else
			printf("X invalido!");
		


		return 0;


	}

	