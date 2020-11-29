#include "lib.h"
#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

ALLEGRO_BITMAP *grama = NULL, *cerca = NULL, *cerca_vert = NULL, *kit = NULL, *vacina = NULL, *cearense_doctor = NULL, *Blue_Virus = NULL, *Green_Virus = NULL, *Pink_Virus = NULL, *Red_Virus = NULL, *Yellow_Virus = NULL;

int num_Virus = 20;

int recebe[20] = {0};
int Vetor_Posicao[num_elementos_vet];
int matriz[linha_Matriz][coluna_Matriz];

void DesenharGrama(){
    
    int i, j;
    
    for(i = 0; i < 1024; i += 50){
        
        for(j = 0; j < 768; j += 50){
            al_draw_bitmap(grama, i, j, 0);
        }
    }
}

void DesenharParede(){
    
    int i, j = 0, aux = 0, num;
    
    // Desenha borda

    for(i = 0; i < 1024; i += 37){
        al_draw_bitmap(cerca, i, 0, 0);
        al_draw_bitmap(cerca, i, 8, 0);
        al_draw_bitmap(cerca, i, 16, 0);
        al_draw_bitmap(cerca, i, 758, 0);
    }
    
    for(i = 0; i < 768; i += 37){
        al_draw_bitmap(cerca_vert, 0, i, 0);
        al_draw_bitmap(cerca_vert, 1014, i, 0);
        al_draw_bitmap(cerca_vert, 1006, i, 0);
    }

    // Desenha primeira linha

    al_draw_bitmap(cerca, 47, 715, 0);
    al_draw_bitmap(cerca, 47+8*37, 715, 0);
    
    for(i = (47+8*37)+(13*37); j < 3; i+=37) {
        j++;
        al_draw_bitmap(cerca, i, 715, 0);
    }
    
    j = 0;

    // Desenha segunda linha

    num = 1;

    al_draw_bitmap(cerca, 10, 715 - 37*num, 0);
    
    for(i = 84+37; j < 5; i+=37) {
        
        aux = i;
        j++;
        
        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 74+37; j < 12; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 37+37; j < 4; i+=37) {
        
        j++;
        
        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    aux = 0;
    j = 0;

    // Desenha terceira linha

    num = 2;
    
    for(i = 47; j < 20; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 37+37; j < 4; i+=37) {
        
        j++;
        
        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    aux = 0;
    j = 0;

    // Desenha quarta linha

    num = 3;
    
    for(i = 10; j < 6; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 74+37; j < 3; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 74+37; j < 5; i+=37) {
        
        j++;
        
        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    aux = 0;
    j = 0;

    // Desenha Quinta linha

    num = 4;
    
    for(i = 10 + 6*37; j < 1; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 37+37; j < 4; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 74 + 37+37; j < 2; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 3*74+37; j < 4; i+=37) {
        
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    aux = 0;
    j = 0;

    // Desenha sexta linha

    num = 5;
    
    for(i = 47; j < 4; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

        for(i = aux + 2*74+37; j < 4; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 74+37; j < 1; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 4*74+37; j < 2; i+=37) {
        
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    aux = 0;
    j = 0;

    // Desenha setima linha 

    num = 6;

    for(i = 10; j < 4; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }

    j = 0;

    for(i = aux + 5*37+37; j < 1; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 5*74+37; j < 2; i+=37) {
        
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    aux = 0;
    j = 0;

    // Desenha oitava linha

    num = 7;

    for(i = 47; j < 6; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 37+37; j < 1; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 9*37+37; j < 2; i+=37) {
        
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    aux = 0;
    j = 0;

    // Desenha nona linha

    num = 8;

    for(i = 10 + 3*74+37; j < 1; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 9*37+37; j < 4; i+=37) {
        
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    aux = 0;
    j = 0;
    
    // Desenha decima linha 

    num = 9;

    for(i = 10; j < 4; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 74+37; j < 3; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 11*37+37; j < 2; i+=37) {
        
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    aux = 0;
    j = 0;

    // Desenha decima primeira linha

    num = 10;

    for(i = 47; j < 2; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 74+37; j < 3; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 6*74+37; j < 3; i+=37) {
        
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    aux = 0;
    j = 0;

    // Desenha decima segunda linha

    num = 11;

    for(i = 10; j < 4; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 5*37+37; j < 1; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 74+37; j < 5; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 74+37; j < 5; i+=37) {
        
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    aux = 0;
    j = 0;

    // Desenha decima terceira linha

    num = 12;

    for(i = 47; j < 4; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 7*37+37; j < 2; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 3*37+37; j < 7; i+=37) {
        
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    aux = 0;
    j = 0;

    // Desenha decima quarta linha

    num = 13;

    for(i = 84+37; j < 1; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 37+37; j < 4; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 74+37; j < 2; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 7*37+37; j < 2; i+=37) {
        
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    aux = 0;
    j = 0;

    // Desenha Decima quinta linha

    num = 14;

    for(i = 47; j < 4; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 37+37; j < 8; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 2*74+37; j < 2; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 37+37; j < 1; i+=37) {
        
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    aux = 0;
    j = 0;

    // Desenha decima sexta linha

    num = 15;

    for(i = 10; j < 2; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 37+37; j < 3; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 37+37; j < 2; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 37+37; j < 5; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 2*74+37; j < 2; i+=37) {
        
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    aux = 0;
    j = 0;

    // Desenha decima setima linha

    num = 16;

    for(i = 47; j < 2; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 37+37; j < 3; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 37+37; j < 2; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 37+37; j < 5; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 2*74+37; j < 2; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 37+37; j < 1; i+=37) {
        
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    aux = 0;
    j = 0;

    // Desenha decima oitava

    num = 17;

    for(i = 10 + 3*74+37; j < 1; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 37+37; j < 2; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 5*37+37; j < 1; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 5*37+37; j < 2; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 37+37; j < 2; i+=37) {
        
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    aux = 0;
    j = 0;

    // Desenha decima noma linha 

    num = 18;

    for(i = 7*37 + 10+37; j < 1; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 8*37+37; j < 1; i+=37) {
        
        aux = i;
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    j = 0;

    for(i = aux + 6*37+37; j < 2; i+=37) {
        
        j++;

        al_draw_bitmap(cerca, i, 715 - 37*num, 0);
    }
    
    aux = 0;
    j = 0;

    for(i = 148; i <= 296; i += 74){
        al_draw_bitmap(cerca_vert, i, 726, 0);
    }
    for(i = 407; i <= 777; i += 74){
        al_draw_bitmap(cerca_vert, i, 726, 0);
    }
    al_draw_bitmap(cerca_vert, 74, 689, 0);
    for(i = 111; i <= 259; i += 74){
        al_draw_bitmap(cerca_vert, i, 689, 0);
    }
    for(i = 296; i <= 814; i += 74){
        al_draw_bitmap(cerca_vert, i, 689, 0);
    }
    for(i = 652; i >= 393; i -= 37){
        al_draw_bitmap(cerca_vert, 814, i, 0);
    }
    al_draw_bitmap(cerca_vert, 74, 652, 0);
    al_draw_bitmap(cerca_vert, 333, 652, 0);
    al_draw_bitmap(cerca_vert, 259, 615, 0);
    al_draw_bitmap(cerca_vert, 444, 615, 0);
    al_draw_bitmap(cerca_vert, 703, 615, 0);
    al_draw_bitmap(cerca_vert, 777, 615, 0);
    for(i = 814; i <= 962; i += 74){
        al_draw_bitmap(cerca_vert, i, 615, 0);
    }
    al_draw_bitmap(cerca_vert, 74, 578, 0);
    al_draw_bitmap(cerca_vert, 148, 578, 0);
    al_draw_bitmap(cerca_vert, 259, 578, 0);
    al_draw_bitmap(cerca_vert, 296, 578, 0);
    al_draw_bitmap(cerca_vert, 444, 578, 0);
    al_draw_bitmap(cerca_vert, 481, 578, 0);
    al_draw_bitmap(cerca_vert, 518, 578, 0);
    for(i = 666; i <= 777; i += 37){
        al_draw_bitmap(cerca_vert, i, 578, 0);
    }
    al_draw_bitmap(cerca_vert, 851, 578, 0);
    al_draw_bitmap(cerca_vert, 925, 578, 0);
    al_draw_bitmap(cerca_vert, 37, 541, 0);
    al_draw_bitmap(cerca_vert, 111, 541, 0);
    for(i = 541; i >= 208; i -= 37){
        al_draw_bitmap(cerca_vert, 185, i, 0);
    }
    al_draw_bitmap(cerca_vert, 222, 541, 0);
    al_draw_bitmap(cerca_vert, 296, 541, 0);
    al_draw_bitmap(cerca_vert, 481, 541, 0);
    al_draw_bitmap(cerca_vert, 518, 541, 0);
    for(i = 629; i <= 777; i += 37){
        al_draw_bitmap(cerca_vert, i, 541, 0);
    }
    al_draw_bitmap(cerca_vert, 851, 541, 0);
    for(i = 222; i <= 333; i += 37){
        al_draw_bitmap(cerca_vert, i, 504, 0);
    }
    al_draw_bitmap(cerca_vert, 407, 504, 0);
    for(i = 504; i >= 134; i -= 37){
        al_draw_bitmap(cerca_vert, 592, i, 0);
    }
    for(i = 629; i <= 740; i += 37){
        al_draw_bitmap(cerca_vert, i, 504, 0);
    }
    al_draw_bitmap(cerca_vert, 851, 504, 0);
    al_draw_bitmap(cerca_vert, 888, 504, 0);
    for(i = 504; i >= 97; i -= 37){
        al_draw_bitmap(cerca_vert, 962, i, 0);
    }
    al_draw_bitmap(cerca_vert, 259, 467, 0);
    al_draw_bitmap(cerca_vert, 296, 467, 0);
    al_draw_bitmap(cerca_vert, 370, 467, 0);
    al_draw_bitmap(cerca_vert, 407, 467, 0);
    al_draw_bitmap(cerca_vert, 629, 467, 0);
    al_draw_bitmap(cerca_vert, 666, 467, 0);
    al_draw_bitmap(cerca_vert, 740, 467, 0); 
    al_draw_bitmap(cerca_vert, 851, 467, 0); 
    al_draw_bitmap(cerca_vert, 888, 467, 0); 
    for(i = 467; i >= 97; i -= 37){
        al_draw_bitmap(cerca_vert, 925, i, 0);
    }
    al_draw_bitmap(cerca_vert, 37, 430, 0); 
    al_draw_bitmap(cerca_vert, 111, 430, 0);
    al_draw_bitmap(cerca_vert, 259, 430, 0);
    al_draw_bitmap(cerca_vert, 333, 430, 0);
    al_draw_bitmap(cerca_vert, 370, 430, 0);
    al_draw_bitmap(cerca_vert, 407, 430, 0);
    al_draw_bitmap(cerca_vert, 629, 430, 0);
    al_draw_bitmap(cerca_vert, 777, 430, 0);
    al_draw_bitmap(cerca_vert, 851, 430, 0);
    al_draw_bitmap(cerca_vert, 74, 393, 0);
    al_draw_bitmap(cerca_vert, 148, 393, 0);
    al_draw_bitmap(cerca_vert, 222, 393, 0);
    al_draw_bitmap(cerca_vert, 333, 393, 0);
    al_draw_bitmap(cerca_vert, 370, 393, 0);
    al_draw_bitmap(cerca_vert, 407, 393, 0);
    al_draw_bitmap(cerca_vert, 629, 393, 0);
    al_draw_bitmap(cerca_vert, 703, 393, 0);
    al_draw_bitmap(cerca_vert, 851, 393, 0);
    for(i = 393; i >= 60; i -= 37){
        al_draw_bitmap(cerca_vert, 888, i, 0);
    }
    al_draw_bitmap(cerca_vert, 148, 356, 0);
    al_draw_bitmap(cerca_vert, 333, 356, 0);
    al_draw_bitmap(cerca_vert, 370, 356, 0);
    al_draw_bitmap(cerca_vert, 407, 356, 0);
    al_draw_bitmap(cerca_vert, 629, 356, 0);
    al_draw_bitmap(cerca_vert, 666, 356, 0);
    al_draw_bitmap(cerca_vert, 703, 356, 0);
    al_draw_bitmap(cerca_vert, 740, 356, 0);
    al_draw_bitmap(cerca_vert, 851, 356, 0);
    al_draw_bitmap(cerca_vert, 111, 319, 0);
    al_draw_bitmap(cerca_vert, 222, 319, 0);
    al_draw_bitmap(cerca_vert, 296, 319, 0);
    al_draw_bitmap(cerca_vert, 333, 319, 0);
    al_draw_bitmap(cerca_vert, 407, 319, 0);
    al_draw_bitmap(cerca_vert, 629, 319, 0);
    al_draw_bitmap(cerca_vert, 666, 319, 0);
    al_draw_bitmap(cerca_vert, 703, 319, 0);
    for(i = 222; i <= 444; i += 37){
        al_draw_bitmap(cerca_vert, i, 282, 0);
    }
    al_draw_bitmap(cerca_vert, 555, 282, 0);
    al_draw_bitmap(cerca_vert, 666, 282, 0);
    al_draw_bitmap(cerca_vert, 37, 245, 0);
    al_draw_bitmap(cerca_vert, 111, 245, 0);
    al_draw_bitmap(cerca_vert, 259, 245, 0);
    al_draw_bitmap(cerca_vert, 333, 245, 0);
    al_draw_bitmap(cerca_vert, 370, 245, 0);
    al_draw_bitmap(cerca_vert, 407, 245, 0);
    al_draw_bitmap(cerca_vert, 518, 245, 0);
    al_draw_bitmap(cerca_vert, 555, 245, 0);
    al_draw_bitmap(cerca_vert, 629, 245, 0);
    al_draw_bitmap(cerca_vert, 703, 245, 0);
    al_draw_bitmap(cerca_vert, 74, 208, 0);
    al_draw_bitmap(cerca_vert, 370, 208, 0);
    al_draw_bitmap(cerca_vert, 518, 208, 0);
    al_draw_bitmap(cerca_vert, 555, 208, 0);
    al_draw_bitmap(cerca_vert, 629, 208, 0);
    al_draw_bitmap(cerca_vert, 666, 208, 0);
    al_draw_bitmap(cerca_vert, 740, 208, 0);
    al_draw_bitmap(cerca_vert, 851, 208, 0);
    al_draw_bitmap(cerca_vert, 222, 171, 0);
    al_draw_bitmap(cerca_vert, 333, 171, 0);
    al_draw_bitmap(cerca_vert, 555, 171, 0);
    al_draw_bitmap(cerca_vert, 629, 171, 0);
    al_draw_bitmap(cerca_vert, 666, 171, 0);
    al_draw_bitmap(cerca_vert, 777, 171, 0);
    al_draw_bitmap(cerca_vert, 814, 171, 0);
    al_draw_bitmap(cerca_vert, 851, 171, 0);
    al_draw_bitmap(cerca_vert, 111, 134, 0);
    al_draw_bitmap(cerca_vert, 259, 134, 0);
    al_draw_bitmap(cerca_vert, 370, 134, 0);
    al_draw_bitmap(cerca_vert, 629, 134, 0);
    al_draw_bitmap(cerca_vert, 666, 134, 0);
    al_draw_bitmap(cerca_vert, 703, 134, 0);
    al_draw_bitmap(cerca_vert, 814, 134, 0);
    al_draw_bitmap(cerca_vert, 851, 134, 0);
    al_draw_bitmap(cerca_vert, 37, 97, 0);
    al_draw_bitmap(cerca_vert, 111, 97, 0);
    al_draw_bitmap(cerca_vert, 148, 97, 0);
    al_draw_bitmap(cerca_vert, 222, 97, 0);
    al_draw_bitmap(cerca_vert, 296, 97, 0);
    for(i = 407; i <= 703; i += 74){
        al_draw_bitmap(cerca_vert, i, 97, 0);
    }
    for(i = 666; i <= 814; i += 74){
        al_draw_bitmap(cerca_vert, i, 97, 0);
    }
    for(i = 37; i <= 259; i += 37){
        al_draw_bitmap(cerca_vert, i, 60, 0);
    }
    al_draw_bitmap(cerca_vert, 333, 60, 0);
    for(i = 407; i <= 592; i += 37){
        al_draw_bitmap(cerca_vert, i, 60, 0);
    }
    for(i = 666; i <= 814; i += 37){
        al_draw_bitmap(cerca_vert, i, 60, 0);
    }
    al_draw_bitmap(cerca_vert, 74, 23, 0);
    al_draw_bitmap(cerca_vert, 185, 23, 0);
    al_draw_bitmap(cerca_vert, 370, 23, 0);
    al_draw_bitmap(cerca_vert, 444, 23, 0);
    al_draw_bitmap(cerca_vert, 518, 23, 0);
    al_draw_bitmap(cerca_vert, 629, 23, 0);
    al_draw_bitmap(cerca_vert, 777, 23, 0);
    al_draw_bitmap(cerca_vert, 851, 23, 0);
    al_draw_bitmap(cerca_vert, 962, 23, 0);
}

int posicaoPersonagem(int *vet) {

  int var = 0, i;

  /*for(i = 0; i < num_elementos_vet; i++)
    vet[i];*/
  
  srand((unsigned) time(NULL));
  //int num = sizeof vet / sizeof *vet;

  var = rand() % 539;

  return var;

}

void posicaoVirus(int *vet, int x, int *recebe) {

  int aux, i;

  for(i = 0; i < num_elementos_vet; i++)
    vet[i];

  srand((unsigned) time(NULL));
  int num = sizeof vet / sizeof *vet;

  recebe[0] = x;

  for(i = 0; i != num_Virus;) {
    
    aux = vet[rand() % num];
    
    if(aux != recebe[i]) {
        
        recebe[i] = aux;
        i++;

    }
  }
}

void matriz_Posicao(int matriz[][27]) {

    int i;
    
    for(i = 0; i < 27; i++){
            matriz[0][i] = 15;
        }
        matriz[0][1] = 35;
        matriz[0][3] *= 7;
        matriz[0][4] = 35;
        matriz[0][6] *= 7;
        matriz[0][7] *= 7;
        matriz[0][8] = 21;
        matriz[0][9] = 35;
        matriz[0][11] = 35;
        matriz[0][13] = 35;
        matriz[0][15] *= 7;
        matriz[0][16] = 35;
        matriz[0][17] = 3;
        matriz[0][18] *= 7;
        matriz[0][19] *= 7;
        matriz[0][20] = 35;
        matriz[0][22] = 35;
        matriz[0][24] = 7;
        matriz[0][25] = 7;
        matriz[0][26] = 5;
        for(i = 0; i <= 6; i++){
            matriz[1][i] = 10;
        }
        matriz[1][7] = 6;
        matriz[1][8] = 35;
        matriz[1][9] = 6;
        matriz[1][10] = 14;
        for(i = 11; i <= 15; i++){
            matriz[1][i] = 10;
        }
        matriz[1][16] = 6;
        matriz[1][17] = 35;
        for(i = 1; i <= 3; i++){
            matriz[i][18] = 10;
        }
        for(i = 1; i <= 2; i++){
            matriz[i][19] = 10;
        }
        matriz[1][20] = 10;
        matriz[1][21] = 10;
        matriz[1][22] = 6;
        matriz[1][23] = 14;
        matriz[1][24] = 15;
        matriz[1][25] = 21;
        matriz[1][26] = 14;
        matriz[2][0] = 10;
        matriz[2][1] = 6;
        matriz[2][2] = 14;
        matriz[2][3] = 10;
        matriz[2][4] = 6;
        matriz[2][5] = 14;
        matriz[2][6] = 6;
        matriz[2][7] = 35;
        matriz[2][8] = 6;
        matriz[2][9] = 21;
        matriz[2][10] = 35;
        matriz[2][11] = 6;
        matriz[2][12] = 14;
        matriz[2][13] = 6;
        matriz[2][14] = 14;
        matriz[2][15] = 6;
        matriz[2][16] = 35;
        for(i = 2; i <= 5; i++){
            matriz[i][17] = 10;
        }
        matriz[2][20] = 6;
        matriz[2][21] = 14;
        matriz[2][22] = 15;
        matriz[2][23] = 7;
        for(i = 2; i <= 12; i++){
            matriz[i][24] = 10;
        }
        matriz[2][25] = 5;
        matriz[2][26] = 5;
        matriz[3][0] = 6;
        matriz[3][1] = 21;
        matriz[3][2] = 35;
        matriz[3][3] = 6;
        matriz[3][4] = 21;
        matriz[3][5] = 21;
        matriz[3][6] = 35;
        matriz[3][7] = 6;
        matriz[3][8] = 21;
        matriz[3][9] = 35;
        matriz[3][10] = 6;
        matriz[3][11] = 21;
        matriz[3][12] = 21;
        matriz[3][13] = 21;
        matriz[3][14] = 21;
        matriz[3][15] = 35;
        for(i = 3; i <= 6; i++){
            matriz[i][16] = 10;
        }
        matriz[3][19] = 6;
        matriz[3][20] = 21;
        matriz[3][21] = 35;
        matriz[3][22] = 10;
        matriz[3][23] = 5;
        for(i = 3; i <= 12; i++){
            matriz[i][25] = 10;
        }
        for(i = 3; i <= 13; i++){
            matriz[i][26] = 10;
        }
        matriz[4][0] = 15;
        matriz[4][1] = 21;
        matriz[4][2] = 42;
        matriz[4][3] = 21;
        matriz[4][4] = 21;
        matriz[4][5] = 35;
        matriz[4][6] = 6;
        matriz[4][7] = 21;
        matriz[4][8] = 7;
        matriz[4][9] = 6;
        for(i = 10; i <= 13; i++){
            matriz[4][i] = 21;
        }
        matriz[4][14] = 35;
        matriz[4][15] = 10;
        matriz[4][18] = 6;
        matriz[4][19] = 21;
        matriz[4][20] = 35;
        matriz[4][21] = 2;
        matriz[4][22] = 10;
        matriz[4][23] = 10;
        matriz[5][0] = 30;
        matriz[5][1] = 35;
        matriz[5][2] = 15;
        matriz[5][3] = 21;
        matriz[5][4] = 35;
        matriz[5][5] = 6;
        matriz[5][6] = 21;
        matriz[5][7] = 21;
        matriz[5][8] = 21;
        matriz[5][9] = 35;
        matriz[5][10] = 15;
        matriz[5][11] = 21;
        matriz[5][12] = 21;
        matriz[5][13] = 35;
        matriz[5][14] = 10;
        matriz[5][15] = 10;
        matriz[5][18] = 15;
        matriz[5][19] = 35;
        matriz[5][20] = 6;
        matriz[5][21] = 105;
        matriz[5][22] = 14;
        matriz[5][23] = 10;
        matriz[6][0] = 10;
        matriz[6][1] = 6;
        matriz[6][2] = 14;
        matriz[6][3] = 3;
        matriz[6][4] = 14;
        matriz[6][5] = 15;
        matriz[6][6] = 35;
        matriz[6][7] = 15;
        matriz[6][8] = 35;
        matriz[6][9] = 10;
        for(i = 6; i <= 12; i++){
            matriz[i][10] = 10;
        }
        matriz[6][11] = 3;
        matriz[6][12] = 21;
        matriz[6][13] = 14;
        matriz[6][14] = 10;
        matriz[6][15] = 10;
        matriz[6][17] = 6;
        matriz[6][18] = 14;
        matriz[6][19] = 6;
        matriz[6][20] = 21;
        matriz[6][21] = 42;
        matriz[6][22] = 21;
        matriz[6][23] = 14;
        matriz[7][0] = 6;
        matriz[7][1] = 21;
        matriz[7][2] = 21;
        matriz[7][3] = 21;
        matriz[7][4] = 35;
        for(i = 5; i <= 8; i++){
            matriz[7][i] = 10;
        }
        matriz[7][9] = 2;
        matriz[7][11] = 10;
        matriz[7][12] = 3;
        matriz[7][13] = 21;
        matriz[7][14] = 14;
        matriz[7][15] = 2;
        matriz[7][16] = 6;
        matriz[7][17] = 35;
        matriz[7][18] = 15;
        for(i = 19; i <= 22; i++){
            matriz[7][i] = 21;
        }
        matriz[7][23] = 7;
        matriz[8][0] = 15;
        matriz[8][1] = 21;
        matriz[8][2] = 7;
        matriz[8][3] = 15;
        matriz[8][4] = 10;
        matriz[8][5] = 2;
        matriz[8][6] = 6;
        matriz[8][7] = 14;
        matriz[8][8] = 10;
        matriz[8][9] = 15;
        for(i = 8; i <= 12; i++){
            matriz[i][11] = 30;
        }
        matriz[8][12] = 105;
        matriz[8][13] = 105;
        matriz[8][14] = 105;
        matriz[8][15] = 35;
        matriz[8][16] = 5;
        matriz[8][17] = 10;
        matriz[8][18] = 10;
        matriz[8][19] = 15;
        matriz[8][20] = 21;
        matriz[8][21] = 21;
        matriz[8][22] = 21;
        matriz[8][23] = 35;
        matriz[9][0] = 6;
        matriz[9][1] = 21;
        matriz[9][2] = 21;
        matriz[9][3] = 14;
        matriz[9][4] = 10;
        matriz[9][5] = 15;
        matriz[9][6] = 21;
        matriz[9][7] = 21;
        matriz[9][8] = 14;
        matriz[9][9] = 10;
        for(i = 9; i <= 12; i++){
            matriz[i][12] = 210;
        }
        for(i = 9; i <= 13; i++){
            matriz[i][13] = 210;
        }
        for(i = 9; i <= 13; i++){
            matriz[i][14] = 210;
        }
        for(i = 9; i <= 12; i++){
            matriz[i][15] = 70;
        }
        for(i = 9; i <= 13; i++){
            matriz[i][16] = 10;
        }
        matriz[9][17] = 10;
        matriz[9][18] = 10;
        matriz[9][19] = 10;
        matriz[9][20] = 3;
        matriz[9][21] = 21;
        matriz[9][22] = 35;
        for(i = 9; i <= 13; i++){
            matriz[i][23] = 10;
        }
        matriz[10][0] = 15;
        matriz[10][1] = 35;
        matriz[10][2] = 15;
        matriz[10][3] = 35;
        matriz[10][4] = 10;
        matriz[10][5] = 10;
        matriz[10][6] = 15;
        matriz[10][7] = 21;
        matriz[10][8] = 35;
        matriz[10][9] = 10;
        matriz[10][17] = 6;
        matriz[10][18] = 14;
        matriz[10][19] = 6;
        matriz[10][20] = 21;
        matriz[10][21] = 35;
        for(i = 10; i <= 15; i++){
            matriz[i][22] = 10;
        }
        matriz[11][0] = 10;
        matriz[11][1] = 6;
        matriz[11][2] = 14;
        matriz[11][3] = 6;
        matriz[11][4] = 14;
        matriz[11][5] = 6;
        matriz[11][6] = 14;
        matriz[11][7] = 15;
        matriz[11][8] = 14;
        matriz[11][9] = 10;
        matriz[11][17] = 15;
        matriz[11][18] = 21;
        matriz[11][19] = 21;
        matriz[11][20] = 35;
        matriz[11][21] = 10;
        matriz[12][0] = 6;
        matriz[12][1] = 21;
        matriz[12][2] = 21;
        matriz[12][3] = 21;
        matriz[12][4] = 35;
        matriz[12][5] = 15;
        matriz[12][6] = 35;
        for(i = 12; i <= 15; i++){
            matriz[i][7] = 10;
        }
        matriz[12][8] = 15;
        matriz[12][9] = 14;
        matriz[12][17] = 10;
        matriz[12][18] = 15;
        matriz[12][19] = 35;
        matriz[12][20] = 6;
        matriz[12][21] = 14;
        matriz[13][0] = 15;
        matriz[13][1] = 21;
        matriz[13][2] = 21;
        matriz[13][3] = 21;
        matriz[13][4] = 14;
        matriz[13][5] = 10;
        matriz[13][6] = 10;
        matriz[13][8] = 10;
        matriz[13][9] = 3;
        matriz[13][10] = 14;
        matriz[13][11] = 6;
        matriz[13][12] = 42;
        matriz[13][15] = 14;
        matriz[13][17] = 10;
        matriz[13][18] = 10;
        matriz[13][19] = 10;
        matriz[13][20] = 15;
        matriz[13][21] = 35;
        matriz[13][24] = 6;
        matriz[13][25] = 14;
        matriz[14][0] = 10;
        matriz[14][1] = 15;
        matriz[14][2] = 35;
        matriz[14][3] = 15;
        matriz[14][4] = 35;
        matriz[14][5] = 10;
        matriz[14][6] = 6;
        matriz[14][8] = 6;
        matriz[14][9] = 21;
        matriz[14][10] = 21;
        matriz[14][11] = 21;
        matriz[14][12] = 35;
        matriz[14][13] = 10;
        matriz[14][14] = 30;
        matriz[14][15] = 21;
        matriz[14][16] = 14;
        for(i = 17; i <= 21; i++){
            matriz[14][i] = 10;
        }
        matriz[14][23] = 6;
        matriz[14][24] = 21;
        matriz[14][25] = 21;
        matriz[14][26] = 14;
        matriz[15][0] = 6;
        matriz[15][1] = 14;
        matriz[15][2] = 6;
        matriz[15][3] = 14;
        matriz[15][4] = 6;
        matriz[15][5] = 42;
        matriz[15][6] = 35;
        matriz[15][8] = 3;
        matriz[15][9] = 21;
        matriz[15][10] = 21;
        matriz[15][11] = 35;
        matriz[15][12] = 10;
        matriz[15][13] = 2;
        matriz[15][14] = 6;
        matriz[15][15] = 21;
        matriz[15][16] = 21;
        matriz[15][17] = 14;
        for(i = 18; i <= 21; i++){
            matriz[15][i] = 10;
        }
        matriz[15][23] = 15;
        matriz[15][24] = 35;
        matriz[15][25] = 15;
        matriz[15][26] = 35;
        matriz[16][0] = 15;
        for(i = 1; i <= 5; i++){
            matriz[16][i] = 21;
        }
        matriz[16][6] = 14;
        matriz[16][7] = 6;
        matriz[16][8] = 21;
        matriz[16][9] = 21;
        matriz[16][10] = 21;
        matriz[16][11] = 14;
        matriz[16][12] = 6;
        for(i = 13; i <= 17; i++){
            matriz[16][i] = 21;
        }
        matriz[16][18] = 14;
        matriz[16][19] = 6;
        matriz[16][20] = 14;
        matriz[16][21] = 10;
        matriz[16][22] = 6;
        matriz[16][23] = 14;
        matriz[16][24] = 6;
        matriz[16][25] = 14;
        matriz[16][26] = 10;
        matriz[17][0] = 6;
        matriz[17][1] = 35;
        matriz[17][2] = 15;
        for(i = 3; i <= 7; i++){
            matriz[17][i] = 21;
        }
        matriz[17][8] = 35;
        matriz[17][9] = 15;
        for(i = 10; i <= 20; i++){
            matriz[17][i] = 21;
        }
        matriz[17][21] = 14;
        matriz[17][22] = 15;
        matriz[17][23] = 21;
        matriz[17][24] = 21;
        matriz[17][25] = 21;
        matriz[17][26] = 14;
        matriz[18][0] = 15;
        matriz[18][1] = 14;
        matriz[18][2] = 10;
        matriz[18][3] = 15;
        matriz[18][4] = 35;
        matriz[18][5] = 15;
        matriz[18][6] = 35;
        matriz[18][7] = 5;
        matriz[18][8] = 30;
        matriz[18][9] = 14;
        for(i = 10; i <= 20; i += 2){
            matriz[18][i] = 15;
            matriz[18][i + 1] = 35;
        }
        matriz[18][22] = 6;
        matriz[18][23] = 21;
        matriz[18][24] = 21;
        matriz[18][25] = 21;
        matriz[18][26] = 35;
        matriz[19][0] = 6;
        matriz[19][1] = 21;
        matriz[19][2] = 42;
        matriz[19][3] = 14;
        matriz[19][4] = 6;
        matriz[19][5] = 14;
        matriz[19][6] = 6;
        matriz[19][7] = 14;
        matriz[19][8] = 6;
        matriz[19][9] = 21;
        for(i = 10; i <= 20; i += 2){
            matriz[19][i] = 14;
            matriz[19][i + 1] = 6;
        }
        for(i = 22; i <= 25; i++){
            matriz[19][i] = 21;
        }
        matriz[19][26] = 14;
}

void desenhaPersonagem(int x) {

    int var = (x / 27), var2 = (x % 27);

    int posicao_p_x = 23 + 37 * var + 37/2;
    int posicao_p_y = 10 + 37 * var2 + 37/2;

    al_draw_bitmap(cearense_doctor, posicao_p_x, posicao_p_y, 0);

}

void desenhaVirus(int *x) {

    int i, j, k, l, m;

    for(i = 0; i < 4; i++) {
        
        int posicao_p_x = 23 + 37 * (x[i] / 27) + 37/2;
        int posicao_p_y = 10 + 37 * (x[i] % 27) + 37/2;
        
        al_draw_bitmap(Blue_Virus, posicao_p_x, posicao_p_y, 0);
        
        }
    
    for(j = i + 1; i < 4; i++) {
        
        int posicao_p_x = 23 + 37 * (x[i] / 27) + 37/2;
        int posicao_p_y = 10 + 37 * (x[i] % 27) + 37/2;
        
        al_draw_bitmap(Green_Virus, posicao_p_x, posicao_p_y, 0);
        
        }
    
    for(k = j + 1; i < 4; i++) {
        
        int posicao_p_x = 23 + 37 * (x[i] / 27) + 37/2;
        int posicao_p_y = 10 + 37 * (x[i] % 27) + 37/2;
        
        al_draw_bitmap(Pink_Virus, posicao_p_x, posicao_p_y, 0);
        
        }
    
    for(l = k + 1; i < 4; i++) {
        
        int posicao_p_x = 23 + 37 * (x[i] / 27) + 37/2;
        int posicao_p_y = 10 + 37 * (x[i] % 27) + 37/2;
        
        al_draw_bitmap(Red_Virus, posicao_p_x, posicao_p_y, 0);
        
        }
    
    for(m = l + 1; i < 4; i++) {
        
        int posicao_p_x = 23 + 37 * (x[i] / 27) + 37/2;
        int posicao_p_y = 10 + 37 * (x[i] % 27) + 37/2;
        
        al_draw_bitmap(Yellow_Virus, posicao_p_x, posicao_p_y, 0);
        
        }
        

}