#include "lib.h"
#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_BITMAP *grama = NULL, *cerca = NULL, *cerca_vert = NULL, *kit = NULL, *vacina = NULL, *cearense_doctor = NULL, *cearense_doctor_1 = NULL, *cearense_doctor_2 = NULL, *Blue_Virus = NULL, *Green_Virus = NULL, *Pink_Virus = NULL, *Red_Virus = NULL, *Yellow_Virus = NULL;
ALLEGRO_EVENT event;
ALLEGRO_TIMER *timer = NULL;

int tecla;
int teclaatual;
int zona;
int posicao_p_x;
int posicao_p_y;

int chegou = 0;

bool running = true;
bool redraw = true;

int recebe[20] = {0};
int Vetor_Posicao[num_elementos_vet];
int matriz[linha_Matriz][coluna_Matriz];


int posicaoPersonagem(int *vet) {

  int var = 0, i;

  /*for(i = 0; i < num_elementos_vet; i++)
    vet[i];*/
  
  srand((unsigned) time(NULL));
  //int num = sizeof vet / sizeof *vet;

  var = rand() % 539;

  return var;

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


void desenhaVirus() {

    al_draw_bitmap(Blue_Virus, posicao_p_x, posicao_p_y, 0);
    
    al_draw_bitmap(Green_Virus, posicao_p_x, posicao_p_y, 0);
        
    al_draw_bitmap(Pink_Virus, posicao_p_x, posicao_p_y, 0);
        
    al_draw_bitmap(Red_Virus, posicao_p_x, posicao_p_y, 0);
        
    al_draw_bitmap(Yellow_Virus, posicao_p_x, posicao_p_y, 0);

}

int verificatecla(){
    if (event.type == ALLEGRO_EVENT_KEY_DOWN){
        switch(event.keyboard.keycode){
        case ALLEGRO_KEY_W:
            tecla = 1;
            break;
        case ALLEGRO_KEY_D:
            tecla = 2;
            break;
        case ALLEGRO_KEY_S:
            tecla = 3;
            break;
        case ALLEGRO_KEY_A:
            tecla = 4;
            break;
        }
    }
    else if (event.type == ALLEGRO_EVENT_KEY_UP){
        tecla = 5;
    }
    else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
        running = 0;
    }
    if (tecla){
        switch (tecla){
        case 1:
            if(matriz[zona / 27][zona % 27] % 2 == 0){
                return 1;
            }
            break;
        case 2:
            if(matriz[zona / 27][zona % 27] % 3 == 0){
                return 2;
            }
            break;
        case 3:
            if(matriz[zona / 27][zona % 27] % 5 == 0){
                return 3;
            }
            break;
        case 4:
            if(matriz[zona / 27][zona % 27] % 7 == 0){
                return 4;
            }
            break;
        }
        tecla = 0;
    }
    return 0;
}

void andar(int tecla){
    if(chegou == 0){
        switch (tecla)
        {
        case 1:
            teclaatual = 1;
            posicao_p_y--;
            chegou++;
            break;
        case 2:
            teclaatual = 2;
            posicao_p_x++;
            chegou++;
            break;
        case 3:
            teclaatual = 3;
            posicao_p_y++;
            chegou++;
            break;
        case 4:
            teclaatual = 4;
            posicao_p_x--;
            chegou++;
            break;
        }
    }else{
        switch (teclaatual)
        {
        case 1:
            posicao_p_y--;
            chegou++;
            break;
        case 2:
            posicao_p_x++;
            chegou++;
            break;
        case 3:
            posicao_p_y++;
            chegou++;
            break;
        case 4:
            posicao_p_x--;
            chegou++;
            break;
        }
        if(chegou == 37){
            switch (teclaatual)
            {
            case 1:
                zona -= 27;
            case 2:
                zona++;
            case 3:
                zona += 27;
            case 4:
                zona--;
            }
            teclaatual = 0;
            chegou = 0;
        }
    }
}