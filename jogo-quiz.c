/* Programa Jogo Quiz:
Vai ser um programa pouco flexível, visto que ao querer jogar novamente as questões serão as
mesmas, porém sua pontuação será diferente.
Consiste em fazer um programa com 5 questões de conhecimentos gerais para marcar com V ou F.
Ao decorrer do jogo as questões ficarão mais difíceis e terão uma maior pontuação.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "Portuguese");

    char sim;
    char verdade = 'V';
    char falso = 'F';

    printf("\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\t\t\tBem vindo ao Quiz Cinco Questões\n");
    printf("\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n\~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ Aqui estão as regras do jogo: ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\n1)Serão cinco questões de conhecimentos gerais para marcar com V ou F.\n");
    printf("\n2)O nível das questões irão subir ao decorrer do jogo.\n");
    printf("\n3)Cada questão terá uma pontuação, sendo a primeira uma pontuação menor e a última uma pontuação maior.\n");
    printf("\n4)No final do Quiz você irá saber quantas das cinco questões acertou e qual foi sua pontuação final.\n");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    printf("\nVamos começar?\nSim (S) ou Não (N):  ");
    scanf("%c", &sim);

    if (sim == 'S')
    {
        printf("\nOK! Vamos lá!\n");
        printf("\n1ª Questão (5 pnts): O menor país do mundo é o Vaticano e o maior é a Rússia. Verdadeiro (V) ou falso (F)?\n");
        printf("Resposta:\t");
        verdade = getche ();
        if(verdade == 'V')
        {
            printf("\n\nMuito bom! Você ganhou 5 pontos!\n\nVamos para a próxima questão!\n");
        }
        else
        {
            printf("\nOps! Não foi dessa vez, mas não desista! Vamos para a próxima questão!\n\n");
        }

        printf("\n\n2ª Questão (7 pnts): Neste ano, 2021, o Atentado de 11 de setembro completa 20 anos\ne a Primavera Árabe 30 anos. Verdadeiro (V) ou falso (F)?");
        printf("\nResposta:\t");
        falso = getche ();
        if(falso == 'F')
        {
            printf("\nMuito bom! Você ganhou 7 pontos!\n\nVamos para a próxima questão!\n");
        }
        else
        {
            printf("\nNão não! A Primavera Árabe ocorreu a partir de 2010! Não foi dessa vez, mas não desista!\n\nVamos para a próxima questão!");
        }

        printf("\n\n3ª Questão (11 pnts): O político Saddam Hussein morreu como vítima de um câncer. Verdadeiro (V) ou Falso (F)?\n");
        printf("Resposta:\t");
        falso = getche ();
        if(falso == 'F')
        {
            printf("\nMuito bom! Você ganhou 11 pontos!\n\nVamos para a próxima questão!\n");
        }
        else
        {
            printf("\nErrado! Após ser capturado pelos EUA ele foi julgado pelo Governo Irariano\ne foi condenado ao enforcamento após anos de um governo aterrorizante!\n\nNão foi dessa vez, mas não desista!\nVamos para a próxima questão!\n");
        }
        printf("\n\n4ª Questão (19 pnts): Os principais autores do Barroco no Brasil são Gregório de Matos, Castro Alves,\nBento Teixeira e Álvares de Azevedo. Verdadeiro (V) ou falso (F)?\n");
        printf("Resposta:\t");
        falso = getche ();
        if(falso == 'F')
        {
            printf("\nMuito bom! Você ganhou 19 pontos!\n\nVamos para a próxima questão!\n");
        }
        else
        {
            printf("\nNão, você errou! Os principais autores do Barroco Brasileiro são: Gregório de Matos,\nBento Texeira e Manuel Botelho de Oliveira.\n\nNão foi dessa vez, não desanime!\nVamos para a próxima questão!\n");

        }
        printf("\n\n5ª Questão: (35 pnts): Além das Olimpíadas de Tóquio 2020 que foram, pela primeira vez na história,\nadiadas devido a Pandemia, outras três tiveram suas datas canceladas,\nforam elas Berlim (1916), Tóquio (1940) e Londres (1944). Verdadeiro (V) ou Falso (F)?\n");
    printf("Resposta:\t");
        verdade = getche ();
        if(verdade == 'V')
        {
            printf("\n\nMuito bom! Você ganhou 35 pontos!\n\nInfelizmente o jogo chegou ao fim. Sua pontuação foi de:\t\nGostaria de jogar novamente?");
        }
        else
        {
            printf("\nOps! Não foi dessa vez! Infelizmente o jogo chegou ao fim. Sua pontuação foi de:\t\nGostaria de jogar novamente?");
        }
    }
    else
        printf("\nTudo bem! Nos vemos numa outra hora! Até mais!\n\n");


}
