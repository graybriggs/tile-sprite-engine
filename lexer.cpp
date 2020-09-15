
#include "lexer.h"

#include <cctype>
#include <memory>

Token::Token(const std::string& id, TokenType tt, unsigned l, unsigned col)
	: data(id), type(tt), line(l), column(col)
{}

std::string getAtom(const std::string& syntax, std::uint32_t position) {

	std::size_t num = 0;
	for (std::size_t i = position; i < syntax.length(); ++i) {
		if (std::isalnum(syntax[i]) || syntax[i] == '.' || syntax[i] == '"')
			num++;
		else
			break;
	}
	return syntax.substr(position, num);
}

bool is_constant(const std::string& atom) {

	for (unsigned i = 0; i < atom.length(); ++i) {
		if (!std::isdigit(atom[i])) {
			return false;
		}
	}
	return true;
}

bool is_real_number(const std::string& atom) {

	// finds decimal point then checks for numbers either side

	for (unsigned i = 0; i < atom.length(); ++i) {
		if (atom[i] == '.') {
			if ((atom.substr(0, i).length() > 0) && (atom.substr(i + 1, atom.length()).length() > 0)) {

				if (is_constant(atom.substr(0, i)) && is_constant(atom.substr(i + 1, atom.length())))
					return true;
				else
					return false;
			}
		}
	}
	return false;
}

bool is_keyword(const std::string& atom) {
	return (atom == "tile:"
		|| atom == "bounding_box:"
		|| atom == "is_collideable:"
		|| atom == "is_animatable:"
		|| atom == "no_of_frames:"
		|| atom == "frame_delay_time:"
		|| atom == "frame_clips:"
		);
}

bool is_string(const std::string& atom) {
	return (atom[0] == '"' && atom[atom.length() - 1] == '"');
}

bool is_whitespace(const char c) {
	return (c == ' ' || c == '\n' || c == '\t');
}

std::vector<Token> scanner(const std::string& syntax) {

	int line = 0;
	int column = 0;

	std::vector<Token> tokens;

	for (std::uint32_t i = 0; i < syntax.length(); ) {

		switch (syntax[i]) {
		case '(': {
			tokens.push_back(Token("(", TokenType::L_PAREN, line, column));
			++i;
			break;
		}
		case ')': {
			tokens.push_back(Token(")", TokenType::R_PAREN, line, column));
			++i;
			break;
		}
		case '{': {
			tokens.push_back(Token("{", TokenType::L_CURLY, line, column));
			++i;
			break;
		}
		case '}': {
			tokens.push_back(Token("}", TokenType::R_CURLY, line, column));
			++i;
			break;
		}
		case ':': {
			tokens.push_back(Token(":", TokenType::COLON, line, column));
			++i;
			break;
		}

		default: {
			if (is_whitespace(syntax[i])) {
				tokens.push_back(Token(std::to_string(syntax[i]), TokenType::WHITESPACE, line, column));
				if (syntax[i] == '\n') {
					column = 0;
					line++;
					i++;
				}
				else if (syntax[i] == '\t') {
					column += 2;
					i++;
				}
				else {
					i++;
					column++;
				}
			}
			else {
				std::string atom = getAtom(syntax, i);

				if (atom == "") {
					tokens.push_back(Token(atom, TokenType::ERROR, line, column));
					return tokens;
				}
				else if (is_string(atom)) {
					tokens.push_back(Token(atom, TokenType::STRING, line, column));
				}
				else if (is_real_number(atom)) {
					if (is_real_number(atom))
						tokens.push_back(Token(atom, TokenType::REAL_NUMBER, line, column));
				}
				else if (is_constant(atom)) {
					tokens.push_back(Token(atom, TokenType::CONSTANT, line, column));
				}
				else if (is_keyword(atom)) {
					tokens.push_back(Token(atom, TokenType::KEYWORD, line, column));
				}
				else {
					tokens.push_back(Token(atom, TokenType::ERROR, line, column));
				}
				i += atom.length();
				column += atom.length();
			}
		}
		} // default
	}
	return tokens;
}

std::string read_source(const std::string& filename) {

	FILE* f = fopen(filename.c_str(), "r");

	fseek(f, 0, SEEK_END);
	long int size = ftell(f);
	rewind(f);

	auto extracted_source = std::make_unique<char[]>(size);

	fread(extracted_source.get(), 1, size, f);
	fclose(f);

	return std::string(extracted_source.get());
}