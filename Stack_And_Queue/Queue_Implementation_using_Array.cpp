#include <bits/stdc++.h>
using namespace std;
class Queue
{
  private : 
  int arr[10] ;
  int arrSize = sizeof(arr)/sizeof(int);
  int tp= -1;
  int start = -1,end = -1;
  int currSize = 0;
  public:
  void push(int num);
   int pop();
   int top();
   int size();
};
 void Queue:: push(int num)
   {

    
    if(currSize == arrSize )
    {
      cout<<"\nQueue is filled\n";
    }
    if(currSize == 0)
    {
         start = 0;
         end = 0;
         arr[start] = num;
         currSize +=1;
    }
    else
    {
        end = (end  + 1) % arrSize;
         arr[end] = num;
         currSize +=1;
    }
    
   }
int Queue :: pop()
   {
    if(currSize == 0)
    {
        return -1;

    }
    if(currSize == 1)
    {
        int element = arr[start];
        start = -1;
        end = -1;
        currSize = 0;
        return element;
    }
    else
    {
        int element = arr[start];
        start = (start + 1)%arrSize;
        currSize-=1;
       return  element;
    }
   }
int Queue :: top()
   {
    
    if(currSize == 0) return -1;
    return this->arr[start];
   }
int Queue :: size()
   {
       return this->currSize;  
   }

int main()
{
     Queue st;
     st.push(2);
     //cout<<st.top();
     st.push(4);
     st.push(5);
     st.push(6);
     st.push(7);
     cout<<st.size()<<" "<<st.top()<<"\n";
     int val = st.size();
}