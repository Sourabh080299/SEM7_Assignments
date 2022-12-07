#include <iostream>
#include <map>
int main() {
    std::map<int, int> mp;
    mp[1] = 3;
    mp[3] = 5;
    mp[2] = 10;
    
    for(auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        cout << itr->first <<" "<<itr->second<< endl;
    }
}
