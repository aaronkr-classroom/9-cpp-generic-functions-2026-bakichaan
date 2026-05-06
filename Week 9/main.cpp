#include <iterator>
#include <iostream>
#include <string>
#include "my_alg_T.h"

using namespace std;

int main(void) {
	string s;
	while (getline(cin, s))
		split(s, ostream_iterator<string>(cout, "\n"));

	return 0;
}
