#include <iostream>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <regex>

#ifndef _POETRY_
#define _POETRY_
#define USELESS_WORD 0
#define RESERVED 1
#define MARK 2
#define NUMBER 4
std::map<std::string, int> numbers;
std::set<std::string> builtin;
std::ifstream is;
std::string nextLexeme;
int nextToken = -1;
#endif

int lex();
void eval_parser();
void mevl_parser();
void divs_parser();
