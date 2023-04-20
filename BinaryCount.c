#include<stdio.h>
#include<stdlib.h>
void display (int a[], int l, int r)
{
  for (int j = 0; j < l; j++)
    printf ("    ");
  for (int i = l; i <= r; i++)
    printf ("%d  ", a[i]);
  printf ("\n");
}

int binarySearch (int a[], int n, int x)
{
  int l, r, mid, c = 1;
  l = 0;
  r = n - 1;
  while (l <= r)
    {
      printf ("Searching array:");
      display (a, l, r);
      mid = (l + r) / 2;
      if (a[mid] == x)
	{
	  printf ("For %d iterations  ", c);
	  return mid;
	}
      if (a[mid] < x)
	l = mid + 1;
      else if (a[mid] > x)
	r = mid - 1;
      c++;
    }
  printf ("completed %d iterations but not found.", c);
  return -1;
}

int main ()
{
  int n, *a, j, i, k;
  printf ("Enter count of elements:");
  scanf ("%d", &n);
  a = (int *) malloc (n * sizeof (int));
  if (a == NULL)
    {
      printf ("Memory allocation error");
      return 1;
    }
  printf ("Enter elements\n");
  for (j = 0; j < n; j++)
    scanf ("%d", a[j]);
  i				//nt a[]={-46,-23,-11,5,8,11,16,23,37,56,88,97,0};
    printf ("Enter element to be found:");
  scanf ("%d", &k);
  i = binarySearch (a, n, k);
  if (i != -1)
    {
      printf ("%d found at %d index\n", k, i);
    }
}
