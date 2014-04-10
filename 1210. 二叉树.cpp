#include <iostream>
#include <string>

using namespace std;

int getTreeNum(string preorder, string postorder)
{
    int treeNum = 1;
    for(int i = 1; i < preorder.length(); i++)
    {
        int j = postorder.length() - 2;
        //找到分支点 
        while(preorder[i] != postorder[j]) j--;
        if(preorder[i - 1] == postorder[j + 1])
            treeNum *= 2;
    }
    return treeNum;
}

int main()
{
    string preorder;
    string postorder;
    
    cin>>preorder;
    cin>>postorder;
    
    int treeNum = getTreeNum(preorder,postorder);
    
    cout<<treeNum;
    return 0;    
}
 
