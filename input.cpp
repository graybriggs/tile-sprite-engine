

#include "input.h"


/*
static const char* button_names[] = {
	[to_underlying(KeyCode::INPUT_K_UP)] = "UP",
	[INPUT_K_DOWN] = "DOWN",
	[INPUT_K_LEFT] = "LEFT",
	[INPUT_K_RIGHT] = "RIGHT",
	[INPUT_K_ENTER] = "ENTER",
	[INPUT_K_SPACE] = "SPACE",
	[INPUT_K_A] = "A",
	[INPUT_K_B] = "B",
	[INPUT_K_C] = "C",
	[INPUT_K_D] = "D",
	[INPUT_K_E] = "E",
	[INPUT_K_F] = "F",
	[INPUT_K_G] = "G",
	[INPUT_K_H] = "H",
	[INPUT_K_I] = "I",
	[INPUT_K_J] = "J",
	[INPUT_K_K] = "K",
	[INPUT_K_L] = "L",
	[INPUT_K_M] = "M",
	[INPUT_K_N] = "N",
	[INPUT_K_O] = "O",
	[INPUT_K_P] = "P",
	[INPUT_K_Q] = "Q",
	[INPUT_K_R] = "R",
	[INPUT_K_S] = "S",
	[INPUT_K_T] = "T",
	[INPUT_K_U] = "U",
	[INPUT_K_V] = "V",
	[INPUT_K_W] = "W",
	[INPUT_K_X] = "X",
	[INPUT_K_Y] = "Y"
};
*/


void input_set_button_state(KeyCode key) {

	int k = to_underlying(key);
	key_pressed[k] = true;
}


void input_release_button_state(KeyCode key) {

	int k = to_underlying(key);
	key_pressed[k] = false;
}

bool input_query_state(KeyCode key) {
	return key_pressed[to_underlying(key)];
}