/**
 * @file main.c
 *
 * Main entry point for the kernel.
 *
 * @author Jeff Cooper <jeff@thejeffcooper.com>
 * @date 2014-05-24
 */

#include <video/video.h>
#include <util/debug.h>

/**
 * The main kernel entry point 
 */
void kernel_main()
{
  init_video();

  //for(int x = 0; x < 25; x++)
  //{
  //  for(int c = 0; c < CONSOLE_WIDTH; c++)
  //  {
  //    put_char('A');
  //  }
  //}

  for(int c = 0; c < CONSOLE_WIDTH; c++)
  {
    put_char('B');
  }



  while(1);
}
