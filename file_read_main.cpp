
#include "file_read_main.h"

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
		TileRawInfo tile;


		if (source[begin_seg] == '{') {

			int end_seg = begin_seg;
			while (end_seg != '}') {
				++end_seg;
			}

			auto test = std::make_unique<char[]>(source.size());
			//char* test = new char[source.size()];
			std::memcpy(test.get(), source.c_str(), end_seg - begin_seg);
			std::vector<char*> vals;

			char* pch = strtok(test.get(), " ");

			while (pch != nullptr) {
				vals.push_back(pch);
				pch = strtok(nullptr, " ");
			}
						
			std::strcpy(tile.file_path, vals[0]);
			tile.bb_x = std::stoi(vals[1]);
			tile.bb_y = std::stoi(vals[2]);
			tile.bb_w = std::stoi(vals[3]);
			tile.bb_h = std::stoi(vals[4]);
			tile.is_collide = std::stoi(vals[5]);
			tile.is_anim = std::stoi(vals[6]);
			tile.no_frames = std::stoi(vals[7]);
			tile.frame_delay = std::stoi(vals[8]);
		
			if (tile.is_anim) {

				auto it = std::begin(vals) + 8;
				for (it; it < std::end(vals); it += 4) {
					SDL_Rect r;
					r.x = std::stoi(*it);
					r.y = std::stoi(*it + 1);
					r.w = std::stoi(*it + 2);
					r.h = std::stoi(*it + 3);
					tile.frame_clips.push_back(r);
				}
			}
			/*
	

				int i = 0;
				int start = 0;
				SDL_Rect clip_data;
				int member = 0;
				while (segment[i] != '\n') {

					if (is_whitespace(segment[i])) {
						std::string value = segment.substr(start, i);
						int val = std::stoi(value);

						if (member == 0)
							clip_data.x = val;
						else if (member == 1)
							clip_data.y = val;
						else if (member == 2)
							clip_data.w = val;
						else if (member == 3)
							clip_data.h = val;

						start = i;
					}

					if (member > 4) {
						tile_info.frame_clips.push_back(clip_data);
						member = 0;
					}
					++i;
				}
				
			}
			begin_seg = end_seg;
			*/
			//tile_info.push_back(tile);
		}
		
	}
	return tile_info;
}