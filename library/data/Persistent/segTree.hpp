struct Node
{
    int value;
    Node *left, *right;

    Node(int _value = INF)
        : value(_value), left(nullptr), right(nullptr) {}
    
    Node(Node* _left, Node* _right)
        : value(INF), left(_left), right(_right)
    {
        if(left)
            value = min(value, left->value);
        if(right)
            value = min(value, right->value);
    }
};

vector<Node*> roots;

Node* build(const vector<int>& arr, int left, int right)
{
    if(left == right)
        return new Node(arr[left]);

    int mid = (left + right) / 2;
    return new Node(
        build(arr, left, mid),
        build(arr, mid + 1, right)
    );
}

Node* update(Node* node, int pos, int value, int left, int right)
{
    if(left == right)
        return new Node(value);
    
    int mid = (left + right) / 2;
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

int query(Node* node, int fr, int to, int left, int right)
{
    if(fr <= left && right <= to)
        return node->value;
    
    if(fr < right || to < left)
        return INF;
    
    int mid = (left + right) / 2;
    return min(
        query(node->left, fr, to, left, mid),
        query(node->right, fr, to, mif + 1, right)
    );
}