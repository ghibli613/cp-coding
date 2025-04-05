double max_f(double left, double right)
{
    int N_ITER = 100;

    for (int i = 0; i < N_ITER; i++)
    {
        double x1 = left + (right - left) / 3.0;
        double x2 = right - (right - left) / 3.0;

        if (f(x1) > f(x2))
            right = x2;
        else
            left = x1;
    }
    return f(left);
}