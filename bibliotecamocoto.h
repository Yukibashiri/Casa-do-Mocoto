#ifndef bibliotecamocoto
#define bibliotecamocoto

#include <stdio.h>              //
#include <stdlib.h>             // Bibliotecas que serão utilizadas
#include <locale.h>             //
#define caso "Proposta de melhoria utilizando as Tecnologias da Informação"
#define aluno "Mario Damião Caparroz Remistico Junior"
#define professor "Fabio Farias Feitosa"
int cont,decisao,opcao,qnt_produto;
char nomegarcom[5][50] = {"NENHUM","NENHUM","NENHUM","NENHUM","NENHUM"};
int mesa[15][50],totalmesa[15],salgarcom[5]; // ESTAO DESTACADAS POIS SERÃO AS QUE SOFREARAM RESET
 float produtos[21][2] = {{8,0.05},{3,0.05},{3,0.07},{5,0.10},{7,0.10},{3,0.10},{60,0.10},{90,0.15},{75,0.10},{60,0.12},{80,0.15},{65,0.15},{15,0.10},{12,0.10},{30,0.15},
                         {30,0.15},{12,0.15},{11,0.15},{4,0.15},{12,0.15},{45,0.15}};
 char nome_produtos[21][50] = {"Cerveja 600ml","Refrigerante Lata","Água mineral 300ml","Suco (Variados)","Suco com leite","Água de coco","Peixada","Camarão no alho e óleo",
                               "Peixe escabeche","Caranguejada","Peixe frito (pescada)","Peixe frito (peixe pedra)","Torta de camarão com arroz de cuxá","Casquinha de caranguejo",
                               "Camarão frito (tira gosto)","Peixe frito (tira gosto)","Sobremesas (creme de bacuri, cupuaçu, maracujá)","Pudim de leite","Sorvete (bola)","Charlote","Mocotó DELUXE"};
void info();
void cardapio();
void parada();
#endif
