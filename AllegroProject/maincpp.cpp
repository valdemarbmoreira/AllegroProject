#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\events.h>
#include <allegro5\keyboard.h>

const int WIDTH = 800;
const int HEIGHT = 600;

int main (void){

	bool done = false;
	float altera_y = 0;

	//Allegro objects
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_FONT *font = NULL;
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;


	if(!al_init())
		return -1; // erro ao iniciclizar o allegro

	display = al_create_display(WIDTH,HEIGHT);

	//Allegro addons
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
    

	if(!display)	
		return -1;

	event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue,al_get_display_event_source(display));

	font = al_load_font("OpenSans-Regular.ttf", 20, 0);

	
	while(!done){

		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			done = true;
		}

		if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
			if(ev.keyboard.keycode == ALLEGRO_KEY_UP){
				altera_y -= 10;
			}

			if(ev.keyboard.keycode == ALLEGRO_KEY_DOWN){
				altera_y += 10;
			}

		}
		if(ev.type == ALLEGRO_EVENT_KEY_UP){

		}

		al_clear_to_color(al_map_rgb(255,255,255));
		al_draw_filled_circle(WIDTH/2,HEIGHT/2 + altera_y,30,al_map_rgb(0,0,0));
		al_draw_text(font,al_map_rgb(0,0,255),WIDTH/2, HEIGHT/2 + 100 ,ALLEGRO_ALIGN_CENTER ,"Trabalhando com fontes no Allegro");
		al_flip_display();
	}

	al_destroy_display(display);
	al_destroy_font(font);
	al_destroy_event_queue(event_queue);

	return 0;
}

