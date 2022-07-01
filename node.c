#include "node.h"

struct node_
{
    int32_t unique_id;
    struct node_ *link;
};

ListNode *
XOR(ListNode *x, ListNode *y)
{
    return (ListNode *)((uintptr_t)(x) ^ (uintptr_t)(y));
}

int32_t
allocHead(ListNode **head)
{
    int32_t rc = NOT_OK;

    if (NULL != head)
    {
        *head = malloc(sizeof(ListNode));

        if (NULL != *head)
        {
            (*head)->unique_id = HEAD_ID;
            (*head)->link = NULL;

            rc = OK;
        }
    }

    return rc;
}

int32_t
getUniqueId(ListNode *node, int32_t *id)
{
    int32_t rc = NOT_OK;

    if (NULL != node)
    {
        *id = node->unique_id;

        rc = OK;
    }

    return rc;
}

ListNode *
add(int32_t unique_id, ListNode *last)
{
    ListNode *newNode = malloc(sizeof(ListNode));

    if (NULL != newNode)
    {
        newNode->link = XOR(last, NULL);
        newNode->unique_id = unique_id;

        last->link = XOR(newNode, XOR(last->link, NULL));
    }
    else if (NULL != newNode && HEAD_ID == unique_id)
    {
        free(newNode);
        newNode = NULL;
    }

    return newNode;
}

ListNode *
get(ListNode *head, int32_t index)
{
    static int32_t iterationCount = 0;

    if (NULL != head)
    {
        if (iterationCount == index)
        {
            iterationCount = 0;
            return head;
        }
        else if (iterationCount < index)
        {
            iterationCount++;
            get(XOR(NULL, head->link), index);
        }
        else
        {
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

void destroyList(ListNode **head)
{
    if (NULL != head && NULL != *head)
    {
        ListNode *nextNode = XOR(NULL, (*head)->link);
        destroyList(&nextNode);

        free(*head);
        *head = NULL;
    }
}
