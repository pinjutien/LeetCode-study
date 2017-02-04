/*

ref: 
https://segmentfault.com/a/1190000007436525
http://en.cppreference.com/w/cpp/container/priority_queue

Q:
Given N 2-D points, and origin point. To find K-th closest point to origin point.
https://segmentfault.com/a/1190000007436525

A:
Use heap to keep track of all the element and store first K-th closest points.
For every new element, when it push in the heap and then heaplify the heap. 
Time complexity: O(N*logK), given K-size of heap, it takes logK to heapify it.
Space compexity: O(K), ie the size of heap

 */

#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>  
#include <vector>
using namespace std;

struct point {
  double x;
  double y;
  point(int x_input, int y_input): x(x_input), y(y_input) {}
};

double get_distance(point a, point b) {
  double dist = 0.0;
  dist = sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
  return dist;
}

typedef bool (*compare_ptr) (point, point);
point origin_point = point(0.0, 0.0);
bool compare(point a, point b) {
  return (get_distance(a, origin_point) < get_distance(b, origin_point));
}

vector<point> first_k_point(vector<point> &input_points, point origin, int k) {
  origin_point = point(origin.x, origin.y);
  priority_queue< point, vector<point>, compare_ptr > heap_obj(compare);
  
  for (int i = 0; i < input_points.size(); i++) {
    point p = input_points[i];
    heap_obj.push(p);
    if (heap_obj.size() > k) {
      heap_obj.pop();
    }
  }

  vector<point> result;
  while(!heap_obj.empty()) {
    point p_temp = heap_obj.top();
    result.push_back(p_temp);
    heap_obj.pop();
  }

  return result;
}


int main()
{
   Point p1 = Point(4.5, 6.0);
   Point p2 = Point(4.0, 7.0);
   Point p3 = Point(4.0, 4.0);
   Point p4 = Point(2.0, 5.0);
   Point p5 = Point(1.0, 1.0);
   vector<Point> array = {p1, p2, p3, p4, p5};
   int k = 2;
   Point origin = Point(0.0, 0.0);
   vector<Point> ans = Solution(array, origin, k);
   for (int i = 0; i < ans.size(); i++) {
       cout << i << ": " << ans[i].x << "," << ans[i].y << endl;
   }
   //cout << getDistance(p1, p2) << endl;
}
