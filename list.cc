#include "iostream"
using namespace std;

struct listNode
{
  int m_value;
  listNode *next;
  listNode(int value):m_value(value), next(0){}
};

//打印链表
void listPrint(const listNode *head)
{
  while(head != NULL)
  {
    cout<<head->m_value<<" ";
    head = head->next;
  }
  cout<<endl;
}
//生成链表
void insert(listNode* &head)
{
  int a;
  cin >> a;
  if(a == 0)
    head = NULL;
  else
  {
    head = new listNode(a);
    insert(head->next);
  }
}

int main()
{
  listNode *head = NULL;
  insert(head);
  listPrint(head);
  return 0;
}


