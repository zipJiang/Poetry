#include "poetry.h"

void eval_parser() {
	std::cout << "parsing <eval>" << std::endl;
	mevl_parser();

	/*
	 * This space is left intentionally for
	 * optional <useless> parse
	 */
	if(nextToken & (USELESS_WORD | MARK))
		useless_parser();
	
	while(nextLexeme == "and") {
		/*
		* This space is left intentionally for
		* optional <useless> parse
		*/
		if(nextToken & (USELESS_WORD | MARK))
			useless_parser();
		lex();
		eval_parser();
	}
	std::cout << "finished <eval>" << std::endl;
}

void mevl_parser() {
	std::cout << "parsing <mevl>" << std::endl;
	divs_parser();

	/* <useless> */
	if(nextToken & (USELESS_WORD | MARK))
		useless_parser();

	while(nextToken == NUMBER || nextLexeme == "without") {
		/* <useless> */
		if(nextToken & (USELESS_WORD | MARK))
			useless_parser();
		
		mevl_parser();
	}
	std::cout << "finished <mevl>" << std::endl;
}

void divs_parser() {
	std::cout << "parsing <divs>" << std::endl;
	if(nextLexeme != "divide") {
		if(nextToken & (USELESS_WORD | MARK))
			useless_parser();
		num_parser();
		std::cout << "finished <divs>" << std::endl;
		return ;
	}

	lex();
	if(nextToken & (USELESS_WORD | MARK))
		useless_parser();
	eval_parser();
	
	/* <useless> */
	if(nextToken & (USELESS_WORD | MARK))
		useless_parser();

	if(nextLexeme != "by") {
		std::cout << "parsing failed, expected \" by \" lexeme." << std::endl;

		/* Probably we need to fix this.*/
	}
	lex();

	/* <useless> */
	if(nextToken & (USELESS_WORD | MARK))
		useless_parser();

	eval_parser();

	if(nextToken & (USELESS_WORD | MARK))
		useless_parser();
	
	if(nextLexeme != "then") {
		std::cout << "parsing failed, expected \" then \" lexeme." << std::endl;

		/* Probably we need to correct this error. */
	}
	else
		lex();
	std::cout << "finished <divs>" << std::endl;
}

void num_parser() {
	std::cout << "parsing <num>" << std::endl;
	if(nextLexeme == "without") {
		lex();
	}

	/* <useless> */
	if(nextToken & (USELESS_WORD | MARK))
		useless_parser();

	nb_parser();
	std::cout << "finished <num>" << std::endl;
}

void nb_parser() {
	std::cout << "parsing <nb>" << std::endl;
	if(nextToken != NUMBER) {
		std::cout << "parsing failed, expected a NUMBER token." << std::endl;
		/* Probably we need to fix this. */
	}
	else
		lex();
	if(nextLexeme == "-") {
		lex();
		if(nextToken != NUMBER) {
			std::cout << "parsing failed, expected a NUMBER after \'-\'" << std::endl;
			/* Probably we need to fix this. */
		}
		else
			lex();
	}
	std::cout << "finished <nb>" << std::endl;
}

void useless_parser() {
	/* parsing useless elements */
	/*start parsing useless*/
	std::cout << "parsing <useless>" << std::endl;
	while(nextToken & (USELESS_WORD | MARK)) {
		/*
		 *std::cout << nextToken << std::endl;
		 */
		lex();
	}
	/*end parsing useless*/
	std::cout << "finished <useless>" << std::endl;
}
