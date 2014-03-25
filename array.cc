#include "iostream"
#include "stack"
using namespace std;
//两个栈实现队列
template <typename T>
class CQueue
{
public:
  CQueue();
  ~CQueue();
  void appendTail(const T& node);
  T deleteHead();
private:
  stack<T> stack1;
  stack<T> stack2;
};
template <typename T>
void CQueue<T>::appendTail(const T& node)
{
  stack1.push(node);
}

template <typename T>
T CQueue<T>::deleteHead()
{
  if(stack2.size()==0)
  {
    while(stack1.size() > 0)
    {
      T temp = stack1.top();
      stack2.push(temp);
      stack1.pop();
    }
  }
  if(stack2.size() == 0)
    throw new exception;
  T head = stack2.top();
  stack2.pop();
  return head;
}


int main()
{


  return 0;
}
