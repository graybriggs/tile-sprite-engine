#pragma once
#ifndef FILE_READ_MAIN_H
#define FILE_READ_MAIN_H

// for fopen; fread; sscanf
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <SDL.h>

#include <iterator>
#include <string>
#include <vector>

struct TileRawInfo {
	TileRawInfo();
	char file_path[256];
	int bb_x, bb_y, bb_w, bb_h;
	int is_collide, is_anim, no_frames, frame_delay;
	std::vector<SDL_Rect> frame_clips;
};

int count_spaces(const std::string& str, std::size_t from, std::size_t to);

std::string read_source(const std::string& filename);
std::vector<TileRawInfo> file_read_main();


#endif
