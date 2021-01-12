// Greatest Common Divisor
int GCD(int a, int b){
  int tmp;
  while(b){
    tmp=a%b;
    a=b;
    b=a;
  }
  return a;
}

// Least Common Multiple
int LCM(int a, int b){
  int gcd=GCD(a, b);
  return (a*b)/gcd;
}
