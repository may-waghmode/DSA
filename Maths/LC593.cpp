class Solution {
public:
    int dist(vector<int>& a, vector<int>& b) {
        int dx = a[0] - b[0];
        int dy = a[1] - b[1];
        return dx * dx + dy * dy;
    }

    bool validSquare(vector<int>& p1, vector<int>& p2, 
                     vector<int>& p3, vector<int>& p4) {
        
        set<int> s;

        s.insert(dist(p1, p2));
        s.insert(dist(p1, p3));
        s.insert(dist(p1, p4));
        s.insert(dist(p2, p3));
        s.insert(dist(p2, p4));
        s.insert(dist(p3, p4));

        return s.size() == 2 && !s.count(0);
    }
};