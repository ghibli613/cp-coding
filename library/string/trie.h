const int MAX = 26;

struct Node
{
    Node* child[MAX];
    int count;

    Node()
    {
        count = 0;
        fill(child, child + MAX, nullptr);
    }
};

void add(Node* root, string s)
{
    Node* cur = root;
    for(char ch : s)
    {
        int c = ch - 'a';
        if(cur->child[c] == nullptr)
            cur->child[c] = new Node();
        cur = cur->child[c];
    }
    cur->count++;
}

bool search(Node* root, string s)
{
    Node* cur = root;
    for(char ch : s)
    {
        int c = ch - 'a';
        if(cur->child[c] == nullptr)
            return false;
        cur = cur->child[c];
    }
    return cur->count > 0;
}

bool isEmpty(Node& temp)
{
    for(int i = 0; i < MAX; i++)
        if(temp.child[i] != nullptr)
            return false;
    return true;
}

bool remove(Node* root, string s, int depth = 0)
{
    if(!root) return false;
    if(depth == s.length())
    {
        if(root->count > 0)
        {
            root->count--;
            return true;
        }
        return false;
    }

    int c = s[depth] - 'a';
    if(!root->child[c])
        return false;
    bool isRemoved = remove(root->child[c], s, depth + 1);
    Node& temp = *(root->child[c]);
    if(isRemoved && temp.count == 0 && isEmpty(temp))
    {
        delete root->child[c];
        root->child[c] = nullptr;
    }
    return isRemoved;
}

void test()
{
    Node* root = new Node();
    add(root, "bigo");
    add(root, "complete");
    add(root, "algo");
    add(root, "algorithm");
    cout << search(root, "competitive") << "\n";
    cout << search(root, "big") << "\n";
    cout << search(root, "algorithm") << "\n";
    cout << remove(root, "algorithm") << "\n";
    cout << remove(root, "comp") << "\n";
    cout << remove(root, "competitive") << "\n";
}