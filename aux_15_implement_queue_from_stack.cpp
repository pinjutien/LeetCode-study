#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>

using namesapce std;

class Queue {
private:
  stack<int> s_enq, s_deq;

public:
  void enqueue(int x) {
    s_enq.emplace(x);
  }

  int dequeue() {
    // populate all the element in s_enq into s_deq.
    while((!s_enq.empty()) & (s_deq.empty())) {
      s_deq.emplace(s_enq.top());
      s_enq.pop();
    }

    if (s_deq.empty()) {
      cout << "empty queue. " << "\n";
      break;
    }

    int pop_val = s_deq.top();
    s_deq.pop();
    return pop_val;
  }

};
