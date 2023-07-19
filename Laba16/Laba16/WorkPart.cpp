void select(int *D, int N)
{
    int max = 0, temp;
    for (int i = 0; i < N; i++)
    {
        max = i;
       
        for (int j = i + 1; j < N; j++)
            max = (D[j] > D[max]) ? j : max;
       
        if (i != max)
        {
            temp = D[i];
            D[i] = D[max];
            D[max] = temp;
        }
    }
}

void qsortRecursive(int* mas, int size) {
    int i = 0;
    int j = size - 1;

    int mid = mas[size / 2];

    do {

        while (mas[i] > mid) {
            i++;
        }

        while (mas[j] < mid) {
            j--;
        }

        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    if (j > 0) {
        qsortRecursive(mas, j + 1);
    }
    if (i < size) {

        qsortRecursive(&mas[i], size - i);
    }
}