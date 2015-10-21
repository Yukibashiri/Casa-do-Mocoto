#include "bibliotecamocoto.h"
#include "menufuncoes.c"

// FUNÇÃO PRINCIPAL
int main (void)
{
    setlocale(LC_ALL, "Portuguese"); // caracteres e acentuação da língua portuguesa.
    info();
    do{
        printf (" ____________________________________\n");
        printf ("|           Casa do Mocotó           | \n");
        printf ("|   [1] CARDAPIO                     |\n");
        printf ("|   [2] INFO                         |\n");
        printf ("|   [3] CADASTRO GARÇOM              |\n");
        printf ("|   [4] ABRIR MESA                   |\n");
        printf ("|   [5] FAZER UM PEDIDO              |\n");
        printf ("|   [6] MOSTRAR A CONTA              |\n");
        printf ("|   [7] FECHAR CONTA                 |\n");
        printf ("|   [8] PAINEL DO ADMNISTRADOR       |\n");
        printf ("|   [9] MOSTRAR COMISSÃO             |\n");
        printf ("|   [ESC] ENCERRAR PROGRAMA          |\n|____________________________________|\nPressione a tecla no teclado referente ao numero do menu.");
        opcao = getch();
        system("cls");
        switch (opcao){
            case (49):
                 cardapio(cont);
                 break;
            case (50):
                 info();
                 break;
            case (51):
                 cadastro_garcom();
                 break;
            case (52):
                 abrir_mesa();
                 break;
            case (53):
                 pedido_item();
                 break;
            case (54):
                 mostrar_conta();
                 printf ("\nPressione qualquer botão para dar continuidade programa.");
                 getch();
                 system("cls");
                 break;
            case (55):
                 fechar_conta();
                 break;
            case (56):
                 admin_admin();
                 break;
            case (57):
                 mostrar_comissao();
                 break;
            case (0x1b):
                 printf ("TEM CERTEZA QUE GOSTARIA DE FECHAR O PROGRAMA?\n 1 - SIM\n 2 - NÃO\n Digite: ");
                 scanf("%d",&decisao);
                 if (decisao==1){
                    opcao = 9999999;
                 }
                 system ("cls");
                 break;
        }
    }
    while (opcao != 9999999);
return 0;
}
