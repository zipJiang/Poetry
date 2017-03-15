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
	std::cout << "finished <mevl>" << std::endl;
}

void divs_parser() {
	std::cout << "parsing <divs>" << std::endl;
	if(nextLexeme != "divide") {
		num_parser();
		return ;
	}

	lex();
	eval_parser();
	
	/* <useless> */

	if(nextLexeme != "by") {
		std::cout << "parsing failed, expected \" by \" lexeme." << std::endl;

		/* Probably we need to correct this error. */
	}
	lex();

	/* <useless> */

	eval_parser();
	
	if(nextLexeme != "then") {
		std::cout << "parsing failed, expected \" then \" lexeme." << std::endl;

		/* Probably we need to correct this error. */
	}
	lex();
}

void num_parser() {
	std::cout << "parsing <num>" << std::endl;
	if(nextLexeme == "without") {
		lex();
	}

	/* <useless> */

	nb_parser();
}

void nb_parser() {
	std::cout << "parsing <num>" << std::endl;
	if(nextToken != NUMBER) {
		std::cout << "parsing failed, expected a NUMBER token." << std::endl;
		/* Probably we need to correct this error. */
	}
	lex();
	if(nextToken == '-') {
		lex();
		if(nextToken != NUMBER) {
			std::cout << "parsing failed, expected a NUMBER after \'-\'" << std::endl;
			/* Probably we need to correct this error. */
		}
	}
}
