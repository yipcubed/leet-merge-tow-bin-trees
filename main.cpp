#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// makes code faster but larger
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster
static auto x = [](){ios_base::sync_with_stdio(false); cin.tie(NULL); return NULL;}();

/**
 * Definition for a binary tree node.
 */
 struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (!t2) return t1;
        if (!t1) return t2;
        t1->val += t2->val;
        t1->left = t1->left? mergeTrees(t1->left, t2->left) : t2->left;
        t1->right = t1->right? mergeTrees(t1->right, t2->right): t2->right;
        return t1;
    }
};

// print it by level
ostream& operator<<(ostream& os, TreeNode* tr) {
  queue<TreeNode*> q;
  bool first = true;
  os << "[";
  if (tr) q.push(tr);
  while (!q.empty()) {
    int nodeCount = q.size();
    while (nodeCount > 0) {
      TreeNode* tp = q.front();
      q.pop();
      if (first) {
        os << tp->val;
        first = false;
      } else {
        os << "," << tp->val;
      }
      if (tp->left) q.push(tp->left);
      if (tp->right) q.push(tp->right);
      --nodeCount;
    }
  }
  os << "]";
  return os;
}


int main() {

  Solution S;

  TreeNode *t1 = new TreeNode(1);
  t1->left = new TreeNode(3);
  t1->right = new TreeNode(2);
  t1->left->left = new TreeNode(5);

  TreeNode *t2 = new TreeNode(2);
  t2->left = new TreeNode(1);
  t2->right = new TreeNode(3);
  t2->left->right = new TreeNode(4);
  t2->right->right = new TreeNode(7);

  cout << "t1: " << t1 << endl;
  cout << "t2: " << t2 << endl;

  cout << "t1+t2? " << S.mergeTrees(t1, t2) << endl;

  std::cout << "Done\n";
}