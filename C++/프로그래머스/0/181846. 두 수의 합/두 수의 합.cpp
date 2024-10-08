#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string sum_big(string a, string b)
{
    int diff = max(a.length(), b.length()) - min(a.length(), b.length());
    
    if(a.length() < b.length())
        for(int i=0; i<diff; i++) a = "0" + a;
    else if(a.length() > b.length())
        for(int i=0; i<diff; i++) b = "0" + b;
    
    vector<int> c;
    for(int i=0; i<a.length(); i++) c.push_back(a[i] - '0' + b[i] - '0');

    reverse(c.begin(), c.end());    
    for(int i=0; i<c.size(); i++) 
    {
        if(c[i] < 10) continue;

        if(i < c.size()-1) c[i+1] += c[i]/10;
        else c.push_back(c[i]/10);
        c[i] %= 10;
    }
    reverse(c.begin(), c.end());
    
    string s_num = "";
    for(auto s : c)
        s_num.push_back((char)s+'0');
    
    return s_num;
}

string solution(string a, string b) {
    string answer = "";

    answer = sum_big(a, b);
    
    return answer;
}