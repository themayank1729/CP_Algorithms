#include <bits/stdc++.h>
using namespace std;
class Stack
{
  private : 
  int arr[10];
  int arrSize =  sizeof(arr)/sizeof(int);
  int tp= -1;
  public:
  void push(int num);
   int pop();
   int top();
   int size();
};
 void Stack:: push(int num)
   {
     if(tp + 1 < arrSize){
    tp = tp + 1;
    arr[tp] = num;
    }
    else
    {
        cout<<"\nStack is Filled\n";
    }
   }
int Stack :: pop()
   {
    if(tp != -1)
    {     
        int temp = tp;
        tp = tp - 1;
        return this->arr[temp];
    }
    else
    {
        return -1;
    }
   }
int Stack :: top()
   {
    if(tp != -1 )
    return this->arr[tp];
    else
    return -1;
   }
int Stack :: size()
   {
    if(tp != -1)
    return (tp + 1);
    else
    return -1;
   }
int main()
{
     Stack st;
     st.push(4);
     cout<<st.top();
     st.push(45);
     st.push(5);
     st.push(564);
     st.push(44565);
     cout<<st.size()<<" "<<st.top()<<"\n";
     int val = st.size();
}