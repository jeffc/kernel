/**
 * @file raw_console.c
 *
 * Definitions for raw console output.
 *
 * @author Jeff Cooper <jeff@thejeffcooper.com>
 * @date 2014-05-30
 */

#include <video/raw_console.h>
#include <video/video.h>

#include <stddef.h>

void put_string(char* s)
{
  if (s == NULL)
  {
    return;
  }
  while(*s != '\0')
  {
    put_char(*s);
    s++;
  }
}
