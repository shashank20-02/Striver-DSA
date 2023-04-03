// bool hasCycle(ListNode *head)
// {
//     ListNode *first = head, *second = head;
//     while (first->next != NULL && second->next->next != NULL)
//     {
//         first = first->next;
//         second = second->next->next;
//         if (first == second)
//             return true;
//     }
//     return false;
// }