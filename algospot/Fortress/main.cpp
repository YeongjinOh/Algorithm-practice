#include <iostream>
#include <cstring>
#include <list>
#include <algorithm>

using namespace std;
int C, n, res;

class Node {
public:
    int x, y, r;
    list<Node*> children;
    Node(int x, int y, int r): x(x), y(y), r(r) { }
    ~Node () {
        for (list<Node *>::iterator iter=children.begin(); iter != children.end(); iter++) {
            delete *iter;
        }
    }
    void insert(Node * newNode) {
        for (list<Node *>::iterator iter=children.begin(); iter != children.end(); iter++) {
            Node * child = *iter;
            int isIncludedInChild = newNode->isIncluded(child);
            if (isIncludedInChild == 1) {
                child->insert(newNode);
                return;
            } else if (isIncludedInChild == -1) {
            // it means that newNode include child
                newNode->children.push_back(child);
            }
        }
        for (list<Node *>::iterator iter = newNode->children.begin(); iter != newNode->children.end(); iter++) {
            children.remove(*iter);
        }

        children.push_back(newNode);
    }
    int isIncluded (Node * parent) {
        int dist = (x-parent->x)*(x-parent->x) + (y-parent->y)*(y-parent->y);
        int rSquare = (r+parent->r) * (r+parent->r);
        if (dist >= rSquare) return 0;
        if (parent->r > r) return 1;
        return -1;
    }
    // return height and calculate maximal result
    int getHeight () {
        if (children.empty()) return 0;
        int max1 = 0, max2 = 0;
        for (list<Node *>::iterator iter=children.begin(); iter != children.end(); iter++) {
            int childHeight = (*iter)->getHeight() + 1;
            if (max1 <= childHeight) {
                max2 = max1;
                max1 = childHeight;
            } else if (max2 < childHeight) {
                max2 = childHeight;
            }
        }
        res = max<int> (res, max1 + max2);
        return max1;
    }
};

int main() {
    cin >> C;
    while (C--) {
        cin >> n;
        int x, y, r;
        cin >> x >> y >> r;
        Node * root = new Node(x, y, r);
        for (int i=1; i<n; i++) {
            cin >> x >> y >> r;
            root->insert(new Node(x, y, r));
        }
        res = 0;
        root->getHeight();
        cout << res << endl;
        delete root;
    }
}
