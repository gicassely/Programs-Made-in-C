#include <stdio.h>



	int main ()
	{

		int pratos, sobremesa, bebida;
		int kcal=0;


		printf("Entre com os valores estabelecido pelo prato, sobremesa ou bebida desejado:\n (1-Vegetariano 2-Peixe 3-Frango 4-Carne)\n (5-Abacaxi 6-Sorvete diet 7-Mouse diet 8-Mouse chocolate)\n (9-Chá 10-Suco de laranja 11-Suco de melão 12-Refrigerante diet)\n");
		scanf("%d,%d,%d", &pratos, &sobremesa, &bebida);
		if (pratos==1)
			kcal= kcal+ 180;
		else
			if(pratos==2)
				kcal= kcal+ 230;
			else
				if(pratos==3)
					kcal= kcal+ 250;
				else
					if(pratos==4)
					kcal= kcal+ 350;
				else
					kcal= kcal+ 0;

		if (sobremesa==5)
			kcal= kcal+ 75;
		else
			if(sobremesa==6)
				kcal= kcal+ 110;
			else
				if(sobremesa==7)
					kcal= kcal+ 170;
				else
					if(sobremesa==8)
						kcal= kcal+ 200;
					else
						kcal=kcal+ 0;
		if (bebida==9)
			kcal= kcal+ 20;
		else
			if(bebida==10)
				kcal= kcal+ 70;
			else
				if(bebida==11)
					kcal= kcal +100;
				else
					if(bebida==12)
						kcal= kcal+ 65;
					else
						kcal= kcal+ 0;
		printf("A quantidade de calorias da refeição é de: %d\n", kcal);


	}


