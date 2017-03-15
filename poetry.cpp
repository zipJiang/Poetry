#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <regex>

using namespace std;

map<string, int> numbers;


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

	/* Initialize input file */

	regex filetype(".+\\.po");
	cmatch m;
	if(!regex_match(argv[1], m, filetype)) {
		cout << "filetype matching failed, this is not a poetry file." << endl;
		exit(0);
	}
	/*
	 *ifstream ifs(argv[1], ios::in);
	 */
	return 0;
}
