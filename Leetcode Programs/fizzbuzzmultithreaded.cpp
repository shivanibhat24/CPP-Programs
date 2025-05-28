class FizzBuzz {
private:
    int n;
    mutex m;
    condition_variable c;
    int i;
public:
    FizzBuzz(int n) {
        this->n = n;
        this->i = 1;
    }
    void fizz(function<void()> printFizz) {
        while(i<=n)
        {
            unique_lock<mutex> lock(m);
            while(i<=n && (((i%3) == 0) && ((i%5) != 0)) == 0)
            {
                c.wait(lock);
            }
            if(i<=n)
            {
                printFizz();
                i++;
            }
            c.notify_all();
        }
    }
    void buzz(function<void()> printBuzz) {
        while(i<=n)
        {
            unique_lock<mutex> lock(m);
            while(i<=n && (((i%3) != 0) && ((i%5) == 0)) == 0)
            {
                c.wait(lock);
            }
            if(i<=n)
            {
                printBuzz();
                i++;
            }
            c.notify_all();
        }
    }
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(i<=n)
        {
            unique_lock<mutex> lock(m);
            while(i<=n && (((i%3) == 0) && ((i%5) == 0)) == 0)
            {
                c.wait(lock);
            }
            if(i<=n)
            {
                printFizzBuzz();
                i++;
            }
            c.notify_all();
        }
    }
    void number(function<void(int)> printNumber) {
        while(i<=n)
        {
            unique_lock<mutex> lock(m);
            while(i<=n && (((i%3) != 0) && ((i%5) != 0)) == 0)
            {
                c.wait(lock);
            }
            if(i<=n)
            {
                printNumber(i++);
            }
            c.notify_all();
        }
    }
};
