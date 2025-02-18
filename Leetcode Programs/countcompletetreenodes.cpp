class Solution {
public:
	int findDepth(TreeNode* root)
	{
		int level = 0;
		while (root)
		{
			++level;
			root = root->left;
		}
		return level;
	}
	TreeNode* getMiddleNode(TreeNode* root, int min, int max, int destination, int level, int targetDepth)
	{
		if (level == targetDepth)
			return max == destination ? root->right : root->left;
		int mid = (min + max) / 2;
		TreeNode** nextNodePtr;
		if (destination > mid)
		{
			min = mid + 1;
			nextNodePtr = &root->right;
		}
		else
		{
			max = mid;
			nextNodePtr = &root->left;
		}
		return getMiddleNode(*nextNodePtr, min, max, destination, ++level, targetDepth);
	}
	int countNodes(TreeNode* root) {
		int level = findDepth(root);
		if (level < 2)
			return level;
		--level;
		int min = 1;
		int max = 2 << (level - 1);
		int lastValid = 0;
		int lastInvalid = max + 1;
		while (lastInvalid - lastValid != 1)
		{
			int destination = lastInvalid - (lastInvalid - lastValid) / 2;
			TreeNode* middleNode = getMiddleNode(root, min, max, destination, 1, level);
			if (middleNode)
				lastValid = destination;
			else
				lastInvalid = destination;
		}
		return (2 << (level - 1)) - 1 + lastValid;
	}
};
