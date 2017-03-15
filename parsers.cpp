#include "poetry.h"

void eval_parser() {
	std::cout << "parsing <eval>" << std::endl;
	mevl_parser();

	/*
	 * This space is left intentionally for
	 * optional <useless> parse
	 */
	
	while(nextToken == MARK || nextLexeme == "and") {
		/*
		* This space is left intentionally for
		* optional <useless> parse
		*/
		lex();
		eval_parser();
	}
	std::cout << "finished <eval>" << std::endl;
}

void mevl_parser() {
	std::cout << "parsing <mevl>" << std::endl;
	divs_parser();

	/* <useless> */

	while(nextToken == NUMBER) {
		lex();
		mevl_parser();
	}
	std::cout << "finished <mevl>" << std:: endl;
}
