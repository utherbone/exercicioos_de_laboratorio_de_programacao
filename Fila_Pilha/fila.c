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

void inserir_na_fila();
void remover_da_fila();
void imprimir_fila();
void sair();



int main (){

    char escolha = 0;
    char buffer[10] = {};
    char buffer2[10] = {};
    int x = 0;
    int *p, *position, *nn, n;

    position = &x;
    p = NULL;

    printf("Digite um tamanho maximo para fila: ");

    fflush(stdin);
    fgets(buffer2, sizeof(buffer2), stdin);
    buffer2[strcspn(buffer2, "\n")] = '\0';
    nn = &n;
    
    sscanf(buffer2, "%d", &n);
    
    p = aloque(n * sizeof(int));

    do {
        printf("\nDigite a opcao: \ni -> Inserir na fila;\nd -> Remover da fila;\np -> "
        "Imprimir fila;\ns -> Sair \n");
        
        fflush(stdin);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';

        sscanf(buffer, "%c", &escolha);

        switch(escolha){
            case 'i': inserir_na_fila(p, position, nn);
            break ;

            case 'd': remover_da_fila(p, position);
            break;

            case 'p': imprimir_fila(p, position);
            break;

            case 's': sair(p);
            break;

            default: printf("Caractere ou operador nao aceito, tente novamente!\n");
            break;
        }

    }while(1); 

}


void inserir_na_fila(int *p, int *position, int *nn){
    char buffer[10] = {};
    if (*position < *nn){
        printf("\33[H\33[2J");
        printf("Digite o um valor para enfileirar: ");

        
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        sscanf(buffer, "%d", &*(p+(*position)));

        *position += 1;
    }
    else {
        printf("\33[H\33[2J");
        printf("Fila atingiu o limite maximo!");
    }
}


void remover_da_fila(int *p, int *position){
    int k, h;
    if (*position == 0){
        printf("\33[H\33[2J");
        printf("Fila não possuí mais intens para remover!\n");
    }
    else {
        if (*position % 2 == 0){
            for (h=0; h < *position; h++){
                *(p+h) = *(p+(h+1));
            }
        }

        if (*position % 2 == 1){
            for (k=0; k < *position; k++){
                *(p+k) = *(p+(k+1));
                if(k == (*position) - 1){
                    k+=1;
                }
            }
            
        }
        *position -= 1;
        printf("\33[H\33[2J");
        printf("Primeiro da fila removido com sucesso!\n");
    }
}

void imprimir_fila(int *p, int *position){
    printf("\33[H\33[2J");
    int k;
    if (*position > 0){
        for (k=0; k < *position; k++){
            printf("\nPosicao da fila: [%d] item da fila: [%d]", k, *(p+(k)));
            printf("\n----------------------------------\n");
        }
    }else {
        printf("\33[H\33[2J");
        printf("Fila esta vasia!\n")
    }
}

void sair(int *p){

    libere(p);
    exit(0);

}