#include<bits/stdc++.h>
using namespace std;
void shortest_distance(vector<vector<int>> &matrix)
{
    // Code here
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 1e9;
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    // to detect negative cycle
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][i] < 0)
        {
            cout << "Negative Cycle\n";
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1e9)
            {
                matrix[i][j] = -1;
            }
        }
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    //Here input is given in the form of adjacency matrix
    //When no edge exists between two vertices then -1 is given
    //When there is a self loop then 0 is given
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(n);
        for (int j = 0; j < n; j++)
        {
            cin >> temp[j];
        }
        matrix[i] = temp;
    }
    shortest_distance(matrix);
    for (auto i : matrix)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
