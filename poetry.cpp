#include <iostream>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <regex>

#define USELESS_WORD 0
#define RESERVED 1
#define MARK 2
#define NUMBER 4

using namespace std;

map<string, int> numbers;

set<string> builtin;

string lexeme;

int lex(string literal) {
	istringstream is(literal);
	ostringstream os;
	int token = -1;
	char current;
	/* First we have to eliminate whitespace before the lexeme */
	while(is.peek() == ' ' || is.peek() == '\t')
		is >> current;

	while(is >> current) {
		if((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z') || current == '-') {
			/* current chat is in the alphabet */
			os<<current;
		}
		else if(current == '?' || current == '.' || current == ':' ||
				current == '!' || current == ',' || current == ';') {
			os<<current;
			lexeme = os.str();
			return MARK;
		}
		current = is.peek();
		if(current == '?' || current == '.' || current == ':' ||
		   current == '!' || current == ',' || current == ';') {
			break;
		}
	}
	/* Preprocess to avoid uppercase */
	lexeme = os.str();
	bool specialized = false;
	for(int i = 0; i != lexeme.size(); ++i) {
		if(lexeme[i] >= 'a' && lexeme[i] <= 'z') {
			specialized = true;
			break;
		}
	}
	if(!specialized) {
		return USELESS_WORD;
	}
	else {
		for(int i = 0; i != lexeme.size(); ++i) {
			if(lexeme[i] >= 'A' && lexeme[i] <= 'Z') {
				lexeme[i] += 'a' - 'A';
			}
		}
	}
	/* Determine the category of this word */
	if(numbers.find(os.str()) != numbers.end()) {
		return NUMBER;
	}
	if(builtin.find(os.str()) != builtin.end()) {
		return RESERVED;
	}

	return USELESS_WORD;
}

int syntax(ifstream &is) {
	;
	return 0;
}

int main( int args, char **argv ) {
	/* Initializing the numbers map */
	numbers["one"] = 1;
	numbers["zero"] = 0;
	numbers["two"] = 2;
	numbers["three"] = 3;
	numbers["four"] = 4;
	numbers["five"] = 5;
	numbers["six"] = 6;
	numbers["seven"] = 7;
	numbers["eight"] = 8;
	numbers["nine"] = 9;
	numbers["ten"] = 10;
	numbers["eleven"] = 11;
	numbers["twelve"] = 12;
	numbers["thirteen"] = 13;
	numbers["fourteen"] = 14;
	numbers["fifteen"] = 15;
	numbers["sixteen"] = 16;
	numbers["seventeen"] = 17;
	numbers["eighteen"] = 18;
	numbers["nineteen"] = 19;
	numbers["twenty"] = 20;
	numbers["thirty"] = 30;
	numbers["fourty"] = 40;
	numbers["fifty"] = 50;
	numbers["sixty"] = 60;
	numbers["seventy"] = 70;
	numbers["eighty"] = 80;
	numbers["ninety"] = 90;
	numbers["hundred"] = 100;
	numbers["thousand"] = 1000;
	numbers["million"] = 1000000;

	/* Initialize builtin identifier */
	builtin.insert("if");
	builtin.insert("else");
	builtin.insert("rather");
	builtin.insert("or");
	builtin.insert("end");
	builtin.insert("cease");

	/* Initialize input file */

	regex filetype(".+\\.po");
	cmatch m;
	if(!regex_match(argv[1], m, filetype)) {
		cout << "filetype matching failed, this is not a poetry file." << endl;
		exit(0);
	}
	ifstream ifs(argv[1], ios::in);

	syntax(ifs);
	return 0;
}
