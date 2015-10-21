#ifndef bibliotecamocoto
#define bibliotecamocoto
#include <stdio.h>                // Bibliotecas padrões
#include <string.h>              // Será utilizada a função de comparar strings.
#include <stdlib.h>             // Bibliotecas que serão utilizadas
#include <locale.h>            // Bibliotecas padrões
#define caso "Proposta de melhoria utilizando as Tecnologias da Informação"
#define aluno "Mario Damião Caparroz Remistico Junior"
#define professor "Fabio Farias Feitosa"
#define nameless "NENHUM"
char loguin[] = {"admin"}; //loguin
int admin = 0,loguin_pw = {12345}; //senha
int cont,decisao,opcao,qnt_produto,clock[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // Variaveis decisão e contadores.
char nomegarcom[6][50] = {"NENHUM","NENHUM","NENHUM","NENHUM","NENHUM","Nenhum"}; //Variavel utilizada apenas, para exibir o nome do garçom
int mesa[15][50]; // Aqui seram salvo os ID's dos items adquiridos pelo usuario(mesa), o tatal da conta (totalmesa) e a comissão do garçom (salgarcom).
int tm[6] = {0,0,0,0,0,0}; // total de mesas atendidas por cada garçom. Utilizado para marcar o espaço do vetor/matriz
int nummesa[6][20] = {0}; // matriz que guarda o numero das mesas atendidas por cada garçom.
float commesa[6][20] = {0}; // matriz que guarda o valor da comissão de cada mesa atendida pelo garçom.
int ti[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; //total items
int link[15] = {5,5,5,5,5,5,5,5,5,5,5,5,5,5,5}; // Essa variavel guarda o id do garçom ( de 0 a 5) e o numero da mesa, utilizando ela fica facil de saber em qual mesa é feita o pedido e qual garçom recebe.
float salgarcom[6] = {0,0,0,0,0,0},soma=0,totalcaixa = 0,totalcomissoes = 0,totalmesa[15] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},calculocomissao = {0};
float produtos[22][2] = {{8,0.05},{3,0.05},{3,0.07},{5,0.10},{7,0.10},{3,0.10},{60,0.10},{90,0.15},{75,0.10},{60,0.12},{80,0.15},{65,0.15},{15,0.10},{12,0.10},{30,0.15}, //Valores dos produtos
                         {30,0.15},{12,0.15},{11,0.15},{4,0.15},{12,0.15},{45,0.15},{0,0}};
char nome_produtos[22][50] = {"Cerveja 600ml","Refrigerante Lata","Água mineral 300ml","Suco (Variados)","Suco com leite","Água de coco","Peixada","Camarão no alho e óleo",//lista dos produtos
                               "Peixe escabeche","Caranguejada","Peixe frito (pescada)","Peixe frito (peixe pedra)","Torta de camarão com arroz de cuxá","Casquinha de caranguejo",
                               "Camarão frito (tira gosto)","Peixe frito (tira gosto)","Sobremesas (creme de bacuri, cupuaçu, maracujá)","Pudim de leite","Sorvete (bola)","Charlote","Mocotó DELUXE","Removido"};
//TODAS AS FUNÇÕES
void parada();
void certificar_mesa();
void info();
void cardapio();
void cadastro_garcom();
void abrir_mesa();
void pedido_item();
void mostrar_conta();
void fechar_conta();
void admin_admin();
void reset_fluxo();
void mostrar_comissao();
void extorquir_item();
void saldo_caixa();
int main();
#endif
