#pragma once

#include <cmath>
#include <cfloat>

class CPow
{
public:
	CPow(void);
	~CPow(void);

	double pow(double x, int n) {
		// this condition is not consided.
		if (abs(abs(x) - 1.0) <= DBL_EPSILON) {
			return n%2 ? x : 1.0;
		}
		else if (n < 0) {
			return 1.0 / pow(x, -n);
		}
		else if (n == 0) {
			return 1.0;
		}
		else if (n == 1) {
			return x;
		}
		else {
			double hpx	= pow(x, n/2);
			if (n % 2 != 0) {
				return hpx * hpx * x;
			}
			else {
				return hpx * hpx;
			}
		}
	}
};

