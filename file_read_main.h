#pragma once
#ifndef FILE_READ_MAIN_H
#define FILE_READ_MAIN_H


#include <SDL.h>

#include <iterator>
#include <memory>
#include <string>
#include <vector>

class Tile;

enum class TileType { STATC, ANIM };

// TileRawInfo contains raw information pertaining to the Tile and its properties
// This is distinct from the Tile type which contains further information 
// such as state.

struct TileRawInfo {
	TileRawInfo();
	TileRawInfo(const Tile& t);

	TileType tile_type;
	std::string file_path;
	int tilesheet_x, tilesheet_y;
	int bb_x, bb_y, bb_w, bb_h;
	int is_collide, no_frames, frame_delay;
	std::vector<SDL_Rect> frame_clips;
};


std::string file_read(const std::string filename);
std::vector<std::string> file_read_lines(const std::string filename);
std::vector<TileRawInfo> read_tile_file(const std::string filename);
std::vector<std::string> str_split(const std::string str, const char delim);

void write_tile_data(std::vector<std::unique_ptr<Tile>>& tiles);

#endif
