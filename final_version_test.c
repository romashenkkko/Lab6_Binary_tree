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

void printTree(struct node* root, int level) {
    if (root == NULL)
        return;

    printTree(root->right, level + 1);

    for (int i = 0; i < level; i++)
        printf("     ");

    printf("%d\n", root->data);

    printTree(root->left, level + 1);
}

struct node* LCA(struct node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;


    struct node* left_lca = LCA(root->left, n1, n2);
    struct node* right_lca = LCA(root->right, n1, n2);

    if (left_lca != NULL && right_lca != NULL)
        return root;

    return (left_lca != NULL) ? left_lca : right_lca;
}

void inOrderTraversal(struct node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int balanceHeight(struct node* currentNode) {
    if (currentNode == NULL) {
        return 0;
    }

    int leftSubtreeHeight = balanceHeight(currentNode->left);
    if (leftSubtreeHeight == -1) return -1;

    int rightSubtreeHeight = balanceHeight(currentNode->right);
    if (rightSubtreeHeight == -1) return -1;

    if (abs(leftSubtreeHeight - rightSubtreeHeight) > 1) {
        return -1;
    }

}

int main()
{


	struct node* root = newNode(3);
    root->left = newNode(3);
    root->right = newNode(1);
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

     int isBalanced = balanceHeight(root);
    if (isBalanced != -1) {
        printf("The tree is balanced.\n");
    } else {
        printf("The tree is not balanced.\n");
    }

    struct node* result = LCA(root, 1, 3);

    if (result != NULL) {
        printf("Lowest Common Ancestor of nodes 8 and 10 is %d\n", result->data);
    } else {
        printf("Nodes not found in the tree.\n");
    }

    printf("In-order traversal of the tree: ");
    inOrderTraversal(root);

	return 0;
}
