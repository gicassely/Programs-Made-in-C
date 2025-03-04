/*(mescla)   Um programa recebe pela linha de comando nome de 2 arquivos de texto, e 3 pares de inteiros representando coordenadas (linha,caracter) em um arquivo de texto (ASCII). Exemplo:
mescla texto-01 texto-02 19 21 3 12 8 46
O programa deve copiar um bloco de texto do 2o arquivo no 1o arquivo, a partir da coordenada indicada no 1o par de inteiros, sobrescrevendo o conteúdo a partir desta posição. O bloco do 2o arquivo é definido pelos dois pares de coordenadas restantes. Após copiar o bloco, espaços em branco devem ser preenchidos ao redor. Finalmente, o resultado deve ser salvo em um 3o arquivo, cujo nome é arbitrário, sendo que uma mensagem final do programa deve indicar este nome.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc,char *argv[])
{
  FILE *arq1, *arq2, *arq3;
  int l1, c1;
  int l2, c2;
  int l3, c3;
  int l,c, caux;
  int cm, lm, lM, cdif;
  int i;
  char ch, ch1;

  l = 1;
  c = 0;
  caux = 0;
  if (argc < 9)
    {
      printf("coordenadas invalidas\n");
      return;
    }
  arq1 = fopen(argv[1], "r");
  if (arq1 == NULL)
    {
      printf("erro na abertura de %s\n",argv[1]);
      return;
    }
  else
    printf("arquivo %s aberto com sucesso\n",argv[1]);
  arq2 = fopen(argv[2], "r");
  if (arq2 == NULL)
    {
      printf("erro na abertura de %s\n",argv[2]);
      return;
    }
  else
      printf("arquivo %s aberto com sucesso\n",argv[2]);
  arq3 = fopen("teste3.txt", "w");
  if (arq3 == NULL)
    {
      printf("erro na abertura de teste3.txt\n");
      return;
    }
  else
      printf("teste3.txt aberto com sucesso\n");
  
  l1 = atoi(argv[3]);
  c1 = atoi(argv[4]);
  l2 = atoi(argv[5]);
  c2 = atoi(argv[6]);
  l3 = atoi(argv[7]);
  c3 = atoi(argv[8]);

  if (l2 < l3)
    {
      lm = l2;
      lM = l3;
    }
  else
    {
      lm = l3;
      lM = l2;
    }
  if (c2 < c3)
    {
      cm = c2;
      cdif = c3 - c2;
    }
  else
    {
      cdif = c2 - c3;
      cm = c3;
    }
      
  
  while (c != c1)
    {
      ch = fgetc(arq1);
      if (ch == '\n')
	l++;
      if (l >= l1)
	c++;
      if (l1-1 == l)
	caux++;
      if ((l1-1 == l) && (caux >= c1) && (caux <= cdif+c1+2))
	{
	  fprintf(arq3," ");
	}
      else
	{
	  if ((l == l1) && (c == c1))
	    fprintf(arq3," ");
	  else
	    fputc (ch,arq3);
	}
    }
  caux = c+1;
  c = 0;
  l = 1;
  while (l < lm)
    {
      ch = fgetc(arq2);
      if (ch == '\n')
	l++; 
    }
  while (l <= lM)
    {
      ch1 = fgetc(arq1);
      ch = fgetc(arq2);
      c++;
      if (caux != 0)
	{
	  for(i=0;i<cm-2;i++)
	    ch = fgetc(arq2);
	  for(i=0;i<cdif+1;i++)
	    {
	      ch1 = fgetc(arq1);
	      ch = fgetc(arq2);
	      fputc(ch,arq3);
	    }
	  fprintf(arq3," ");
	  while (ch1 != '\n')
	    {
	      ch1 = fgetc(arq1);
	      fputc(ch1,arq3);
	    }
	  caux=0;
	}
      else
	{
	  if (c == c1-1)
	    fprintf(arq3," ");
	  if ((c >= c1-1) && (c <= cdif+cm))
	    {
	      while (ch != '\n')
		ch = fgetc(arq2);
	      c=0;
	      while (caux <= cm-2)
		{
		  ch = fgetc(arq2);
		  caux++;
		  c++;
		} 
	      for (i=0;i<cdif+1;i++)
		{
		  ch = fgetc(arq2);
		  ch1 = fgetc(arq1);
		  fputc(ch,arq3);
		  c++;
		}
	      ch1 = fgetc(arq1);
	      fprintf(arq3," ");
	    }
	  else
	    fputc(ch1,arq3);
	}
      if (ch1 == '\n')
	{
	  c = 0;
	  l++;
	  caux = 0;
	}
      caux = 0;
    }
  c = 0;
  while (l == lM+1)
    {
      c++;
      ch1 = fgetc(arq1);
      if ((c <= c1-2) || ( c >= cdif+c1+2))
	fputc(ch1,arq3);
      else
	fprintf(arq3," ");
      if (ch1 == '\n')
	l++;
    }
  fclose (arq2);
  while ((ch=fgetc(arq1)) != EOF)
    fputc (ch,arq3);
  printf("copiado para o arquivo 'teste3.txt' com sucesso!\n");
  fclose (arq1);
  fclose (arq3);
}
