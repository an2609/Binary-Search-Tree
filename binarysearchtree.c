#include<stdio.h>
#include<stdlib.h>
int kk;
struct tree * search(int );
struct tree
{
    int info;
    struct tree *left;
    struct tree *right;
} *n1,*temp,*root,*temp3,*parent,*temp4;
void del(int aa)
{
    struct tree *p=search(aa);
    if(p!=NULL)
    {
        if(p->right==NULL&&p->left==NULL)
        {
            if(kk==1)
                parent->left=NULL;
            else if(kk==2)
                parent->right=NULL;
        }
        else if(p->right==NULL)
        {
            p->info=p->left->info;
            free(p->left);
            p->left=NULL;
        }
        else if(p->left==NULL)
        {
            p->info=p->right->info;
            free(p->right);
            p->right=NULL;
        }
        else
        {
            int tem;
            temp4=p->right;
            while(1)
            {
                if(temp4->left==NULL)
                    break;
                temp4=temp4->left;
            }
            tem=temp4->info;
            del(temp4->info);
            p->info=tem;
        }
    }
    else
        printf("The element to be deleted do not exist\n");
}
int ma(int a,int b)
{
    if(a-b>=0)
        return a;
    else return b;
}
struct tree* search(int lm)
{
    temp3=NULL;
    parent=root;
    temp=root;
    while(1)
    {
        if(lm==temp->info)
        {
            temp3=temp;
            break;
        }
        else if(lm<temp->info)
        {
            parent=temp;
            if(temp->left==NULL)
                break;
            kk=1;
            temp=temp->left;
        }
        else
        {
            parent=temp;
            if(temp->right==NULL)
                break;
            kk=2;
            temp=temp->right;
        }
    }
    return temp3;
}
void preorder(struct tree *node)
{
    if(node==NULL) return;
    printf("%d ",node->info);
    preorder(node->left);
    preorder(node->right);
}
void inorder(struct tree *node)
{
    if(node==NULL) return;
    inorder(node->left);
    printf("%d ",node->info);
    inorder(node->right);
}
void postorder(struct tree *node)
{
    if(node==NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d ",node->info);
}
void add()
{
    int i,j;
    n1=(struct tree*)malloc(sizeof(struct tree));
    n1->left=NULL;
    n1->right=NULL;
    printf("Enter the number to be inserted in the tree\n");
    scanf("%d",&n1->info);
    temp=root;
    while(1)
    {
        if(n1->info<temp->info)
        {
            if(temp->left==NULL)
                break;
            temp=temp->left;
        }
        else
        {
            if(temp->right==NULL)
                break;
            temp=temp->right;
        }
    }
    if(n1->info<temp->info)
        temp->left=n1;
    else
        temp->right=n1;
}
void create()
{
    int i,j;
    printf("Enter the no. of elements to be entered in the tree\n");
    scanf("%d",&i);
    for(j=0; j<i; j++)
    {
        n1=(struct tree*)malloc(sizeof(struct tree));
        n1->left=NULL;
        n1->right=NULL;
        printf("Enter the number to be inserted in the tree\n");
        scanf("%d",&n1->info);
        if(j==0)
        {
            root=n1;
        }
        else
        {
            temp=root;
            while(1)
            {
                if(n1->info<temp->info)
                {
                    if(temp->left==NULL)
                        break;
                    temp=temp->left;
                }
                else
                {
                    if(temp->right==NULL)
                        break;
                    temp=temp->right;
                }
            }
            if(n1->info<temp->info)
                temp->left=n1;
            else
                temp->right=n1;
        }
    }
}
int main()
{
    int sw;
    while(1)
    {
        printf("What do u want to do\n\
           1.Create a binary search tree\n\
           2.Add an element to the binary search tree\n\
           3.Pre order traversal\n\
           4.In order traversal\n\
           5.Post order traversal\n\
           6.Search an element\n\
           7.Delete\n\
           8.Exit\n");
        scanf("%d",&sw);
        switch(sw)
        {
        case 1:
        {
            create();
            break;
        }
        case 2:
        {
            add();
            break;
        }
        case 3:
        {
            preorder(root);
            printf("\n");
            break;
        }
        case 4:
        {
            inorder(root);
            printf("\n");
            break;
        }
        case 5:
        {
            postorder(root);
            printf("\n");
            break;
        }
        case 6:
        {
            int lm;
            struct tree *c;
            printf("Enter the element to be searched\n");
            scanf("%d",&lm);
            c=search(lm);
            if(c!=NULL)
                printf("Successful search\n");
            else
                printf("Unsuccessful search\n");
            break;
        }
        case 7:
        {
            int aa;
            printf("Enter the element to be deleted\n");
            scanf("%d",&aa);
            del(aa);
            break;
        }
        case 8:
        {
            exit(0);
        }
        default:
            printf("You have entered a wrong choice\n");
        }
    }
}
