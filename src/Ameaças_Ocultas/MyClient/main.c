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
ALLEGRO_BITMAP *imagem = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;

int main(int argc, char *argv[]) {
    printf("O segredo do universo é %d\n", SegredoDoUniverso());

    int err = initAllegro();
    if(err) {
        return err;
    }

    bool running = true;
    bool redraw = true;

    // Display a Green screen
    al_clear_to_color(al_map_rgb(0, 255, 0));
    al_flip_display();

    // Game loop
    while (running) {
        ALLEGRO_EVENT event;

        // Check if we need to redraw
        if (redraw && al_is_event_queue_empty(event_queue)) {
            // Redraw
            al_clear_to_color(al_map_rgb(0, 255, 0));
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

    // Create the display
    display = al_create_display(largura, Profundidade);
    if (!display) {
        fprintf(stderr, "Failed to create display.\n");
        return 1;
    }

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