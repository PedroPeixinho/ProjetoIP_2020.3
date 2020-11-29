#include "lib.h"
#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

extern ALLEGRO_BITMAP *grama, *cerca, *cerca_vert, *kit, *vacina, *cearense_doctor;

#define largura 1024
#define Profundidade 768

#define FPS 60

int initAllegro();

ALLEGRO_DISPLAY *display = NULL;
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
            al_draw_bitmap(kit, 500, 430, 0);
            al_draw_bitmap(vacina, 20, 730, 0);
            al_draw_bitmap(cearense_doctor, 480, 670,0);
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
    kit = al_load_bitmap("src/Ameaças_Ocultas/Resources/Tile_Sets/Imagens_editadas/kit.png");
    vacina = al_load_bitmap("src/Ameaças_Ocultas/Resources/Tile_Sets/Imagens_editadas/Explosives_and_Medic_Icons_From_Youtube_series_PixelTime.png");
    cearense_doctor = al_load_bitmap("src/Ameaças_Ocultas/Resources/Tile_Sets/Imagens_editadas/PARADO.png");

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