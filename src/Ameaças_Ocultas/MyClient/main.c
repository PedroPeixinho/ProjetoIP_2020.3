#include "lib.h"
#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

extern int chegou;
extern bool running;
extern bool redraw;
extern int tecla;
extern int teclaatual;
extern int zona;
extern int posicao_p_x;
extern int posicao_p_y;
extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_EVENT event;
extern ALLEGRO_BITMAP *grama, *cerca, *cerca_vert, *kit, *vacina, *cearense_doctor, *cearense_doctor_1, *cearense_doctor_2, *Blue_Virus, *Green_Virus, *Pink_Virus, *Red_Virus, *Yellow_Virus;
extern ALLEGRO_TIMER *timer;
extern int recebe[20];
extern int matriz[20][27];
extern int apertouBotaoPlay, inMenu, inGame, apertouBotaoExit, apertouBotaoHowtoPlay, delay, inChat, inChooseChar;

int initAllegro();

int main(int argc, char *argv[]) {
    printf("O segredo do universo é %d\n", SegredoDoUniverso());

    int err = initAllegro();
    if(err) {
        return err;
    }

    // Display a Green screen
    al_clear_to_color(al_map_rgb(0, 110, 0));
    al_flip_display();

    zona = posicaoPersonagem();
    posicao_p_x = 23 + 37 * (zona / 27) + 37/2;
    posicao_p_y = 10 + 37 * (zona / 27) + 37/2;
    
    // Game loop
    while (running) {
        
        // Check if we need to redraw
        if (redraw && al_is_event_queue_empty(event_queue)) {
            // Redraw
            al_clear_to_color(al_map_rgb(0, 110, 0));
            al_draw_bitmap(kit, 500, 430, 0);
            al_draw_bitmap(vacina, 20, 730, 0);
            al_draw_bitmap(cearense_doctor, posicao_p_x, posicao_p_y, 0);
            desenhaVirus();
            al_flip_display();
            redraw = false;
        }
        while(!al_is_event_queue_empty(event_queue)){
            al_wait_for_event(event_queue, &event);
            if(event.type == ALLEGRO_EVENT_TIMER){
                al_clear_to_color(al_map_rgb(0, 110, 0));
                al_draw_bitmap(kit, 500, 430, 0);
                al_draw_bitmap(vacina, 20, 730, 0);
                if(chegou == 0){
                    al_draw_bitmap(cearense_doctor, posicao_p_x, posicao_p_y, 0);
                }else{
                    if(teclaatual == 4){
                        if(chegou < 10){
                            al_draw_bitmap(cearense_doctor_1, posicao_p_x, posicao_p_y, 1);
                        }else if(chegou < 20){
                            al_draw_bitmap(cearense_doctor_2, posicao_p_x, posicao_p_y, 1);
                        }else if(chegou < 30){
                            al_draw_bitmap(cearense_doctor_1, posicao_p_x, posicao_p_y, 1);
                        }else{
                            al_draw_bitmap(cearense_doctor_2, posicao_p_x, posicao_p_y, 1);
                        }
                    }else{
                        if(chegou < 10){
                            al_draw_bitmap(cearense_doctor_1, posicao_p_x, posicao_p_y, 0);
                        }else if(chegou < 20){
                            al_draw_bitmap(cearense_doctor_2, posicao_p_x, posicao_p_y, 0);
                        }else if(chegou < 30){
                            al_draw_bitmap(cearense_doctor_1, posicao_p_x, posicao_p_y, 0);
                        }else{
                            al_draw_bitmap(cearense_doctor_2, posicao_p_x, posicao_p_y, 0);
                        }
                    }
                }
                desenhaVirus();
                al_flip_display();
            }
            andar(verificatecla());
        }
    }

    // Clean up
    al_destroy_display(display);
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);

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
    if (!al_install_keyboard()){
        fprintf(stderr, "Failed to create keyboard.\n");
        return 1;
    }

    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
        fprintf(stderr, "Failed to create timer.\n");
        return 0;
    }

    grama = al_load_bitmap("src/Ameaças_Ocultas/Resources/Tile_Sets/Imagens_editadas/GramaPQ.png");
    cerca = al_load_bitmap("src/Ameaças_Ocultas/Resources/Tile_Sets/Imagens_editadas/cerca_edit2.png");
    cerca_vert = al_load_bitmap("src/Ameaças_Ocultas/Resources/Tile_Sets/Imagens_editadas/cerca_edit_vert2.png");
    kit = al_load_bitmap("src/Ameaças_Ocultas/Resources/Tile_Sets/Imagens_editadas/kit.png");
    vacina = al_load_bitmap("src/Ameaças_Ocultas/Resources/Tile_Sets/Imagens_editadas/Explosives_and_Medic_Icons_From_Youtube_series_PixelTime.png");
    cearense_doctor = al_load_bitmap("src/Ameaças_Ocultas/Resources/Tile_Sets/Imagens_editadas/PARADO.png");
    cearense_doctor_1 = al_load_bitmap("src/Ameaças_Ocultas/Resources/Tile_Sets/Imagens_editadas/CAMINA 1.png");
    cearense_doctor_2 = al_load_bitmap("src/Ameaças_Ocultas/Resources/Tile_Sets/Imagens_editadas/CAMINA 2.png");
    Blue_Virus = al_load_bitmap("src/Ameaças_Ocultas/Resources/Tile_Sets/Imagens_editadas/Blue_Virus.png");
    Green_Virus = al_load_bitmap("src/Ameaças_Ocultas/Resources/Tile_Sets/Imagens_editadas/Green_Virus.png");
    Pink_Virus = al_load_bitmap("src/Ameaças_Ocultas/Resources/Tile_Sets/Imagens_editadas/Pink_Virus.png");
    Red_Virus = al_load_bitmap("src/Ameaças_Ocultas/Resources/Tile_Sets/Imagens_editadas/Red_Virus.png");
    Yellow_Virus = al_load_bitmap("src/Ameaças_Ocultas/Resources/Tile_Sets/Imagens_editadas/Yellow_Virus.png");

    // Create the event queue
    event_queue = al_create_event_queue();
    if (!event_queue) {
        fprintf(stderr, "Failed to create event queue.");
        return 1;
    }

    matriz_Posicao(matriz);

    // Register event sources
    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_keyboard_event_source()); 
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_start_timer(timer);
    return 0;
}