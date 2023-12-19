#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

typedef struct aluno{
    char nome[100];
    char rga[12];
    float nota[2];
}aluno;

void incluir_registro(); void imprimir_registros();
void pesquisar_registro(); void editar_registro();
void excluir_registro(); void sair();void sleep_teste(int milliseconds);

int main(void){
    aluno aluno[5];
    int marcador = 0;
    int *Pmarcador;
    Pmarcador = &marcador;
    char escolha;

    time_t startTime = time(NULL);  // Obtém o tempo inicial

    while (1) {
        
        // Obtém o tempo atual
        time_t currentTime = time(NULL);  

        // Calcula o tempo decorrido
        time_t elapsedTime = currentTime - startTime;
  
        if (elapsedTime >= 1) {
            printf("\33[H\33[2J"); //limpar tela
            printf("     888     888 888    888\n"
            "     888     888 888    888\n"
            "     888     888 888    888\n"
            "     888     888 888888 88888b.   .d88b.  888d888\n"
            "     888     888 888    888 *88b d8P  Y8b 888P*\n"
            "     888     888 888    888  888 88888888 888\n"
            "     Y88b. .d88P Y88b.  888  888 Y8b.     888\n"
            "      *Y88888P*   *Y888 888  888  *Y8888  888\n\n"
            "     888                                        8888888\n"
            "     888                                      88       88\n"
            "     888                                     88  88888  88\n"
            "     88888b.   .d88b.  88888b.   .d88b.      88 88      88\n"
            "     888 *88b d88**88b 888 *88b d8P  Y8b     88 88      88\n"
            "     888  888 888  888 888  888 88888888     88  88888  88\n"
            "     888 d88P Y88..88P 888  888 Y8b.          88       88\n"
            "     88888P*   *Y88P*  888  888  *Y8888         8888888\n\n");
            printf("Carregando... %lld\n", -((long long int)elapsedTime)+5);
            sleep_teste(1000);// tempo em miliseconds
        }

        // em 5 segundos, encerra o loop
        if (elapsedTime >= 5) {
            break;
        }
    }
 
    do {
        printf("\33[H\33[2J"); //limpar tela

        printf("Digite a opcao: \ni -> Incluir registro;\np -> "
        "Mostrar registros em ordem de registor;\ns -> Pesquisar "
        "registro;\ne -> Editar registro;\ne -> Excluir registro;\nx -> Sair;\n");
        scanf("%c", &escolha);
        switch(escolha){
            case 'i': incluir_registro(aluno, Pmarcador);
            break ;

            case 'p': imprimir_registros(aluno, Pmarcador);
            break;
            
            case 's': pesquisar_registro(aluno, Pmarcador);
            break;

            case 'e': editar_registro(aluno, Pmarcador);
            break;

            case 'k': excluir_registro(aluno, Pmarcador);
            break;

            case 'x': sair();
            break;

            default: printf("Caractere ou operador nao aceito, tente novamente!\n");
            break;
        }

    }while(1);  
    
    return 0;
}


void incluir_registro(aluno aluno[MAX], int *pmarcador){
    int a;
    char buffer[10];
    char buffer2[12];
    a = *pmarcador;
    // grava dados do aluno
        
    //limpa tela
    printf("\33[H\33[2J");

    // Limpar o buffer antes da leitura
    setbuf(stdin, NULL);

    printf("Digite o nome do aluno: ");

    fgets(aluno[a].nome, 100, stdin);
    
    //Remove caractere de formatação
    aluno[a].nome[strcspn(aluno[a].nome, "\n")] = '\0';
/*
    printf("Digite o RGA do aluno: ");

    fgets(aluno[a].rga, 12, stdin);

     //Remove caractere de formatação
    aluno[a].rga[strcspn(aluno[a].rga, "\n")] = '\0';
    
    getchar();
    

    //limpa tela
    printf("\33[H\33[2J");
    
    printf("Digite a nota 1 do aluno: ");
    
    getchar();
    fgets(buffer, sizeof(buffer), stdin);

    //Remove caractere de formatação
    buffer[strcspn(buffer, "\n")] = '\0';

    sscanf(buffer, "%f", &aluno[a].nota[0]);

    //limpa tela
    printf("\33[H\33[2J");
    printf("Digite a nota 2 do aluno: ");

    //Remove caractere de formatação
    buffer2[strcspn(buffer2, "\n")] = '\0';

    fgets(buffer2, sizeof(buffer2), stdin);
    sscanf(buffer2, "%f", &aluno[a].nota[1]);
*/
    if (*pmarcador == 0)
        *pmarcador += 1;
    else
        *pmarcador += 1;
}

void sair(){

    exit(0);

}

void imprimir_registros(aluno aluno[MAX], int *pmarcador){
    int a;
    char buffer_[10];

    printf("\33[H\33[2J");
    printf("\nQuantidade de Alunos: %d \n", *pmarcador);

    

    // mostra dados dos alunos
    for (a = 0 ; a < *pmarcador ; a++){

        printf("-------------------------------------\n");

        printf("ID do aluno: %d \n", a);

        printf("Aluno: %s \n", aluno[a].nome);
    
        //printf("Nota 1: %.1f \n", aluno[a].nota[0]);

        //printf("Nota 2: %.1f \n", aluno[a].nota[1]);
    }
    getchar();
    printf("Precione Enter para sair! \n");
    buffer_[strcspn(buffer_, "\n")] = '\0';
    fgets(buffer_, sizeof(buffer_), stdin);

}


void pesquisar_registro(aluno aluno[MAX], int *pmarcador){
    int a;
    char buffer[10];
    char buffer_[10];
    char nome[100];

    printf("\33[H\33[2J");
    getchar();
    printf("Digite o nome para pesquisar aluno:");
    
    
    fgets(nome, 100, stdin);

    //Remove caractere de formatação do fgets
    nome[strcspn(nome, "\n")] = '\0';

    for (a = 0; a < *pmarcador ; a++){
        if(strstr(aluno[a].nome, nome) != NULL){
            printf("\nAluno encontrado!\n");
            printf("N: [%s] Aluno: [%s]\n", aluno[a].rga, aluno[a].nome);

            printf("\nPrecione Enter para sair! \n");

            //Remove caractere de formatação
            buffer_[strcspn(buffer_, "\n")] = '\0';

            fgets(buffer_, sizeof(buffer_), stdin);
            printf("\33[H\33[2J");
            
        }else if(a == *pmarcador && strstr(aluno[a].nome, nome) == NULL){
            printf("Aluno(s) nao ncontrado(s)!\n");

            printf("\nPrecione Enter para sair! \n");

            //Remove caractere de formatação
            buffer_[strcspn(buffer, "\n")] = '\0';

            fgets(buffer, sizeof(buffer), stdin);
            printf("\33[H\33[2J");  
        }
    
    }
    

    

}


void editar_registro(aluno aluno[MAX], int *pmarcador){
    char buffer_entrada[10];
    int key = 0;

    //limpa tela
    printf("\33[H\33[2J");

   
    printf("Digite o numero do Aluno (nao o RGA): \n");
    getchar();
    fgets(buffer_entrada, sizeof(buffer_entrada), stdin);
    buffer_entrada[strcspn(buffer_entrada, "\n")] = '\0';
    sscanf(buffer_entrada, "%d", &key);
    printf("\nEditar Registro\n\n");

    char temp_nome[100];
    char temp_nota1[10];
    char temp_nota2[10];
    strcpy(temp_nome, aluno[key].nome);
    snprintf(temp_nota1, sizeof temp_nota1, "%f", aluno[key].nota[0]);
    snprintf(temp_nota2, sizeof temp_nota2, "%f", aluno[key].nota[1]);

    printf("Precione Enter para preservar a informacao original\n"
           "ou\n"
           "Digite a nova informacao e depois precione enter para salvar! \n");
    
    // nome
    printf("Nome: \n"); 
    if (fgets(temp_nome, sizeof(temp_nome), stdin) != NULL) {
        // Remove o caractere de nova linha, se presente
        temp_nome[strcspn(temp_nome, "\n")] = '\0';

        // Verifica se foi precionado o enter sem digitar nada
        if (temp_nome[0] == '\0') {
            printf("Informacao nao alterada\n");
            strcpy(aluno[key].nome, temp_nome);
        } else {
            printf("O nome do aluno com RGA: [%s] foi lterado com Sucesso!\n", aluno[key].rga);
        }
    }

    //nota 1
    printf("\n Nota 1: "); 
    if (fgets(temp_nota1, sizeof(temp_nota1), stdin) != NULL) {
        // Remove o caractere de nova linha, se presente
        temp_nota1[strcspn(temp_nota1, "\n")] = '\0';

        // Verifica se foi precionado o enter sem digitar nada
        if (temp_nota1[0] == '\0') {
            printf("Informacao nao alterada\n");
            sscanf(temp_nota1, "%f", &aluno[key].nota[0]);
        } else {
            printf("A nota 1 do aluno com RGA: [%s] foi alterado com Sucesso!\n", aluno[key].rga);
        }
    }

    //nota 2
    printf("\n Nota 2: "); 
    if (fgets(temp_nota2, sizeof(temp_nota2), stdin) != NULL) {
        // Remove o caractere de nova linha, se presente
        temp_nota2[strcspn(temp_nota2, "\n")] = '\0';

        // Verifica se foi precionado o enter sem digitar nada
        if (temp_nota2[0] == '\0') {
            printf("Informacao nao alterada\n");
            sscanf(temp_nota2, "%f", &aluno[key].nota[1]);
        } else {
            printf("A nota 2 do aluno com RGA: [%s] foi alterado com Sucesso!\n", aluno[key].rga);
        }
    }
}

void excluir_registro(aluno aluno[MAX]){

    printf("\nExcluir Registro\n\n");

}


void sleep_teste(int milliseconds) {
    struct timespec req, rem;

    req.tv_sec = milliseconds / 1000;
    req.tv_nsec = (milliseconds % 1000) * 1000000;

    while (nanosleep(&req, &rem) == -1) {
        req = rem;
    }
}

    