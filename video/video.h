/**
 * @file video.h
 *
 * Basic video functions for the kernel.
 *
 * @note These functions use raw access to MMIO video memory.
 *
 * @author Jeff Cooper <jeff@thejeffcooper.com>
 * @date 2014-05-29
 */

#ifndef _VIDEO_VIDEO_H_
#define _VIDEO_VIDEO_H_

#define CRTC_INDEX_REG  0x3D4 /**< CRTC Index Register */
#define CRTC_DATA_REG   0x3D5 /**< CRTC Data Register */
#define CRTC_CURSOR_LSB 0x0F  /**< Index of least-significant bit of CRTC cursor */
#define CRTC_CURSOR_MSB 0x0E  /**< Index of most-significant bit of CRTC cursor */

#define CONSOLE_WIDTH  80 /**< The width of the console */
#define CONSOLE_HEIGHT 25 /**< The height of the console */

/**
 * A VGA color code
 */
typedef enum vga_color 
{
  COLOR_BLACK = 0,          /**< Black */
  COLOR_BLUE = 1,           /**< Blue */
  COLOR_GREEN = 2,          /**< Green */
  COLOR_CYAN = 3,           /**< Cyan */
  COLOR_RED = 4,            /**< Red */
  COLOR_MAGENTA = 5,        /**< Magenta */
  COLOR_BROWN = 6,          /**< Brown */
  COLOR_LIGHT_GREY = 7,     /**< Light Grey */
  COLOR_DARK_GREY = 8,      /**< Dark Grey */
  COLOR_LIGHT_BLUE = 9,     /**< Light Blue */
  COLOR_LIGHT_GREEN = 10,   /**< Light Green */
  COLOR_LIGHT_CYAN = 11,    /**< Light Cyan (!?) */
  COLOR_LIGHT_RED = 12,     /**< Light Red */
  COLOR_LIGHT_MAGENTA = 13, /**< Light Magenta */
  COLOR_LIGHT_BROWN = 14,   /**< Light Brown */
  COLOR_WHITE = 15,         /**< White */
} vga_color_t;


/**
 * Set the cursor position.
 *
 * @param[in] x The x position of the cursor
 * @param[in] y The y position of the cursor
 *
 * @return void.
 */
void set_cursor(unsigned x, unsigned y);

/**
 * Get the cursor position.
 * 
 * @param[out] x Where to store the x position.
 * @param[out] y Where to store the y position.
 *
 * @return void.
 */
void get_cursor(unsigned* x, unsigned* y);


/**
 * Set the color for new video output.
 *
 * @param[in] fg Foreground color.
 * @param[in] bg Background color.
 *
 * @return void.
 */
void set_color(vga_color_t fg, vga_color_t bg);

/**
 * Put a character to the screen.
 *
 * @param[in] c The character
 * 
 * @return void
 */
void put_char(char c);

/**
 * Scroll the console.
 *
 * @return void.
 */
void scroll_console();

/**
 * Clear the console.
 *
 * @return void.
 */
void clear_console();


/**
 * Initialize the video system with some reasonable settings.
 *
 * @return void.
 */
void init_video();
#endif /* _VIDEO_VIDEO_H_ */
