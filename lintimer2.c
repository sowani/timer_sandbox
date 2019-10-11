#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#define CLOCKID CLOCK_REALTIME

int main (void)
{
  timer_t timerid;
  struct itimerspec its;

  if (timer_create (CLOCKID, NULL, &timerid) == -1)
    return (-1);

  its.it_value.tv_sec = 1;
  its.it_value.tv_nsec = 0;
  its.it_interval.tv_sec = 1;
  its.it_interval.tv_nsec = 0;
  if (timer_settime (timerid, 0, &its, NULL) == -1)
    return (-1);
  return (0);
}
