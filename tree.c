#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node {
    int n;
    struct node *left;
    struct node *right;
};

struct node *newnode(int k);

void print(struct node *root)  {
    if (root!=NULL)  {
        print(root->left);
        printf("%d\n", root->n);
        print(root->right);
    }
}

struct node *add(struct node *root, int k)  {
    if (root == NULL) {
        root = newnode(k);
    } else
    if (root->n > k)  {
        root->left = add(root->left, k);
    }  else
    /*if (root->n <= k)*/  {
        root->right = add(root->right, k);
    }
    return root;
}

struct node *newnode(int k)  {
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->n = k;
    p->left = NULL;
    p->right = NULL;
    return p;
};

int main() {
    time_t t;
    srand((unsigned) time(&t));

    char length = 5;
    struct node *c[length];
    // = (struct node **)malloc(sizeof(struct node)*length);

    for(int i = 0 ; i < length ; i++ ) {
      c[i] = newnode(rand() % 255);
      printf("%d\n",c[i]->n);
   }

   unsigned char min1,min2,tmp1,tmp2;
   char *test;

   while ( length >= 1) {
     min1 = 255,min2 = 255,tmp1 = 1,tmp2 = 1;
       for(int i = 0 ; i < length ; i++ ) {
           //printf("%d",c[i]->n);
           unsigned char read = c[i]->n;
           if (read < min1) {
               //printf("yeah");
               min2 = min1;
               min1 = read;
               tmp1 = i;
           } else if (read < min2) {
               min2 = read;
               tmp2 = i;
               //printf("yeah");
           } //else printf("No");
      }
        printf("%s %d %s %d \n","min1 = ",min1,"tmp1 = ",tmp1);
        printf("%s %d %s %d \n","min2 = ",min1,"tmp2 = ",tmp2);

        scanf("%s",test);

       struct node *mem = c[tmp1];
       c[tmp1] = newnode(c[tmp1]->n + c[tmp2]->n );
       c[tmp1]->left = mem;
       c[tmp1]->right = c[tmp2];

       c[tmp2] = c[length];
       length--;
    }
}
