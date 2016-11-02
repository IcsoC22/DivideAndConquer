#include <iostream>
using namespace std;

int majority(int A[], int begin, int end);

int main()
{
  int  *A;
  int size;

  cout << "How many elements? ";
  cin >> size;
  A = new int[size];

  cout << "Give me " << size << " numbers\n";

  for (int i=0; i<size; i++)
    {
    cin >> A[i];
    }

  cout << "Here is your array: ";

  for (int i=0; i<size; i++)
    {
      cout << A[i] << " ";
    }
  cout << endl;

  int m = majority(A,0,size-1);

  if (m == -1)
    {
      cout << "No number has a majority" << endl;
    }
  else
    {
      cout << "The number " << m << " appears more than half of the time"
	   << endl;
    }

  return 0;
}

int majority(int A[], int begin, int end)
{
  if(begin == end){
    return A[begin];
  }
  else {
    int a = majority(A, begin, (begin+end)/2);
    int b = majority(A, (begin+end)/2+1, end);
    if (a == b){
      return a;
    }

    else {
      int counta = 0;
      int countb = 0;
      for(int i = begin; i <= end; i++){
        if(A[i] == a){
          counta++;
        }
        if(A[i] == b){
          countb++;
        }
      }

      if(2*counta > (end-begin)+1){
        return a;
      }

      else if(2*countb > (end-begin)+1){
        return b;
      }

      else{
        return -1;
      }

    }
  }
}
