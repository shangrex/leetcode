/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    /*
    Approach 1. use add to store all the parent, and triverse the other tree
    to see the first intersections

    time complexity: O(h), h is the deeper node
    space complexity: O(h)

    Approach 2. find the deeper node. and escalate to the same level

    Approach 3. find the intersection of two linked list
                -> 4
    1 -> 2 -> 3
                -> 6 -> 7
    */
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node *r1 = p, *r2 = q;
        while(r1 != r2){
            r1 = (r1 == NULL) ? q : r1->parent;
            r2 = (r2 == NULL) ? p : r2->parent;
        }

        return r1;
    }
};