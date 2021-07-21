class Solution {
public:
    string pushDominoes(string A) {

        int N = A.size();
        vector<int> forces(N,0);

        // Populate forces going from left to right
        int force = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] == 'R') force = N;
            else if (A[i] == 'L') force = 0;
            else force = max(force - 1, 0);
            forces[i] += force;
        }

        // Populate forces going from right to left
        force = 0;
        for (int i = N-1; i >= 0; --i) {
            if (A[i] == 'L') force = N;
            else if (A[i] == 'R') force = 0;
            else force = max(force - 1, 0);
            forces[i] -= force;
        }

        string ans="";
        for (auto f: forces){
            char c = f > 0 ? 'R' : f < 0 ? 'L' : '.';
            ans += c;
        }
        return ans;
    }

};
