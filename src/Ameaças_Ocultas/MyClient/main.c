#include "lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define largura 1024
#define Profundidade 768

#define FPS 60

int initAllegro();

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_BITMAP *grama = NULL, *cerca = NULL, *cerca_vert = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;

void DesenharGrama();

void DesenharParede();

int main(int argc, char *argv[]) {
    printf("O segredo do universo é %d\n", SegredoDoUniverso());

    int err = initAllegro();
    if(err) {
        return err;
    }

    bool running = true;
    bool redraw = true;

    // Display a Green screen
    al_clear_to_color(al_map_rgb(0, 110, 0));
    al_flip_display();

    // Game loop
    while (running) {
        ALLEGRO_EVENT event;

        // Check if we need to redraw
        if (redraw && al_is_event_queue_empty(event_queue)) {
            // Redraw
            al_clear_to_color(al_map_rgb(0, 110, 0));
            DesenharGrama();
            DesenharParede();
            al_flip_display();
            redraw = false;
        }
    }

    // Clean up
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);

    return 0;
}

int initAllegro() {
    // Initialize allegro
    if (!al_init()) {
        fprintf(stderr, "Failed to initialize allegro.\n");
        return 1;
    }

    al_init_image_addon();

    // Create the display
    display = al_create_display(largura, Profundidade);
    if (!display) {
        fprintf(stderr, "Failed to create display.\n");
        return 1;
    }

    grama = al_load_bitmap("src/Ameaças_Ocultas/Resources/Tile_Sets/Imagens_editadas/GramaPQ.png");
    cerca = al_load_bitmap("src/Ameaças_Ocultas/Resources/Tile_Sets/Imagens_editadas/cerca_edit2.png");
    cerca_vert = al_load_bitmap("src/Ameaças_Ocultas/Resources/Tile_Sets/Imagens_editadas/cerca_edit_vert2.png");

    // Create the event queue
    event_queue = al_create_event_queue();
    if (!event_queue) {
        fprintf(stderr, "Failed to create event queue.");
        return 1;
    }

    // Register event sources
    al_register_event_source(event_queue, al_get_display_event_source(display));

    return 0;
}

void DesenharGrama(){
    
    int i, j;
    
    for(i = 0; i < 1024; i += 50){
        
        for(j = 0; j < 768; j += 50){
            al_draw_bitmap(grama, i, j, 0);
        }
    }
}

void DesenharParede(){
    
    int i, j = 0;
    
    for(i = 0; i < 1024; i += 37){
        al_draw_bitmap(cerca, i, 0, 0);
        al_draw_bitmap(cerca, i, 758, 0);
    }
    
    for(i = 0; i < 768; i += 37){
        al_draw_bitmap(cerca_vert, 0, i, 0);
        al_draw_bitmap(cerca_vert, 1014, i, 0);
    }

    al_draw_bitmap(cerca, 47, 715, 0);
    al_draw_bitmap(cerca, 306, 715, 0);
    al_draw_bitmap(cerca, 750, 715, 0);
    
    for(i = 750; j < 3; i+=37) {
        j++;
        al_draw_bitmap(cerca, i, 715, 0);
    }

    al_draw_bitmap(cerca, 10, 752, 0);
    
    for(i = 84; j < 5; i+=37) {
        j++;
        al_draw_bitmap(cerca, i, 752, 0);
    }

    for(i = 343; j < 12; i+=37) {
        j++;
        al_draw_bitmap(cerca, i, 752, 0);
    }

    for(i = 861; j < 4; i+=37) {
        j++;
        al_draw_bitmap(cerca, i, 752, 0);
    }

    for(i = 47; j < 20; i+=37) {
        j++;
        al_draw_bitmap(cerca, i, 789, 0);
    }

    for(i = 787; j < 4; i+=37) {
        j++;
        al_draw_bitmap(cerca, i, 789, 0);
    }

    for(i = 10; j < 6; i+=37) {
        j++;
        al_draw_bitmap(cerca, i, 826, 0);
    }

    for(i = 232; j < 3; i+=37) {
        j++;
        al_draw_bitmap(cerca, i, 826, 0);
    }

    for(i = 417; j < 5; i+=37) {
        j++;
        al_draw_bitmap(cerca, i, 826, 0);
    }

    for(i = 195; j < 1; i+=37) {
        j++;
        al_draw_bitmap(cerca, i, 863, 0);
    }

    for(i = 232; j < 4; i+=37) {
        j++;
        al_draw_bitmap(cerca, i, 863, 0);
    }

    for(i = 491; j < 2; i+=37) {
        j++;
        al_draw_bitmap(cerca, i, 863, 0);
    }

    for(i = 787; j < 4; i+=37) {
        j++;
        al_draw_bitmap(cerca, i, 863, 0);
    }


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
    for(i = 629; i <= 740; i += 37){
        al_draw_bitmap(cerca_vert, i, 504, 0);
    }
    al_draw_bitmap(cerca_vert, 851, 504, 0);
    al_draw_bitmap(cerca_vert, 888, 504, 0);
    for(i = 504; i >= 60; i -= 37){
        al_draw_bitmap(cerca_vert, 962, i, 0);
    }
    al_draw_bitmap(cerca_vert, 259, 467, 0);
    al_draw_bitmap(cerca_vert, 296, 467, 0);
    al_draw_bitmap(cerca_vert, 370, 467, 0);
    al_draw_bitmap(cerca_vert, 407, 467, 0);
    for(i = 467; i >= 97; i -= 37){
        al_draw_bitmap(cerca_vert, 592, i, 0);
    }
    al_draw_bitmap(cerca_vert, 629, 467, 0);
    al_draw_bitmap(cerca_vert, 666, 467, 0);
    al_draw_bitmap(cerca_vert, 740, 467, 0); 
    al_draw_bitmap(cerca_vert, 851, 467, 0); 
    al_draw_bitmap(cerca_vert, 888, 467, 0); 
    for(i = 467; i >= 60; i -= 37){
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
    for(i = 393; i >= 23; i -= 37){
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
}