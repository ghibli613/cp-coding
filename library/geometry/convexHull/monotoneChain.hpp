void convexHull(Polygon &pts)
{
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());

    Polygon up, down;
    int n = 0, m = 0;
    for (int i = 0; i < (int)pts.size(); i++)
    {
        while (up.size() > 1 && ccw(up[up.size() - 2], up[up.size() - 1], pts[i]) >= 0)
            up.pop_back();
        up.push_back(pts[i]);

        while (down.size() > 1 && ccw(down[down.size() - 2], down[down.size() - 1], pts[i]) <= 0)
            down.pop_back();
        down.push_back(pts[i]);
    }
    pts = down;
    for (int i = up.size() - 2; i > 0; i--)
        pts.push_back(up[i]);
}