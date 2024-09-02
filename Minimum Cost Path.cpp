//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


struct cell {
    int x;
    int y;
    int cost;
    cell(int x1, int y1,  int cost1) {
        x = x1;
        y = y1;
        cost = cost1;
    }
};

// function to sort the cells according to cost, x, y
bool operator<(const cell& a, const cell& b){
    if(a.cost == b.cost)
    {
        return (a.x != b.x? a.x < b.x: a.y < b.y);
    }
    else
    {
        return a.cost < b.cost;
    }
}

class Solution
{
    public:
    
    // Function to compare cell path
    // c.x & c.y coordinates of new cell
    // c.cost of source cell
    void validateCell(vector<vector<int>>& grid, vector<vector<int>>& cost, set<cell>& s,
        cell& c) {
        // validate coordinates x, y
        if(c.x >=0 && c.x < grid.size() && c.y >= 0 && c.y < grid.size())
        {
            // check if new cost lower than old one
            int newCost = c.cost + grid[c.y][c.x];
            if(newCost < cost[c.y][c.x])
            {
                c.cost = cost[c.y][c.x];
                cost[c.y][c.x] = newCost;
                auto cp = s.find(c);
                if(cp != s.end())
                {
                    s.erase(cp);
                }
                c.cost = newCost;
                s.insert(c);
            }
        }
    }
    
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size();

        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));
        cost[0][0] = grid[0][0];
        set<cell> s;
        s.insert(cell(0, 0, grid[0][0]));

        while(!s.empty() && s.begin()->cost < cost[n-1][n-1])
        {
            cell c = *s.begin();
            s.erase(s.begin());
            
            // validate left cell
            cell cl = c;
            cl.x--;
            validateCell(grid, cost, s, cl);
            
            // validate right cell
            cell cr = c;
            cr.x++;
            validateCell(grid, cost, s, cr);
            
             // validate upper cell
            cell cu = c;
            cu.y--;
            validateCell(grid, cost, s, cu);
            
            // validate lower cell
            cell cb = c;
            cb.y++;
            validateCell(grid, cost, s, cb);
            
       }

        return cost[n-1][n-1];
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
