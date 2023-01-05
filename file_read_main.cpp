
#include "file_read_main.h"

#include <algorithm>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <iostream>
#include <sstream>

using namespace GTE;

TileRawInfo::TileRawInfo() :
	bb_x(0), bb_y(0), bb_w(0), bb_h(0),
	is_collide(0), is_anim(0), no_frames(0), frame_delay(0),
	file_path("")
{
}


bool is_whitespace(const char c) {
	return (c == ' ' || c == '\n' || c == '\t');
}

std::string GTE::file_read(const std::string filename) {

	std::ifstream file;
	file.open(filename);
	if (file.fail()) {
		throw "Failed to open " + filename;
	}

	std::stringstream buffer;
	buffer << file.rdbuf();

	return buffer.str();
}

std::vector<std::string> GTE::file_read_lines(const std::string filename) {

	std::vector<std::string> data;

	std::ifstream ifs(filename);
	std::string input;

	while (std::getline(ifs, input)) {
		data.push_back(input);
	}
	return data;
}


std::vector<TileRawInfo> GTE::file_read_main(const std::string filename) {

	std::vector<std::string> source = file_read_lines(filename);

	std::vector<TileRawInfo> tile_info;
	
	auto it = std::begin(source);
	for (it; it != std::end(source); it++) {

		std::string line = *it;

		// skip comments
		if (line[0] == '#')
			continue;

		if (line[0] == '{') {
			it++;
			
			std::string line = *it;
			std::vector<std::string> tokens = strtok(line, ' ');
			
			TileRawInfo tile;
			
			tile.file_path = tokens[0];
			tile.bb_x = std::stoi(tokens[1]);
			tile.bb_y = std::stoi(tokens[2]);
			tile.bb_w = std::stoi(tokens[3]);
			tile.bb_h = std::stoi(tokens[4]);
			tile.is_collide = std::stoi(tokens[5]);
			tile.is_anim = std::stoi(tokens[6]);
			tile.no_frames = std::stoi(tokens[7]);
			tile.frame_delay = std::stoi(tokens[8]);
			

			if (tile.is_anim) {

				it++;
				std::string c = *it;
				std::vector<std::string> clips = strtok(c, ' ');
				
				for (std::size_t i = 0; i <= clips.size(); i += 4) {
					SDL_Rect r;
					r.x = std::stoi(clips[i]);
					r.y = std::stoi(clips[i+1]);
					r.w = std::stoi(clips[i+2]);
					r.h = std::stoi(clips[i+3]);
					tile.frame_clips.push_back(r);
				}
			}
			tile_info.push_back(tile);
		}
	}
	return tile_info;
}

std::vector<std::string> GTE::strtok(const std::string str, const char delim) {
	std::vector<std::string> tokens;
	std::string temp = "";
	for (std::size_t i = 0; i < str.length(); i++) {
		if (str[i] == delim) {
			tokens.push_back(temp);
			temp = "";
		}
		else
			temp += str[i];
	}
	tokens.push_back(temp);
	return tokens;
}
