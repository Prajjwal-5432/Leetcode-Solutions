//Link: https://leetcode.com/problems/detect-squares/

class DetectSquares {
public:
    int ar[1001][1001];
    DetectSquares() {
        memset(ar, 0, sizeof(ar));
    }
    
    void add(vector<int> point) {
        ar[point[0]][point[1]]++;
    }
    
    int count(vector<int> p) {
        int ways = 0;
        for(int i = 0; i < 1001; ++i) {
            if(ar[i][p[1]] and i != p[0]) {
                int len = abs(p[0] - i);
                
                int x2 = i, y2 = p[1];
                int x3 = i, y3 = p[1] - len;
                int x4 = p[0], y4 = p[1] - len;
                
                if(max(y3, y4) < 1001 and min(y3, y4) >= 0) 
                    ways += (ar[x2][y2] * ar[x3][y3] * ar[x4][y4]);
                
                y3 = p[1] + len, y4 = y3;
                if(max(y3, y4) < 1001 and min(y3, y4) >= 0) 
                    ways += (ar[x2][y2] * ar[x3][y3] * ar[x4][y4]);
            }
        }
        return ways;
    }
};