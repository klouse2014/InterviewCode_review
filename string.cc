#include "iostream"
using namespace std;
//string类定义
class CMyString
{
public:
  CMyString(char *pData = NULL);
  CMyString(const CMyString& str);
  ~CMyString();
  CMyString operator = (const CMyString &str);
private:
  char *m_pData;
};

CMyString::CMyString(char *pData)
{
  if(pData == NULL)
  {
    m_pData = new char;
    m_pData[0] = '\0';
  }
  else
  {
    int len = strlen(pData);
    m_pData = new char[len+1];
    strcpy(m_pData, pData);
  }
}
CMyString::CMyString(const CMyString& str)
{
  int len = strlen(str.m_pData);
  m_pData = new char[len+1];
  strcpy(m_pData, str.m_pData);
}
CMyString::~CMyString(){delete[] m_pData;}
CMyString CMyString::operator = (const CMyString &str)
{
  if(this == &str)
    return *this;
  char *temp = new char[strlen(str.m_pData) + 1];
  strcpy(temp, str.m_pData);
  delete[] m_pData;
  m_pData = temp;
  return *this;
}

void ReplaceBank(char* &str, char *m_str)
{
  if(str == NULL || m_str == NULL)
    return;
  char *p = str;
  int bank_num = 0;
  int len = strlen(str);
  int m_len = strlen(m_str);
  while(*p != '\0')
  {
    if(*p == ' ')
      ++bank_num;
    p++;
  }
  int new_len = len + bank_num*(m_len-1);
  char *temp = new char[new_len+1];
  char *q = temp + new_len;
  while(len>=0)
  {
    if(*p != ' ')
    {
      *q = *p;
      --q;
    }
    else
    {
      memcpy(q-m_len+1, m_str, m_len);
      q -= m_len;
    }
    --p;
    --len;
  }
  str = temp;
}


int main()
{
  char str[] = "this is my destiny";
  char *p = str;
  char m_str[] = "===";
  cout<<str<<endl;
  ReplaceBank(p, m_str);
  cout<<p<<endl;;

  return 0;
}
