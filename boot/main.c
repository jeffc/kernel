/**
 * @file main.c
 *
 * Main entry point for the kernel.
 *
 * @author Jeff Cooper <jeff@thejeffcooper.com>
 * @date 2014-05-24
 */

#include <video/video.h>
#include <video/raw_console.h>
#include <util/debug.h>

/**
 * The main kernel entry point 
 */
void kernel_main()
{
  init_video();

  put_string("Hello, Jeff!\n");

  while(1);
}
