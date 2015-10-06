#include "bibliotecamocoto.h"

//
//
//FUNÇÃO LIMPARTELA E PAUSA
void parada(){
    printf ("\nPressione qualquer botão para voltar ao menu do programa.");
    getch();
    system("cls");
    return;
}
//FUNÇÃO INFO
void info(){
   printf ("CASE: %s  \nAluno: %s \nProfessor: %s \n",caso,aluno,professor);  // Titulo do programa
   parada();
   return;
}
//FUNÇÃO CARDAPIO
void cardapio(){
    system("cls");
    printf ("------------------------------------CARDAPIO------------------------------------");
    for (cont = 0; cont < 21; cont++) {
        if (cont <=9){
            printf ("[0%d] Produto: %s, Valor: %.2f.\n",cont,nome_produtos[cont],produtos[cont][0]);
        }
        else{
            printf ("[%d] Produto: %s, Valor: %.2f.\n",cont,nome_produtos[cont],produtos[cont][0]);
        }
    }
    printf ("------------------------------------CARDAPIO------------------------------------\n");
    parada();
    return;
}
//FUNÇÂO CADASTRO DE GARÇOM, SENDO QUE SÓ PODEM TER 5.
void cadastro_garcom(){
    printf ("Lista dos Garçons atuais\n");
    for (cont = 0; cont < 5; cont++){
        printf ("\nID:[%d]  Nome: %s.",cont,nomegarcom[cont]);
    }
    printf ("\n Gostaria de Adicionar/Alterar algum Garçom?\n 1 - Sim. 2- Nao\n R: ");
    scanf ("%d",&decisao);
    if (decisao == 1){
        system ("cls");
        printf ("Informe o ID no qual o Garçom será registrado: ");
        scanf ("%d",&cont);
        while (cont > 5){
              printf ("\nERRO!\nInforme um ID valido no qual o Garçom será registrado:");
              scanf ("%d",&cont);
        }
        if (strcmp(nomegarcom[cont], "NENHUM") == 0){
            printf ("Informe o nome do Garçom a ser registrado: ");
            scanf ("%s",&nomegarcom[cont]);
            printf ("\nGarçom: %s, foi registrado ao ID: %d, com sucesso!\n",nomegarcom[cont],cont);
        }
        else{
            printf ("o ID informado já possui o Garçom: %s registado.",nomegarcom[cont]);
        }
    }
    parada();
    return;
}
// REGISTRAR GARÇOM A MESA.
void abrir_mesa(){
    printf ("Gostaria de ver a lista das mesas e seus garçons antes?\n 1 - Sim. 2 - Não\nR: ");
    scanf ("%d", &decisao);
    if (decisao == 1){
        for (cont = 0; cont <15; cont++){
                if (cont <=9){
                    printf ("\nMesa 0%d, Garçom: %s.",cont,nomegarcom[link[cont]]);
                }
                else{
                    printf ("\nMesa %d, Garçom: %s.",cont,nomegarcom[link[cont]]);
                }
        }
    }
    parada();
    do{
        printf ("\nInforme o ID da mesa: ");
        scanf ("%d",&decisao);
        if ((decisao <=14) && (link[decisao] == 5)) {
            for (cont = 0; cont < 5; cont++){
                printf ("\nID:[%d]  Nome: %s.",cont,nomegarcom[cont]);
            }
            do{
                printf ("\nInforme o ID do Garçom: ");
                scanf ("%d",&link[decisao]);
            }
              while (link[decisao] > 5);
            }
        else {
            printf ("\nERRO! ID informado não corresponde com nenhuma mesa ou a mesma já esta registrada.\n");
            decisao = 20;
        }
    }
    while (decisao == 20);
    parada();
}

void pedido(){
    printf ("\Gostaria de rever o cardapio? 1 - SIM. 2 - NÃO\nR: ");
    scanf ("%d",&decisao);
    if (decisao == 1){
        cardapio();
    }
    do{
        printf ("\nQual o ID da mesa? ");
        scanf("%d",&decisao);
        printf ("\nQual o ID do produto? ");
        scanf ("%d", &opcao);
        printf ("\n quantas unidades? ");
        scanf ("%d",&qnt_produto);
        for (cont = 0; cont < qnt_produto; cont++){
            mesa[decisao][ti[decisao]] = opcao;
            ti[decisao] ++
        }
    }
}
//


int main (void)
{
    setlocale(LC_ALL, "Portuguese"); // caracteres e acentuação da língua portuguesa.
    info();
    do{
        printf ("---------------------------Bem-Vindo a Casa do Mocotó--------------------------\n[1] CARDAPIO\n[2] INFO\n[3] CADASTRO GARÇOM\n[4] ABRIR MESA\n[5] FAZER UM PEDIDO\n[0] ENCERRAR PROGRAMA\n");
        scanf ("%d", &opcao);
        system("cls");
        switch (opcao){
            case (1):
                 cardapio(cont);
                 break;
            case (2):
                 info();
                 break;
            case (3):
                 cadastro_garcom();
                 break;
            case (4):
                 abrir_mesa();
                 break;
            case (0):
                 printf ("TEM CERTEZA QUE GOSTARIA DE FECHAR O PROGRAMA?\n 1 - SIM\n 2 - NÃO\n Digite: ");
                 scanf("%d",&decisao);
                 if (decisao!=1){
                    opcao = 1;
                    system ("cls");
                 }
                 break;
        }
    }
    while (opcao != 0);
return 0;
}
