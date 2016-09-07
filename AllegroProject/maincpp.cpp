#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

const int WIDTH = 800;
const int HEIGHT = 600;

int main (void){

	bool done = false;

	//Allegro objects
	ALLEGRO_DISPLAY *display = NULL;
	ALLEGRO_FONT *font = NULL;


	if(!al_init())
		return -1; // erro ao iniciclizar o allegro

	display = al_create_display(WIDTH,HEIGHT);

	//Allegro addons
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
    

	if(!display)	
		return -1;

	font = al_load_font("OpenSans-Regular.ttf", 20, 0);

	
	while(!done){
		al_clear_to_color(al_map_rgb(255,255,255));
		al_draw_filled_circle(WIDTH/2,HEIGHT/2,30,al_map_rgb(0,0,0));
		al_draw_text(font,al_map_rgb(0,0,255),WIDTH/2, HEIGHT/2 + 100 ,ALLEGRO_ALIGN_CENTER ,"Trabalhando com fontes no Allegro");
		al_flip_display();
	}

	al_destroy_display(display);

	return 0;
}

