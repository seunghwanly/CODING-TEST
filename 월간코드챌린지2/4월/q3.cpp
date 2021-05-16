#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct node
{
    int w;
    int n;
    vector<int> link();
};

long long solution(vector<int> a, vector<vector<int> > edges)
{
    long long answer = -2;

    vector<vector<node> > map;
    const int sizeofA = a.size();
    
    bool check[sizeofA] = { false, };

    // make tree
    for (int i = 0; i < edges.size(); ++i)
    {
        int start = edges[i][0];
        int dest = edges[i][1];

        node temp = {a[dest], dest};
        bool isThere = false;
        for(int j=0; j<map[start].size(); ++j) {
            if(map[start][j].n == dest) isThere = true;
        }
        if(!isThere)
            map[start].push_back(temp);
    }

    // find max child
    int maxChildLength = -1;
    int maxChildName = -1;
    for (int i = 0; i < map.size(); ++i)
    {
        int size = map[i].size();
        if (maxChildLength < size)
        {
            maxChildName = i;
            maxChildLength = size;
        }
    }
    cout << maxChildName << " " << maxChildLength << endl;

    // show tree
    for (int i = 0; i < map.size(); ++i)
    {
        for (int j = 0; j < map[i].size(); ++j)
        {
            cout << i << " >> " << map[i][j].n << " / " << map[i][j].w << " | ";
        }
        cout << "\n";
    }

    return answer;
}

int main()
{
    const int arr[5] = {-5, 0, 2, 1, 2};
    const int eArr[4][2] = {
        {0, 1},
        {3, 4},
        {2, 3},
        {0, 3}};

    vector<int> a = vector<int>();
    vector<vector<int> > edges = vector<vector<int> >(4);

    for (int i = 0; i < 5; ++i)
    {
        a.push_back(arr[i]);
    }
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            edges[i].push_back(eArr[i][j]);
        }
    }

    cout << solution(a, edges) << endl;

    return 0;
}