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
//反向打印链表
void listPrint_rev(const listNode *head)
{
  if(head == NULL)
    return;
  listPrint_rev(head->next);
  cout<<head->m_value<<" ";
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
//删除节点
void RemoveNode(listNode* &head, int value)
{
  if(head == NULL)
    return;
  //对头节点的检验
  if(head->m_value == value)
  {
    listNode *p = head;
    head = head->next;
    delete p;
  }
  else
  {
    listNode *q = head;
    while(q->next != NULL && q->next->m_value != value)
      q = q->next;
    if(q->next != NULL && q->next->m_value == value)
    {
      listNode *p = q->next;
      q->next = q->next->next;
      delete p;
    }
  }
}


//倒数第k个节点
listNode* FindKthToTail(listNode *head, int k)
{
  if(head == NULL)
    return NULL;
  listNode *quick, *slow;
  quick = head;
  slow = head;
  while(k>1 && quick->next != NULL)
  {
    quick = quick->next;
    --k;
  }
  if(k != 1)
    return NULL;
  while(quick->next != NULL)
  {
    quick = quick->next;
    slow = slow->next;
  }
  return slow;
}


int main()
{
  listNode *head = NULL;
  insert(head);
  listPrint(head);
  /* cout<<FindKthToTail(head, 3)->m_value<<endl; */
  /* RemoveNode(head, 4); */
  /* listPrint(head); */
  listPrint_rev(head);
  return 0;
}


