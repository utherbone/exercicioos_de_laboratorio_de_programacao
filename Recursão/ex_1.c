//Exemplo:
// Qual a ordem de chamada da função rec e os respectivos valores passados por ela? Quais serão os valores impressos no vídeo?

#include <stdio.h>
void rec(int);

int main(void) {
   rec(20);
   return 0;
}

void rec(int a){
  int valor;
  valor = a/2;
  if (valor > 0)
  	rec(valor);
  printf(" %d \n", valor);
}
/* Resolução

                             EMPILHAMENTO (chamada)

       1            2            3            4            5            6
  +---------+  +---------+  +---------+  +---------+  +---------+  +---------+
  | rec(40) |  | rec(20) |  | rec(10) |  | rec(40) |  | rec(40) |  | rec(40) |
  +---------+  +---------+  +---------+  +---------+  +---------+  +---------+

                      DESENPILHAMENTO (retorno no printf)

       6            5            4            3            2            1
  +---------+  +---------+  +---------+  +---------+  +---------+  +---------+
  |    0    |  |    1    |  |    2    |  |    5    |  |   10    |  |   20    |
  +---------+  +---------+  +---------+  +---------+  +---------+  +---------+



*/