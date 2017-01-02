// ref: // http://www.geeksforgeeks.org/median-of-stream-of-integers-running-integers/
#include <iostream>
using namespace std;

// utility function
void swap(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;
}

bool Greater(int x, int y) { return x>y }

bool Smaller(int x, int y) { return y>x }

int Average(int x, int y) { return (x+y)/2 }

// Heap construction
#define MAX_HEAP_SIZE (128)
#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

class Heap {

public:
  // Initialize heap an array and comparator
  Heap(int *array_, bool (*comp_)(int, int)) : heap_array(array_), comparator(comp_) {
    heap_size = -1;
  }

  // free up heap_array, dynamics array.
  virtual ~Heap() {
    if (heap_array) {
      delete[] heap_array;
    }
  }

  // pure virtual function
  virtual bool Insert(int x) = 0;
  virtual int GetTop() = 0;
  virtual int ExtractTop() = 0;
  virtual int GetCount() = 0;


protected:

  int *heap_array;
  bool (*comparator)(int, int);
  int heap_size;

  // i: the index of element
  // left_child: the index of left child
  int left_child(int i) {
    return 2*i + 1;
  }

  // right_child: the index of right child
  int right_child(int i) {
    return 2*(i + 1);
  }

  // parent: the index of parent
  int parent(int i) {
    if (i <= 0 ) return -1;
    return (i-1)/2;
  }

  // root element
  int top() {

    if (heap_size >= 0) {
      return heap_array[0];
    }

    return -1;
  }

  int count() {
    return heap_size+1;
  }

  // heapify a heap to make sure all the elements following the heap structure.
  void heapify(int i) {
    int p = parent(i);
    if (p >= 0 && comparator(heap_array[i], heap_array[p])) {
      swap(heap_array[i], heap_array[p]);
      heapify(p);
    }
  }

  // delete root of heap
  int deleteTop() {
    int top_element = -1;
    if (heap_size >= 0) {
      root_element = heap_array[0];
      swap(heap_array[0], heap_array[heap_size]);
      heap_size -=1;
      heapify(parent(heap_size +1));
    }
    return top_element;
  }

  // insert helper function
  // if the heap_size still smaller than MAX_HEAP_SIZE, return true
  bool insert_helper(int x) {
    if (heap_size < MAX_HEAP_SIZE) {
      heap_size += 1;
      heap_array[heap_size] = x;
      heapify(heap_size);
      return true;
    }
    return false;
  }

};


// Max heap
class MaxHeap : public Heap {

public:
  MaxHeap() : Heap(new int[MAX_HEAP_SIZE], &Greater) {}
  ~MaxHeap() {}

  // return the top element
  int GetTop() {
    return top();
  }

  // delete the top element
  int ExtractTop() {
    return deleteTop();
  }

  // return the size of heap
  int GetCount() {
    return count();
  }

  // insert function
  // if the heap_size still smaller than MAX_HEAP_SIZE, return true
  bool Insert(int x) {
    return insert_helper(x);
  }

};


// Min heap
class MinHeap : public Heap {

public:
  MinHeap() : Heap(new int[MAX_HEAP_SIZE], &Smaller) {}
  ~MinHeap() {}

  // return the top element
  int GetTop() {
    return top();
  }

  // delete the top element
  int ExtractTop() {
    return deleteTop();
  }

  // return the size of heap
  int GetCount() {
    return count();
  }

  // insert function
  // if the heap_size still smaller than MAX_HEAP_SIZE, return true
  bool Insert(int x) {
    return insert_helper(x);
  }

};


