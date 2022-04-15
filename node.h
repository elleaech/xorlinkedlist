#include <stdlib.h>
#include <inttypes.h>

#define OK 0
#define NOT_OK -1
#define HEAD_ID 0

typedef struct node_ ListNode;

int32_t allocHead(ListNode **head);
void destroyList(ListNode **head);

int32_t getUniqueId(ListNode *node, int32_t *id);
ListNode *add(int32_t unique_id, ListNode *previous);
ListNode *get(ListNode *head, int32_t index);
