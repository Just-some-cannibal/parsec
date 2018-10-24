#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <cctype>

using std::string;
using std::vector;
using std::set;

typedef const char * constcharp;

enum type {
	OPERATOR,
	TYPE,
	VARIABLE,
	ENDSTATE
};

set<string> types = {"int"};

struct Symbol {
	type Type;
	string Name;
	string Op;
};

string getWord(constcharp & loc) {
	string output;
	
	while(std::isalnum(*loc)) {
		output+= *loc;
		++loc;
	}
	return output;
}

void findOperator(vector<Symbol> & symbols, constcharp & loc) {
	switch(*loc) {
		case ';':
			symbols.push_back({type::ENDSTATE, "", ""});
			break;
		case '=':
			symbols.push_back({type::OPERATOR, "=", "="});
	}
	++loc;
}

vector<Symbol> lex(const string src) {
	const char * loc = src.c_str();
	
	vector<Symbol> symbols;
	while(*loc != '\0') {
		if (std::isspace(*loc)) {
			++loc;
			continue;
		}
		if (std::isalpha(*loc)) {
			string word = getWord(loc);
			if (types.find(word) != types.end()) {
				symbols.push_back({type::TYPE, word, ""});
			} else {
				symbols.push_back({type::VARIABLE, word, ""});
			}
		} else {
			findOperator(symbols, loc);
		}
	}
	return symbols;
}

string parse(vector<Symbol> symbols) {
	bool indecl = false;
	for (auto symbol : symbols) {
		if (indecl) {
			if (symbol.Type = type::VARIABLE);
		}
		if (symbol.Type == type::TYPE) {
			std::cout << "TYPE";
			indecl = true;
		}
		if (symbol.Type == type::OPERATOR) {
			std::cout << symbol.Op;
		}
		if (symbol.Type == type::VARIABLE) {
			std::cout << symbol.Name;
		}
		
		if (symbol.Type == type::ENDSTATE) {
			std::cout << ";" << std::endl;
		}
	}
	return "";
}

int main() {
	parse(lex("int i = b;"));
}