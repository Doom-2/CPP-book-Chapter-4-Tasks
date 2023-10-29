
#include <std_lib_facilities.h>

int main()
{
    vector<double> temps_list;
    for (double temp; cin >> temp;)
        temps_list.push_back(temp);

    double sum = 0;
    for (int x : temps_list) sum += x;
    cout << "Avarage temperature: " << sum / temps_list.size() << endl;
    sort(temps_list);
    cout << "Median temperature: " << temps_list[temps_list.size() / 2];
}
