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

void
Merge (int a[], int l, int mid, int r)
{
  int n1 = mid - l + 1;
  int n2 = r - mid;
  int L[n1], R[n2];
  int i, j, k;
  for (i = 0; i < n1; i++)
    L[i] = a[l + i];
  for (j = 0; j < n2; j++)
    R[j] = a[mid + 1 + j];
  i = 0;
  j = 0;
  k = l;
  while (i < n1 && j < n2)
    {
      a[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }
  while (i < n1)
    a[k++] = L[i++];
  while (j < n2)
    a[k++] = R[j++];
}

void mergesort (int a[], int l, int r)
{
  int mid;
  if (l < r)
    {
      mid = l + (r - l) / 2;
      mergesort (a, l, mid);
      mergesort (a, mid + 1, r);
      Merge (a, l, mid, r);
      clock_for_swap = clock () - t;
      time_for_swap = ((double) clock_for_swap) / CLOCKS_PER_SEC;
      printf ("sorted from %d to %d in time %f\t", l, r, time_for_swap);
      display (a);
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
    scanf ("%d",&a[i]);
  double time_taken;
  t = clock ();
  mergesort (a, 0, n - 1);
  t = clock () - t;
  time_taken = ((double) t) / CLOCKS_PER_SEC;
  printf ("Total Time taken for sorting :%f", time_taken);

}
