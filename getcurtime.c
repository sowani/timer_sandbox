#include <time.h>
#include <stdio.h>

int main (void)
{
  time_t currTime;
  currTime = time(NULL);
  printf ("%ld\n", currTime);
  return (0);
}
