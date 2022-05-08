/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> ans;
    int x=0;
    NestedIterator(vector<NestedInteger> &List) 
    {
        Loop(List);
    }
    
    void Loop(vector<NestedInteger> &List)
    {
        int s=List.size();
        // if current is integer add ot list otherwise recursively flat the list
        for(int i=0; i<s; i++)
            List[i].isInteger()?  ans.push_back(List[i].getInteger()) : Loop(List[i].getList());
    }
    
    int next() 
    {
        return ans[x++];
    }
    
    bool hasNext() 
    {
        return x < ans.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */