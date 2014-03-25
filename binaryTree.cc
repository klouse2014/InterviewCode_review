#include "iostream"
#include "stack"
#include "queue"
using namespace std;

struct binaryTreeNode
{
  int m_value;
  binaryTreeNode *lchild;
  binaryTreeNode *rchild;
  binaryTreeNode(int value):m_value(value), lchild(0), rchild(0){}
};

void insert(binaryTreeNode* &root)
{
  int a;
  cin >> a;
  if(a == 0)
    root = NULL;
  else
  {
    root = new binaryTreeNode(a);
    insert(root->lchild);
    insert(root->rchild);
  }
}

void preOrder(binaryTreeNode *root)
{
  stack<binaryTreeNode *> stk;
  while(root != NULL || !stk.empty())
  {
    while(root != NULL)
    {
      stk.push(root);
      root = root->lchild;
    }
    if(!stk.empty())
    {
      binaryTreeNode *temp = stk.top();
      stk.pop();
      cout<< temp->m_value<<" ";
      root = temp->rchild;
    }
  }
  cout<<endl;
}

void inOrder(binaryTreeNode *root)
{
  if(root == NULL)
    return;
  stack<binaryTreeNode *> stk;
  stk.push(root);
  while(!stk.empty())
  {
    binaryTreeNode *temp = stk.top();
    stk.pop();
    cout<<temp->m_value<<" ";
    if(temp->rchild != NULL)
      stk.push(temp->rchild);
    if(temp->lchild != NULL)
      stk.push(temp->lchild);
  }
  cout<<endl;
}

void postOrder(binaryTreeNode *root)
{
  stack<binaryTreeNode *> stk;
  stack<int> stk_symbol;
  while(root != NULL || !stk.empty())
  {
    while(root != NULL)
    {
      stk.push(root);
      stk_symbol.push(0);
      root = root->lchild;
    }
    if(!stk.empty())
    {
      int temp_symbol = stk_symbol.top();
      binaryTreeNode *temp = stk.top();
      if(temp_symbol == 0)
      {
        stk_symbol.pop();
        stk_symbol.push(1);
        root = temp->rchild;
      }
      else
      {
        cout<<temp->m_value<<" ";
        stk.pop();
        stk_symbol.pop();
        root = NULL;
      }
    }
  }
  cout<<endl;
}

void levelOrder(binaryTreeNode *root)
{
  if(root == NULL)
    return;
  queue<binaryTreeNode *> que;
  que.push(root);
  while(!que.empty())
  {
    binaryTreeNode *temp = que.front();
    que.pop();
    cout<<temp->m_value<<" ";
    if(temp->lchild != NULL)
      que.push(temp->lchild);
    if(temp->rchild != NULL)
      que.push(temp->rchild);
  }
  cout<<endl;
}

int main()
{
  binaryTreeNode *root = NULL;
  insert(root);

  preOrder(root);
  inOrder(root);
  postOrder(root);
  levelOrder(root);
  return 0;
}






