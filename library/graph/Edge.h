struct Edge
{
    int u, v, w;
    Edge(int u = 0, int v = 0, int w = 0)
        : u(u), v(v), w(w) {}
    bool operator<(const Edge& other) const
    {
        return w < other.w;
    }
};