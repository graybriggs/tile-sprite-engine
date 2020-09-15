#pragma once

#include <string>

enum class TokenType {
	WHITESPACE,
	L_PAREN,
	R_PAREN,
	L_CURLY,
	R_CURLY,
	KEYWORD,
	IDENTIFIER,
	CONSTANT, // remove
	REAL_NUMBER,
	NUMBER,
	STRING,
	STRING_CONCAT,
	COMMENT,
	ERROR,
	COLON,
	NONE // used for printing
};

struct Token {

	Token(const std::string& id, TokenType tt, unsigned l, unsigned col);

	std::string data;  // the actual data of the token
	TokenType type;	   // the determined type of token
	unsigned line;     // the line number that the token appeard in the source file
	unsigned column; // token's column in the source file
};