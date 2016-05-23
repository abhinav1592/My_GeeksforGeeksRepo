#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
void printGivenLevel(struct node* root, int level);

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
void preorder(struct node *root)
{
    if(root==NULL) return;
    cout<<root->data<<" == ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node *root)
{
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" == ";
    inorder(root->right);
}


void postorder(struct node *root)
{
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" == ";
}

// Height of Binary Tree

int height(struct node *root)
{
    if(root==NULL) return 0;
    else
        {
            int left_subtree_height = height(root->left);
            int right_subtree_height = height(root->right);
            if(left_subtree_height>right_subtree_height)
                return left_subtree_height+1;
            else return right_subtree_height+1;
        }
}

// Level order traversal

/* Function to print level order traversal a tree*/
void level_order_without_queue(struct node *root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}

/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout<< root->data<<" == ";
    else if (level > 1)
        {
            printGivenLevel(root->left, level-1);
            printGivenLevel(root->right, level-1);
        }
}


/* Function to print level order traversal a tree (with queue)*/
void level_order_with_queue(struct node *root)
{
    queue<struct node *> node_queue;
    struct node *temp_node = root;
    while(temp_node!=NULL)
        {
            cout<<temp_node->data<<" == ";
            if(temp_node->left)
                node_queue.push(temp_node->left);
            if(temp_node->right)
                node_queue.push(temp_node->right);
            if(!node_queue.empty())
                {
                    temp_node = node_queue.front();
                    node_queue.pop();
                }
            else
                {
                    temp_node=NULL;
                }
        }
}



//Inorder Tree Traversal without Recursion
//
void inorder_tree_traversal_without_recursion(struct node *root)
{
    if(root==NULL) return;
    else
        {
            stack<struct node *> node_stack;
            struct node *current_node = root;
            bool done = 0;
            while(!done)
                {
                    if(current_node!=NULL)
                        {
                            node_stack.push(current_node);
                            current_node = current_node->left;
                        }
                    else if(!node_stack.empty())
                        {
                            struct node *temp_node = node_stack.top();
                            node_stack.pop();
                            cout<<temp_node->data<<" == ";
                            current_node = temp_node->right;
                        }
                    else done=1;
                }
        }
}


void inorder_tree_traversal_without_recursion_without_stack(struct node *root)
{
    struct node *current_node = root,*pre;
    while(current_node!=NULL)
        {
            if(current_node->left==NULL)
                {
                    cout<<current_node->data<<" == ";
                    current_node = current_node->right;
                }
            else
                {
                    /* Find the inorder predecessor of current */
                    pre = current_node->left;
                    while(pre->right != NULL && pre->right != current_node)
                        pre = pre->right;
                    /* Make current as right child of its inorder predecessor */
                    if(pre->right == NULL)
                        {
                            pre->right = current_node;
                            current_node = current_node->left;
                        }
                    /* Revert the changes made in if part to restore the original
                      tree i.e., fix the right child of predecssor */
                    else
                        {
                            pre->right = NULL;
                            cout<<current_node->data<<" == ";
                            current_node = current_node->right;
                        } /* End of if condition pre->right == NULL */
                }
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
    cout<<"\n Inorder Traversal without Recursion (using stack) : "<<endl;
    inorder_tree_traversal_without_recursion(root);
    cout<<" \n Inorder Traversal without Recursion without stack - Morris Traversal : "<<endl;
    inorder_tree_traversal_without_recursion_without_stack(root);
    cout<<"\n Postorder traversal : "<<endl;
    postorder(root);
    cout<<"\n Level Order Traversal(without Queue) : "<<endl;
    level_order_without_queue(root);
    cout<<"\n Level Order Traversal(with Queue) : "<<endl;
    level_order_with_queue(root);
    // ===================================================
    // Height of tree
    cout<<"\n Height of current tree : "<<height(root)<<endl;
    return 0;
}
