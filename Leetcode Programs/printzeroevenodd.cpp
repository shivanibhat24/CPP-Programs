class ZeroEvenOdd {
private:
    int n;
    mutex mx;
    condition_variable cv;
    int print = 0;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->print = 0;
    }
    void zero(function<void(int)> printNumber) {
        for(int i = 0; i < n; ++i){
            unique_lock<mutex> lock(mx);
            cv.wait(lock,[&](){return print == 0;});
            printNumber(0);
            if (i%2)
                print = 2;
            else
                print = 1;
            cv.notify_all();
        }
    }
    void even(function<void(int)> printNumber) {
        for(int i = 0; i < n/2; ++i){
            unique_lock<mutex>lock(mx);
            cv.wait(lock, [&](){return print == 2;});
            printNumber(i*2 + 2);
            print = 0;
            cv.notify_all();
        }
    }
    void odd(function<void(int)> printNumber) {        
        for(int i = 0; i < (n+1)/2; ++i){
            unique_lock<mutex> lock(mx);
            cv.wait(lock, [&](){return print == 1;});
            printNumber(i*2 + 1);
            print = 0;
            cv.notify_all();
        }
    }
};
