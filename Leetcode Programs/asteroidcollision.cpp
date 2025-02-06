lass Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int index = 0; // Acts like the top of the stack
        for (int a : asteroids) {
            while (index > 0 && asteroids[index - 1] > 0 && asteroids[index - 1] < -a) {
                index--; // Pop the last asteroid (collision occurs)
            }
            if (index == 0 || asteroids[index - 1] < 0 || a > 0) {
                asteroids[index++] = a; // Push asteroid into "stack"
            } else if (asteroids[index - 1] == -a) {
                index--; // Both asteroids explode
            }
        }
        return vector<int>(asteroids.begin(), asteroids.begin() + index);
    }
};
