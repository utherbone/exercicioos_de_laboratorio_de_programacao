//3. Dada a seguinte função:
//Informar qual o valor retornado por F1 para as seguintes chamadas e mostre a ordem de empilhamento e desempilhamento das chamadas para cada item:
//a) F1(4) = 12		b) F1(10) = 37	c) F1(12) =  47

#include <stdio.h>
int F1 (int);
int main()
{
	printf("%d \n", F1(12));
	return 0;
}

int F1 (int x){
	int teste;
	int teste_2;
    if (x < 5) {
		teste_2 = (3*x);
		printf("%d \n 3 * %d \n",x , x);
       	return teste_2;
	}
    else {
		teste = (2*F1(x-5)+7);
	  	printf("%d \n 2 * ( %d - %d) + 7 \n", x, x, 5);
	   	return teste;
	}
}
/*Resolução
        a) F1(4) = 12				 b)F1(10) = 37				   C)F1(12) = 47


		chamada		retorno	  |		chamada 	retorno	     |		chamada		retorno
		1- F1(4)	  3*4     |		2- F1(5)	  3*5	     |      3- f1(2)      3*2
						      |     1- F1(10)     2*15+7     |	    2- f1(7)	  2*6+7
							  |	     		    	   	     |      1- F1(12)	  2*20+7
*/