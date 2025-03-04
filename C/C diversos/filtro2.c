#include "stdio.h"
int main(int argc, char const *argv[])
{
int matriz[1000][1000], max, col, lin, i, j, limiar;
char px[3], com, com2;
scanf("%s", px);
scanf("%d", &col);
scanf("%d", &lin);
scanf("%d", &max);
limiar= 7;
for(i=0 ; i < lin ; i++) {
	for(j=0 ; j < col ; j++) {
		scanf("%d", &matriz[i][j]);
	}
}	
printf("%s\n", px );
printf("%d\n", col );
printf("%d\n", lin );
printf("%d\n", max );
for(i=0 ; i < lin ; i++) {
	for(j=0 ; j < col ; j++){
		if ((max - matriz[i][j]) < limiar){
			printf("%d  ", (matriz[i][j] - matriz[i][j]));
		} 
		else {
		printf("%d ", (max);
	}
	}
	printf("\n");
}
}
}