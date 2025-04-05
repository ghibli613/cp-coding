void convexHull(Polygon& pts)
{
    pivot = pts[0];
    for(int i = 1; i < (int)pts.size(); i++)
        if(cmp(pivot.y, pts[i].y) > 0 || (cmp(pivot.y, pts[i].y) == 0 && cmp(pivot.x, pts[i].x) > 0))
            pivot = pts[i];
    
    sort(pts.begin(), pts.end(), compare);
    // remove duplicate points
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    if(pts.size() < 3) return;

    int n = 0;
    for(int i = 0; i < (int)pts.size(); i++)
    {
        while(n > 1 && ccw(pts[n - 2], pts[n - 1], pts[i]) <= 0) n--;
        pts[n++] = pts[i];
    }
    pts.resize(n);
}