#pragma once
#ifndef FILE_READ_MAIN_H
#define FILE_READ_MAIN_H


#include <SDL.h>

#include <iterator>
#include <string>
#include <vector>

enum class TileType { STATC, ANIM };

struct TileRawInfo {
	TileType tile_type;
	std::string file_path;
	int tilesheet_x, tilesheet_y;
	int bb_x, bb_y, bb_w, bb_h;
	int is_collide, no_frames, frame_delay;
	std::vector<SDL_Rect> frame_clips;
};


std::string file_read(const std::string filename);
std::vector<std::string> file_read_lines(const std::string filename);
std::vector<TileRawInfo> file_read_main(const std::string filename);
std::vector<std::string> str_split(const std::string str, const char delim);

#endif
