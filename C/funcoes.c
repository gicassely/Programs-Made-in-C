#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "libstack.h"
#include "matricula.h"
#include "funcoes.h"


struct aluno *inserealuno (struct aluno *alu,int k)
{
  int id;
  char c;
  int i;
  int t=0;
  
  i = 0;
  alu[k].nome = calloc(1,sizeof(char));
  printf("digite o nome do aluno que deseja inserir:  ");
  getchar();
  c = getchar(); //nome armazenado totalmente por alocação de memória
  while(c != '\n')
    {
      alu[k].nome[i] = c;
      i++;
      alu[k].nome = realloc (alu[k].nome, (i+1)*sizeof(char));
      c=getchar();
    }
  while (t == 0)
    {
      printf("digite o ID do aluno que deseja inserir:  ");
      scanf("%d",&id);
      while ((id <= 1) || (id >= 100000))
	{
	  printf("id deve ser maior que 1 e menor que 100000:  ");
	  scanf("%d",&id);
	}
      for (i=0;i<k;i++)
	if (alu[i].ID == id)
	  t++;
      if (t > 0)
	{
	  printf("ID ja cadastrado, por favor escolha outro\n");
	  t = 0;
	}
      else
	t++;
    }
  alu[k].ID = id;
  alu[k].mat = calloc (1, sizeof(struct matricula));
  alu[k].n_dis = 0;
  alu = realloc (alu, (k+2)*sizeof(struct aluno));
  return alu;
};

struct aluno *inseremat (struct aluno *alu, int k)
{
  int i=0, j=0, t=0; //testes de saída de laço
  int id;
  char teste[6];
  
  printf("digite o id do aluno que deseja matricular:  \n");
  scanf("%d",&id);
  while((i < k) && (t == 0))
    {
      if(id == alu[i].ID)
	t=1;
      else
	i++;
    }
  if (t == 0)
    printf("aluno nao encontrado\n");
  else
    {
      alu[i].n_dis++;
      alu[i].mat = realloc (alu[i].mat,(alu[i].n_dis+1)*sizeof(struct matricula));
      printf("digite o codigo da matricula que deseja matricular o aluno: \n");
      getchar();
      gets (alu[i].mat[alu[i].n_dis-1].dis);
      while (j<alu[i].n_dis)
	{
	  if(strcmp(teste,alu[i].mat[j].dis)==0)
	    break;
	  else
	    j++;
	}
      if (j==alu[i].n_dis)
	{
	  alu[i].mat[alu[i].n_dis-1].n_notas = 0;
	  alu[i].mat[alu[i].n_dis-1].P = calloc (1,sizeof(float));
	  printf("aluno matriculado com sucesso!\n");
	}
      else
	printf("aluno ja matriculado nesta disciplina\n");
    }
};
int alteranotas (struct aluno *alu, int k)
{
  int id;
  int i, j;
  int t=1;
  int m=0,n=0,o=0;
  char dis[5];
  
  while (n!=2)
    {
      printf("o que deseja fazer?\n");
      printf("1-Digitar ID de aluno que deseja mudar a nota\n");
      printf("2-Voltar ao menu anterior\n");
      scanf("%d",&n);
      if (n == 1)
	{
	  printf("digite o ID desejado\n");
	  scanf("%d",&id);
	  i = 0;
	  
	  while ((i<k) && (t==1))
	    {
	      if (alu[i].ID == id)
		t = 0;
	      else
		i++;
	    }
	  t = 1;
	  if (i == k)
	    printf("ID nao encontrado\n");
	  else
	    {
	      for (j=0;j<alu[i].n_dis;j++)
		{
		  printf("%s",alu[i].mat[j].dis);
		  printf("  P1: ");
		  if (alu[i].mat[j].P[0])
		    printf("%f, ",alu[i].mat[j].P[0]);
		  else
		    printf("--, ");
		  printf("P2:");
		  if (alu[i].mat[j].P[1])
		    printf("%f, ",alu[i].mat[j].P[1]);
		  else
		    printf("--, ");
		  printf("\n");
		}
	      while (m!=2)
		{
		  printf("o que deseja fazer?\n");
		  printf("1 - digitar a disciplina que deseja alterar notas\n");
		  printf("2 - Voltar ao menu anterior / procurar por outro aluno\n");
		  scanf("%d",&m);
		  if (m == 1)
		    {
		      printf("digite a disciplina desejada: \n");
		      getchar();
		      gets(dis);
		      j =0;
		      t =0;
		      while ((j<alu[i].n_dis) && (t==0))
			{
			  if (strcmp(alu[i].mat[j].dis,dis)==0)
			    t=1;
			  else
			    j++;
			}
		      if (j == alu[i].n_dis)
			printf("disciplina nao encontrada!!\n");
		      else
			{
			  while (o!=4)
			    {
			      printf("o que deseja fazer?\n");
			      printf("1-inserir uma nota\n");
			      printf("2-remover uma nota\n");
			      printf("3-mostrar notas\n");
			      printf("4-Voltar ao menu anterior\n");
			      scanf("%d",&o);
			      
			      if (o == 1)
				{
				  inserepilha(alu[i].mat[j].P,alu[i].mat[j].n_notas);
				  alu[i].mat[j].n_notas++;
				}
			      if (o == 2)
				if (vaziapilha(alu[i].mat[j].n_notas)== 1)
				  printf("a pilha esta vazia!!\n");
				else
				  {
				    removepilha(alu[i].mat[j].P,alu[i].mat[j].n_notas);
				    alu[i].mat[j].n_notas--;
				  }
			      if (o == 3)
				{
				  printf("%s - ",alu[i].nome);
				  printf("%s - ",alu[i].mat[j].dis);
				  if (alu[i].mat[j].n_notas == 0)
				    printf ("P1: --,P2: -- ");
				  if (alu[i].mat[j].n_notas == 1)
				    printf("P1: %f,P2: -- ",alu[i].mat[j].P[0]);
				  if (alu[i].mat[j].n_notas == 2)
				    printf("P1: %f,P2: %f ",alu[i].mat[j].P[0],alu[i].mat[j].P[1]);
				  printf("\n");
				}
			    }
			  o = 0;
			}
		    }
		}
	      m =0;
	    }
	}
    }
  n =0;
};

int removealuno(struct aluno *alu, int k)
{
  int id;
  int i=0;
  int t=1;

  if (k > 0)
    {
      printf("digite o id do aluno que deseja remover:\n");
      scanf("%d",&id);
      
      while ((i<k) && (t==1))
	if (id == alu[i].ID)
	  t=0;
	else
	  i++;
      if (i==k)
	printf("aluno nao encontrado\n");
      else
	{
	  if (alu[i].n_dis > 0)
	    printf("aluno matriculado, nao pode ser removido\n");
	  else
	    {
	      printf("teste\n");
	      alu[i] = alu[k-1];
	      if (k == 1)
		alu = calloc(1,sizeof(struct aluno));
	      else
		alu = realloc(alu,(k-1)*sizeof(struct aluno));
	    }
	}
    }
  else
    printf("nao ha alunos matriculados\n");
};

int removemat (struct aluno *alu, int k)
{
  int id;
  int i=0, j;
  int t=1;
  char dis[5];
  int m,o;
  
  while (m != 3)
    {
      printf("1-digitar o ID do aluno que deseja matricular\n");
      printf("2-Voltar ao menu principal\n");
      scanf("%d",&o);
      if (o == 2)
	m=3;
      if (o == 1)
	{
	  printf("digite o ID do aluno que deseja desmatricular: ");
	  scanf("%d",&id);
	  while ((i<k) && (t==1))
	    if (id == alu[i].ID)
	      t=0;
	    else
	      i++;
	  if (i==k)
	    printf("aluno nao encontrado\n");
	  else	
	    for (j=0;j<alu[i].n_dis;j++)
	      {
		printf("%s",alu[i].mat[j].dis);
		printf("  P1: ");
		if (alu[i].mat[j].P[0])
		  printf("%f, ",alu[i].mat[j].P[0]);
		else
		  printf("--, ");
		printf("P2:");
		if (alu[i].mat[j].P[1])
		  printf("%f, ",alu[i].mat[j].P[1]);
		else
		  printf("--, ");
		printf("\n");
	      }
	  if (alu[i].n_dis == 0)
	    printf("aluno nao esta matriculado\n");
	  else
	    {
	      printf("o que deseja fazer?\n");
	      printf("1- Remover todas as matriculas do aluno\n");
	      printf("2- Digitar uma disciplina a ser removida\n");
	      printf("3- Voltar ao menu principal\n");
	      scanf("%d",&m);
	      
	      if (m == 1)
		{
		  alu[i].mat = calloc (1,sizeof(struct matricula));
		  alu[i].n_dis = 0;
		  m = 3;
		}
	      if (m == 2)
		{
		  printf("qual disciplina deseja remover?\n");
		  scanf("%s",dis);
		  t = 0;
		  j = 0;
		  while ((j<alu[i].n_dis) && (t=0))
		    {
		      if (strcmp(alu[i].mat[j].dis,dis)==0)
			t=1;
		      else
			j++;
		    }
		  if (j == alu[i].n_dis)
		    printf("disciplina nao encontrada!!\n");
		  else
		    {
		      if (alu[i].n_dis == 1)
			{
			  alu[i].mat = calloc(1,sizeof(struct matricula));
			  alu[i].n_dis = 0;
			}
		      else
			{
			  alu[i].mat[j] = alu[i].mat[alu[i].n_dis-1];
			  alu[i].mat = realloc (alu[i].mat,(alu[i].n_dis)*sizeof(struct matricula));
			  alu[i].n_dis--;
			}
		    }
		  m = 3;
		}
	    }
	}      
    }
};
