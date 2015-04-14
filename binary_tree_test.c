#include <stdio.h>
#include "binary_tree.h"
#include "list_queue.h"

void callback(void* data)
{
    if (!data) return;
    printf("%d ", *(int*)data);
}

int main()
{
        btree_node_p arr[16];
        
        int i=0;
        for(i=0;i<15;i++)
        {
            arr[i]=create_btree_node(&i,sizeof(int));
        }
        arr[0]->left_child = arr[1];
        arr[0]->right_child = arr[2];
        arr[1]->left_child = arr[3];
        arr[1]->right_child = arr[4];
        arr[2]->left_child = arr[5];
        arr[2]->right_child = arr[6];
        arr[3]->left_child = arr[7];
        arr[3]->right_child = arr[8];
        arr[4]->left_child = arr[9];
        arr[4]->right_child = arr[10];
        arr[5]->left_child = arr[11];
        arr[5]->right_child = arr[12];
        arr[6]->left_child = arr[13];
        arr[6]->right_child = arr[14];
        binary_inorder(arr[0], callback);
        printf("\n");
        binary_iter_inorder(arr[0], callback);
        printf("\n");
        binary_preorder(arr[0], callback);
        printf("\n");
        binary_iter_preorder(arr[0], callback);
        printf("\n");
        binary_postorder(arr[0], callback);
        printf("\n");
        binary_iter_postorder(arr[0], callback);
        printf("\n");
        binary_level(arr[0], callback);
        printf("\n");
        printf("%d\n", binary_depth(arr[0]));
        printf("%d\n", binary_depth(arr[1]));
        printf("%d\n", binary_depth(arr[3]));
        printf("%d\n", binary_depth(arr[7]));
        binary_destroy(arr[0]);
        return 0;
}