#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <map>
#include <pair>


using std::map;
using std::make_pair;
using std::pair;

typedef std::map<pair<int, int>, int> mypair;

// greatest common divisor
int gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  if (a < 0) return gcd(-a, b);
  if (b < 0) return gcd(a, -b);
  // convention: first arg is the smaller one.
  if (a > b) return gcd(b, a);
  // when b > a,
  return gcd(b%a, a);
}

int maxPoints(vector<int> vec_x, vector<int> vec_y) {
  // check if they have the same slope
  // calculate all the slope for every two points.
  // and count how many time the slope show up.
  // In order to avoid, the float number of slope.
  // We use two integers to repressent it.
  // For example, slope = 6/15 = 2/5, corresponding a pair <2, 5>
  // then count how many this kind of pair.
  // Thus, construct a map. The key is pair, the value is integer.
  // e.g. <2, 5> -> 3
  int n = vec_x.size();
  if (vec_y.size() != n) {
    cout << "Inconsistent input." << "\n";
    return 0;
  }

  int x_diff, y_diff, gcd_factor;
  int max_temp = 0;
  int repeat_count = 1;
  mypair dict_pair;

  for (int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      x_diff = vec_x[i] - vec_x[j];
      y_diff = vec_y[i] - vec_y[j];

      // count how many points are exactly the same
      if (x_diff == 0 & y_diff == 0) {
	repeat_count += 1;
      }

      // the convetion: if x_diff < 0, move the minus sign to y_diff
      if (x_diff < 0 ) {
	x_diff = -1 * x_diff;
	y_diff = -1 * y_diff;
      }
      
      gcd_factor = gcd(x_diff, y_diff);
      dict_pair[make_pair(x_diff/gcd_factor, y_diff/gcd_factor)] += 1;
      max_temp = max(max_temp, dict_pair[make_pair(x_diff/gcd_factor, y_diff/gcd_factor)]);
      
    }
  }

  return (max_temp + repeat_count);

}




int main() {
  int x[] = {1, 1};
  int y[] = {2, 2};
  vector<int> vec_x(x, x + sizeof(x)/sizeof(x[0]));
  vector<int> vec_y(y, y + sizeof(y)/sizeof(y[0]));
  int res = maxPoints(vec_x, vec_y);

  cout << "max points: " << res << "\n";

  return 0;


}
