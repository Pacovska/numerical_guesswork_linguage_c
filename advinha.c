#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    
    printf("******************************************\n");
    printf("* Bem-vindo ao nosso jogo de adivinhação *\n");
    printf("******************************************\n");
    printf("*** Você inicia o jogo com 500 pontos ****\n");
    printf("******************************************\n");
    printf("**************** Boa sorte ***************\n");
    printf("******************************************\n");
    
    srand(time(NULL));
    int maquina = rand() % 500;
    float chute, pontosperdidos, pontos = 1000, tentativas = 0;
    char valor = 'S';
    
    while (valor == 'S'){
       
        printf("Chute um valor: ");
        scanf("%f", &chute);
        
        if (chute < maquina) {
           printf("Você errou!!\n");
           printf("O número que você tem que acertar é maior\n\n");
           tentativas ++;
        }else if (chute > maquina) {
            printf("Você errou!!\n");
            printf("O número que você tem que acertar é menor\n\n");
            tentativas ++;
        }else if (chute == maquina){
            printf("Você Acetou!!\n");
            printf("O seu número de tentativas totais foi de %.0f \n", tentativas);
            valor = 'N';
        }  

        pontosperdidos = abs((chute - maquina)) / 2.0;
        pontos = pontos - pontosperdidos;
        if (pontos <= 0){
            printf("O jogo acabou, pois você acabou com seus pontos\n");
            printf("O número correto é: %d \n", maquina);
            printf("Quantidade de tentativas foi: %.2f", tentativas);
            valor = 'N';
        }

    }
    if (pontos > 0){
        printf("Sua pontuação final foi %.2f", pontos);
    }
}