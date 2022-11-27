
typedef struct node {
    int data;
    struct node *left, *right,*parent;
}node;

struct node* newNode(int item);
void inorder(struct node* root);
struct node* insert(struct node* node, int key);
node* max_tree(struct node*root);
node* min_tree(struct node*root);
node* Search(node*root,int k);
node* removeHelper(node* root,node* root1);
void Delete(node* root,node* root1);
int high_tree(node *t);
void high(node *t);
int max(int l,int r);
node* Successor(node* root, node* n);
node* Predecessor(node* root, node* n);
int size_tree(node *t);
void size(node *t);
node* load(node *root);
void Load(node **root);
void save(node* root);
void save2(FILE *p,node *root);
void Insert(node **root);
void Delete2(node* root);
void Search2(node*root);
void max_tree2(node*root);
void min_tree2(node*root);
void Successor2(node* root);
void Predecessor2(node* root);
void Exit1(node*root);


