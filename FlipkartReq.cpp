#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> cups;
    vector<int> temp;
    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(1);
    temp.push_back(1);
    cups.push_back(temp);
    vector<int> require;
    require=temp;
    int lower=*max_element(require.begin(),require.end()-1);
    int min_cost=INT_MAX;
    for(int i=0;i<cups.size();i++){
        vector<int> cup=cups[i];
        if(*max_element(cup.begin(),cup.end()-1) < lower ) continue;
        int cost=0;
        for(int j=0;j<require.size();j++){
            cost+= (require[j] - (*lower_bound(cup.begin(),cup.end(),require[j])));
        }
        if(cost<min_cost){
            min_cost=cost;
        }
    }
    cout<<min_cost<<endl;
    return 0;
}
