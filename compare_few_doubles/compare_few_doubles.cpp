
#include <std_lib_facilities.h>

// validates unit
bool check_unit(string unit)
{
	if (unit == "cm" || unit == "m" || unit == "in" || unit == "ft")
		return true;
	else return false;
}

// converts value into meters according its unit and returns it
double unit_conv_to_meter(double val, string unit)
{
	if (unit == "m") return val;
	else if (unit == "cm") return val / 100.0;
	else if (unit == "in") return val / 100.0 * 2.54;
	else if (unit == "ft") return val / 100.0 * 2.54 * 12;
}

int main()
{
	vector<double> doubles;
	cout << "Enter double and its unit separated by a space or together." << endl;
	double num1, num2, min_num = 0, max_num = 0, total = 0;
	string unit;
	int i = 0;
	while (i < 5)
	{
		if (i == 0 && cin >> num1 >> unit) // first iteration
		{
			if (!check_unit(unit)) { cout << "Invalid input. Type 'cm', 'm', 'in' or 'ft'." << endl; continue; }
			else if (num1 <= 0) { cout << "Invalid input. The value must be positive." << endl; continue; }
			doubles.push_back(unit_conv_to_meter(num1, unit));
			min_num = max_num = unit_conv_to_meter(num1, unit);
			total += unit_conv_to_meter(num1, unit);
			cout << "Current value " << num1 << unit << " is the first." << endl;
		}
		else if (i % 2 != 0 && cin >> num2 >> unit) // odd iteration
		{
			if (!check_unit(unit)) { cout << "Invalid input. Type 'cm', 'm', 'in' or 'ft'." << endl; continue; }
			else if (num2 <= 0) { cout << "Invalid input. The value must be positive." << endl; continue; }
			total += unit_conv_to_meter(num2, unit);
			doubles.push_back(unit_conv_to_meter(num2, unit));
			if (unit_conv_to_meter(num2, unit) > max_num)
			{
				max_num = unit_conv_to_meter(num2, unit);
				cout << "Current value " << num2 << unit << " is the biggest among the entered." << endl;
			}
			else if (unit_conv_to_meter(num2, unit) < min_num) // even iteration
			{
				min_num = unit_conv_to_meter(num2, unit);
				cout << "Current value " << num2 << unit << " is the smallest among the entered." << endl;
			}
		}
		else if (i % 2 == 0 && cin >> num1 >> unit)
		{
			if (!check_unit(unit)) { cout << "Invalid input. Type 'cm', 'm', 'in' or 'ft'." << endl; continue; }
			else if (num1 <= 0) { cout << "Invalid input. The value must be positive." << endl; continue; }
			total += unit_conv_to_meter(num1, unit);
			doubles.push_back(unit_conv_to_meter(num1, unit));
			if (unit_conv_to_meter(num1, unit) > max_num)
			{
				max_num = unit_conv_to_meter(num1, unit);
				cout << "Current value " << num1 << unit << " is the biggest among the entered." << endl;
			}
			else if (unit_conv_to_meter(num1, unit) < min_num)
			{
				min_num = unit_conv_to_meter(num1, unit);
				cout << "Current value " << num1 << unit << " is the smallest among the entered." << endl;
			}
		}
		else
		{
			cout << "Only doubles or integers are allowed." << endl;
			cin.clear();
			while (cin.get() != '\n');
			continue;
		}
		++i;
	}
	// Output results
	cout << "Minimum value is " << min_num << "m" << endl;
	cout << "Maximum value is " << max_num << "m" << endl;
	cout << "Quantity is " << i << endl;
	cout << "Total is " << total << "m" << endl;
	if (doubles.size() == 0) return 0;
	cout << "All entered values ascending are:" << endl;
	sort(doubles);
	for (double x : doubles)
	{
		cout << x << "m" << endl;
	}
	cout << endl;
}
