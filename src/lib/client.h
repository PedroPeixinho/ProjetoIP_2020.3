#ifndef CLIENT_H
#define CLIENT_H

#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

void DesenharGrama();
void DesenharParede();
void desenhaPersonagem(int *x);
int* posicaoPersonagem(int **v);
int* posicaoVirus(int **v, int *x);
int** matriz_Posicao();

#endif