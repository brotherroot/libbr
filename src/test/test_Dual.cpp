#include <iostream>
#include <math\Dual.hpp>

using namespace std;
using namespace BR;

int main1()
{
	Dual< long double > d0;

	cout << "read Dual<double> d0\n";
	cin >> d0;
	cout << "d0 = " << d0 << "\n";

	Dual< double > d1;

	cout << "read Dual<double> d1\n";
	cin >> d1;
	cout << "d1 = " << d1 << "\n";

	cout << "d0 + d1 = " << d0 + d1 << "\n";
	cout << "d0 - d1 = " << d0 - d1 << "\n";
	cout << "d0 * d1 = " << d0 * d1 << "\n";
	cout << "d0 / d1 = " << d0 / d1 << "\n";
	cout << "1.5 * d0 = " << 1.5 * d0 << "\n";
	cout << "d0 / 0.5 = " << d0 / 0.5 << "\n";
	cout << "d0.conj() = " << d0.conj() << "\n";
	cout << "d0.arg() = " << d0.arg() << "\n";
	cout << "d0.norm() = " << d0.norm() << "\n";
	cout << "sin(d0) = " << sin(d0) << "\n";
	cout << "cos(d0) = " << cos(d0) << "\n";
	cout << "tan(d0) = " << tan(d0) << "\n";
	cout << "sinh(d0) = " << sinh(d0) << "\n";
	cout << "cosh(d0) = " << cosh(d0) << "\n";
	cout << "tanh(d0) = " << tanh(d0) << "\n";
	cout << "asin(d0) = " << asin(d0) << "\n";
	cout << "acos(d0) = " << acos(d0) << "\n";
	cout << "atan(d0) = " << atan(d0) << "\n";
#ifdef USING_STD_CPP11
	cout << "asinh(d0) = " << asinh(d0) << "\n";
	cout << "acosh(d0) = " << acosh(d0) << "\n";
	cout << "atanh(d0) = " << atanh(d0) << "\n";
#endif // USING_STD_CPP11
	return 0;
}