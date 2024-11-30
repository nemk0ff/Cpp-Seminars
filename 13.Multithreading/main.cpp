#include "mainwindow.h"
#include <thread>
#include <mutex>
#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    int counter = 0;

    std::mutex mtx;

    thread t1([&](){
        for(auto i = 0; i < 1000; i++)
        {
            {
                mtx.lock();
                ++counter;
                mtx.unlock();
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    });

    thread t2([&](){
        while (true) {
            {
                mtx.lock();
                w.updateProgress(counter);
                mtx.unlock();
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });

    w.show();

    int result = a.exec();

    t1.join();

    return result;
}

