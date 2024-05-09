/*Um Posto de Saúde, responsável pela vacinação contra o Covid-19, contratou os seus serviços de programador
para criar uma solução para o seguinte problema: calcular a quantidade de pesssoas que foram vacinadas e que possuem
a mesma idade da pessoa mais velha. */

#include <stdio.h>
#include <locale.h>

int maiorIdade(int idadePaciente[], int dosesDisponiveis);
int quantidadeMaiorIdade(int pacienteMaiorIdade, int idadePaciente[], int dosesDisponiveis);

int main(){

    setlocale(LC_ALL, "Portuguese");

    int dosesDisponiveis;

    printf("\nQuantas doses de vacina estão disponíveis? ");
    fflush(stdin);
    scanf("%d", &dosesDisponiveis);

    int idadePaciente[dosesDisponiveis];

    for (int i = 0; i < dosesDisponiveis; i++){
        printf("\nQual a idade da pessoa %d a ser vacinada? ", i+1);
        fflush(stdin);
        scanf("%d", &idadePaciente[i]);
    }

    int pacienteMaiorIdade = maiorIdade(idadePaciente, dosesDisponiveis);
    int somaMaiorIdade = quantidadeMaiorIdade(pacienteMaiorIdade, idadePaciente, dosesDisponiveis);

    printf("\nA quantidade total de pessoas vacinadas foi: %d", dosesDisponiveis);
    printf("\nA maior idade vacinada é: %d", pacienteMaiorIdade);
    printf("\nO número de pessoas com idade igual a maior idade vacinada é de: %d", somaMaiorIdade);

    return 0;
}

int maiorIdade(int idadePaciente[], int dosesDisponiveis){

    int idadeMaior = 0;

    for(int i=0; i < dosesDisponiveis; i++){
        if(idadeMaior < idadePaciente[i]){
            idadeMaior = idadePaciente[i];
        }
    }
    return idadeMaior;
}

int quantidadeMaiorIdade(int pacienteMaiorIdade, int idadePaciente[], int dosesDisponiveis){

    int contadorMaiorIdade = 0;

    for(int i=0; i < dosesDisponiveis; i++){
        if(pacienteMaiorIdade == idadePaciente[i]){
            contadorMaiorIdade++;
        }
    }
    return contadorMaiorIdade;
}
