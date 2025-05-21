struct Node
{
    int value;
    Node *left, *right;
    
    Node(int _value = 0)
        : value(_value), left(nullptr), right(nullptr) {}
    
    Node(Node* _left, Node * _right)
        : value(0), left(_left), right(_right) {}
};

vector<Node*> roots;
int n;

Node* update(Node* node, int pos, int value, int left, int right)
{
    if(left == right)
        return new Node(value);
    
    int mid = (left + right) / 2;
    Node* newNode;
    if(pos > mid)
        return new Node(
            node->left,
            update(node->right, pos, value, mid + 1, right)
        );
    
    return new Node(
        update(node->left, pos, value, left, mid),
        node->right
    );
}

int query(Node* node, int pos, int left, int right)
{
    if(left == right)
        return node->value;

    int mid = (left + right) / 2;
    if(pos > mid)
        return query(node->right, pos, mid + 1, right);
    return query(node->left, pos, left, mid);
}