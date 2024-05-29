#include<bits/c++.h> 
using namespace std; 

   vector<TreeNode*> generate(int left, int right){ 
        if(left > right) return {NULL};  
        if(left == right) return {new TreeNode(left)}; 
        vector<TreeNode*> store ; 
        for(int val = left ; val <= right; val++) { 
            vector<TreeNode*>left_tree = generate(left,val-1); 
            vector<TreeNode*>right_tree = generate(val+1,right);  
            for(int i = 0; i < left_tree.size(); i++){ 
                for(int j = 0; j < right_tree.size(); j++){ 
                    TreeNode *node = new TreeNode(val,left_tree[i],right_tree[j]); 
                    store.push_back(node);
                }
            }
        }
        return store; 
    }

    vector<TreeNode*> generateTrees(int n) {
        return generate(1,n);
    }
