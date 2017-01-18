
// time limit issue
double myPow_v1(double x, int n) {
  if (n == 0) return 1.0;
  int count = 1;
  int abs_n = n;
  double output = x;
  
  if (n < 0) {
    abs_n = -n;
  }
        
  
  while (count < abs_n) {
    output *= x;
    count += 1;
  }
        
  if (n < 0) {
    output = 1.0/output;
  }
        
  return output;
}





double myPow(double x, int n) {
  if (n >= 0) {
    return pow_util(x, n);
  }
  else {
    return 1.0/pow_util(x, -n);
  }
}
    
// x^n = x^(n/2) * x^(n/2) * x^(n%2)
double pow_util(double x, int n) {
  if (n == 0) return 1.0;
  
  double temp = pow_util(x, n/2);
  temp *= temp;
  
  // n%2 can be only 1 or 0.
  // when n%2 is 1, we multiply additional x.
  if (n%2 != 0) {
    temp *= x;
  }
        
  return temp;
        
}

