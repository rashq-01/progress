#include<bits/stdc++.h>

using namespace std;

int find(int i,vector<int>& parent){
    if(i == parent[i]){
        return i;
    }
    return parent[i] = find(parent[i],parent);
}

// void Union(int x, int y, vector<int>& parent){
//     int parent_x = find(x,parent);
//     int parent_y = find(y,parent);

//     if(parent_x != parent_y){
//         parent[parent_x] = parent_y;
//     }
// }
void Union(int x, int y, vector<int>& parent, vector<int>& rank){
    int parent_x = find(x,parent);
    int parent_y = find(y,parent);

    if(parent_x == parent_y){
        return;
    }

    if(rank[parent_x] > rank[parent_y]){
        parent[parent_y] = parent_x;
    }
    else if(rank[parent_x] < rank[parent_y]){
        parent[parent_x] = parent_y;
    }
    else{
        parent[parent_x] = parent_y;
        rank[parent_y]++;
    }
}

int main(){



    return 0;
}