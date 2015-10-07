#include "bibliotecamocoto.h"
//
//FUNÇÃO LIMPARTELA E PAUSA
void parada(){
    printf ("\nPressione qualquer botão para dar continuidade programa.");
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
        if ( (strcmp(nomegarcom[cont], "NENHUM") == 0) || (admin == 1) ){
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
    printf("\nMesa registrada com sucesso!\n");
    parada();
}
// Função que cria o pedido, já indicando a mesa e garçom.
void pedido_item(){
        do{
            printf ("\nQual o ID da mesa? ");
            scanf("%d",&decisao);
            if (decisao > 15){
                printf ("\nERRO! ID digitado invalido!\n");
            }
        }
        while (decisao > 15);
        system("cls");
        printf ("\nGostaria de rever o cardapio? 1 - SIM. 2 - NÃO\nR: ");
        scanf ("%d",&decisao);
        if (decisao == 1){
            cardapio();
        }
        do{
        printf ("\nQual o ID do produto? ");
        scanf ("%d", &opcao);
        printf ("\n Produto: %s.\n Quantidade: ",nome_produtos[opcao]);
        scanf ("%d",&qnt_produto);
        for (cont = 0; cont < qnt_produto; cont++){
            mesa[decisao][ti[decisao]] = opcao;
            ti[decisao] ++;
        }
        printf ("\n Item adicionado com sucesso!\n\nGostaria de adicionar mais algum item ao pedido? 1- SIM. 2- NÃO\nR: ");
        scanf ("%d",&opcao);
    }
    while (opcao == 1);
    parada();
    return;
}
// Função que mostra a a lista dos itens já consumidos pela mesa e o total até o momento.
void mostrar_conta(){
    do{
        printf ("\nQual o ID da mesa? ");
        scanf("%d",&decisao);
        if (decisao > 15){
            printf ("\nERRO! ID digitado invalido!\n");
            }
        }
    while (decisao < 15);
    printf ("Produtos consumidos pela mesa %d.\n",decisao);
    for (cont = 0; cont > ti[decisao]; cont ++){
        printf ("\nProduto: %s, valor: %.2f.",nome_produtos[mesa[decisao][cont]]);
        totalmesa[decisao] += produtos[mesa[decisao][cont]][0];
    }
    printf ("                       TOTAL: RS %.2f.", totalmesa[decisao]);
    parada();
    return;
}

void admin_admin(){
    if (admin == 0){
        printf ("Area destinada a Admnistradores!\n Admnistradores podem alterar nome de garçons e fechar/abrir a noite.\n");
        printf ("\nPor favor, informe os seguintes dados:\n Usuario: ");
        scanf ("%s",&loguin);
        printf ("\n Senha: ");
        scanf ("%d",&loguin_pw);
        if (strcmp(loguin, "admin") == 0 && (loguin_pw == 12345)){
            admin = 1;
            printf ("\nLogado com sucesso!");
        }
        else{
            printf ("\nUsuario ou senha invalido!");
        }
    }
    else{
        printf ("\nGostaria de deslogar a conta de Admnistrador?  1- SIM. 2- NÃO.\n R: ");
        scanf ("%d",&decisao);
        if (decisao == 1){
            admin = 0;
            printf ("\n     Conta deslogada!");
        }
    }
    parada();
    return;
}

int main (void)
{
    setlocale(LC_ALL, "Portuguese"); // caracteres e acentuação da língua portuguesa.
    info();
    do{
        printf ("---------------------------Bem-Vindo a Casa do Mocotó--------------------------\n[1] CARDAPIO\n[2] INFO\n[3] CADASTRO GARÇOM\n[4] ABRIR MESA\n[5] FAZER UM PEDIDO\n");
        printf ("[6] MOSTRAR A CONTA\n[7] FECHAR CONTA\n[8] ADMIN\n[9] FECHAR O DIA\n[0] ENCERRAR PROGRAMA\n");
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
                // fechar_conta();
                 break;
            case (8):
                 admin_admin();
                 break;
            case (9):
                // reset_variavel();
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
