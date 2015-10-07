#include "bibliotecamocoto.h"
#include "menufuncoes.c"

// FUNÇÃO PRINCIPAL
int main (void)
{
    //setlocale(LC_ALL, "Portuguese"); // caracteres e acentuação da língua portuguesa.
    info();
    do{
        printf("\n    Casa do Mocoto ÄÄÄÄÄÄÄ¿\n");
        printf("   ³                              ³\n");
        printf("   ³ %s Cardapio                  ³\n");
        printf("   ³ %s Info                      ³\n");
        printf("   ³ %s Cadastro de Garcom          ³\n");
        printf("   ³ %s Cardapio                  ³\n");
        printf("   ³ %s Cardapio                  ³\n");
        //printf ("---------------------------Bem-Vindo a Casa do Mocoto--------------------------\n[1] CARDAPIO\n[2] INFO\n[3] CADASTRO GARÇOM\n[4] ABRIR MESA\n[5] FAZER UM PEDIDO\n");
        //printf ("[6] MOSTRAR A CONTA\n[7] FECHAR CONTA\n[8] PAINEL DO ADMNISTRADOR\n[9] MOSTRAR COMISSAO\n[0] ENCERRAR PROGRAMA\n");
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
