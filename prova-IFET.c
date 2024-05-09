/*
Um armazém comercializa diversos produtos identificados por um código único. Codificar um programa capaz de registrar as vendas realizadas
pelo armazém, ou seja, a quantidade vendida e o código do produto vendido. Em paralelo o programa deverá permitir o registro dos preços dos
produtos que comercializa.
Ao final do dia de trabalho o programa deverá exibir o faturamento diário do armazém e qual a venda (código do
produto vendido, quantidade vendida do produto e o seu preço) que superou o valor médio das vendas.
*/

/*
1- Flexibilizar a qt de produtos (cadastro) OK
2- Retirar a variavel global
3- Colocar o menu em uma função separada
4- Rerirar o idAtual (virar uma variavel de controle)
5- Retirar o uso de ponteiro
6- Retirar o sleep
7- Inserir Pause no entrada inválida
8- Exibir valor total das vendas
9- Limitar cadastro após atingir o limite
10- Inibir uso de numeros negativos
11- Criar funções para buscar valores
12- Criar função para calcular média
13- Tirar warnings
14- criar constantes p opção do menu
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAX 100

typedef struct
{
    char nome[30];
    float  preco;
    int qtVendida;
    int codigo;
} Produto;

// Funções do Menu
void cadastro();
void venda();
void relatorio();
void listar();

// Funções para manipular os produtos
void inserirProduto(Produto produto);
void listarProdutos();

Produto produtos[MAX];
int idAtual = 1;

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    do
    {
        system("cls");
        printf("------------------------------");
        printf("\n   *** Armazém do BSI *** ");
        printf("\n------------------------------");
        printf("\n   *** MENU DE OPÇÕES *** ");
        printf("\n------------------------------");
        printf("\n[1] Cadastro de Novo Produto");
        printf("\n[2] Registro de Venda");
        printf("\n[3] Listar Produtos Cadastrados");
        printf("\n[4] Relatório de Vendas do Dia");
        printf("\n[5] Sair");
        printf("\n------------------------------\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            cadastro();
            break;
        case 2:
            venda();
            break;
        case 3:
            listar();
            break;
        case 4:
            relatorio();
            break;
        case 5:
            printf("\nFinalizando Programa...");
            break;
        default:
            printf("\nEntrada Inválida!");
        }
    }
    while (opcao != 5);

    return 0;
}

//Função para realizar o cadastro de um novo produto
void cadastro()
{
    Produto produto;
    char continuar;

    printf("------------------------------\n");
    printf("  *** Cadastro de Produtos ***  ");
    printf("\n------------------------------");
    printf("\nDigite o nome do produto: ");
    setbuf(stdin,NULL);
    gets(produto.nome);
    printf("\nDigite o valor unitário R$: ");
    scanf("%f", &produto.preco);
    inserirProduto(produto);
    printf("\nProduto Cadastrado");
    sleep(1);
    printf("\nDeseja continuar cadastrando [S/N]? ");
    continuar = getche();
    printf("\n");
    system("pause");
    system("cls");
    if (continuar == 'S' || continuar == 's')
    {
        cadastro();
    }
}

//Função para realizar a venda
void venda()
{
    int id, quantidade;
    char continuar;

    listarProdutos();

    printf("\n------------------------------\n");
    printf("    *** Venda de Produtos *** ");
    printf("\n------------------------------\n");
    printf("Qual o código do produto? ");
    scanf("%d", &id);

    if (id <= 0 || id >= idAtual)
    {
        printf("\nCódigo Inválido");
        printf("\n");
        system("pause");

        return;
    }

    Produto* produto = &produtos[id-1];
    printf("Quantas unidades de %s deseja vender? ", produto->nome);
    scanf("%d", &quantidade);
    produto->qtVendida += quantidade;

    printf("\nDeseja continuar vendendo [S/N]? ");
    continuar = getche();
    printf("\n");
    system("pause");
    system("cls");

    if (continuar == 'S' || continuar == 's')
    {
        venda();
    }
}

//Função que gera o relatório de vendas
void relatorio()
{
    float faturamentoProduto, mediaFaturamentoProduto;
    float faturamentoTotal = 0;
    int quantidadeProdutos = idAtual - 1;

    Produto produto;

    printf("\n-----------------------------------------------------------------");
    printf("\n                     -- VENDAS DO DIA --                         ");
    printf("\n-----------------------------------------------------------------\n");
    printf("%3s\t%-30s %s %s %8s %s","Código", "Nome", "Preço", " Qtd Vend", "Total", "Superou a média?");
    for (int i = 0; i < quantidadeProdutos; i++)
    {
        produto = produtos[i];
        faturamentoProduto = produto.qtVendida * produto.preco;
        faturamentoTotal += faturamentoProduto;

        printf("\n%3d\t%-30s %5.2f %5d %12.2f", produto.codigo, produto.nome, produto.preco, produto.qtVendida, faturamentoProduto);
    }

    mediaFaturamentoProduto = faturamentoTotal / quantidadeProdutos;

    printf("\n------------------------------------------------------------------");
    printf("\n      Produtos que SUPERARAM o valor MÉDIO das vendas ");
    printf("\n                   Média de vendas: %.2f", mediaFaturamentoProduto);
    printf("\n------------------------------------------------------------------");
    printf("\n%3s\t%-30s %s %s %8s","Código", "Nome", "Preço", " Qtd Vend", "Total");

    for (int i = 0; i < quantidadeProdutos; i++)
    {
        produto = produtos[i];
        faturamentoProduto = produto.qtVendida * produto.preco;
        if (faturamentoProduto > mediaFaturamentoProduto)
        {
            printf("\n%3d\t%-30s %5.2f %5d %12.2f", produto.codigo, produto.nome, produto.preco, produto.qtVendida, faturamentoProduto);
        }
    }
    printf("\n");
    system("pause");
}

//Função que gera insere o produto e gera o código
void inserirProduto(Produto produto)
{
    produto.codigo = idAtual;
    produto.qtVendida = 0;
    produtos[idAtual - 1] = produto;
    idAtual++;
}

//Função que lista os produtos cadastrados (usado na venda)
void listarProdutos()
{
    Produto produto;

    printf("\n----------------------------------------------------");
    printf("\n              -- LISTA DE PRODUTOS --               ");
    printf("\n---------------------------------------------------\n");
    printf("%3s\t%-30s\t%s","Código", "Nome", "Preço");
    for (int i=0; i < (idAtual-1); i++)
    {
        produto = produtos[i];
        printf("\n%3d\t%-30s %6.2f", produto.codigo, produto.nome, produto.preco);
    }
    printf("\n");
}

//Função que apenas lista os produtos cadastrados
void listar()
{
    listarProdutos();
    system("pause");
}
