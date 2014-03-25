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
//生成二叉树
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
//前序遍历
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
//中序遍历
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
//后序遍历
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
//层次遍历
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
//重建二叉树
binaryTreeNode* construct(int *preorder, int *inorder, int len)
{
  if(preorder == NULL || inorder == NULL || len <= 0)
    return NULL;
  int value = preorder[0];
  binaryTreeNode *root = new binaryTreeNode(value);
  int i=0;
  while(i<len && inorder[i] != value)
    i++;
  if(i == len)
    throw std::exception();
  root->lchild = construct(preorder+1, inorder, i);
  root->rchild = construct(preorder+i+1, inorder+i+1, len-i-1);
  return root;
}

int main()
{
  binaryTreeNode *root = NULL;
  /* insert(root); */
  /* preOrder(root); */
  /* inOrder(root); */
  /* postOrder(root); */
  /* levelOrder(root); */
  int pre[] = {2,3,5,4,1};
  int in[] = {3,5,2,1,4};
  root = construct(pre, in, 5);
  postOrder(root);

  return 0;
}






