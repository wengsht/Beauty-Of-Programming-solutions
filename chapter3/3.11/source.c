int bisearch(char **arr, int b, int e, char *v)
{
    int minIndex = b, maxIndex = e, midIndex;
    int res = -1;

    while(minIndex <= maxIndex)
    {
        midIndex = minIndex + (maxIndex - minIndex) / 2;
        int tmp = strcmp(arr[midIndex], v);

        if(tmp <= 0)
        {
            if(tmp == 0)
                res = midIndex;
            minIndex = midIndex + 1;
        }
        else
            maxIndex = midIndex - 1;
    }
    return res;
}
