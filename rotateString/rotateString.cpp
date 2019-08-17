#include <iostream>
#include <string>
using namespace std;
class Soluction
{
public:
	//方法一：
	void rotateString(string &str, int offset)
	{
		if(str.empty())
			return ;
		string str1 = str.substr(0, str.length() - offset % str.length());
		string str2 = str.substr(str.length() - offset % str.length(), str.length());
	str = str2 + str1;
	}
	
	//方法二：
	void rotateString(string &str, int offset)
	{
		if(!str.empty())
		{
			offset = offset % str.length();
			str.insert(0, str, str.length() - offset, offset);
			str.erase(str.end() - offset, str.end());
		}
	}
};

int main()
{
	Soluction s;
    string str = "abcdefg";
    int offset = 1;
    s.rotateString(str, offset);
    cout << str << endl;
    return 0;
}
