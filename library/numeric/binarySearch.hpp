int binarySearch(int a[], int left, int right, int x)
{
    int res = right;
    while(left < right)
    {
        int mid = left + (right - left) / 2;
        if(a[mid] >= x)
        {
            res = mid;
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return res;
}