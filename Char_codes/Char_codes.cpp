
#include <std_lib_facilities.h>


int main()
{
    cout << "Character\tASCII Value\n";
    char ch;
    /* int i = 97;
    while (i <= 122)
    {
        ch = i;
        cout << ch << "\t\t" << i << endl;
        ++i;
    }*/
    for (int i = 48; i <= 90; i++)
    {
        if (i >= 58 && i <= 64) continue;
        ch = i;
        cout << ch << "\t\t" << i << endl;
    }
    cout << sqrt(7);

}
