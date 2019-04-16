/*  
  ��Ŀչ�����ţ�
  ���ӣ�input 2(a), ouput aa;
  ����Ϊ��ͨ������
  input   1{2(3[b])3[c]} ,output bbbbbbccc

*/


#include <string>
#include <vector>
using namespace std;

//�ж��Ƿ񻹴�������
bool brackets(string str)
{
	int length = str.size();
	for (int i = 0;i<length;i++)
	{
		if (str[i] =='(' || str[i] ==')' || str[i] =='[' || str[i] ==']' || str[i] =='{' || str[i] =='}' )
		{
			return false;
		}
	}
	return true;

}

//��չ
string strexpansion(string str, int begin,int end ,int n)
{
	int length = str.size();
	string str1 = str.substr(0,begin-1);
	string str2 = str.substr(begin+1,end - begin -1);
	string str_n2;
	for (int i = 0;i<n;i++)
	{
		str_n2 = str_n2+str2;
	}
	string str3 = str.substr(end+1,length-end);
	return str1+str_n2+str3;
}

//ȥ����С�����ţ�
string removeMinbrackets(string str)
{
	if (brackets(str))return str;
	int begin,end,n;
	int length = str.size();
	for (int i = 0;i<length;i++)
	{
		if (str[i] == ')' || str[i] == '}' || str[i] == ']')
		{
			end = i;
			for (int j =i-1;j>=0;j--)
			{
				if (str[j] =='(' || str[j] =='[' ||str[j] =='{')
				{
					begin = j;
					n = int(str[begin-1] - '0');
					break;
				}
			}
			str = strexpansion(str,begin,end,n);
			break;
		}
	}
	return removeMinbrackets(str);
}

int main()
{

	string str_test1 = "12313";
	string str_test2 = "1231(3";

	bool b1,b2;
	b1 = brackets(str_test1);
	b2 = brackets(str_test2);

	string str_test3 = "2(aaa)";
	string out1 = strexpansion(str_test3,1,5,2);
	//string out2 = removeMinbrackets(str_test3);

	string str_test4 = "1{2(bbb)3[c]}";
	string out3 = removeMinbrackets(str_test4);
	return 0;
}
