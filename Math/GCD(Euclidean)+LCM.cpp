// Greatest Common Divisor -> Euclidean Algorithm
int GCD(int a, int b){
  int tmp;
  while(b){
    tmp=a%b;
    a=b;
    b=tmp;
  }
  return a;
}

// Least Common Multiple
int LCM(int a, int b){
  int gcd=GCD(a, b);
  return (a*b)/gcd;
}
