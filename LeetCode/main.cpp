#include "Pow.h"
#include <iostream>
using namespace std;

void main() {
	CPow pow;

	double x	= 1.0;
	int n		= 0;

	cin >> x >> n;
	cout << pow.Pow(x, n) << endl;
}