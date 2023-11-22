#include <stdio.h>
#include <stdlib.h>

int lk=0, rk=0;

struct node{
    int key;
    struct node *left,*right;
};

struct node *new_node(int key){
    struct node *new = (struct node *)malloc(sizeof (struct node));
    new->key=key;
    new->left = new->right = NULL;
    return new;
}

struct node *insert(struct node *node, int key){
    if(node != NULL){
        if(key < node->key){
            node->left = insert(node->left,key);
        }
        else{
            node->right = insert(node->right,key);
        }
    }else{
        return new_node(key);
    }
    return node;
}

void delete_childs(struct node *node){
    struct node *temp = node;
    if(temp->left != NULL)
        delete_childs(temp->left);
    free(node);
    if(temp->right != NULL)
        delete_childs(temp->right);
}

struct node *delete(struct node *node, int key){
    if(node->left != NULL)lk = node->left->key;
    if(node->right != NULL)rk = node->right->key;
    if(lk == key){
        node->left = NULL;
    }else if(rk == key){
        node->right = NULL;
    }else{
        if(key < node->key){
            delete(node->left, key);
        }else{
            delete(node->right, key);
        }
    }
    if(node == NULL){
        printf("ARBOL VACIO");
        return NULL;
    }
    return node;
}

void display_right(struct node *child){
    printf("RIGHT: %d",child->key);
}
void display_left(struct node *child){
    printf("LEFT: %d ",child->key);
}
void display_middle(struct node *node){
    printf("KEY: %d ",node->key);
    if(node->left != NULL){
        display_left(node->left);
    }if(node->right != NULL){
        display_right(node->right);
    }
    printf("\n");
}
void display(struct node *node){
    if(node != NULL){
        display(node->left);
        display_middle(node);
        display(node->right);
    }
}
void find(struct node *node, int key){ //inorder
    if(key==node->key){
        display_middle(node);
    }else{
        if(key < node->key){
            find(node->left,key);
        }
        else{
            find(node->right,key);
        }
    }
}

int main() {
    struct node *n = (struct node *)malloc(sizeof (struct node));
    //--INSERTAR--
    n = insert(n, 8);
    n = insert(n, 3);
    n = insert(n, 1);
    n = insert(n, 6);
    n = insert(n, 7);
    n = insert(n, 10);
    n = insert(n, 14);
    n = insert(n, 4);
    n = insert(n, 11);
    n = insert(n, 15);
    n = insert(n, 13);
    n = insert(n, 16);
    n = insert(n, 12);
    n = insert(n, 17);
    n = insert(n, 19);
    printf("--LISTAR--\n");
    display(n);
    printf("--ENCONTRAR--\n");
    find(n,8);
    find(n,11);
    find(n,15);
    printf("--LISTAR DESPUES DE BORRAR--\n");
    n = delete(n,7);
    display(n);
    return 0;
}
