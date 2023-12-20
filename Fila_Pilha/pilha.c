#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef void* (*aloque_ptr)(size_t);
typedef void (*libere_ptr)(void*);
typedef void* (*realoque_ptr)(void*, size_t);
libere_ptr libere = free;
aloque_ptr aloque = malloc;
realoque_ptr realoque = realloc;

void empilhar();
void desempilhar();
void imprimir_pilha();
void sair();



int main (){

    char escolha = 0;
    char buffer[10] = {};
    char buffer2[10] = {};
    int x = 0;
    int *p, *position, *nn, n;

    position = &x;
    p = NULL;

    printf("Digite um tamanho maximo para Pilha: ");

    fflush(stdin);
    fgets(buffer2, sizeof(buffer2), stdin);
    buffer2[strcspn(buffer2, "\n")] = '\0';
    nn = &n;
    
    sscanf(buffer2, "%d", &n);
    
    p = aloque(n * sizeof(int));

    do {
   
        printf("\nDigite a opcao: \ni -> Inserir na pilha;\nd -> Remover da pilha;\np -> "
        "Imprimir pilha;\ns -> Sair \n");
        
        fflush(stdin);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        sscanf(buffer, "%c", &escolha);

        switch(escolha){
            case 'i': empilhar(p, position, nn);
            break ;

            case 'd': desempilhar(p, position);
            break;

            case 'p': imprimir_pilha(p, position);
            break;

            case 's': sair(p);
            break;

            default: printf("Caractere ou operador nao aceito, tente novamente!\n");
            break;
        }

    }while(1); 

}


void empilhar(int *p, int *position, int *nn){
    char buffer[10] = {};
    if (*position < *nn){
        printf("\33[H\33[2J");
        printf("Digite o um valor para empilhar: ");

        
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        sscanf(buffer, "%d", &*(p+(*position)));

        *position += 1;
    }
    else {
        printf("\33[H\33[2J");
        printf("Pilha atingiu o limite maximo!");
    }
}


void desempilhar(int *p, int *position){

    if (*position == 0){
        printf("\33[H\33[2J");
        printf("Pilha nao possui mais intens para remover!\n");
    }
    else {
        
        *(p+(*position - 1)) = 0;
        *position -= 1;

        printf("\33[H\33[2J");
        printf("Ultimo da pilha removido com sucesso!\n");
    }
}

void imprimir_pilha(int *p, int *position){
    printf("\33[H\33[2J");
    int k;
    if (*position > 0){
        for (k=(*position - 1); k > -1; k--){
            printf("\nPosicao da Piha: [%d] item da fila: [%d]", k, *(p+(k)));
            printf("\n----------------------------------\n");
        }
    }else {
        printf("\33[H\33[2J");
        printf("Pilha esta vasia!\n");
    }
}

void sair(int *p){

    libere(p);
    exit(0);

}