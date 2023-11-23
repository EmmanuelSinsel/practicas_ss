#include <stdio.h>
#include <stdlib.h>

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
    if(node==NULL){
        printf("%d NO EXISTE EN EL ABB\n",key);
        return;
    }
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

int validate(struct node *node){
    if(node != NULL) {
        struct node *l = node->left;
        struct node *r = node->right;
        if (l != NULL) {
            if (l->key == node->key) {
                printf("ESTE NO ES UN ARBOL BINARIO DE BUSQUEDA VALIDO\n");
                return 0;
            }
        }
        if (r != NULL) {
            if (r->key == node->key) {
                printf("ESTE NO ES UN ARBOL BINARIO DE BUSQUEDA VALIDO\n");
                return 0;
            }
        }
        if(validate(node->left)==0){
            return 0;
        }
        if(validate(node->right)==0){
            return 0;
        }
    }
    if(node == NULL){
        return 1;
    }
    return 1;
}

int main() {
    struct node *n = new_node(8);
    //--INSERTAR--
    n = insert(n, 10);
    n = insert(n, 8);
    n = insert(n, 7);
    n = insert(n, 6);
    n = insert(n, 12);
    n = insert(n, 13);
    n = insert(n, 14);
    n = insert(n, 16);
    //n = insert(n, 6);
    int flag = validate(n);
    if(flag==1){
        printf("ESTE ES UN ARBOL BINARIO DE BUSQUEDA VALIDO\n");
        printf("--LISTAR--\n");
        display(n);
        printf("--ENCONTRAR--\n");
        find(n,8);
        find(n,11);
        find(n,15);
        printf("--LISTAR DESPUES DE BORRAR--\n");
        n = delete(n,7);
        display(n);
    }
    return 0;
}
