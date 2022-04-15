#include "node.h"
#include <stdio.h>

int main()
{
    int32_t rc = OK;

    ListNode *head = NULL;

    rc = allocHead(&head);

    printf("rc=[%d]\n", rc);

    if (OK == rc)
    {
        add(5, add(4, add(3, add(2, add(1, head)))));

        ListNode *thirdPosition = get(head, 3);

        if (NULL != thirdPosition)
        {
            printf("NOT NULL\n");
            int32_t id = -1;
            getUniqueId(thirdPosition, &id);

            printf("Unique ID: %d\n", id);
        }
    }

    return OK;
}
