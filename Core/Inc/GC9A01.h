#include "main.h"

#define Display_CS_Port CS_GPIO_Port
#define Display_CS_Pin CS_Pin

#define Display_DC_Port DC_GPIO_Port
#define Display_DC_Pin DC_Pin

#define Display_Reset_Port RST_GPIO_Port
#define Display_Reset_Pin RST_Pin

void display_Reset(void);
void display_WriteCommand(uint8_t byte);
void display_WriteData(uint8_t buffer);
void display_Init();
void display_set_window(unsigned char x_start,unsigned char y_start,unsigned char x_end,unsigned char y_end);
void display_send_buffer(uint16_t w, uint16_t h, uint8_t *s);
