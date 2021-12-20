//https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1#


//Approach - We will populate in reverse order i.e first call the right subtree, save the pointer to right subtree and then set this pointer to next of previous pointer

// Complete solution:

// Maintain a static nextsuccessor pointer that will keep the address of next inorder succesor.
// Call the right subtree first.
// Save the next of root at nextsuccessor
// Then save nextsuccessor to root
// Then call the left subtree.


class Solution
{
public:
    void populateNextRecur(Node *p, Node **next_ref)
    {
        if (p)
        {

            populateNextRecur(p->right, next_ref);

            p->next = *next_ref;

            *next_ref = p;

            populateNextRecur(p->left, next_ref);
        }
    }

    void populateNext(Node *root)
    {

        Node *next = NULL;

        populateNextRecur(root, &next);
    }
};
