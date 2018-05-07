/* Function to get the middle of the linked list*/
void printMiddle(struct Node *head)
{
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;
 
    if (head!=NULL)
    {
        while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
        }
        printf("The middle element is [%d]\n\n", slow_ptr->data);
    }
}






/* deletes alternate nodes of a list starting with head */
void deleteAlt(struct Node *head)
{
    if (head == NULL)
        return;
 
    /* Initialize prev and node to be deleted */
    struct Node *prev = head;
    struct Node *node = head->next;
 
    while (prev != NULL && node != NULL)
    {
        /* Change next link of previous node */
        prev->next = node->next;
 
        /* Free memory */
        free(node);
 
        /* Update prev and node */
        prev = prev->next;
        if (prev != NULL)
            node = prev->next;
    }
}






/* Counts the no. of occurences of a node
   (search_for) in a linked list (head)*/
int getCount(struct Node* head)
{
    // Base case
    if (head == NULL)
        return 0;
 
    // count is 1 + count of remaining list
    return 1 + getCount(head->next);
}




/* Function to remove duplicates from a
   unsorted linked list */
void removeDuplicates(struct Node *start)
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;
 
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
 
        /* Compare the picked element with rest
           of the elements */
        while (ptr2->next != NULL)
        {
            /* If duplicate then delete it */
            if (ptr1->data == ptr2->next->data)
            {
                /* sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}




/* Function to get union of two linked lists head1 and head2 */
struct Node *getUnion(struct Node *head1, struct Node *head2)
{
    struct Node *result = NULL;
    struct Node *t1 = head1, *t2 = head2;
 
    // Insert all elements of list1 to the result list
    while (t1 != NULL)
    {
        push(&result, t1->data);
        t1 = t1->next;
    }
 
    // Insert those elements of list2 which are not
    // present in result list
    while (t2 != NULL)
    {
        if (!isPresent(result, t2->data))
            push(&result, t2->data);
        t2 = t2->next;
    }
 
    return result;
}





 
/* Function to get intersection of two linked lists
  head1 and head2 */
struct Node *getIntersection(struct Node *head1, 
                              struct Node *head2)
{
    struct Node *result = NULL;
    struct Node *t1 = head1;
 
    // Traverse list1 and search each element of it in
    // list2. If the element is present in list 2, then
    // insert the element to result
    while (t1 != NULL)
    {
        if (isPresent(head2, t1->data))
            push (&result, t1->data);
        t1 = t1->next;
    }
 
    return result;
}






/* Takes two lists sorted in increasing order, and splices
   their nodes together to make one big sorted list which
   is returned.  */
struct Node* SortedMerge(struct Node* a, struct Node* b)
{
    /* a dummy first node to hang the result on */
    struct Node dummy;
 
    /* tail points to the last result node  */
    struct Node* tail = &dummy;
 
    /* so tail->next is the place to add new nodes
      to the result. */
    dummy.next = NULL;
    while (1)
    {
        if (a == NULL)
        {
            /* if either list runs out, use the
               other list */
            tail->next = b;
            break;
        }
        else if (b == NULL)
        {
            tail->next = a;
            break;
        }
        if (a->data <= b->data)
            MoveNode(&(tail->next), &a);
        else
            MoveNode(&(tail->next), &b);
 
        tail = tail->next;
    }
    return(dummy.next);
}