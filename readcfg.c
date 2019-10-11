#include <stdio.h>  /* fopen, printf */
#include <string.h> /* strtok */
#include <stdlib.h> /* atoi */

#define DEFAULT_CONFIG_FILE "config"

struct config_values
{
  int localToggleIntervalMilliseconds;
  int remoteToggleIntervalMillisec;
  int remoteMaxNormalHBGapMillisec;
  int missedToggleCountFailureThreshold;
  int missedAckCountFailureThreshold;
  int shortToggleCountFailureThreshold;
  int longToggleCountFailureThreshold;
  int longAckCountFailureThreshold;
  int longAckMilliseconds;
} config_vals;

void extractValues (char *inStr, char *label, char *val)
{
  char *param;
  const char delim = '=';

  param = inStr;
  strcpy (label, strtok (param, &delim));
  strcpy (val, strtok (NULL, &delim));
  return;
}

void printVals()
{
  printf ("localToggleIntervalMilliseconds %d\n", config_vals.localToggleIntervalMilliseconds);
  printf ("remoteToggleIntervalMillisec %d\n", config_vals.remoteToggleIntervalMillisec);
  printf ("remoteMaxNormalHBGapMillisec %d\n", config_vals.remoteMaxNormalHBGapMillisec);
  printf ("missedToggleCountFailureThreshold %d\n", config_vals.missedToggleCountFailureThreshold);
  printf ("missedAckCountFailureThreshold %d\n", config_vals.missedAckCountFailureThreshold);
  printf ("shortToggleCountFailureThreshold %d\n", config_vals.shortToggleCountFailureThreshold);
  printf ("longToggleCountFailureThreshold %d\n", config_vals.longToggleCountFailureThreshold);
  printf ("longAckCountFailureThreshold %d\n", config_vals.longAckCountFailureThreshold);
  printf ("longAckMilliseconds %d\n", config_vals.longAckMilliseconds);
  return;
}

int main (void)
{
  FILE *fp;
  size_t size = 80;
  char line[80];
  char *pLine = &line[0];
  char **ppLine = &pLine;
  int i;

  if (NULL == (fp = fopen (DEFAULT_CONFIG_FILE, "r")))
  {
    printf ("error opening config file\n");
    return (-1);
  }

  while ((i = getline (&pLine, &size, fp)) != -1)
  {
    char label[40], value[5];
    line[i-1] = '\0';
    if (i > 1)
    {
      extractValues (pLine, &label[0], &value[0]);
      {
        if (strncmp (label, "localToggleIntervalMilliseconds", strlen ("localToggleIntervalMilliseconds")) == 0)
          config_vals.localToggleIntervalMilliseconds = atoi(value);
        if (strncmp (label, "remoteToggleIntervalMillisec", strlen("remoteToggleIntervalMillisec")) == 0)
          config_vals.remoteToggleIntervalMillisec = atoi(value);
        if (strncmp (label, "remoteMaxNormalHBGapMillisec", strlen("remoteMaxNormalHBGapMillisec")) == 0)
          config_vals.remoteMaxNormalHBGapMillisec = atoi(value);
        if (strncmp (label, "missedToggleCountFailureThreshold", strlen("missedToggleCountFailureThreshold")) == 0)
          config_vals.missedToggleCountFailureThreshold = atoi(value);
        if (strncmp (label, "missedAckCountFailureThreshold", strlen("missedAckCountFailureThreshold")) == 0)
          config_vals.missedAckCountFailureThreshold = atoi(value);
        if (strncmp (label, "shortToggleCountFailureThreshold", strlen("shortToggleCountFailureThreshold")) == 0)
          config_vals.shortToggleCountFailureThreshold = atoi(value);
        if (strncmp (label, "longToggleCountFailureThreshold", strlen("longToggleCountFailureThreshold")) == 0)
          config_vals.longToggleCountFailureThreshold = atoi(value);
        if (strncmp (label, "longAckCountFailureThreshold", strlen("longAckCountFailureThreshold")) == 0)
          config_vals.longAckCountFailureThreshold = atoi(value);
        if (strncmp (label, "longAckMilliseconds", strlen("longAckMilliseconds")) == 0)
          config_vals.longAckMilliseconds = atoi(value);
      }
    }
  }
  fclose (fp);
  printVals();
  return (0);
}
