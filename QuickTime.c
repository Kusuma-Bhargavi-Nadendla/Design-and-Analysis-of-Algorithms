#include<stdio.h>
#include<stdlib.h>
#include <time.h>
int r = 1;
clock_t clock_for_swap, t;
double time_for_swap;
void
display (int a[])
{
  int i = 0;
  printf ("swap-%d :", r++);
  while (a[i])
    {
      printf ("%d  ", a[i]);
      i++;
    }
  printf ("\n");
}

void swap (int *a, int *b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition (int a[], int l, int r)
{
  int i, j, pivot;
  i = l;
  j = r;
  pivot = l;
  while (i < j)
    {
      while (a[i] <= a[pivot])
	i++;
      while (a[j] > a[pivot])
	j--;
      if (i < j)
	swap (&a[i], &a[j]);
    }
  swap (&a[pivot], &a[j]);
  clock_for_swap = clock () - t;
  time_for_swap = ((double) clock_for_swap) / CLOCKS_PER_SEC;
  printf ("placed-%d at %d in time %f\t", a[j], j, time_for_swap);
  display (a);
  return j;
}

void quicksort (int a[], int l, int r)
{
  int j;
  if (l < r)
    {
      j = partition (a, l, r);
      quicksort (a, l, j - 1);
      quicksort (a, j + 1, r);
    }
}

int main ()
{
  int n, *a, i;
  printf ("Enter count of elements:");
  scanf ("%d", &n);
  a = (int *) malloc (n * sizeof (int));
  if (a == NULL)
    {
      printf ("Memory allocation error");
      return 1;
    }
  printf ("Enter elements\n");
  for (i = 0; i < n; i++)
    scanf ("%d", &a[i]);
  double time_taken;
  clock_for_swap = t = clock ();;
  quicksort (a, 0, n - 1);
  t = clock () - t;
  time_taken = ((double) t) / CLOCKS_PER_SEC;
  printf ("Total Time taken for sorting :%f", time_taken);
}
