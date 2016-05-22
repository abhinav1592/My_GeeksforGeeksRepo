#include <bits/stdc++>
#define endl "\n"
using namespace std;

// Basic Tree Structure
struct node
{
    int data;
    struct node *left,*right;
};


struct node *newNode(int data)
{
      struct node *node = (struct node *)malloc(sizeof(struct node));
      node->data = data;
      node->left = NULL;
      node->right = NULL;
      return (node);
}
// Traversal - Pre,In,Post
void preorder(struct node *node)
{
	cout<<node->data<<endl;
	preorder(node->left);
	preorder(node->right);
}

void inorder(struct node *node)
{
	inorder(node->left);
	cout<<node->data<<endl;
	inorder(node->right);
}


void postorder(struct node *node)
{
	
	postorder(node->left);
	postorder(node->right);
	cout<<node->data<<endl;
}

// Height of Binary Tree

int height(struct node *node)
{
	if(node==NULL) return 0;
	else
	{
		int left_subtree_height = height(node->left);
		int right_subtree_height = height(node->right);

		if(left_subtree_height>right_subtree_height)
			return left_subtree_height+1;
		else return right_subtree_height+1;
	}
}
int main()
{
	struct node *root = newNode(1);

	root->left = newNode(2);
	root->right = newNode(3);

	root->left->left = newNode(4);
	root->left->right = newNode(5);

	root->right->left = newNode(6);
	root->right->right = newNode(7);
    // ==================================================
    //Traversals
    cout<<"\n Preorder traversal : "<<endl;
    preorder(root);
     cout<<"\n Inorder traversal : "<<endl;
    inorder(root);
    cout<<"\n Postorder traversal : "<<endl;
    postorder(root);
    cout<<"\n Level Order Traversal(without Queue) : "
    cout<<level_order_without_queue(root);
    cout<<"\n Level Order Traversal(with Queue) : "
    cout<<level_order_with_queue(root);
    cout<<"\n Depth First Traversal(with stack) : "
    cout<<depth_first_traversal_with_stack(root);
    
    // ===================================================
    
    // Height of tree
    cout<<" Height of current tree : "<<height(root)<<endl;


	return 0;
}