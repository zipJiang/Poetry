#include "poetry.h"

using namespace std;
std::map<std::string, int> numbers;
std::set<std::string> builtin;
std::ifstream is;
std::string nextLexeme;
int nextToken;

int lex() {
	if(is.eof())
		return nextToken = EMPTY;
	cout << nextLexeme << endl;
	ostringstream os;
	char current;
	while(is.good()) {
		is.get(current);
		while((current == ' ' || current == '\t' || current == '\n')
				&& is.good())
			is.get(current);

		if((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z')) {
			/* current chat is in the alphabet */
			/*
			 *cout << "current = " << current << " written" << endl;
			 */
			os<<current;
		}
		else if(current == '?' || current == '.' || current == ':' ||
				current == '!' || current == ',' || current == ';' ||
				current == '-') {
			os<<current;
			nextLexeme = os.str();
			return nextToken = MARK;
		}
		current = is.peek();
		/*
		 *cout << (int)current << endl;
		 */
		if(current == '?' || current == '.' || current == ':' ||
		   current == '!' || current == ',' || current == ';' ||
		   current == ' ' || current == '\t'|| current == '-' ||
		   current == '\n') {
			break;
		}
	}
	/* Preprocess to avoid uppercase */
	nextLexeme = os.str();
	bool specialized = true;
	for(int i = 0; i != nextLexeme.size(); ++i) {
		if(nextLexeme[i] >= 'a' && nextLexeme[i] <= 'z') {
			specialized = false;
			break;
		}
	}
	if(specialized) {
		return nextToken = USELESS_WORD;
	}
	else {
		for(int i = 0; i != nextLexeme.size(); ++i) {
			if(nextLexeme[i] >= 'A' && nextLexeme[i] <= 'Z') {
				nextLexeme[i] += 'a' - 'A';
			}
		}
	}
	/* Determine the category of this word */
	if(numbers.find(os.str()) != numbers.end()) {
		return nextToken = NUMBER;
	}
	if(builtin.find(os.str()) != builtin.end()) {
		return nextToken = RESERVED;
	}
	return nextToken = USELESS_WORD;
}

int syntax() {
	/* Note: this is only for trial */
	lex();
	if(nextToken & (USELESS_WORD | MARK))
		useless_parser();

	if(nextToken == EOF)
		return 0;

	eval_parser();
	if(nextToken & (USELESS_WORD | MARK))
		useless_parser();
	/* End Trail */
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
	builtin.insert("then");
	builtin.insert("divide");
	builtin.insert("without");
	builtin.insert("by");

	/* Initialize input file */

	regex filetype(".+\\.po");
	cmatch m;
	if(!regex_match(argv[1], m, filetype)) {
		cout << "filetype matching failed, this is not a poetry file." << endl;
		exit(0);
	}
	is.open(argv[1], ios::in);
	syntax();
	return 0;
}
