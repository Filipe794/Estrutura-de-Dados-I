#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "prova.lib"

int main()
{
  srand(time(NULL)); // semente do random

  // eliminando a parte de precisar inserir para agilizar os testes
  inserir_teste(&root_br, "12/1/2012", 1400, "sao paulo");

  inserir_teste(&root_br, "17/2/2013", 2400, "sao paulo");

  inserir_teste(&root_br, "16/3/2014", 3400, "teresina");

  inserir_teste(&root_br, "15/4/2015", 4400, "fortaleza");

  inserir_teste(&root_br, "14/5/2016", 5400, "rio de janeiro");

  inserir_teste(&root_br, "13/6/2017", 6400, "floriaNopolis");

  inserir_teste(&root_ar, "12/7/2018", 7400, "bueNos aires");

  inserir_teste(&root_ar, "15/8/2019", 8400, "bueNos aires");

  inserir_teste(&root_ar, "17/8/2020", 9400, "mendonza");

  inserir_teste(&root_ar, "15/9/2021", 10400, "bariloche");

  inserir_teste(&root_ar, "19/10/2022", 11400, "salta");

  inserir_teste(&root_ar, "11/09/2023", 12400, "cordova");

  int opc = 1;
  char destiNo[50];

  while (opc != 0)
  {
    menu();
    scanf("%d", &opc);
    fflush(stdin);
    switch (opc)
    {
    case 1:
      inserir_raiz(&root_br);
      break;

    case 2:
      inserir_raiz(&root_ar);
      break;

    case 3:
      printf("Digite o destiNo a ser procurado: ");
      scanf("%50[^\n]s", destiNo);
      buscar_destiNo(root_br, destiNo);
      break;

    case 4:
      printf("Digite o destiNo a ser procurado: ");
      scanf("%50[^\n]s", destiNo);
      buscar_destiNo(root_ar, destiNo);
      break;

    case 5:
      imprimir(root_br);
      break;

    case 6:
      imprimir(root_ar);
      break;

    case 7:
      faturamento(root_br);
      printf("Faturamento: %f\n", fatura.valor);
      printf("Quantidade de passagens Vendidas: %d\n", fatura.qtde);
      arrecadacao = 0;   // zerando o contador de arrecadação para nao acumular
      qnt_passagens = 0; // zerando o contador de passagens para nao acumular
      break;

    case 8:
      faturamento(root_ar);
      printf("Faturamento: %f\n", fatura.valor);
      printf("Quantidade de passagens Vendidas: %d\n", fatura.qtde);
      arrecadacao = 0;
      qnt_passagens = 0;
      break;

    case 9:
      faturamento_global();
      break;

    case 10:
      // a funcao consolidar só realiza o processo para uma arvore de cada vez
      consolidar(root_br);
      consolidar(root_ar);
      root_ar = NULL; // depois de consolidar, fazer os ponteiros pras raizes das arvores
      root_br = NULL; // apontarem para nulo, para reiniciar o aNo;
      break;

    case 11:
      imprimir(root_consolidada);
      break;
    case 12:
      faturamento(root_consolidada);
      printf("Faturamento: %f\n", fatura.valor);
      printf("Quantidade de passagens Vendidas: %d\n", fatura.qtde);
      arrecadacao = 0;
      qnt_passagens = 0;
      break;

    case 0:
      break;

    default:
      printf("Opção inválida\n");
      break;
    }
  }

  return 0;
}