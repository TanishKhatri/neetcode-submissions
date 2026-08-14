class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        int j = -1;
        for (int i : asteroids) {
            if (j >= 0 && asteroids[j] > 0 && i < 0) {
                bool iDestroyed = false;
                while(j >= 0 && asteroids[j] > 0 && i < 0) {
                    if (abs(asteroids[j]) < abs(i)) {
                        j--;
                    } else if (abs(asteroids[j]) == abs(i)) {
                        j--;
                        iDestroyed = true;
                        break;
                    } else {
                        iDestroyed = true;
                        break;
                    }
                }

                if (!iDestroyed) {
                    asteroids[++j] = i;
                }
            } else {
                asteroids[++j] = i;
            }
        }

        res = vector<int>(asteroids.begin(), asteroids.begin() + j + 1);
        return res;
    }
};