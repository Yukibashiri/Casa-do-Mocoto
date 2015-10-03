#include "bibliotecamocoto.h"

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
    printf ("------------------------------------CARDAPIO------------------------------------\n");
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
//
//
int main (void)
{
    setlocale(LC_ALL, "Portuguese"); // caracteres e acentuação da língua portuguesa.
    info();
    do{
        printf ("\n[1] CARDAPIO\n[2] INFO\n[0] ENCERRAR PROGRAMA\n");
        scanf ("%d", &opcao);
        system("cls");
        switch (opcao){
            case (1):
                 cardapio(cont);
                 break;
            case (2):
                 info();
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
