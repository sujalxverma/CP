#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;

// Simple threading tutorial.

/*
    ~Thread creation using function pointer.~
Both threads are independent of one another.

When creating mutliple threads together,
it is not guranteed that they are created in order.

long long odd, even;
void evensum(long long s, long long e)
{
    even = 0;
    for (long long i = s; i <= e; i++)
    {
        if (i % 2 == 0)
        {
            even += i;
        }
    }
}
void oddsum(long long s, long long e)
{
    odd = 0;
    for (long long i = s; i <= e; i++)
    {
        if (i % 2 == 1)
        {
            odd += i;
        }
    }
}


int main()
{

    auto start = high_resolution_clock::now();

    long long s = 1;
    long long e = 19000000000;

    std ::thread t1(oddsum, s, e);
    std ::thread t2(evensum, s, e);

    t1.join();
    t2.join();

    cout << odd << " " << even << "\n";

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);
    cout << "Time taken: " << duration.count() << " seconds\n";

    return 0;
}
*/
// ----------------------------------------------------------------
/*
    ~Threads using Lambda function.~


int main()
{
    // Directly injects lambda function when thread is created.
    auto start = high_resolution_clock::now();
    long long even = 0;
    long long e = 19000000000;
    auto evensum = [](long long x, long long &even)
    {
        while (x-- > 0)
        {
            if (x % 2 == 0)
            {
                even += x;
            }
        }
    };

    long long odd = 0;

    auto oddsum = [](long long x, long long &odd)
    {
        while (x-- > 0)
        {
            if (x % 2 == 1)
            {
                odd += x;
            }
        }
    };

    std ::thread t1(evensum, e, std::ref(even));
    std::thread t2(oddsum, e, std::ref(odd));

    t1.join();
    t2.join();

    cout << odd << " " << even << "\n";
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);
    cout << duration.count() << " second\n";
}
*/

// ----------------------------------------------------------------
/*
    ~ Threads using Functor (Function Object)~


class Base
{
public:
    void operator()(int x)
    {
        while (x-- > 0)
        {
            // do something.
        }
    }
};

int main()
{

    auto start = high_resolution_clock::now();

    std ::thread t1(Base(), 10);
    t1.join();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(end - start);
    cout << duration.count() << " second\n";
}
*/

/*
    ~Thread using Non static member function.~


class Base
{
public:
    void run(int x){
        while(x --> 0){
            //
        }
    }
};
int main(){
    Base b;
    std :: thread t1 (&Base::run , &b , 10);
    t1.join();
}
*/
