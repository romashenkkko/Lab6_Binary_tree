#include <stdio.h>
#include <stdlib.h>


typedef struct Node;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
int Leafes_Counter(struct node* node){
    if (node == NULL)
        return 0;
    if (node-> left == NULL && node-> right == NULL)
		return 1;
	else
		return Leafes_Counter(node->left) + Leafes_Counter(node->right);
    }

int Tree_Height(struct node* root){
	int left_height, right_height;
    if (root == NULL)
    	return 0;
	else{
		left_height = Tree_Height(root->left);
    		right_height =Tree_Height(root->right);
		if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}


int minVal(struct node* root) {
    if (root == NULL)
        return INT_MAX; 
    int result = root->data;
    int left_result = minVal(root->left);
    int right_result = minVal(root->right);
if (left_result < result)
    result = left_result;
if (right_result < result)
    result = right_result;
return result;
}

int maxVal(struct node* root) {
    if (root == NULL) 
        return INT_MIN; 
    int result = root->data;
    int left_result = maxVal(root->left);
    int right_result = maxVal(root->right);
    if (left_result > result)
        result = left_result;
    if (right_result > result)
        result = right_result;
    return result;
}

int CheckBST(struct node* node) {
    if (node == NULL) {
        return 1; 
    }
    if(node->left != NULL && maxVal(node->left) > node->data)
        return 0;
    if(node->left != NULL && minVal(node->right) < node-> data)
        return 0;
    if(!CheckBST(node->left) || !CheckBST(node->right))
        return 0;

        return 1;
}

void printTree(struct node* root, int level) {
    if (root == NULL)
        return;

    printTree(root->right, level + 1);

    for (int i = 0; i < level; i++)
        printf("     ");

    printf("%d\n", root->data);

    printTree(root->left, level + 1);
}

int main()
{


	struct node* root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(4);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(7);
    root->right->right->left = newNode(6);

     printf("Binary Tree:\n");
    printTree(root, 0);

 	printf("The number of leaf nodes is %d\n", Leafes_Counter(root));
	printf("The height of the tree is %d\n",Tree_Height(root));
	
    int BST_result = CheckBST(root);
    if (BST_result == 1) {
        printf("The tree is a BST\n");
    } else {
        printf("The tree is NOT a BST\n");
    }
	return 0;
}
