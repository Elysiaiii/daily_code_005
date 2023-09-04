

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//µÝ¹é
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    if (list1->val <= list2->val)
    {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    list2->next = mergeTwoLists(list1, list2->next);
    return list2;
}

//µü´ú
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* prehead = (struct ListNode*)malloc(sizeof(struct ListNode));
    //prehead->val=8;
    struct ListNode* prev = prehead;
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->val <= list2->val)
        {
            prev->next = list1;
            list1 = list1->next;
        }
        else
        {
            prev->next = list2;
            list2 = list2->next;
        }
        prev = prev->next;
    }
    if (list1 == NULL)
    {
        prev->next = list2;
        return prehead->next;
    }
    if (list2 == NULL)
    {
        prev->next = list1;
        return prehead->next;
    }
    return prehead->next;
}