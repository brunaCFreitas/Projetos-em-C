#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define DIAS 30

int main (){
    setlocale(LC_ALL, "Portuguese");

    int temperaturas[DIAS];
    float soma = 0;
    float maiorTemp = -273;
    float menorTemp = 500;

    for (int i = 0; i < DIAS; i++){
        printf("\nQual valor da temperatura do dia #%d ", i+1);
        scanf("%d", &temperaturas[i]);
        soma += temperaturas[i];
        if (temperaturas[i] > maiorTemp){
           maiorTemp = temperaturas[i];
        }
        if (temperaturas[i] < menorTemp) {
            menorTemp = temperaturas[i];
        }
    }

    float media = (float)soma / (float)DIAS;



    printf("\nO valor da média de temperaturas é %.2fºC ", media);
    printf("\nA maior temperatura registrada foi: %.2fºC ", maiorTemp);
    printf("\nA menor temperatura registrada foi: %.2fºC ", menorTemp);


    return 0;
}
