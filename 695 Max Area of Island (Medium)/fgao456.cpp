//global variable + void dfs()   not recomended
class Solution
{
    int maxArea = 0;

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        if (grid.size() < 1 || grid[0].size() < 1)
            return maxArea;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                int count = 0;
                if (grid[i][j] == 1)
                {
                    dfs(grid, count, i, j);
                }
                maxArea = max(maxArea, count);
            }
        }
        return maxArea;
    }

    void dfs(vector<vector<int>> &grid, int &count, int i, int j)
    {

        count++;
        grid[i][j] = 0;

        if (i - 1 >= 0 && grid[i - 1][j] == 1)
            dfs(grid, count, i - 1, j);
        if (i + 1 < grid.size() && grid[i + 1][j] == 1)
            dfs(grid, count, i + 1, j);
        if (j - 1 >= 0 && grid[i][j - 1] == 1)
            dfs(grid, count, i, j - 1);
        if (j + 1 < grid[0].size() && grid[i][j + 1] == 1)
            dfs(grid, count, i, j + 1);

        return;
    }
};

//no global variable + int dfs()
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int maxArea = 0;
        if (grid.size() < 1 || grid[0].size() < 1)
            return maxArea;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                int count = 0;
                if (grid[i][j] == 1)
                {
                    count = dfs(grid, i, j);
                    maxArea = max(maxArea, count);
                }
            }
        }
        return maxArea;
    }
    int dfs(vector<vector<int>> &grid, int i, int j)
    {

        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return 0;

        grid[i][j] = 0;

        return 1 + dfs(grid, i - 1, j) + dfs(grid, i + 1, j) + dfs(grid, i, j - 1) + dfs(grid, i, j + 1);
    }
};