#include <iostream>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <regex>

#ifndef _POETRY_
#define _POETRY_
#define EMPTY 0
#define USELESS_WORD 1
#define RESERVED 2
#define MARK 4
#define NUMBER 8
extern std::map<std::string, int> numbers;
extern std::set<std::string> builtin;
extern std::ifstream is;
extern std::string nextLexeme;
extern int nextToken;
#endif

int lex();
void eval_parser();
void mevl_parser();
void divs_parser();
void num_parser();
void nb_parser();

void useless_parser();

void ifstat_parser();
void stmt_parser();
