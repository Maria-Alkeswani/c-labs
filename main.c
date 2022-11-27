#include<stdio.h>
#include"bt.h"
#include"bt.c"
int main()
{struct node* root = NULL;
int x;
for(;;)
{
printf("1- Insert.\n2- Delete.\n3- Search.\n4- Maximum.\n5- Minimum.\n6- Successor.\n7- Predecessor.\n8- Print tree inorder.\n9- Depth.\n10- Size.\n11- Load.\n12- Save.\n13- Exit.\n");
printf("Enter the order number: ");
scanf("%d",&x);
printf("--------------------------------------------------------\n"); 

if(x==1) Insert(&root);
else if(x==2) Delete2(root);
else if(x==3) Search2(root);
else if(x==4) max_tree2(root);
else if(x==5) min_tree2(root);
else if(x==6) Successor2(root);
else if(x==7) Predecessor2(root);
else if(x==8) {inorder(root); printf("\n");}
else if(x==9) high(root);
else if(x==10) size(root);
else if(x==11) Load(&root);
else if(x==12) save(root);
else if(x==13) Exit1(root);


printf("--------------------------------------------------------\n");
}





return 0;
}
