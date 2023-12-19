//2. Complete o empilhamento e desempilhamento das chamadas nos comentários a seguir
#include <stdio.h>
int rec1(int a);

int main (void){
	
	printf(" %d \n", rec1(0));
   	return 0;
}

int rec1(int a){
    if (a == 0)
       return 1;
    else {
		return (a*rec1(a-1));
   }
}


/* Resolução

       Empilha			  Desempilha
5	  0*rec1(0)		= 0   0*(-1)=0 [CASO BASE = 1]
4	  1*rec1(1)		= 1	1*1
3	  2*rec1(2)		= 2	2*1 
2    3*rec1(3)	   = 6   3*2
1    4*rec1(4)		= 24  4*6 			

*/