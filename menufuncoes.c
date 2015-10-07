#include "bibliotecamocoto.h"

//FUNÇÃO LIMPARTELA E PAUSA
void parada(){
    printf ("\nPressione qualquer botão para dar continuidade programa.");
    getch();
    system("cls");
    return;
}
//Função para confirmação do numero da mesa, pois essa é a principal variavel no momemento dos calculos.
void certificar_mesa(){
    do{
        printf ("\nQual o ID da mesa? ");
        scanf("%d",&decisao);
        if (decisao > 15){
            printf ("\nERRO! ID digitado invalido!\n");
            }
    }
    while (decisao > 15);
    system ("cls");
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
              printf ("\nERRO!\nInforme um ID valido no qual o Garçom será registrado: ");
              scanf ("%d",&cont);
        }
        if ( (strcmp(nomegarcom[cont], "NENHUM") == 0) || (admin == 1) ){
            printf ("\n Informe o nome do Garçom a ser registrado: ");
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
    system("cls");
    if (decisao == 1){
        for (cont = 0; cont <15; cont++){
                if (cont <=9){
                    printf ("\nMesa 0%d, Garçom: %s.",cont,nomegarcom[link[cont]]);
                }
                else{
                    printf ("\nMesa %d, Garçom: %s.",cont,nomegarcom[link[cont]]);
                    parada();
                }
        }
    }
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
        certificar_mesa();
        printf ("\nGostaria de rever o cardapio? 1 - SIM. 2 - NÃO\nR: ");
        scanf ("%d",&opcao);
        if (opcao == 1){
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
        system ("cls");
    }
    while (opcao == 1);
    parada();
    return;
}
// Mostra a conta e o valor total até o momento.
void mostrar_conta(){
    if (opcao != 99){
        certificar_mesa();
    }
    printf ("Produtos consumidos pela mesa %d.\n",decisao);
    for (cont = 0; cont < (ti[decisao]); cont ++){
        if (cont <= 9){
            printf ("\n [0%d]  Produto: %s, valor: %.2f.",cont,nome_produtos[mesa[decisao][cont]],produtos[mesa[decisao][cont]][0]);

        }
        else{
            printf ("\n [%d]  Produto: %s, valor: %.2f.",cont,nome_produtos[mesa[decisao][cont]],produtos[mesa[decisao][cont]][0]);
        }
        soma += produtos[mesa[decisao][cont]][0];
    }
    printf ("\n                                      TOTAL: RS %.2f.\n", soma);
    soma = 0;
    parada();
    return;
}
// FECHAR CONTA, Atibuir comissao ao garçom.
void fechar_conta(){
    certificar_mesa();
    printf ("Produtos consumidos pela mesa %d.\n",decisao);
    for (cont = 0; cont < (ti[decisao]); cont ++){
        printf ("\nProduto: %s, valor: %.2f.",nome_produtos[mesa[decisao][cont]],produtos[mesa[decisao][cont]][0]);
        }
    for (clock[decisao]; clock[decisao] < (ti[decisao]); clock[decisao] ++){
        totalmesa[decisao] += produtos[mesa[decisao][clock[decisao]]][0];
        salgarcom[link[decisao]] = salgarcom[link[decisao]] + (produtos[mesa[decisao][clock[decisao]]][0] * produtos[mesa[decisao][clock[decisao]]][1]);
    }
    printf ("\n\nTotal a pagar: %.2f.\n",totalmesa[decisao],salgarcom[link[decisao]]);
    printf ("Efetuar pagamento?    1- SIM.    2 - NÃO.\nR: ");
    scanf ("%d",&opcao);
    if (opcao == 1){
        totalcaixa += totalmesa[decisao];
        printf ("Mesa [%d], pagamento efetuado!\n       Obrigado pela preferência e volte sempre! \2\n",decisao);
        for (cont = 0; cont < ti[decisao]; cont++){
            mesa[decisao][cont] = 0;
        }
        totalmesa[decisao] = 0;
        link[decisao] = 0;
        ti[decisao] = 0;
        clock[decisao] = 0;
    }
    else {
        printf ("\nPagamento da conta, não efetuado!\n");
    }
    parada();
    return;
}
// FUNÇÃO QUE RESETA TODAS AS VARIAVEIS, PARA REINICIAR O "DIA".
void reset_fluxo(){
    printf ("Tem certeza que gostaria de Reiniciar os valores?  1 - SIM.    2 - NÃO\n R: ");
    scanf ("%d",&opcao);
    if ((admin == 1) && (opcao == 1)){
        for (decisao = 0; decisao < 15; decisao ++){
            clock[decisao] = 0;
            ti[decisao] = 0;
            link[decisao] = 5;
            totalmesa[decisao] = 0;
            totalcaixa = 0;
            totalcomissoes = 0;
            for (cont = 0; cont < 50; cont++){
                mesa[decisao][cont] = 0;
            }
            for (cont = 0; cont < 6; cont++){
                salgarcom[cont] = 0;
                if ((strcmp(nomegarcom[cont], "NENHUM") != 0)){
                    strcpy(nomegarcom[cont],nameless);
                }
            }
        }
        printf ("\nVariaveis Reiniciadas!\n");
    }
    else{
        ("\nVariaveis mantidas!\n");
    }
    parada();
    return;
}
//FUNÇÃO DE EXTORQUIR ITENS
void extorquir_item(){
    mostrar_conta();
    do{
        printf ("Informe o ID do pedido a ser extorquido: ");
        scanf ("%d",&cont);
        printf ("\n [%d]  Produto: %s, valor: %.2f.\n esta correto?     \n1 - SIM.    2 - NÃO.\nR: ",cont,nome_produtos[mesa[decisao][cont]],produtos[mesa[decisao][cont]][0]);
        scanf ("%d",&opcao);
        if (opcao == 1){
            opcao = 99;
            mesa[decisao][cont]= 21;
            system("cls");
            printf ("\nItem %d, extorquido com sucesso!.\n",cont);
            getch();
            printf ("Gostaria de ver a conta atualizada?\n1 - SIM.    2 - NÃO.\nR: ");
            scanf ("%d",&cont);
            if (cont == 1){
                mostrar_conta();
            }
        }
        else{
            printf ("\nOpção digitada Invalida!\n");
            system ("cls");
        }
    }
    while(opcao != 99);
    parada();
    return;
}
//FUNÇÃO DE LOGUIN
void admin_admin(){
    if (admin == 0){
        printf ("Area destinada a Admnistradores!\n Admnistradores podem alterar nome de garçons, fechar/abrir a noite e Extorquir um pedido.\n");
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

    if (admin == 1){
        do{
            system("cls");
            printf ("\n---MENU---  \n[1] FECHAR/ABRIR NOITE\n[2] EXTORQUIR ITEM\n[3] SALDO CAIXA\n[8] VOLTAR AO MENU PRINCIPAL\n[9] DESLOGAR\n");
            scanf ("%d",&opcao);
            switch (opcao){
                case (1):
                     reset_fluxo();
                     break;
                case (2):
                     extorquir_item();
                     break;
                case (3):
                     saldo_caixa();
                     break;
                case (8):
                     opcao = 9;
                     printf ("Voltando ao menu principal!");
                     break;
                case (9):
                     admin = 0;
                     printf ("\n     Conta deslogada!");
                     break;
            }
        }
        while (opcao != 9);
    }
    parada();
    return;
}
// FUNÇÃO QUE MOSTRA AO GARÇOM O VALOR QUE ESSE TEM A RECEBER.
mostrar_comissao(){
    printf ("\nExistem duas formas de checar a comissão total:    \n1 - ID da mesa sendo atendida atualmente.  \n2 - ID do garçom.\n R: ");
    scanf ("%d",&opcao);
    switch (opcao){
        case (1):
             certificar_mesa();
             printf ("Garçom: %s, Comissão:  %.2f.",nomegarcom[link[decisao]],salgarcom[link[decisao]]);
             break;
        case (2):
             do{
                printf ("\nInforme o ID do garçom: ");
                scanf("%d",&opcao);
                if (opcao > 5){
                    printf ("\nERRO! ID digitado invalido!\n");
                }
            }
            while (opcao > 5);
            system ("cls");
            printf ("Garçom: %s, Comissão:  %.2f.",nomegarcom[opcao],salgarcom[opcao]);
            break;
        default:
            printf ("\nOpção invalida!\n");
    }
    parada();
    return;
}
// FUNÇÃO QUE MOSTRA O TOTAL DE DINHEIRO JÁ RECEBIDO.
void saldo_caixa(){
    for (cont = 0; cont < 6; cont ++){
        totalcomissoes += salgarcom[cont];
    }
    printf ("Total recebido: %.2f.\nComissões: %.2f.\nResto: %.2f.",totalcaixa,totalcomissoes,(totalcaixa - totalcomissoes));
    totalcomissoes = 0;
    parada();
    return;
}
