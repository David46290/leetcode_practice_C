# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define max(a,b) (((a) > (b)) ? (a) : (b))

 struct TreeNode 
 {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
 };

struct TreeNode* tree_init(int value)
{
    struct TreeNode* root=malloc(sizeof(struct TreeNode));
    root->val = value;
    root->right = NULL;
    root->left = NULL;
    return root;
}

void insert_leaf(struct TreeNode* root, int value, char location[])
{
    struct TreeNode* current_node = root;
    struct TreeNode* new_node = malloc(sizeof(struct TreeNode));
    new_node->val = value;
    new_node->right = NULL;
    new_node->left = NULL;
    for (int i=0; i<strlen(location); i++)
    {
        if (location[i] == 'r')
        {
            if (current_node->right != NULL)
            {
                current_node = current_node->right;
            }
            else
            {
                current_node->right = new_node;
                return;
            }
        }
        else if (location[i]  == 'l')
        {
            if (current_node->left != NULL)
            {
                current_node = current_node->left;
            }
            else
            {
                current_node->left = new_node;
                return;
            }
        }
        else
        {
            printf("something wrong while inserting the leaf\n");
        }
    }
}

int depth_first_search(struct TreeNode* current_node, int* max_depth) // Depth First Search: return maximum height of the current_node
{
    if (current_node == NULL)
    {
        return 0;
    }
    int height_branch_left = depth_first_search(current_node->left, max_depth);
    int height_branch_right = depth_first_search(current_node->right, max_depth);
    *max_depth = max(*max_depth, (height_branch_left+height_branch_right)); // max. path num. = sum of both-side branch lengths
    return 1 + max(height_branch_left, height_branch_right); // one more edge to add for connecting to current_node
}

int diameterOfBinaryTree(struct TreeNode* root)
{
    int max_depth = 0;
    depth_first_search(root, &max_depth);
    return max_depth;
}


int main(void)
{
    char loc_1[] = "l"; 
    char loc_2[] = "r";
    char loc_3[] = "ll";
    char loc_4[] = "lr";
    char loc_5[] = "rl";
    char loc_6[] = "rr";
    char loc_7[] = "lll";
    struct TreeNode* tree = tree_init(0);
    insert_leaf(tree, 1, &loc_1);
    insert_leaf(tree, 2, &loc_2);
    insert_leaf(tree, 3, &loc_3);
    insert_leaf(tree, 4, &loc_4);
    insert_leaf(tree, 5, &loc_5);
    insert_leaf(tree, 6, &loc_6);
    //insert_leaf(tree, 7, &loc_7);
    int answer = diameterOfBinaryTree(tree);
    printf("diameter: %d", answer);
    free(tree);
    return 0;
}