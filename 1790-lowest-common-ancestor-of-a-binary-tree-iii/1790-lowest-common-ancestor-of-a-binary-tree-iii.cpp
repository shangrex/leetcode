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

    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node *r1 = p, *r2 = q;
        while(r1 != r2){
            r1 = (r1 == NULL) ? q : r1->parent;
            r2 = (r2 == NULL) ? p : r2->parent;
        }

        return r1;
    }
    */
    int getHeight(Node *r){
        int height = 0;
        while(r){
            height++;
            r = r->parent;
        }
        return height;
    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
        // approach 2.

        int h1 = getHeight(p);
        int h2 = getHeight(q);
        
        
        // let h2 always shorter than h1
        if(h1 < h2){
            swap(h1, h2);
            swap(p, q);
        }

        // up the h1
        for(int i = 0; i < h1-h2; i++){
            p = p->parent;
        }

        while(p != q){
            p = p->parent;
            q = q->parent;
        }

        return p;
    }
};