#include "lib.h"
#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

ALLEGRO_BITMAP *grama = NULL, *cerca = NULL, *cerca_vert = NULL, *kit = NULL, *vacina = NULL, *cearense_doctor = NULL;

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