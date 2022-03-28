#include <iostream>
#include <mutex>
#include <thread>
#include <condition_variable>

std::mutex mut;
std::condition_variable cv;
bool sw = false;

int main()
{
    auto thread1 = [](){
       while(true)
       {
            std::unique_lock<std::mutex> ls(mut);
            cv.wait(ls, [](){return sw;});
            std::cout << "2]";
            sw = false;
            cv.notify_one();
       }
    };

    auto thread2 = [](){
        while(true)
        {
            std::unique_lock<std::mutex> ls2(mut);
            cv.wait(ls2, [](){return !sw;});
                std::cout << "[1";
                sw = true;
            cv.notify_one();
        }
    };

    auto start1 = std::thread(thread1);
    auto start2 = std::thread(thread2);

    start1.join();
    start2.join();

    return 0; 
}
