class FooBar {
private:
    int             n;
    atomic<bool>    alt; 
public:
    FooBar(int n)
    {
        this->n = n;
        alt = false;
    }
    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++)
        {
		while (alt)
		{
			this_thread::yield();
		}
		printFoo();
		alt = !alt; 
        }
    }
    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++)
        {
		while (!alt)
		{
			this_thread::yield();
		}
		printBar();
		alt = !alt; 
        }
    }
};
