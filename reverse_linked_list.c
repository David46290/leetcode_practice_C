# include <stdio.h>
# include <stdlib.h>


struct ListNode 
{
      int val;
      struct ListNode *next;
};


struct ListNode* creat_linked_list(int* nums, int numsSize)
{
    struct ListNode *head=NULL;
    // h: head node, n: node, v: nums, v_size: numsSize
    // (nums) v[0], v[1], v[2], v[3], v[v_size]
    // (init)                            h
    // (1st)                      h  ->  n
    // (2nd)               h ->   n  ->  n
    // (3rd)         h ->  n ->   n  ->  n
    // ... ...
    for (int i=numsSize-1; i>=0; i--)
    {
        struct ListNode *new_node = malloc(sizeof(struct ListNode));
        new_node->val = nums[i];
        if (head == NULL) // if the linked list is empty
        {
            head = new_node;
            head->next = NULL;
            continue;
        }
        new_node->next = head;
        head = new_node;
    }

    return head;
}

struct ListNode* reverseList(struct ListNode* head)
{
    // turn the head to last node (pointing null pointer)
    // turn the last node to head (not pointing null anymore)
    struct ListNode* previous_node = NULL; // to makie the new link, cause we want current node point to the previous node
    struct ListNode* current_node = head;  // check whether hit the null ptr, which is the end of the original linked list
    struct ListNode* next_node; // to save the original link
    while (current_node != NULL)
    {
        next_node = current_node->next; // save the original link first
        current_node->next = previous_node; // make a reversed link
        printf("done with node %d \n", current_node->val);
        //move on to next node in the original linked list
        previous_node = current_node;
        current_node = next_node; 
    } 
    return previous_node;
}

void show_linked_trail(struct ListNode* head)
{
    struct ListNode* current_node = head;
    printf("linked list:");
    while (current_node != NULL)
    {
        printf(" %d ->", current_node->val);
        current_node = current_node->next;
    } 
    printf(" NULL\n");
}

int main(void)
{
    int numsSize = 0;
    printf("length: ");
    scanf("%d", &numsSize);
    int *nums = malloc(numsSize * sizeof(int));

    for(int i=0; i<numsSize; i++)
    {
        printf("nums[%d] = ", i);
        scanf("%d", nums+i); // nums+i is the address of nums[i]
    }

    printf("nums = [");
    for(int i=0; i<numsSize-1; i++)
    {
        printf("%d,", *(nums+i));
    }
    printf("%d", *(nums+numsSize-1));
    printf("]\n");

    struct ListNode *list = creat_linked_list(nums, numsSize);
    show_linked_trail(list);
    struct ListNode *reversed_list = reverseList(list);
    show_linked_trail(reversed_list);
    free(list);
    free(reversed_list);
    return 0;
}