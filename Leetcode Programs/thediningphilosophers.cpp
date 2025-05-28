class DiningPhilosophers {
    std::array<std::mutex, 5> mutexes;
public:
    DiningPhilosophers() {        
    }
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int leftFork = philosopher;
        int rightFork = (philosopher + 1) % 5;
        std::scoped_lock lock(mutexes[leftFork], mutexes[rightFork]);
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
    }
};
