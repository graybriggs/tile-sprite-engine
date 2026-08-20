
#include "file_read_main.h"
#include "tile.h"

#include <algorithm>
#include <cstring>
#include <fstream>
#include <memory>
#include <stdexcept>
#include <iostream>
#include <sstream>

TileRawInfo::TileRawInfo() :
	tile_type(TileType::STATIC),
	bb_x(0), bb_y(0), bb_w(0), bb_h(0),
	tilesheet_x(0), tilesheet_y(0),
	is_collide(0), no_frames(0), frame_delay(0),
	file_path("")
{
}

TileRawInfo::TileRawInfo(const Tile& t) {

	file_path = t.getTileImagePath();

	if (t.getCanAnimate()) {
		tile_type = TileType::ANIM;

		frame_clips = t.getFrameClips();
	}
	else {
		tile_type = TileType::STATIC;
	}

	SDL_Rect r = t.getSDL_Rect();
	bb_x = r.x;
	bb_y = r.y;
	bb_w = r.w;
	bb_h = r.h;
	tilesheet_x = t.getImageClip().x;
	tilesheet_y = t.getImageClip().y;
	is_collide = t.getIsCollidable(); // bool to int
	no_frames = t.getNumFrames();
	frame_delay = t.getFrameDelayTime();
}


// Reads tile format data from storage and converts it into
// RawTileInfo format
// Must be converted from RawTileInfo to Tile to use in engine
//
std::vector<TileRawInfo> read_tile_file(const std::string& filename) {

	std::vector<std::string> source = file_read_lines(filename);

	std::vector<TileRawInfo> tile_info;
	
	auto it = std::begin(source);
	for (it; it != std::end(source); it++) {

		std::string line = *it;

		// this should not evaluate to true based on the file_read_lines function
		if (line[0] == '#')
			continue;
		
		if (line[0] == '}')
			continue;

		if (line[0] == '{') {
			//it++;
			
			line = line.substr(1, line.length());
			
			auto tokens = strtok(line, ',');

			std::string get_tile_type = *it;
						
			TileRawInfo raw_tile;

			// if (get_tile_type[0] == 's') { // probably should use a proper strcmp
			// 	raw_tile.tile_type = TileType::STATIC;
			// }
			// 	raw_tile.tile_type = TileType::STATIC;
			// }
			// else {
			// 	raw_tile.tile_type = TileType::ANIM;
			// }

			//it++;
			//std::string line = *it;
			//std::vector<std::string> tokens = str_split(line, ' ');

			//raw_tile.file_path = tokens[0];
			if (std::strcmp(tokens[0].c_str(), "s") == 0) {
				raw_tile.tile_type = TileType::STATIC;
				std::cout << "Static Tile" << std::endl;
			}
			else if (std::strcmp(tokens[0].c_str(), "a") == 0) {
				raw_tile.tile_type = TileType::ANIM;
			}
			else {
				std::cout << "MAP DATA READ ERROR - Unrecognized tile type" << std::endl;
			}
			raw_tile.bb_x = std::stoi(tokens[1].c_str());
			raw_tile.bb_y = std::stoi(tokens[2].c_str());
			raw_tile.bb_w = std::stoi(tokens[3].c_str());
			raw_tile.bb_h = std::stoi(tokens[4].c_str());
			raw_tile.tilesheet_x = std::stoi(tokens[5].c_str());
			raw_tile.tilesheet_y = std::stoi(tokens[6].c_str());
			
			//raw_tile.tilesheet_y = std::stoi(tokens[7].c_str());
			if (std::stoi(tokens[7].c_str()) == 1) {
				raw_tile.is_collide = true;
			}
			else {
				raw_tile.is_collide = false;
			}
			//raw_tile.no_frames = std::stoi(tokens[8]);
			// raw_tile.frame_delay = std::stoi(tokens[8]);
			
			// if (raw_tile.tile_type == TileType::ANIM) {
			// 	it++;
			// 	std::string c = *it;
			// 	std::vector<std::string> clips = str_split(c, ' ');
				
			// 	for (std::size_t i = 0; i <= clips.size() - 4; i += 4) {
			// 		SDL_Rect r;
			// 		r.x = std::stoi(clips[i]);
			// 		r.y = std::stoi(clips[i+1]);
			// 		r.w = std::stoi(clips[i+2]);
			// 		r.h = std::stoi(clips[i+3]);
			// 		raw_tile.frame_clips.push_back(r);
			// 	}
			// }
			tile_info.push_back(raw_tile);
		}
	}
	return tile_info;
}

std::vector<TileRawInfo> parse_raw_tile_data(std::vector<std::string>& data) {
	std::vector<TileRawInfo> tile_info;
	
	auto it = std::begin(data);
	for (it; it != std::end(data); it++) {

		std::string line = *it;

		// this should not evaluate to true based on the file_read_lines function
		if (line[0] == '#')
			continue;
		
		if (line[0] == '}')
			continue;

		if (line[0] == '{') {
			//it++;
			
			line = line.substr(1, line.length());
			
			auto tokens = strtok(line, ',');

			std::string get_tile_type = *it;
						
			TileRawInfo raw_tile;

//
			raw_tile.bb_x = std::stoi(tokens[1].c_str());
			raw_tile.bb_y = std::stoi(tokens[2].c_str());
			raw_tile.bb_w = std::stoi(tokens[3].c_str());
			raw_tile.bb_h = std::stoi(tokens[4].c_str());
			raw_tile.tilesheet_x = std::stoi(tokens[5].c_str());
			raw_tile.tilesheet_y = std::stoi(tokens[6].c_str());
			if (std::stoi(tokens[7].c_str()) == 1) {
				raw_tile.is_collide = true;
			}
			else {
				raw_tile.is_collide = false;
			}
			//raw_tile.no_frames = std::stoi(tokens[8]);
			// raw_tile.frame_delay = std::stoi(tokens[8]);
			
			// if (raw_tile.tile_type == TileType::ANIM) {
			// 	it++;
			// 	std::string c = *it;
			// 	std::vector<std::string> clips = str_split(c, ' ');
				
			// 	for (std::size_t i = 0; i <= clips.size() - 4; i += 4) {
			// 		SDL_Rect r;
			// 		r.x = std::stoi(clips[i]);
			// 		r.y = std::stoi(clips[i+1]);
			// 		r.w = std::stoi(clips[i+2]);
			// 		r.h = std::stoi(clips[i+3]);
			// 		raw_tile.frame_clips.push_back(r);
			// 	}
			// }


			tile_info.push_back(raw_tile);
		}
	}
	return tile_info;
}


void write_tile_data(std::vector<std::unique_ptr<Tile>>& tiles) {

	std::vector<TileRawInfo> raw_tiles;

	for (auto& tile : tiles) {
		Tile t = *(tile.get());
		raw_tiles.push_back(TileRawInfo(t));
	}

	std::ofstream outfile("test_map.txt");

	for (const auto& rt : raw_tiles) {

		outfile << "{\n";
		
		if (rt.tile_type == TileType::STATIC) {
			outfile << "static\n";
		}
		else {
			outfile << "anim\n";
		}

		outfile << "\"" << rt.file_path << "\" " <<
		rt.bb_x << " " << rt.bb_y << " " << rt.bb_w << " " << rt.bb_h  << " " <<
		rt.tilesheet_x << " " << rt.tilesheet_y << " " << rt.is_collide << " " <<
		rt.no_frames << " " << rt.frame_delay << "\n";

		for (const SDL_Rect& r : rt.frame_clips) {
			outfile << r.x << " " << r.y << " " << r.w << " " << r.h << " ";
		}
		outfile << "}\n";
	}

	outfile.close();
}

/////////////////////
/////////////////////

std::string file_read(const std::string& filename) {

	std::ifstream file;
	file.open(filename);
	if (file.fail()) {
		throw "Failed to open " + filename;
	}

	std::stringstream buffer;
	buffer << file.rdbuf();
	file.close();
	auto sbuf = buffer.str();
	//std::cout << sbuf << std::endl;
	return sbuf;
}

std::vector<std::string> file_read_lines(const std::string& filename) {

	std::vector<std::string> data;

	std::ifstream ifs(filename);
	std::string input;

	while (std::getline(ifs, input)) {
		if (input[0] != '#') {
			data.push_back(input);
		}
	}
	std::cout << "Read " << data.size() << " lines." << std::endl;
	return data;
}


std::vector<std::string> str_split(const std::string& str, const char delim) {
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


std::vector<std::string> strtok(const std::string& str, const char delim) {

    if (std::size(str) == 0)
        return std::vector<std::string>(0);

    std::vector<std::string> tokens;
    std::string temp = "";
    for (int i = 0; i < std::size(str); i++) {
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