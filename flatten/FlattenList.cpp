#include <iostream>
#include <vector>
using namespace std;

class NestedInteger
{
public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList();
};

class SingletonInteger : public NestedInteger
{
public:
    SingletonInteger(int value)
        {
            this.value = value;
        }
    bool isInteger() const
        {
            return true;
        };

    int getInteger() const
        {
            return value;
        };

    const vector<NestedInteger> &getList()
        {
            return NULL;
        }

private:
    int value;
};

class NestedList : public NestedInteger
{
public:
    NestedList(vector<NestedInteger> v)
        {
            for(NestedInteger value : v)
                v.push_back(value);
        }

    bool isInteger() const
        {
            return false;
        }

    int getInteger() const
        {
            return NULL;
        }

    const vector<NestedInteger> &getList()
        {
            return v;
        }
private:
    vector<NestedInteger> v;
};

class Solution
{
public:
	//方法一：dfs
	vector<int> flatten(vector<NestedInteger> &nestedList)
	{
		vector<int> result;
		dfs(result, nestedList);
		return result;
	}

	void dfs(vector<int> &result, vector<NestedInteger> nestedList)
	{
		for(nl : nestedList)
		{
			if(nl.isInteger())
				result.push_back(nl.getInteger);
			else
				dfs(result, nestedList);
		}
	}

	//方法二：递归
	vector<int> flatten2(vector<NestedInteger> &nestedList)
	{
		vector<int> result;
		for(nl : nestedList)
		{
			if(nl.isInteger())
				result.push_back(nl.getInteger());
			else
				flatten(nl);
		}
	}

	//方法三:非递归
	vector<int> flatten(vector<NestedInteger> &nestedList)
	{
		vector<int> result;
		stack<NestedInteger> s;
		for(auto rit = nestedList.rbegin(); rit != nestedList.rend(); ++rit)
			s.push(*rit);
		while(!s.empty())
		{
			auto nl = s.top();
			s.pop();
			if(nl.isInteger())
				result.push_back(nl.getInteger());
			else
			{
				const auto lst = nl.getList();
				for(auto rit = lst.rbegin(); rit != lst.rend(); ++rit)
					s.push(*rit);
			}	
		}
		return result;
	}
};
int main()
{
    vector<NestedInteger> v {[4, [3, 2,[1]]]};
	Solution s;
    cout << s.flatten(v) << endl;
    return 0;
}
