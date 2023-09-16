#pragma once
#ifndef INPUT_H
#define INPUT_H

#include <array>

enum class KeyCode {
	INPUT_K_UP = 0,
	INPUT_K_DOWN = 1,
	INPUT_K_LEFT = 2,
	INPUT_K_RIGHT = 3,
	INPUT_K_SPACE = 4,
	INPUT_K_ENTER = 5,
	INPUT_K_a = 6,
	INPUT_K_b = 7,
	INPUT_K_c = 8,
	INPUT_K_d = 9,
	INPUT_K_e = 10,
	INPUT_K_f = 11,
	INPUT_K_g = 12,
	INPUT_K_h = 13,
	INPUT_K_i = 14,
	INPUT_K_j = 15,
	INPUT_K_k = 16,
	INPUT_K_l = 17,
	INPUT_K_m = 18,
	INPUT_K_n = 19,
	INPUT_K_o = 20,
	INPUT_K_p = 21,
	INPUT_K_q = 22,
	INPUT_K_r = 23,
	INPUT_K_s = 24,
	INPUT_K_t = 25,
	INPUT_K_u = 26,
	INPUT_K_v = 27,
	INPUT_K_w = 28,
	INPUT_K_x = 29,
	INPUT_K_y = 30,
	INPUT_K_z = 31,
	INPUT_K_ESC = 32,
	
	INPUT_K_LAST = 33
};

//bool key_press[32];
static std::array<bool, 33> key_pressed;

// This template is to make enum classes work as an array index. Standard implementation
// is planned for C++23
template <typename E>
constexpr typename std::underlying_type<E>::type to_underlying(E e) {
	return static_cast<typename std::underlying_type<E>::type>(e);
}

void input_set_button_state(KeyCode key);
void input_release_button_state(KeyCode key);
bool input_query_state(KeyCode);


#endif