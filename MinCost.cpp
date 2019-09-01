#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

void calculate_min(vector<vector<int>> v,int level,int cost,int& min_till,bool takencolor[]){
    if(level == v.size()){
        if(cost<min_till) min_till=cost;
        return;
    }else{
        for(int i=0;i<v.size();i++){
            if(takencolor[i] == true) continue;
            takencolor[i]=true;
            calculate_min(v,level+1,cost+v[level][i],min_till,takencolor);
            takencolor[i]=false;
        }
    }
}

int main()
{
    vector<int> v1={1,2,3};
    vector<int> v2={2,1,3};
    vector<int> v3={6,1,5};
    vector<vector<int>> v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    int min=INT_MAX;
    bool takencolor[v.size()];
    memset(takencolor,false,sizeof(takencolor));
    calculate_min(v,0,0,min,takencolor);
    cout<<min<<" "<<endl;
    return 0;
}
