#include <iostream>
#include "graph.hpp"

using namespace std;

int main() 
{
	graph g;
	if (g.read(cin))
		g.depthsearch(2, cout);
	else  cout << "Error!\n";
	return 0;
}