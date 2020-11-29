#ifndef CLIENT_H
#define CLIENT_H

#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define num_elementos_vet 540
#define linha_Matriz 20
#define coluna_Matriz 27
#define largura 1024
#define Profundidade 768
#define FPS 60

void DesenharGrama();
void DesenharParede();
void desenhaVirus(int *x);
int posicaoPersonagem(int *vet);
void posicaoVirus(int *vet, int x, int *recebe);
void matriz_Posicao(int matriz[][27]);
int verificatecla();
void andar(int tecla);

#endif