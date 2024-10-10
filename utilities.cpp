#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <utility>
#include <unordered_map>

using namespace std;

void printDelimiter()
{
    cout << "--------------------------------" << endl;
}

string getTime12HourFormat(int time)
{
    string suffix = "AM";
    if(time >= 12)
    {
        suffix = "PM";
        if(time > 12)
        {
            time -= 12;
        }
    }
    return to_string(time) + ":00 " + suffix;
}