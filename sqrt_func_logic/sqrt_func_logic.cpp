
#include <std_lib_facilities.h>

double mysqrt(double number)
{
    double error = 0.00001; //define the precision of your result
    double s = number;

    while ((s - number / s) > error) //loop until precision satisfied 
    {
        s = (s + number / s) / 2;
    }
    return s;
}

int main()
{
    cout << mysqrt(7);
}
