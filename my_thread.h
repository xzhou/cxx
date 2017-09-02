//
// Created by xz on 9/2/17.
//

#ifndef CXX_MYTHREAD_H
#define CXX_MYTHREAD_H

#include <iostream>
#include <future>
#include <thread>

class MyThread {
 public:
  static void RunInThread() {
    std::packaged_task<int()> task([](){ return 7; });
    std::future<int> result = task.get_future();

    std::thread(std::move(task)).detach();

    result.wait();

    std::cout << "Done!" << std::endl;
    std::cout << "Result is " << result.get() << std::endl;
  }

};


#endif //CXX_MYTHREAD_H
