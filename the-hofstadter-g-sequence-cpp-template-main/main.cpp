#include <iostream>
#include <vector>
#include <chrono>
using namespace std::chrono;
using namespace std;


int naive_calls = 0;
int memo_calls = 0;


//naive version
int g_naive(int n){
  if (n==0)
    return 0;
  else if (n>0)
    return n-g_naive(g_naive(n-1));
  
  return 0;
}

//memo

const int maxN = 1000;
int memo[maxN + 1];
bool isItComputed[maxN + 1];

int g_memo(int n){
  if (n==0)
    return 0;
  if (isItComputed[n])
    return memo[n];

  memo[n] = n-g_memo(g_memo(n-1));
  isItComputed[n]=true;
  return memo[n];
}

int main(){
  int N = 40; //max n
  int trials = 10;  //runs per n

  cout<<"n,NaiveTime,MemoTime,NaiveValue,MemoValue\n";

  for (int i = 0; i<=N; i++){
    long long naiveTime = 0, memoTime = 0;
    int naiveVal = 0, memoVal = 0;

    //avg naive
    for (int t = 0; t<trials; t++ ){
      auto start = high_resolution_clock::now();
       naiveVal = g_naive(i);
       auto end = high_resolution_clock::now();
       naiveTime += duration_cast<microseconds>(end-start).count();

    }
    //avg memo
    for (int t = 0; t<trials; t++){
      for(int j = 0; j<=i; j++){
        isItComputed[j]=false;
        memo[j] = 0;

      }
      auto start = high_resolution_clock::now();
      memoVal = g_memo(i);
      auto end = high_resolution_clock::now();
      memoTime += duration_cast<microseconds>(end - start).count();
    }

    cout << i << ","
         << naiveTime / (double)trials << ","
         << memoTime / (double)trials << ","
         << naiveVal << ","
         << memoVal << "\n";

  }
  return 0;
}