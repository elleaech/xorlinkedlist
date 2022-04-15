#include "node.h"

struct node_
{
    int32_t unique_id;
    struct node_ *next;
    struct node_ *previous;
};

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
            (*head)->previous = NULL;
            (*head)->next = NULL;

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
add(int32_t unique_id, ListNode *previous)
{
    ListNode *newNode = malloc(sizeof(ListNode));

    if (NULL != newNode)
    {
        newNode->next = NULL;
        newNode->previous = previous;
        newNode->unique_id = unique_id;

        previous->next = newNode;
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
            get(head->next, index);
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
        ListNode *nextNode = (*head)->next;
        destroyList(&nextNode);

        free(*head);
        *head = NULL;
    }
}
