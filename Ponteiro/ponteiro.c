#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void* (*alocar_ptr)(size_t);
typedef void (*free_ptr)(void*);
typedef void* (*realloc_ptr)(void*, size_t);
free_ptr liberar = free;
alocar_ptr alocar = malloc;
realloc_ptr realocar = realloc;



void inserir(); //inserir 10 valores
void duplicar(); //duplicar elementos do vetor
void imprimir(); //imprimir valores do vetor
void sair(); // sair do programa e liberar memória

int main(){
    
    int *p;
    int tamanho = 10;
    int *t;
    t = &tamanho;
    int x = *t;
    p = alocar(sizeof(int) * x);

    char buffer[10];
    char escolha;

    do {
        //printf("\33[H\33[2J"); //limpar tela

        printf("Digite a opcao: \ni -> Inserir;\nd -> Duplicar;\np -> "
        "Imprimir;\ns -> Sair \n");

        //Remove caractere de formatação
        buffer[strcspn(buffer, "\n")] = '\0';
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%c", &escolha);
        switch(escolha){
            case 'i': inserir(p);
            break ;

            case 'd': duplicar(p, t);
            break;

            case 'p': imprimir(p, t);
            break;

            case 's': sair(p);
            break;

            default: printf("Caractere ou operador nao aceito, tente novamente!\n");
            break;
        }

    }while(1); 

    return 0;

}


void inserir(int *p){
    char buffer[10];
    for (int a = 0; a < 10; a++){

        printf("Digite um numero para guardar na posicao %d do vetor\n", a);

        buffer[strcspn(buffer, "\n")] = '\0';
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &*(p+a));
    }

}

void duplicar(int *p, int *t){
    p = realocar(p, sizeof(int) * 20);
    for (int a = 10; a < 20; a++){
        int x = -10+a;
        *(p+a) = *(p+x);
        printf("valor da posicao %d : %d \n",a, *(p+a));
    }
    *t = 20;
}

void imprimir(int *p, int *t){
    printf("%d \n", *t);
    if (*t == 10){
        for (int a = 0; a < 10; a++){
            printf("valor da posicao %d : %d \n",a, *(p+a));
        }
    }else if (*t == 20){
        for (int a = 0; a < 20; a++){
            printf("valor da posicao %d : %d \n",a, *(p+a));
        }
    } 
}

void sair(int *p){
    liberar(p);
    exit(0);
}