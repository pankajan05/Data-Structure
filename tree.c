#include<stdio.h>
#include<conio.h>
#include<stdio.h>


typedef struct bst
{
    int data;
    struct BST* left;
    struct BST* right;
}BST;

BST *minValue(BST *root){
    if (!root)
        return NULL;
    if (root->left==NULL)
        return root;
    else
        return minValue(root->left);
}

BST *maxValue(BST *root){
    if (!root)
        return NULL;
    if (root->right==NULL)
        return root;
    else
        return maxValue(root->right);
}

BST * delete(BST *root,int key){

    if (!root)
        return NULL;
    if (key<root->data)
        root->left=delete(root->left,key);
    else if (key>root->data)
        root->right=delete(root->right,key);
    else{
        BST *temp;
        if(root->left==NULL ){
            temp=root->right;
            free(root);
            return temp;

        }else if(root->right==NULL){
            temp=root->left;
            free(root);
            return temp;
        }

        temp=minValue(root->right);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
        return root;
        /*
        temp=maxValue(root->left);
        root->data=temp->data;
        root->left=delete(root->left,temp->data);
        return root;*/
    }



}



BST *search(BST *root,int key)
{
  if (!root)
    return NULL;
  if (key == root->data)
    return root;
  if (key < root->data)
      return search(root->left,key);
  else
      return search(root->right,key);
}

BST *insert(BST *root, int key)
{
 if(!root) {
		root=(BST *)malloc(sizeof(BST));
		root->data = key;
		root->left = NULL;
		root->right = NULL;
		return(root);
	}
	if(root->data>key)
	     root->left = insert(root->left,key); else {
		if(root->data<key)
			root->right = insert(root->right,key);
	}
	return(root);
}


void inorder(BST *root) {
	if(root != NULL) {
		inorder(root->left);
		printf(" %d",root->data);
		inorder(root->right);
	}
	return;
}
void main(){

printf("Binary Search Trees\n");
printf("-------------------\n");

BST *root = NULL;
int t,i;
int elements[11]={25,30,20,22,35,10,17,7,37,15,33};

for(i=0;i<11;i++){

    printf("\n Inserting value %d to tree",elements[i]);
    root=insert(root,elements[i]);

}
printf("\n\nInorder Traveling in the tree \n");
inorder(root);
printf("\nMinimum is :%d \n",minValue(root)->data);
printf("\nMaximum is :%d \n",maxValue(root)->data);

printf("\nEnter value for delete :" );
scanf("%d",&t);

root=delete(root,t);
inorder(root);
}
