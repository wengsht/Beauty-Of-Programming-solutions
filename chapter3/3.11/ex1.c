/*
 * 实际上用链表异步走可以更高效
 */
LinkedList *IsCyclicLinkedList(LinkedList * pHead)
{
    LinkedList * pCur = pHead;
    LinkedList * pStart = pHead;

    while(pCur != NULL)
    {
        pCur = pCur->next;
        if(pStart->next == NULL) return NULL;
        else pStart = pStart->next->next;

        if(pStart == NULL || pCur == NULL) return NULL;
        if(pStart == pCur) return pStart;
    }
    return NULL;
}
