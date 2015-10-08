#include "bibliotecamocoto.h"
#include "menufuncoes.c"

// FUNÇÃO PRINCIPAL
int main (void)
{
    setlocale(LC_ALL, "Portuguese"); // caracteres e acentuação da língua portuguesa.
    info();
    do{
        printf ("_____________________________________\n");
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
        printf ("|   [0] ENCERRAR PROGRAMA            |\n_____________________________________\nOpcão: ");
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
            case (5):
                 pedido_item();
                 break;
            case (6):
                 mostrar_conta();
                 break;
            case (7):
                 fechar_conta();
                 break;
            case (8):
                 admin_admin();
                 break;
            case (9):
                 mostrar_comissao();
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
