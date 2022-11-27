

struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;
    return temp;
}
//------------------------------

void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
//------------------------------
struct node* insert(struct node* node, int data)
{
    /* 1. If the tree is empty, return a new,
      single node */
    if (node == NULL)
        return (newNode(data));
    else {
        struct node* temp;
 
        /* 2. Otherwise, recur down the tree */
        if (data <= node->data) {
            temp = insert(node->left, data);
            node->left = temp;
            temp->parent = node;
        }
        else {
            temp = insert(node->right, data);
            node->right = temp;
            temp->parent = node;
        }
 
        /* return the (unchanged) node pointer */
        return node;
    }
}
//------------------------------------------
node* max_tree(node*root)
{
if (root==NULL)
return NULL;
node *t=root;
while(t->right!=NULL)
{t=t->right;
}

return t;

}
//-------------------------------------------
node* min_tree(node*root)
{
if (root==NULL)
return NULL;
node *t=root;
while(t->left!=NULL)
{t=t->left;
}

return t;

}
//-------------------------------------------
node* Search(node*root,int k)
{

if(root==NULL)
{
printf("Tree is empty.   ");
return NULL;
}	

node *t;
t=root;

while(t!=NULL)
{
if(k==t->data)
return t;
else if(k<=t->data)
t=t->left;
else
t=t->right;

}
return NULL;
}
//-------------------------------------------

node* removeHelper(node*root,node* root1)
{
if (root == NULL) return root;
else if (root1->data < root->data)
root->left = removeHelper(root->left, root1);
else if (root1->data > root->data)
root->right = removeHelper(root->right, root1);
else
{
if (root->left == NULL)
{
node* temp = root->right;
free(root);
return temp;
}
else if (root->right == NULL)
{
node* temp = root->left;
free(root);
return temp;
}
else
{
node *t1=root->left;
while(t1->right!=NULL)
{t1=t1->right;
}
int maxValue=t1->data;
root->data = maxValue;
root->left = removeHelper(root->left,t1);
}

}
return root;
}
//----------------------------------------------
	
void Delete(node* root,node* root1)
{
if(root1==NULL)
printf("not found value\n");
else
{
root=removeHelper(root,root1);
printf("Success delete.\n");
}
}
//--------------------------------------------

int high_tree(node *t)
{
if(t==NULL) 
return -1;

int L=high_tree(t->left);
int R=high_tree(t->right);
return 1+max(L,R);

}
//---------------------------------------------
void high(node *t)
{
if(high_tree(t)==-1)
printf("Tree is empty.");
else
printf("High Tree: %d \n",high_tree(t));
}
//--------------------------------------------
int max(int l,int r)
{
if(l>r) return l;
else return r;
}
//---------------------------------------------


node* Successor(node* root, node* n)
{
    // step 1 of the above algorithm
    if (n->right != NULL)
        return min_tree(n->right);
 
    // step 2 of the above algorithm
    struct node* p = n->parent;
    
    while (p != NULL && n == p->right) {
        n = p;
        p = p->parent;
    }
    return p;
}
//-----------------------------------------------

node* Predecessor(node* root, node* n)
{
    // step 1 of the above algorithm
    if (n->left != NULL)
        return max_tree(n->left);
 
    // step 2 of the above algorithm
    struct node* p = n->parent;
    
    while (p != NULL && n == p->left) {
        n = p;
        p = p->parent;
    }
    return p;
}
//------------------------------------------

int size_tree(node *t)
{
if(t==NULL) 
return 0;
if(t->left!=NULL && t->right!=NULL)
return 2+size_tree(t->left)+size_tree(t->right);
else if(t->left!=NULL)
return 1+size_tree(t->left);
else if(t->right!=NULL)
return 1+size_tree(t->right);
}
//------------------------------------------
void size(node *t)
{
	if(t==NULL)
	printf("Tree is empty.");
	else
	printf("Size Tree: %d \n",size_tree(t)+1);
}

//----------------------------------------------
node* load(node *root)
{
char name[100],c;
char Sn[10];
int i,i1;

printf("Enter the file name: ");
scanf("\n");
gets(name);

//printf("%s",name);
FILE *p;
p = fopen (name,"r");
i=0;
while((c=fgetc(p))!=EOF)
{
Sn[i++]=c;
i1=i;

if(c=='\n' || c=='\0')
{
Sn[i]='\0';
i=0;
root=insert(root,atoi(Sn));
}

}

if(i!=0)
{
Sn[i1]='\0';
root=insert(root,atoi(Sn));
}

fclose (p);
return root;
}
//------------------------------------------------
void Load(node **root)
{
*root=load(*root);
}
//------------------------------------------------


void save(node* root)
{	
	char name[100];
	printf("Enter the file name: ");
	scanf("\n");
	gets(name);
	
	FILE *p;
	p = fopen (name,"w");
	save2(p,root);
    fclose (p);
}
//--------------------------------------------
void save2(FILE *p,node *root)
{
	
if (root != NULL) 
{
save2(p,root->left);
fprintf(p,"%d\n", root->data);
save2(p,root->right);
}

}
//-------------------------------------------
void Insert(node **root)
{int k;
printf("Enter the number:");
scanf("%d",&k);
*root=insert(*root,k);
}
//----------------------------------------------
void Delete2(node* root)
{
int k;
printf("Enter the number:");
scanf("%d",&k);
Delete(root,Search(root,k));

}
//-------------------------------------
void Search2(node*root)
{
int k;
printf("Enter the number:");
scanf("%d",&k);
if(Search(root,k)==NULL)
printf("Not Found.\n");
else
printf("I found its address to be: 0x%x \n",Search(root,k));

}
//-----------------------------------------
void max_tree2(node*root)
{
if(max_tree(root)==NULL)
printf("Tree is empty.\n");
else
printf("Max tree: %d \n",max_tree(root)->data);

}
//-----------------------------------------
void min_tree2(node*root)
{
if(min_tree(root)==NULL)
printf("Tree is empty.\n");
else
printf("Min tree: %d \n",min_tree(root)->data);

}
//-----------------------------------------
void Successor2(node* root)
{
int k;
printf("Enter the number:");
scanf("%d",&k);
if(Search(root,k)==NULL)
printf("Not Found value= %d \n",k);
else if(Successor(root,Search(root,k))==NULL)
printf("Not Found.\n");
else
printf("Successor(%d): %d \n",k,Successor(root,Search(root,k))->data);

}
//-----------------------------------------
void Predecessor2(node* root)
{
int k;
printf("Enter the number:");
scanf("%d",&k);
if(Search(root,k)==NULL)
printf("Not Found value= %d \n",k);
else if(Predecessor(root,Search(root,k))==NULL)
printf("Not Found.\n");
else
printf("Predecessor(%d): %d \n",k,Predecessor(root,Search(root,k))->data);

}
//-----------------------------------------
void Exit1(node*root)
{
char aa[10];
printf("Do you want to save the file? .. Enter Yes / No :");
scanf("\n");
gets(aa);
if(strcmp(aa,"Yes")==0 || strcmp(aa,"yes")==0)
{save(root); exit(0);}
else
exit(0);

}



