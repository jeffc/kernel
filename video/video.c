/**
 * @file video.c
 *
 * Definitions for console video functions.
 *
 * @author Jeff Cooper <jeff@thejeffcooper.com>
 * @date 2014-05-29
 */

#include <util/asm.h>
#include <util/debug.h>
#include <video/video.h>

#include <stdint.h>

/**
 * The current color for puting characters to the screen.
 */
static char current_color;

/**
 * Video memory, as a pointer.
 */
static char* vmem = (char*)0xB8000; 

void set_cursor(unsigned x, unsigned y)
{
  x &= 0xFF; /* we can only store a single byte in each register */
  y &= 0xFF;

  /* give up if we're out of bounds */
  if(x >= CONSOLE_WIDTH || y >= CONSOLE_HEIGHT)
    return;

  unsigned cursor_bits = ((y*CONSOLE_WIDTH) + x);

  outb(CRTC_INDEX_REG, CRTC_CURSOR_LSB);
  outb(CRTC_DATA_REG, cursor_bits & 0xFF);
  outb(CRTC_INDEX_REG, CRTC_CURSOR_MSB);

  /* figure out if the cursor is hidden */
  uint8_t hidden = inb(CRTC_DATA_REG) & 0x80;
  outb(CRTC_DATA_REG, ((cursor_bits >> 8) | hidden) & 0xFF);
}

void get_cursor(unsigned* x, unsigned* y)
{
  uint16_t cursor_bits;

  outb(CRTC_INDEX_REG, CRTC_CURSOR_LSB);
  cursor_bits = inb(CRTC_DATA_REG);

  outb(CRTC_INDEX_REG, CRTC_CURSOR_MSB);
  cursor_bits |= (inb(CRTC_DATA_REG) << 8);
  
  /* chop out the hidden bit */
  cursor_bits &= 0x7FFF;

  *x = cursor_bits % CONSOLE_WIDTH;
  *y = cursor_bits / CONSOLE_WIDTH;
}

void set_color(vga_color_t fg, vga_color_t bg)
{
  current_color = fg | (bg << 4);
}


/**
 * Helper function for put_char
 *
 * @param[in] x The x position
 * @param[in] y The y position
 * @param[in] color The color
 * @param[in] c The character
 *
 * @return void.
 */
void put_char_at(unsigned x, unsigned y, unsigned color, char c)
{
  vmem[(y * CONSOLE_WIDTH + x) * 2] = c;
  vmem[(y * CONSOLE_WIDTH + x) * 2 + 1] = color;
}

/**
 * Get character at a position.
 *
 * @param[in] x The x position.
 * @param[in] y The y position.
 *
 * @return The character.
 */
char get_char_at_pos(unsigned x, unsigned y)
{
  return vmem[(y * CONSOLE_WIDTH + x) * 2];
}

/**
 * Get color at a position.
 *
 * @param[in] x The x position.
 * @param[in] y The y position.
 *
 * @return The color.
 */
char get_color_at_pos(unsigned x, unsigned y)
{
  return vmem[(y * CONSOLE_WIDTH + x) * 2 + 1];
}

void put_char(char c)
{
  unsigned row, col;
  get_cursor(&col, &row);

  switch(c)
  {
    case '\b':
    {
      if(col > 0)
      {
        col--;
        put_char_at(col, row, current_color, ' ');
      }
      break;
    }

    case '\r':
    {
      col = 0;
      break;
    }

    case '\n':
    {
      if(row == CONSOLE_HEIGHT - 1)
      {
        scroll_console();
      }
      else
      {
        row++;
      }
      col = 0;
      break;
    }

    default:
    {
      if(col == CONSOLE_WIDTH-1)
      {
        put_char('\n');
        get_cursor(&col, &row);
      }
      else
      {
        col++;
      }
      put_char_at(col-1, row, current_color, c);
      break;
    }
  }

  set_cursor(col, row);
}

void clear_console()
{
  for(int y = 0; y < CONSOLE_HEIGHT; y++)
  {
    for(int x = 0; x < CONSOLE_WIDTH; x++)
    {
      put_char_at(x, y, current_color, ' ');
    }
  }
}
void scroll_console()
{
  for(int y = 0; y < CONSOLE_HEIGHT - 1; y++)
  {
    for(int x = 0; x < CONSOLE_WIDTH; x++)
    {
      char c = get_char_at_pos(x, y);
      char col = get_color_at_pos(x, y);
      put_char_at(x, y+1, col, c);
    }
  }

  for(int x = 0; x < CONSOLE_WIDTH; x++)
  {
    put_char_at(x, CONSOLE_HEIGHT-1, current_color, ' ');
  }
}

void init_video()
{
  set_color(COLOR_WHITE, COLOR_BLACK);
  clear_console();
  set_cursor(0,0);
}

