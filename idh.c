/* Codificar um programa capaz de registrar o Índice de Desenvolvimento Humano (IDH) de todos os países membros da ONU. O programa deverá imprimir a quantidade de países com IDH inferior à média geral*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    int NUMERO_PAISES;

    setlocale(LC_ALL, "Portuguese");

    printf("Qual a quantidade de países que serão declarados?");
    scanf("%d", &NUMERO_PAISES);

    int i, contador = 0;
    float idh_n[NUMERO_PAISES], soma = 0, media;

    for(i = 0; i <NUMERO_PAISES; i++)
    {
        printf("Digite o IDH do país %i: ",i+1);
        scanf("%f", &idh_n[i]);
        soma = soma + idh_n[i];
    }
    media = soma/NUMERO_PAISES;
    printf("\n=====================================================================");
    printf("\nO IDH médio dos países declarados é: %.2f", media);
    printf("\n=====================================================================");
    for(i=0; i<NUMERO_PAISES; i++)
    {
        if(idh_n[i] < media)
        {
            contador++;
        }
    }
    printf("\n=====================================================================");
    printf("\nO número de países com IDH inferior à média geral é: %d",contador);
    printf("\n=====================================================================");

    Sleep (5000);
    return 0;
}


