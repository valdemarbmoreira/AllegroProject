#include <allegro5\allegro.h>

int main (void){

	ALLEGRO_DISPLAY *display = NULL;

	if(!al_init())
		return -1; // erro ao iniciclizar o allegro

	display = al_create_display(800,600);

	if(!display)	
		return -1;

	while(1);

	return 0;
}

