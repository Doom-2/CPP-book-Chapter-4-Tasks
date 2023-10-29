
#include <std_lib_facilities.h>

// Uses for standard input to string object.
// Contains std::strtod() to convert string to double, if possible.
// The pointer 'p' of this func will point to the first character that cannot be converted to a double.
// If the string is '|', then this will be a flag for the subsequent aborting the program.
double cin_double_with_check()
{
	double val;
	string s;
	while (1) {

		cin >> s;
		char* p;
		val = strtod(s.c_str(), &p);
		if (*p == 0) {
			return val;
		}
		else {
			if (s == "|") return 0.0000001;
			else
			{
				cout << "Invalid input! Only decimal value is allowed.\n" << "Try again\n";
				cin.clear();
				while (cin.get() != '\n');
			}
		}
	}
}

int main()
{
	vector<double> doubles;
	cout << "Enter 2 doubles or '|' to abort" << endl;
	double num;
	int i = 0;
	while (i < 2)
	{
		num = cin_double_with_check();
		if (num == 0.0000001) { cout << "Exiting the program.." << endl; return 0; }
		doubles.push_back(num);
		++i;
	}
	cout << endl << "The entered values are" << endl;
	for (double x : doubles)
	{
		cout << x << '\n';
	}
	if (doubles.size() < 2) return 0;
	if (abs(doubles[0] - doubles[1]) < 1.0 / 100 && doubles[0] != doubles[1]) cout << "Both values are almost equal.";
	else if (doubles[0] < doubles[1]) {
		cout << "Minimum value is " << doubles[0] << endl;
		cout << "Maximum value is " << doubles[1] << endl;
	}
	else if (doubles[0] > doubles[1]) {
		cout << "Minimum value is " << doubles[1] << endl;
		cout << "Maximum value is " << doubles[0] << endl;
	}
	else cout << "Both values are equal." << endl;
}
