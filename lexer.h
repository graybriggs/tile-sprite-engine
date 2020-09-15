#pragma once
#ifndef LEXER_H
#define LEXER_H

// For fread
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <string>
#include <vector>

#include "tokens.h"

std::string getAtom(const std::string& syntax, std::uint32_t position);
bool is_constant(const std::string& atom);
bool is_real_number(const std::string& atom);
bool is_keyword(const std::string& atom);
bool is_string(const std::string& atom);

std::vector<Token> scanner(const std::string& syntax);

std::string read_source(const std::string& filename);

#endif