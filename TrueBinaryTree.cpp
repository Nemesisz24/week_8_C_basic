#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
} node;
node *makenode(int x){
    node *temp=(node*)malloc(sizeof(node));
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp; 
}
node* themnode(node *p,node *proot){
    if (proot == NULL) {
        proot = p;
    }
    else if (proot->data > p->data){
        proot->left = themnode(p,proot->left);
    }
    else if (proot->data < p->data){
        proot->right = themnode(p,proot->right);
    }
    return proot;
}
node* taocay(node *proot){
    int n,x;
    printf("Nhap so gia tri can them:");
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        printf("Nhap gia tri can them:");
        scanf("%d",&x);
        proot = themnode(makenode(x),proot);
    }
    return proot;
}
void incayNLR(node *proot){
    if(proot == NULL) return;
    printf("%d ",proot->data);
    incayNLR(proot->left);
    incayNLR(proot->right);
}
void incayLNR(node *proot){
    if (proot == NULL) return ;
    incayLNR(proot->left);
    printf("%d ",proot->data);
    incayLNR(proot->right);
}
node *find(node *proot,int x){
    if (proot==NULL) return NULL;
    if (proot->data == x)
        return proot;
    else if (x > proot->data)
        find (proot->right,x);
    else if (x <proot->data)
        find (proot->left,x);

}
void timkiem(node *proot){
    int x;
    printf("Nhap gia tri can tim: ");
    scanf("%d",&x);
    node *k=find(proot,x);
    if (k!=NULL)
        printf("Tim duoc !\n");
        else printf(" khong tim duoc !\n");
}
void nutla(node *proot, int *dem){
    if (proot == NULL) return;
    if (proot -> left == NULL && proot -> right == NULL)
        *dem= *dem +1;
    nutla(proot->left, dem);
    nutla(proot->right, dem);
}
void demnutla(node *proot){
    int dem =0 ;
    nutla(proot,&dem);
    printf("leaves = %d",dem);
}
node* timnodecha(node *proot,int x){
    if (proot->left->data == x || proot->right->data == x)
        return proot;
    else if (proot->data < x) return timnodecha(proot->right,x);
    else if (proot->data > x) return timnodecha(proot->left,x);
}
void parent(node *proot) {
    int x;
    printf("Nhap gia tri node can tim node cha:");
    scanf("%d",&x);
    node *k=NULL;
    k=timnodecha(proot,x);
    printf("Node cha  = %d",k->data );
}
void sonut(node *proot,int *dem){
    if (proot == NULL) return;
    *dem = *dem + 1;
    sonut(proot->left,dem);
    sonut(proot->right,dem);
}
void count(node *proot){
    int dem = 0;
    sonut(proot,&dem);
    printf("So nut tren cay: %d",dem);
}
void heightcount(node *proot,int *max,int *dem){
    if (proot == NULL ){ 
        if (*dem > *max){
            *max = *dem;
        }
        return;
    }
    *dem = *dem + 1;
    heightcount(proot->left, max, dem);
    heightcount(proot->right, max, dem);
    *dem = *dem -1 ;
}
void height(node *proot){
    int dem = 0,max =1;
    int x;
    printf("Nhap gia tri can tinh do cao: ");
    scanf("%d",&x);
    node *p = find(proot,x);
    heightcount(p,&max,&dem);
    printf("Chieu cao cua nut %d la %d !\n",x,max);
}

int main(){
    node* root=NULL;
    int chucnang;
    while (1){
        printf("\n\t\t\t---------------MENU---------------\n"); 
        printf("\t\t\t0: Thoat chuong trinh\n");
        printf("\t\t\t1: Tao cay moi\n");
        printf("\t\t\t2: In cay vua tao theo thu tu NLR\n");
        printf("\t\t\t3: In cay vua tao theo thu tu LNR\n");
        printf("\t\t\t4: Tim kiem mot node co gia tri x\n");
        printf("\t\t\t5: Dem so nut la (leaves) co trong cay\n");
        printf("\t\t\t6: Tim node cha cua 1 node con co gia tri bat ki\n");
        printf("\t\t\t7: Dem tong so nut tren cay\n");
        printf("\t\t\t8: Tinh chieu cao cua 1 nut bat ki\n");
        printf("Nhap chuc nang: ");
        scanf("%d",&chucnang);
        switch(chucnang){
            case 1: root = taocay(root); break;
            case 2: incayNLR(root); break;
            case 3: incayLNR(root); break;
            case 4: timkiem(root); break;
            case 5: demnutla(root); break;
            case 6: parent(root); break;
            case 7: count(root);break;
            case 8: height(root); break;
        }
        if (chucnang == 0) break;
    }
    return 0;
}