#include "iostream"
using namespace std;

void arrPrint(int *arr, int len)
{
  for(int i=0; i<len; i++)
    cout<<arr[i]<<" ";
  cout<<endl;
}
//快速排序
void quickSort(int *arr, int begin, int end)
{
  if(begin >= end)
    return;
  int pivot = arr[end];
  int i=0, j=end-1;
  while(1)
  {
    while(arr[i] < pivot)
      i++;
    while(arr[j] > pivot)
      j--;
    if(i < j)
      swap(arr[i], arr[j]);
    else
      break;
  }
  swap(arr[i], arr[end]);
  quickSort(arr, begin, i-1);
  quickSort(arr, i+1, end);
}
//插入排序
void insertSort(int *arr, int len)
{
  for(int i=1; i<len; i++)
  {
    int pivot = arr[i];
    int j = i-1;
    for(; j>=0 && arr[j] > pivot; j--)
      arr[j+1] = arr[j];
    arr[j+1] = pivot;
  }
}
//冒泡排序
void bubbleSort(int *arr, int len)
{
  for(int i=0; i<len-1; i++)
  {
    for(int j=len-1; j>i; j--)
    {
      if(arr[j] > arr[j-1])
        swap(arr[j], arr[j-1]);
    }
  }
}
//归并排序
void merge(int *arr, int *arr_temp, int leftStart, int rightStart, int rightEnd)
{
  int leftEnd = rightStart - 1;
  int i = leftStart, j = rightStart;
  int index = leftStart;
  while(i <= leftEnd && j <= rightEnd)
  {
    if(arr[i] > arr[j])
        arr_temp[index++] = arr[i++];
    else
        arr_temp[index++] = arr[j++];
  }
  while(i <= leftEnd)
    arr_temp[index++] = arr[i++];
  while(j <= rightEnd)
    arr_temp[index++] = arr[j++];

  for(int i=leftStart; i<=rightEnd; i++)
    arr[i] = arr_temp[i];
}
void mergeSort(int *arr, int *arr_temp, int left, int right)
{
  if(left >= right)
    return;
  int mid = (left + right) / 2;
  mergeSort(arr, arr_temp, left, mid);
  mergeSort(arr, arr_temp, mid+1, right);
  merge(arr, arr_temp, left, mid+1, right);
}
//希尔排序
void shellSort(int *arr, int len)
{
  for(int step = len>>1; step >= 1; step/=2)
  {
    for(int i=step; i<len; i++)
    {
      int pivot = arr[i];
      int j = i - step;
      for(; j>=0 && arr[j]>pivot; j-=step)
        arr[j+step] = arr[j];
      arr[j+step] = pivot;
    }
  }
}
//堆排序
void sitDown(int *arr, int index, int size)
{
  if(index < 0)
    return;
  int child = 0;
  int pivot = arr[index];
  for(; index*2 + 1 < size; index = child)
  {
    child = index*2 + 1;
    if(child<size-1 && arr[child] > arr[child+1])
      child++;
    if(arr[child] < pivot)
      arr[index] = arr[child];
    else
      break;
  }
  arr[index] = pivot;
}
void heapSort(int *arr, int len)
{
  if(len<=0)
    return;
  int start = len/2 - 1;
  while(start >= 0)
  {
    sitDown(arr, start, len);
    --start;
  }

  /* arrPrint(arr, len); */
  for(int i=len-1; i>=1; i--)
  {
    swap(arr[i], arr[0]);
    sitDown(arr, 0, --len);
  }
}


int main()
{
  int a[] = {7,3,5,1,2,6,10};
  /* quickSort(a, 0, 4); */
  /* insertSort(a, 5); */
  /* bubbleSort(a, 5); */
  /* int a_temp[5] = {0}; */
  /* mergeSort(a, a_temp, 0, 4); */
  /* shellSort(a, 5); */
  heapSort(a, 7);
  arrPrint(a, sizeof(a)/sizeof(int));

  return 0;
}
