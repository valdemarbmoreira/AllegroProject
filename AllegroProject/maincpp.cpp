#include <allegro5\allegro.h>
#include <allegro5\\allegro_primitives.h>

const int WIDTH = 800;
const int HEIGHT = 600;

int main (void){

	ALLEGRO_DISPLAY *display = NULL;

	if(!al_init())
		return -1; // erro ao iniciclizar o allegro

	display = al_create_display(WIDTH,HEIGHT);

	al_init_primitives_addon();

	if(!display)	
		return -1;

	al_clear_to_color(al_map_rgb(255,255,255));
	al_draw_filled_circle(WIDTH/2,HEIGHT/2,30,al_map_rgb(0,0,0));
	al_flip_display();
	while(1);

	al_destroy_display(display);

	return 0;
}

