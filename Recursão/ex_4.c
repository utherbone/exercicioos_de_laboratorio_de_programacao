//4. Dada a seguinte função:
//Informar qual o valor retornado por F2 para as seguintes chamadas:
//a) F2(2, 7) = -3		b) F2(5, 3) = 0		c) F2(15, 3) = 15

#include<stdio.h>
int F2 (int, int);

int F2 (int x, int y){
    if (x < y) {
       return (-3);
    }else{
       return (F2(x-y, y+3)+y);
    }
}

int main()
{
	printf("%d \n", F2(5,3));
	return 0;
}
/*                                Resolução

a) F2(2,7) = -3				b) F2(5,3) = 0				     C) F2(15,3) = 15

chamada		retorno	   |	 chamada 		retorno	     |	 chamada		retorno
F2(2,7)     -3  	      |     F2(5,3)     -3+3=0        |   4- F2(6,12)     -3
                        |                               |   3- F2(9,9)      -3+9=6
                 	      |                               |   2- F2(12,6)     6+6=12
					         |			              	        |   1- F2(15,3)     12+3=15
*/