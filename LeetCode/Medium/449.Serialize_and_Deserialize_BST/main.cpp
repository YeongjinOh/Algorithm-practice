/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
	public:

		// Encodes a tree to a single string.
		string serialize(TreeNode* root) {
			if (root == NULL) return "";
			string res = std::to_string(root->val) + "/";
			res += serialize(root->left);
			res += serialize(root->right);
			return res;
		}

		// Decodes your encoded data to tree.

		TreeNode* deserialize (vector<int> vals, int &pos, int lb, int ub) {
			if (pos >= vals.size()) return NULL;
			if (vals[pos] < lb || vals[pos] >= ub) return NULL;
			TreeNode *root = new TreeNode(vals[pos++]);
			root->left = deserialize(vals,pos,lb,root->val);
			root->right = deserialize(vals,pos,root->val,ub);
			return root;
		}

		TreeNode* deserialize(string data) {
			vector<int> vals;
			int  i = 0;
			while (i<data.size()) {
				int num = 0;
				while (data[i] != '/') {
					num = 10*num + data[i]-'0';
					i++;
				}
				i++;
				vals.push_back(num);
			}
			int pos = 0;
			return deserialize(vals, pos, INT_MIN, INT_MAX);
		}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
