#include "IntervalTree.hpp"

// ...existing code...

// not completed yet


IntervalTree::IntervalTree() {
    root = nullptr;
}

void IntervalTree::insert(int low, int high) {
    root = insert(root, low, high);
}

IntervalTree::Node* IntervalTree::insert(Node* node, int low, int high) {
    if (node == nullptr)
        return new Node(low, high);

    if (low < node->low)
        node->left = insert(node->left, low, high);
    else
        node->right = insert(node->right, low, high);

    node->max = max(node->max, high);
    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && low < node->left->low)
        return rightRotate(node);

    if (balance < -1 && low > node->right->low)
        return leftRotate(node);

    if (balance > 1 && low > node->left->low) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && low < node->right->low) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

bool IntervalTree::search(int low, int high) {
    return search(root, low, high);
}

bool IntervalTree::search(Node* node, int low, int high) {
    if (node == nullptr)
        return false;

    if (doOverlap(node->low, node->high, low, high))
        return true;

    if (node->left != nullptr && node->left->max >= low)
        return search(node->left, low, high);

    return search(node->right, low, high);
}

void IntervalTree::remove(int low, int high) {
    root = remove(root, low, high);
}

IntervalTree::Node* IntervalTree::remove(Node* node, int low, int high) {
    if (node == nullptr)
        return node;

    if (low < node->low)
        node->left = remove(node->left, low, high);
    else if (low > node->low)
        node->right = remove(node->right, low, high);
    else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = minValueNode(node->right);
        node->low = temp->low;
        node->high = temp->high;
        node->right = remove(node->right, temp->low, temp->high);
    }

    if (node == nullptr)
        return node;

    node->max = max(node->high, max(node->left ? node->left->max : INT_MIN, node->right ? node->right->max : INT_MIN));
    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0)
        return rightRotate(node);

    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0)
        return leftRotate(node);

    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

IntervalTree::Node* IntervalTree::minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left != nullptr)
        current = current->left;
    return current;
}

bool IntervalTree::doOverlap(int low1, int high1, int low2, int high2) {
    return (low1 <= high2 && low2 <= high1);
}

int IntervalTree::height(Node* node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int IntervalTree::getBalance(Node* node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}

IntervalTree::Node* IntervalTree::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    y->max = max(y->high, max(y->left ? y->left->max : INT_MIN, y->right ? y->right->max : INT_MIN));
    x->max = max(x->high, max(x->left ? x->left->max : INT_MIN, x->right ? x->right->max : INT_MIN));

    return x;
}

IntervalTree::Node* IntervalTree::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    x->max = max(x->high, max(x->left ? x->left->max : INT_MIN, x->right ? x->right->max : INT_MIN));
    y->max = max(y->high, max(y->left ? y->left->max : INT_MIN, y->right ? y->right->max : INT_MIN));

    return y;
}
