#include <iostream>
#include <math\Vector2D.hpp>

using namespace std;
using namespace BR;

int main()
{
	Vector2D<int> veci0;

	cout << "read Vector2D<int> veci0\n";
	cin >> veci0;
	cout << "veci0 = " << veci0 << "\n";

	Vector2D<int> veci1;

	cout << "read Vector2D<int> veci1\n";
	cin >> veci1;
	cout << "veci1 = " << veci1 << "\n";

	cout << "veci0 + veci1 = " << veci0 + veci1 << "\n";
	cout << "veci0 - veci1 = " << veci0 - veci1 << "\n";
	cout << "2 * veci0 = " << 2 * veci0 << "\n";
	cout << "veci0 / 2 = " << veci0 / 2 << "\n";

	cout << "end\n";

	return 0;
}