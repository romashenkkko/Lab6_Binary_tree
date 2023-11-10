#include <stdio.h>
#include <stdlib.h>


typedef struct Node;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* SearchBST(int data, struct node* root){
	struct node* current = root;
	printf("Visiting elements: ");
	while(current->data != data){
		if(current != NULL){
			printf("%d", current->data);
			
			//go to left tree 
			if(current->data > data){
				current = current->left;
			}//else go to right tree
		else{
			current = current->right;
			}
			//not found
			if(current == NULL){
				return NULL;
			}
		}
	}
	return NULL;
}


struct node* newNode(int data)
{
	struct node* node = (struct node*)malloc(sizeof(struct node));
	// Assign data to this node
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


int main()
{


	struct node* root = newNode(3);
    root->left = newNode(2);
    root->right = newNode(4);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->right = newNode(7);
    root->right->right->left = newNode(6);

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
