#include "iostream"
#include "stack"
using namespace std;

//http://blog.csdn.net/luckyxiaoqiang/article/details/8937978#topic10
int binarySearch(int *arr, int len, int value)
{
  if(arr == NULL || len <= 0)
    return -1;
  int start = 0, end = len - 1;
  while(start <= end)
  {
    int mid = start + ((end - start)>>1);
    if(arr[mid] == value)
      return mid + 1;
    if(arr[mid] > value)
      end = mid - 1;
    else
      start = mid + 1;
  }
  return -1;
}

int searchFirstPos(int *arr, int len, int value)
{
  if(arr == NULL || len <= 0)
    return -1;
  int start = 0, end = len - 1;
  int mid = 0;
  while(start < end)
  {
    mid = start + ((end - start)>>1);
    if(arr[mid] >= value)
      end = mid;
    else
      start = mid + 1;
  }
  if(arr[start] == value)
    return start + 1;
  else
    return -1;
}

int searchLastPos(int *arr, int len, int value)
{
  if(arr == NULL || len <= 0)
    return -1;
  int start = 0, end = len - 1;
  int mid = 0;
  while(start < end)
  {
    mid = start + ((end-start)>>1) + 1;
    if(arr[mid] <= value)
      start = mid;
    else
      end = mid - 1;
  }
  if(arr[end] == value)
    return end + 1;
  else
    return -1;
}

int count(int *arr, int len, int value)
{
  if(arr == NULL || len <= 0)
    return -1;
  int first = searchFirstPos(arr, len, value);
  if(first == -1)
    return 0;
  int last = searchLastPos(arr, len, value);
  return last - first + 1;
}

int searchLastPosLessThan(int *arr, int len, int value)
{
  if(arr == NULL || len <= 0)
    return -1;
  int start = 0, end = len - 1;
  int mid = 0;
  while(start < end)
  {
    mid = start + ((end-start)>>1) + 1;
    if(arr[mid] < value)
      start = mid;
    else
      end = mid - 1;
  }
  return arr[start] < value ? start + 1 : -1;
}

int searchInsert(int *arr, int len , int value)
{
  if(arr == NULL || len <= 0)
    return -1;
  if(arr[len-1] < value)
    return len + 1;
  int start = 0, end = len - 1;
  int mid = 0;
  while(start < end)
  {
    mid = start + ((end-start)>>1);
    if(arr[mid] >= value)
      end = mid;
    else
      start = mid + 1;
  }
  return start + 1;
}

int searchMisAbs(int *arr, int len)
{
  if(arr == NULL || len <= 0)
    return -1;
  int start = 0, end = len - 1;
  int mid = 0;
  while(start < end)
  {
    mid = start + ((end-start)>>1);
    if(arr[mid] >= 0)
      end = mid;
    else
      start = mid + 1;
  }
  if(arr[start] > 0 && abs(arr[start-1]) < abs(arr[start]))
    return start - 1 + 1;
  else
    return start + 1;
}

int searchFirstPosMoreThan(int *arr, int len, int value)
{
  if(arr == NULL || len <= 0)
    return -1;
  int start = 0, end = len - 1;
  int mid = 0;
  while(start < end)
  {
    mid = start + ((end-start)>>1);
    if(arr[mid] > value)
      end = mid;
    else
      start = mid + 1;
  }
  if(arr[start] > value)
    return start + 1;
  else
    return -1;
}

int searchInRotated(int *arr, int len, int value)
{
  if(arr == NULL || len <= 0)
    return -1;
  int start = 0, end = len - 1;
  while(start <= end)
  {
    int mid = start + ((end - start)>>1);
    if(arr[mid] == value)
      return mid + 1;
    if(arr[start] < arr[mid])
    {
      if(value >= arr[start] && value < arr[mid])
        end = mid - 1;
      else
        start = mid + 1;
    }
    else
    {
      if(value <= arr[end] && value > arr[mid])
        start = mid + 1;
      else
        end = mid - 1;
    }
  }
  return -1;
}
//查找旋转数组中的最小值
int searchMinInRotated(int *arr, int len)
{
  if(arr == NULL || len <= 0)
    return -1;
  int start = 0, end = len - 1;
  int mid = start;
  //start，end分别指向前后两个升序序列
  while(arr[start] >= arr[end])//考虑未发生旋转的特殊情况
  {
    if(end - start == 1)
    {
      mid = end;
      break;
    }
    mid = start + ((end-start)>>1);
    if(arr[mid] >= arr[start])//前半部分为升序
      start = mid;
    else//后半部分为升序
      end = mid;
  }
  return mid + 1;
}

int searchKthInRotated(int *arr, int len, int k)
{
  int posMin = searchMinInRotated(arr, len);
  return (posMin + k - 1)%len;
}


int main()
{
  int a[] = {4,5,1,2,3};
  /* cout<<searchInRotated(a, 5, 2)<<endl; */
  cout<<searchMinInRotated(a, 5)<<endl;
  cout<<searchKthInRotated(a, 5, 4)<<endl;
  /* int a[] = {1,2,3,4,5}; */
  /* cout<<binarySearch(a, 5, 4)<<endl; */
  /* int a[] = {1,2,3,3,5}; */
  /* cout<<searchFirstPos(a, 5, 3)<<endl; */
  /* cout<<searchLastPos(a, 5, 3)<<endl; */
  /* cout<<count(a, 5, 3)<<endl; */
  /* cout<<searchLastPosLessThan(a, 5, 3)<<endl; */
  /* cout<<searchFirstPosMoreThan(a, 5, 3)<<endl; */
  /* int a[] = {1,5,7,9,11}; */
  /* cout<<searchInsert(a, 5, 11)<<endl; */
  /* cout<<searchMisAbs(a, 5)<<endl; */

  return 0;
}
