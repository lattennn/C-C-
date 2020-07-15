#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>//INT_MAX INT_MIN
//#include<float.h> FLT_MAX
//#include<ctype.h> isdigit()


typedef struct node{
	int key;
	struct node *left;
	struct node *right;
}node_t;


int treeHeight(node_t * root, int level);
int treeNodes(node_t *root);
int treeLeaves(node_t *root);
void shortestPath(node_t *root, int level, int *lengthadd);



node_t * newNode(int key){
	node_t *n = (node_t*) malloc (sizeof(node_t));
	n->key = key;
	n->left = NULL;
	n->right = NULL;
	return n;
}
//preorder
void visit(node_t * root)
{
	if(root == NULL)
		return;
	visit(root->left);
	visit(root->right);
	printf("%d ", root->key);
}

int treeHeight(node_t * root,int level)//level = 0 in main
{
	int nl, nr;
	if(root == NULL){
		return level;
	}

	nl = treeHeight(root->left, level+1);
	nr = treeHeight(root->right, level+1);

	if(nl > nr)
		return nl;
	return nr;
}

int treeNodes(node_t *root)
{
	int nl, nr;
	if(root == NULL)
		return 0;
	nl = treeNodes(root->left);
	nr = treeNodes(root->right);

	return nl + nr + 1;
}

int treeLeaves(node_t *root)
{
	int nl, nr;
	if(root == NULL)
		return 0;

	if(root->left == NULL && root->right == NULL)
		return 1;

	nl = treeLeaves(root->left);
	nr = treeLeaves(root->right);

	//if(root->left == NULL && root->right == NULL)
		//return 1;

	return nl + nr;
}

void shortestPath(node_t *root, int level, int *lengthadd)
{
	//int nl, nr;
	if(root == NULL)
		return;
	if(root->left == NULL && root->right == NULL){
		if((*lengthadd)>level)
            *lengthadd = level;
		return;
	}
	shortestPath(root->left, level+1, lengthadd);
	shortestPath(root->right, level+1, lengthadd);
}


int main()
{
	/*
	         6
		4	      8
	2           7    9
	  3                 1
	                  22        */

	node_t *root;

	root = newNode(6);
	root->left = newNode(4);
	root->left->left = newNode(2);
	root->left->left->right = newNode(3);
	root->right = newNode(8);
	root->right->left = newNode(7);
	root->right->right = newNode(9);
    root->right->right->right = newNode(1);
    root->right->right->right->left = newNode(22);

	visit(root);//call

	//printf("%d ", root->key);
	printf("\nHeight: %d\n", treeHeight(root, 0)); //height ��ʵ����longest path
	printf("Nodes: %d\n", treeNodes(root));  //����nr+nl+1 ����Ҳ���� �Ҳ���Ҫleft��right��=NULL ֱ�ӵײ�����nl+nr+1 Ȼ��root==NULL����0�ͺ�
	printf("Leaves: %d\n", treeLeaves(root)); //����nr + nl ����+1 ������ ������left��rightͬʱ==NULL�ŷ���1 ��������ֻ������leaves

	int length = INT_MAX;//INT_MIN FLT_MAX FLT_MIN
	shortestPath(root, 1, &length);//level��0��ʼ ȥ���ײ� ��level+1����lengthָ��
	printf("Shortest path: %d\n", length);

	return 0;
}

