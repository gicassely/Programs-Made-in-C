#include <stdio.h>

	int verifica(int a, int b, int c)
	{
		if ((a + b > c) && (a + c > b) && (b + c > a))
		return 1;
	else 
		return 0;
	}

	int main()
	{
		int a,b,c;

		printf("Entre com os tres lados do triangulo:");
		scanf("%d,%d,%d", &a, &b, &c);


	
		if (verifica(a,b,c) == 1) 
			{
				if (((a * a) == ((b * b) + (c * c)) || ((b * b) == ((a * a) + (c * c)))   || ((c * c)  == ((a * a) + (b * b)))))
					printf("O triangulo e Retangulo!");
				else
					if (((a * a) > ((b * b) + (c * c)) || ((b * b) > ((a * a) + (c * c)))   || ((c * c)  > ((a * a) + (b * b)))))
						printf("O triangulo e Obtusangulo!");
					else
						if (((a * a) < ((b * b) + (c * c)) || ((b * b) < ((a * a) + (c * c)))   || ((c * c)  < ((a * a) + (b * b))))                        )
							printf("O triangulo e Acutangulo!");
			}
		else
			printf("O triangulo e Invalido!");		

	}