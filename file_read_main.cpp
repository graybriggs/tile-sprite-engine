
#include "file_read_main.h"

#include <algorithm>
#include <cstring>
#include <cstdio>
#include <memory>
#include <stdexcept>

TileRawInfo::TileRawInfo() {
	std::memset(&file_path, 0, 256);
	bb_x = bb_y = bb_w = bb_h = 0;
	is_collide = is_anim = no_frames = frame_delay;
}


bool is_whitespace(const char c) {
	return (c == ' ' || c == '\n' || c == '\t');
}

std::string read_source(const std::string& filename) {

	FILE* f = fopen(filename.c_str(), "r");
	if (f == nullptr) {
		throw std::string("Error opening file");
	}

	fseek(f, 0, SEEK_END);
	long int size = ftell(f);
	rewind(f);

	auto extracted_source = std::make_unique<char[]>(size);

	fread(extracted_source.get(), 1, size, f);
	fclose(f);

	return std::string(extracted_source.get());
}

std::vector<TileRawInfo> file_read_main() {

	auto source = read_source("tile_format_idea.txt");

	std::vector<TileRawInfo> tile_info;
	
	for (int begin_seg = 0; begin_seg < source.length(); ++begin_seg) {

		if (source[begin_seg] == '{') {

			int end_seg = begin_seg;
			while (end_seg != '}') {
				++end_seg;
			}

			source.erase(std::remove(std::begin(source), std::end(source), '\n'), std::end(source));

			std::vector<char*> vals;
			std::string tile_info_str = source.substr(begin_seg, end_seg - begin_seg);
			
			char* pch = strtok(&tile_info_str[0], " ");
			while (pch != nullptr) {
				vals.push_back(pch);
				pch = strtok(nullptr, " ");
			}
			
			
			TileRawInfo tile;
			/*
			std::strcpy(tile.file_path, vals[0]);
			tile.bb_x = std::stoi(std::string(vals[1]));
			tile.bb_y = std::stoi(std::string(vals[2]));
			tile.bb_w = std::stoi(std::string(vals[3]));
			tile.bb_h = std::stoi(std::string(vals[4]));
			tile.is_collide = std::stoi(std::string(vals[5]));
			tile.is_anim = std::stoi(std::string(vals[6]));
			tile.no_frames = std::stoi(std::string(vals[7]));
			tile.frame_delay = std::stoi(std::string(vals[8]));
		
			if (tile.is_anim) {

				/*
				for (std::size_t i = 8; i <= vals.size() - 4; i += 4) {
					SDL_Rect r;
					r.x = std::stoi(vals[i+1]);
					r.y = std::stoi(vals[i+2]);
					r.w = std::stoi(vals[i+3]);
					r.h = std::stoi(vals[i+4]);
					tile.frame_clips.push_back(r);
				}
				*/
				
			//}
			tile_info.push_back(tile);
		}
	}
	return tile_info;
}