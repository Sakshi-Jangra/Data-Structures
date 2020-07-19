#include <iostream>
#include <map>
#include <functional>

using namespace std;

// Map : Pair<Key,Value>
// Key/Value can have any type
// TYPES of maps: Unordered & Ordered
//
int main()
{
    map<int,int> rollPresent;
    map<string,int> namePresent;
    cout << "Map created!" << endl;

    // inserting into map
    rollPresent.insert({1,10});
    rollPresent[2] = 20;
    rollPresent.insert(make_pair(3,30));

    // iterative insert
    for(int i=4; i<10; i++)
        rollPresent[i] = i*10;  // any of above three

    // output map || traverse map || access map
    for(auto &ele : rollPresent){
        cout<<ele.first<<ele.second;
    }
    return 0;
}
