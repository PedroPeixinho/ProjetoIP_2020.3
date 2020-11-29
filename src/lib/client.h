#ifndef CLIENT_H
#define CLIENT_H

#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define posicaoMatriz 540
#define linha_Matriz 20
#define coluna_Matriz 27

void DesenharGrama();
void DesenharParede();
void desenhaPersonagem(int x);
void desenhaVirus(int *x);
int posicaoPersonagem(int *vet);
int* posicaoVirus(int *vet, int x);
int** matriz_Posicao();

#endif