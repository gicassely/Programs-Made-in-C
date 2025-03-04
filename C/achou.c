#include <stdio.h>
#include "dicionario.h"
#include <ctype.h>

#define MAXPALAVRAS 275502 // Palavras totais do dicionario
#define MAXLETRAS 25


unsigned char dicionario[MAXPALAVRAS][MAXLETRAS];

int main ()
{


// Declaracao de variaveis 

unsigned char palavra[50];
unsigned char save [50];
int letra;
int tamanho;
int i;
int ja_achou;


Carrega_dicionario ("/usr/share/dict/brazilian");
    
  



letra = getchar ();

  while (letra != EOF)
	{
		ja_achou = 0;
    tamanho = 0;

    while ((letter(letra)==0) && (letra != EOF))
    {
      putchar (letra);
     letra = getchar ();
    }

		while ((letter(letra)==1) && (letra != EOF))
		    {
			    palavra[tamanho] = letra;
          save[tamanho] = palavra[tamanho];
			    tamanho++;
				  letra = getchar();
			   } 
					

			    if ( tamanho != 0)
				  	{

                
               palavra[tamanho] = '\0';
               save[tamanho] ='\0';
               if (((palavra[0] >=65) && (palavra[0] <=90)) || ((palavra[0] >= 192) && (palavra[0] <= 220))) // Se Primeira letra da palavra eh maiuscula 
                  {
                    for (i=1;i<tamanho;++i)
                      palavra[i] = Deixa_minuscula (palavra[i]); // Deixamos todas as letras restantes minusculas , para procurar caso um nome de cidade por exemplo seja dado em Caps look 
                       
                    if (verifica_palavra (palavra,tamanho)) // Se achou a palavra no dicionario eh acionada uma variavel true or false
                        ja_achou =1;
                  }
              else 
              {
                for (i=0;i<tamanho;++i) // Caso a primeira letra seja minuscula , deixamos todas as letras minusculas Ex: "aBOBRINHA" ="abobrinha"
                  palavra[i] = Deixa_minuscula (palavra[i]);
               
                    if (verifica_palavra (palavra,tamanho)) // Se achou a palavra no dicionario eh acionada uma variavel true or false
                        ja_achou=1;

              }
              if (ja_achou == 0);  // Caso nao tenha achado a palavra no dicionario temos outras possibilidades que devem ser analizadas 
                {
                 if (((palavra[0] >=65) && (palavra[0] <=90)) || ((palavra[0] >= 192) && (palavra[0] <= 220))) // Primeira letra maiuscula 
                    {
                      palavra[0]= Deixa_minuscula (palavra[0]); // Podemos ter uma palavra com a primeira letra maiuscula com todos os caracteres minusculos no dicionario , logo deixamos esse primeiro caractere minusculo 
                      if (verifica_palavra (palavra,tamanho)) 
                         ja_achou=1;
                    }
                    else
                    {
                      // Caso a palavra seja inteiramente minuscula ela ainda pode existir com a primeira letra maiuscula 
                     palavra[0] = Deixa_maiuscula (palavra[0]); 
                      if (verifica_palavra (palavra,tamanho))
                             ja_achou=1;

                    }

                }
               if (ja_achou == 1) // Imprime de acordo com a existencia ou nao da palavra no dicionario
                 printf ("%s", save);
              else
              {
                if (tamanho > 1)
                  printf ("[%s]", save);
                else 
                  printf("%s",save);
              }
           
            }  

   
			  printf("%c", letra);
            

				letra = getchar ();

				   
	       }
return 0;       
}













