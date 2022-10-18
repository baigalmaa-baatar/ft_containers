#include <iostream>
#include <vector>
using namespace std;

int main(){

    vector< vector<int> > vec2d;

    vector<int> tmp1;
    tmp1.push_back(1);
    tmp1.push_back(2);

    vector<int> tmp2;
    tmp2.push_back(3);
    tmp2.push_back(4);

    vec2d.push_back(tmp1);
    vec2d.push_back(tmp2);

    vector< vector<int> >::iterator i, iEnd;
    i = vec2d.begin();
    iEnd = vec2d.end();

    cout << (*i)[1] << endl;        // outputs 2 (same as vec2d[0][1])
    cout << vec2d[0][1] << endl;    // outputs 2
    cout << vec2d[1][0] << endl;    // outputs 3
    cout << vec2d[1][1] << endl;    // outputs 4

    return 0;
}