
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <windows.h>
#include <wchar.h>
#include <locale.h>
#include <string.h>
#include <string>
#include <sstream>




#include <allegro5/allegro.h>

#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>

#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_primitives.h>

#include <allegro5/allegro_image.h>

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>


using namespace std;

ALLEGRO_DISPLAY *display;
ALLEGRO_BITMAP *imageBitmap;
ALLEGRO_FONT *fuente;
ALLEGRO_KEYBOARD_STATE estadoTeclado;
ALLEGRO_EVENT_QUEUE *eventoCola;
ALLEGRO_EVENT eventosTeclado;
ALLEGRO_TIMER *timer;
ALLEGRO_USTR* String;

int pos = (int)al_ustr_size(String);
char entradaTeclado[40] = "";
bool inicio=false;
int i = 0;
int posX = 100;
int a = 1;
int numeroBinario = 0;
const char* cadenaBinaria;
const char* datoAnterior[1] = {0};
int nrzi_x = 50;
int nrzi_y = 250;


void dibujarLineas(char estado[1], int posicion) {
	if (estado == "1"){ //linea alta
		al_draw_line(posicion, 250, posicion * 2, 250, al_map_rgb(255, 0, 0), 2);
	}
	else { //linea baja
		al_draw_line(posicion, 300, posicion * 2, 300, al_map_rgb(255, 0, 0), 2);
	}
}
/*char cod_NRZI(int binario) {


}*/

char* hxtobin(char cadena[100]) {

	char hex[12];
	int res = 0;

	switch (cadena[0]) {
	case '0':
		hex[0] = '0';
		hex[1] = '0';
		hex[2] = '0';
		hex[3] = '0';
		break;

	case '1':
		hex[0] = '0';
		hex[1] = '0';
		hex[2] = '0';
		hex[3] = '1';
		break;

	case '2':
		hex[0] = '0';
		hex[1] = '0';
		hex[2] = '1';
		hex[3] = '0';
		break;

	case '3':
		hex[0] = '0';
		hex[1] = '0';
		hex[2] = '1';
		hex[3] = '1';
		break;

	case '4':
		hex[0] = '0';
		hex[1] = '1';
		hex[2] = '0';
		hex[3] = '0';
		break;
	case '5':
		hex[0] = '0';
		hex[1] = '1';
		hex[2] = '0';
		hex[3] = '1';
		break;
	case '6':
		hex[0] = '0';
		hex[1] = '1';
		hex[2] = '0';
		hex[3] = '1';
		break;
	case '7':
		hex[0] = '0';
		hex[1] = '1';
		hex[2] = '1';
		hex[3] = '1';
		break;
	case '8':
		hex[0] = '1';
		hex[1] = '0';
		hex[2] = '0';
		hex[3] = '0';
		break;
	case '9':
		hex[0] = '1';
		hex[1] = '0';
		hex[2] = '0';
		hex[3] = '1';
		break;
	case 'A':
		hex[0] = '1';
		hex[1] = '0';
		hex[2] = '1';
		hex[3] = '0';
		break;
	case 'B':
		hex[0] = '1';
		hex[1] = '0';
		hex[2] = '1';
		hex[3] = '1';
		break;
	case 'C':
		hex[0] = '1';
		hex[1] = '1';
		hex[2] = '0';
		hex[3] = '0';
		break;
	case 'D':
		hex[0] = '1';
		hex[1] = '1';
		hex[2] = '0';
		hex[3] = '1';
		break;
	case 'E':
		hex[0] = '1';
		hex[1] = '1';
		hex[2] = '1';
		hex[3] = '0';
		break;
	case 'F':
		hex[0] = '1';
		hex[1] = '1';
		hex[2] = '1';
		hex[3] = '1';
		break;
	}

	switch (cadena[1]) {
	case '0':
		hex[4] = '0';
		hex[5] = '0';
		hex[6] = '0';
		hex[7] = '0';
		break;

	case '1':
		hex[4] = '0';
		hex[5] = '0';
		hex[6] = '0';
		hex[7] = '1';
		break;

	case '2':
		hex[4] = '0';
		hex[5] = '0';
		hex[6] = '1';
		hex[7] = '0';
		break;

	case '3':
		hex[4] = '0';
		hex[5] = '0';
		hex[6] = '1';
		hex[7] = '1';
		break;

	case '4':
		hex[4] = '0';
		hex[5] = '1';
		hex[6] = '0';
		hex[7] = '0';
		break;
	case '5':
		hex[4] = '0';
		hex[5] = '1';
		hex[6] = '0';
		hex[7] = '1';
		break;
	case '6':
		hex[4] = '0';
		hex[5] = '1';
		hex[6] = '0';
		hex[7] = '1';
		break;
	case '7':
		hex[4] = '0';
		hex[5] = '1';
		hex[6] = '1';
		hex[7] = '1';
		break;
	case '8':
		hex[4] = '1';
		hex[5] = '0';
		hex[6] = '0';
		hex[7] = '0';
		break;
	case '9':
		hex[4] = '1';
		hex[5] = '0';
		hex[6] = '0';
		hex[7] = '1';
		break;
	case 'A':
		hex[4] = '1';
		hex[5] = '0';
		hex[6] = '1';
		hex[7] = '0';
		break;
	case 'B':
		hex[4] = '1';
		hex[5] = '0';
		hex[6] = '1';
		hex[7] = '1';
		break;
	case 'C':
		hex[4] = '1';
		hex[5] = '1';
		hex[6] = '0';
		hex[7] = '0';
		break;
	case 'D':
		hex[4] = '1';
		hex[5] = '1';
		hex[6] = '0';
		hex[7] = '1';
		break;
	case 'E':
		hex[4] = '1';
		hex[5] = '1';
		hex[6] = '1';
		hex[7] = '0';
		break;
	case 'F':
		hex[4] = '1';
		hex[5] = '1';
		hex[6] = '1';
		hex[7] = '1';
		break;
	}

	switch (cadena[2]) {
	case '0':
		hex[8] = '0';
		hex[9] = '0';
		hex[10] = '0';
		hex[11] = '0';
		break;

	case '1':
		hex[8] = '0';
		hex[9] = '0';
		hex[10] = '0';
		hex[11] = '1';
		break;

	case '2':
		hex[8] = '0';
		hex[9] = '0';
		hex[10] = '1';
		hex[11] = '0';
		break;

	case '3':
		hex[8] = '0';
		hex[9] = '0';
		hex[10] = '1';
		hex[11] = '1';
		break;

	case '4':
		hex[8] = '0';
		hex[9] = '1';
		hex[10] = '0';
		hex[11] = '0';
		break;
	case '5':
		hex[8] = '0';
		hex[9] = '1';
		hex[10] = '0';
		hex[11] = '1';
		break;
	case '6':
		hex[8] = '0';
		hex[9] = '1';
		hex[10] = '0';
		hex[11] = '1';
		break;
	case '7':
		hex[8] = '0';
		hex[9] = '1';
		hex[10] = '1';
		hex[11] = '1';
		break;
	case '8':
		hex[8] = '1';
		hex[9] = '0';
		hex[10] = '0';
		hex[11] = '0';
		break;
	case '9':
		hex[8] = '1';
		hex[9] = '0';
		hex[10] = '0';
		hex[11] = '1';
		break;
	case 'A':
		hex[8] = '1';
		hex[9] = '0';
		hex[10] = '1';
		hex[11] = '0';
		break;
	case 'B':
		hex[8] = '1';
		hex[9] = '0';
		hex[10] = '1';
		hex[11] = '1';
		break;
	case 'C':
		hex[8] = '1';
		hex[9] = '1';
		hex[10] = '0';
		hex[11] = '0';
		break;
	case 'D':
		hex[8] = '1';
		hex[9] = '1';
		hex[10] = '0';
		hex[11] = '1';
		break;
	case 'E':
		hex[8] = '1';
		hex[9] = '1';
		hex[10] = '1';
		hex[11] = '0';
		break;
	case 'F':
		hex[8] = '1';
		hex[9] = '1';
		hex[10] = '1';
		hex[11] = '1';
		break;
	}
	


	return hex;

}
void cod_NRZI() {

}




int main() {

	if (!al_init()) {
		fprintf(stderr, "failed to initialize allegro!\n");
		return -1;
	}
	//crear un display
	al_set_new_display_flags(ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE); //caracteristicas del display a crear
	display = al_create_display(1200, 640); // tamaño del display en pixeles
	al_set_window_position(display, 200, 200); // posicion del display en la pnatalla en coordenadas x y y
	al_set_window_title(display, "Tarea programa - Diseño lógico");
	//añadir una imagen al display
	float imgX = 0;
	float imgY = 200;
	al_init_image_addon(); //inicializar los modulos para imagenes
	imageBitmap = al_create_bitmap(30, 300);
	al_set_target_bitmap(al_get_backbuffer(display));
	imageBitmap = al_load_bitmap("Eje2.jpg"); //carga la imagen de los ejes para NZRI
	al_draw_bitmap(imageBitmap, imgX, imgY, NULL); //dibuja la imagen en el display en la posicion x y
	//fuentes
	al_init_font_addon(); //inicializar los modulos para fuentes 
	al_init_ttf_addon();//inicializa la función para cargar las fuentes TrueType
	float fontX=100;
	float fontY=50;
	fuente = al_load_font("Ho.ttf", 36, NULL); //la fuente se coloca en la carpeta raiz del proyecto, al igual que las imagenes
	al_draw_text(fuente, al_map_rgb(255, 0, 0), fontX, fontY, ALLEGRO_ALIGN_LEFT, "Codigo NRZI"); //dibuja en pantalla el texto entre comillas con la fuente indicada
	//teclado
	eventoCola= al_create_event_queue(); //crea una cola de eventos
	al_init_primitives_addon();
	al_install_keyboard(); //instala el teclado para comenzar a utilizarse posteriormente
	al_install_mouse();
	al_register_event_source(eventoCola, al_get_mouse_event_source());
	al_register_event_source(eventoCola, al_get_keyboard_event_source()); //registra en la cola de eventos creada, todo lo relacionado con el teclado del computatdor
	bool estado = false;
	al_flip_display();
	String = al_ustr_new("");
	while (!inicio)
	{
		al_draw_text(fuente, al_map_rgb(25, 100, 93), 100, 100, ALLEGRO_ALIGN_LEFT, "Ingrese numero hexadecimal: ");
		al_draw_ustr(fuente, al_map_rgb(255, 0, 0), 400, 100, ALLEGRO_ALIGN_LEFT, String);
		al_draw_text(fuente, al_map_rgb(25, 100, 93), 100, 150, ALLEGRO_ALIGN_LEFT, "Presione para continuar ");
		al_flip_display();
		al_wait_for_event(eventoCola, &eventosTeclado);
		switch (eventosTeclado.type) {

		case ALLEGRO_EVENT_KEY_CHAR: //guarda en la cola de eventos toda las teclas presionadas 
			if (eventosTeclado.keyboard.unichar >= 32)
			{
				pos += al_ustr_append_chr(String, eventosTeclado.keyboard.unichar);
			}
			else if (eventosTeclado.keyboard.keycode == ALLEGRO_KEY_BACKSPACE)
			{
				if (al_ustr_prev(String, &pos))
					al_ustr_truncate(String, pos);
			}
			break;
		case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN: //registra unicamente cuando el mouse es presionado
			inicio = true;
			al_ustr_to_buffer(String, entradaTeclado, 200);

		}
	}
	cadenaBinaria = hxtobin(entradaTeclado);
	printf("The value entered is %c. Its double is %d.\n", cadenaBinaria);
	while (a<=12){
		if (a == 1) {//Está comenzando y debe imprimir linea en alto, por requerimientos
			al_draw_line(nrzi_x, nrzi_y, nrzi_x+50, nrzi_y, al_map_rgb(255, 0, 0), 2);
		}
		else {
			if (cadenaBinaria[a] == '0') {
				al_draw_line(nrzi_x, nrzi_y, nrzi_x + 50, nrzi_y, al_map_rgb(255, 0, 0), 2);
			}
			else {
				if (nrzi_y == 250) {
					nrzi_y = 400;
				}
				else {
					nrzi_y = 250;
				}
				al_draw_line(nrzi_x, nrzi_y, nrzi_x + 50, nrzi_y, al_map_rgb(255, 0, 0), 2);
			}
		}
		nrzi_x = nrzi_x + 50;
		al_flip_display();
		a = a + 1;

	}

	
	al_rest(10.0); //allegro espera dos segundos
	al_destroy_display(display);
	al_destroy_font(fuente);
	al_destroy_bitmap(imageBitmap);
	al_destroy_event_queue(eventoCola);
	al_destroy_timer(timer);
}