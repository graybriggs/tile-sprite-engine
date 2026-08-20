#pragma once

#include <SDL2/SDL.h>

#include <iterator>
#include <memory>
#include <string>
#include <vector>

class Tile;

enum class TileType { STATIC, ANIM };

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


std::string file_read(const std::string& filename);
std::vector<std::string> file_read_lines(const std::string& filename);
std::vector<TileRawInfo> read_tile_file(const std::string& filename);
std::vector<std::string> str_split(const std::string& str, const char delim);

std::vector<TileRawInfo> parse_raw_tile_data(std::vector<std::string>& data);

void write_tile_data(std::vector<std::unique_ptr<Tile>>& tiles);
std::vector<std::string> strtok(const std::string& str, const char delim);

