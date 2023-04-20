#include<stdio.h>
#include<stdlib.h>
int a[30];
void
MaxMin (int i, int j, int *max, int *min)
{
  int mid;
  int max1, min1;
  if (i == j)
    {
      *max = *min = a[i];
    }
  else if ((i + 1) == j)
    {
      if (a[i] < a[j])
	{
	  *min = a[i];
	  *max = a[j];
	}
      else
	{
	  *min = a[j];
	  *max = a[i];
	}
    }
  else
    {
      mid = (i + j) / 2;
      MaxMin (i, mid, max, min);
      MaxMin (mid + 1, j, &max1, &min1);
      if ((*max) < max1)
	*max = max1;
      if ((*min) > min1)
	*min = min1;
    }
}

int
main ()
{
  int max, min, n, i;
  printf ("Enter n:");
  scanf ("%d", &n);
  printf ("Enter elements\n");
  for (i = 0; i < n; i++)
    scanf ("%d", &a[i]);
  MaxMin (0, n - 1, &max, &min);
  printf ("Maximum-%d\nMinimum-%d", max, min);
}

