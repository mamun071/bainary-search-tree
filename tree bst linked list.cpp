#include<bits/stdc++.h>
using namespace std;

struct node{
    int roll;
    node *left,*right;
    node()
    {
        left=NULL;
        right=NULL;
    }
};
node *root;

void insert(int roll)
{
    if(root==NULL)
    {
        root=new node();
        root->roll=roll;
    }
    else
    {
        node *cur_node=root,*parent;
        while(cur_node!=NULL)
        {
            if(roll<cur_node->roll)
            {
                parent=cur_node;
                cur_node=cur_node->left;
            }
            else
            {
                parent=cur_node;
                cur_node=cur_node->right;
            }
        }
        node *newnode=new node();
        newnode->roll=roll;
        if(newnode->roll<parent->roll)
            parent->left=newnode;
        else
            parent->right=newnode;
    }
}

void print_inorder(node *current)
{
	if(current==NULL)
        return;
	print_inorder(current->left);
	cout<<current->roll<<endl;
	print_inorder(current->right);

}

void print_preorder(node *current)
{
	if(current==NULL)
        return;
	cout<<current->roll<<endl;
	print_preorder(current->left);
	print_preorder(current->right);

}

void print_postorder(node *current)
{
	if(current==NULL)
        return;
	print_postorder(current->left);
	print_postorder(current->right);
	cout<<current->roll<<endl;

}
main()
{
    int n,m;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m;
        insert(m);
    }
    cout<<"inorder Traversal"<<endl;
    print_inorder(root);
    cout<<"Preorder Traversal"<<endl;
    print_preorder(root);
    cout<<"postorder Traversal"<<endl;
    print_postorder(root);
}
