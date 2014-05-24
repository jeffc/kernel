/**
 * @file main.c
 *
 * Main entry point for the kernel.
 *
 * @author Jeff Cooper <jeff@thejeffcooper.com>
 * @date 2014-05-24
 */

void kernel_main()
{
  char* video = (char*)0xB8000; // start of video memory
  for(int x = 0; x < 80; x++)
  {
    for(int y = 0; y < 25; y++)
    {
      video[(80*y + x)*2] = ' ';
      video[(80*y + x)*2 + 1] = 0x27;
    }
  }

  while(1);
}
