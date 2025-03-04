#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "matricula.h" //biblioteca do programa principal (contem estruturas)
#include "libstack.h" // biblioteca do programa da pilha (funçoes que manipulam pilhas)
#include "funcoes.h" // biblioteca das funções do programa principal

int main()
{
  int o; // menu
  int i,j, k; // contadores
  int t; //variavel de teste
  struct aluno *alu; //estrutura principal
  int n_disc=0;
  //char **disc; tentativa de fazer uma matriz para armazenar as disciplinas
  FILE *arq1;

  // alocação de estruturas
  alu = calloc(1,sizeof(struct aluno));
  o = 0;
  k = 0; //contador principal (quantidade de alunos)
  while (o != 8)
    {
      printf("o que gostaria de fazer?\n");
      printf("1-Inserir um aluno\n");
      printf("2-Inserir uma matricula\n");
      printf("3-Alterar notas\n");
      printf("4-Remover um aluno\n");
      printf("5-Remover uma matricula\n");
      printf("6-Consultar lista por disciplina\n");
      printf("7-Consultar lista por aluno e salvar em arquivo 'matricula.dat'\n");
      printf("8-Terminar o programa\n");
      scanf("%d",&o);
     
      if (o == 1)
	{
	  alu = inserealuno(alu,k); 
	  k++;
	}
      if (o == 2)
	{
	  inseremat(alu,k); 
	  /*i = 0;       função para organizar disciplinas (nao funciona)
	  n_disc++;
	  while (i<n_disc)
	    {
	      if (strcmp(alu[k-1].mat[alu[k-1].n_dis-1].dis,disc[i])==0)
		break;
	      else
		i++;
	    }
	  printf("teste\n");
	  printf("%d %d\n",i,n_disc);
	  if (i==n_disc)
	    {
	      strcpy(disc[n_disc-1],alu[k-1].mat[alu[k-1].n_dis-1].dis);
	      printf("teste2\n");
	      disc = realloc (disc,(n_disc)*sizeof(char *));
	      printf("teste3\n");
	      printf("%d\n",n_disc);
	      disc[n_disc] = realloc (disc[n_disc-1], 6*sizeof(char));
	      printf("teste4\n");
	    }
	  else
	  n_disc--;*/
	}
      if (o == 3)
	alteranotas(alu, k); //adiciona ou remove notas usando pilhas (libstack)
      if (o == 4)
	{
	  removealuno(alu,k);
	  k--;
	}
      if (o == 5)
	removemat(alu,k);
      if (o == 6)
	printf("em breve =(\n"); //nao consegui imprimir por disciplinas
	//imprimedisc(alu,k);
      if (o == 7) //impressao por alunos
	{
	  arq1 = fopen ("matricula.dat","w");
	  for (i=0;i<k;i++)
	    {
	      printf("%s - %d: \n",alu[i].nome, alu[i].ID);
	      fprintf(arq1, "%s  --  %d: \n",alu[i].nome, alu[i].ID);
	      for (j=0;j<alu[i].n_dis;j++)
		{
		  printf("**%s - ",alu[i].mat[j].dis);
		  fprintf(arq1, "**%s -- ",alu[i].mat[j].dis);
		  if (alu[i].mat[j].n_notas == 0)
		    {
		      printf ("P1: --,P2: -- ");
		      fprintf(arq1, "P1: --, P2: -- ");
		    }
		  if (alu[i].mat[j].n_notas == 1)
		    {
		      printf("P1: %f,P2: -- ",alu[i].mat[j].P[0]);
		      fprintf(arq1,"P1: %f, P2: -- ",alu[i].mat[j].P[0]);
		    }
		  if (alu[i].mat[j].n_notas == 2)
		    {
		      printf("P1: %f,P2: %f ",alu[i].mat[j].P[0],alu[i].mat[j].P[1]);
		      fprintf(arq1,"P1: %f, P2: %f ",alu[i].mat[j].P[0],alu[i].mat[j].P[1]);
		    }
		  printf("\n");
		  fprintf(arq1,"\n");
		}
	    }
	}
    }
}
