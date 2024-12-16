class Solution {
public:
    int maxRectangleArea(vector<vector<int>>& points) {
        int best = -1;
        vector<int> rectangle(8);
        // brute force all rectanges checking if they are valid at end
        solve(points, 0, best, 0, rectangle);
        return best;
    }

    void solve(vector<vector<int>>& points, int mask, int & best, int count, vector<int> rectangle) {
        if (points.size() < 4) return;
        // if 4 points used check if valid
        if  (count == 4) {
            //cout << "checking" << endl;
            for (int i = 0; i < points.size(); i++) {
                // this point is used
                if (mask & (1 << i)) continue;
                // else check if valid
                else {
                    if ((rectangle[1] <= points[i][1] && points[i][1] <= rectangle[3]) && (rectangle[0] <= points[i][0] && points[i][0] <= rectangle[6])) return;
                }
            }
            best = max(best, (rectangle[3] - rectangle[1])*(rectangle[6] - rectangle[0]));
            return;
        }

        for (int i = 0; i < points.size(); i++) {
            vector<int> point = points[i];
            // this point is used
            if (mask & (1 << i)) continue;
            // this point is valid based on prev
            if (count == 1) {
                if (rectangle[0] != point[0]) continue;
                if (rectangle[1] >= point[1]) continue;
            }
            else if (count == 2) {
                if (rectangle[2] >= point[0]) continue;
                if (rectangle[3] != point[1]) continue;
            }
            else if (count == 3) {
                if (rectangle[4] != point[0]) continue;
                if (rectangle[1] != point[1]) continue;
            }
            rectangle[count*2] = point[0];
            rectangle[count*2+1] = point[1];
            // search this space
            solve(points, mask | (1 << i), best, count+1, rectangle);
        }
    }
};

// its the google question