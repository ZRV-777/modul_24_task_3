#include <iostream>
#include <ctime>
#include <iomanip>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    time_t t = 0;
    tm *gmt = gmtime(&t);

    cout << "Start timer (MM:SS)" << endl;
    cin >> get_time(gmt, "%M:%S");

    while(gmt->tm_min >= 0)
    {
        while(gmt->tm_sec >= 0)
        {
            this_thread::sleep_for (chrono::seconds(1));

            cout << gmt->tm_min << ":" << gmt->tm_sec << endl;
            gmt->tm_sec--;
        }

        gmt->tm_min--;
        gmt->tm_sec = 59;
    }

    cout << "DING! DING! DING!";
}