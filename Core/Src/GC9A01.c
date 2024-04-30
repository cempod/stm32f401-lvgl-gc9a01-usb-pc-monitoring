#include "GC9A01.h"

extern SPI_HandleTypeDef hspi1;

void display_Reset(void){
	HAL_GPIO_WritePin(Display_CS_Port, Display_CS_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(Display_Reset_Port, Display_Reset_Pin, GPIO_PIN_RESET);
    HAL_Delay(10);
    HAL_GPIO_WritePin(Display_Reset_Port, Display_Reset_Pin, GPIO_PIN_SET);
    HAL_Delay(10);
}

void display_WriteCommand(uint8_t byte) {
    HAL_GPIO_WritePin(Display_CS_Port, Display_CS_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(Display_DC_Port, Display_DC_Pin, GPIO_PIN_RESET);
    HAL_SPI_Transmit(&hspi1, (uint8_t *) &byte, 1, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(Display_CS_Port, Display_CS_Pin, GPIO_PIN_SET);
}

void display_WriteData(uint8_t buffer) {
    HAL_GPIO_WritePin(Display_CS_Port, Display_CS_Pin, GPIO_PIN_RESET); 
    HAL_GPIO_WritePin(Display_DC_Port, Display_DC_Pin, GPIO_PIN_SET);
    HAL_SPI_Transmit(&hspi1, (uint8_t *) &buffer, 1, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(Display_CS_Port, Display_CS_Pin, GPIO_PIN_SET);
}

/*No comments, only magic*/
void display_Init()	{
	display_Reset();
	display_WriteCommand(0xEF); 		
	display_WriteCommand(0xEB); 		
	display_WriteData(0x14);
	display_WriteCommand(0xFE); 		
	display_WriteCommand(0xEF); 		
	display_WriteCommand(0xEB);
	display_WriteData(0x14);
	display_WriteCommand(0x84);
	display_WriteData(0x40);
	display_WriteCommand(0x85);
	display_WriteData(0xFF);
	display_WriteCommand(0x86);
	display_WriteData(0xFF);
	display_WriteCommand(0x87);
	display_WriteData(0xFF);
	display_WriteCommand(0x88);
	display_WriteData(0x0A);
	display_WriteCommand(0x89);
	display_WriteData(0x21);
	display_WriteCommand(0x8A);
	display_WriteData(0x00);
	display_WriteCommand(0x8B);
	display_WriteData(0x80);
	display_WriteCommand(0x8C);
	display_WriteData(0x01);
	display_WriteCommand(0x8D);
	display_WriteData(0x01);
	display_WriteCommand(0x8E);
	display_WriteData(0xFF);
	display_WriteCommand(0x8F);
	display_WriteData(0xFF);
	display_WriteCommand(0xB6); 	
	display_WriteData(0x00); 		
	display_WriteData(0x20);
	display_WriteCommand(0x36); 	
	display_WriteData(0x08); 		
	display_WriteCommand(0x3A); 	
	display_WriteData(0x05); 			
	display_WriteCommand(0x90); 	
	display_WriteData(0x08);
	display_WriteData(0x08);
	display_WriteData(0x08);
	display_WriteData(0x08);
	display_WriteCommand(0xBD); 	
	display_WriteData(0x06);
	display_WriteCommand(0xBC); 	
	display_WriteData(0x00);
	display_WriteCommand(0xFF); 	
	display_WriteData(0x60);
	display_WriteData(0x01);
	display_WriteData(0x04);
	display_WriteCommand(0xC3); 	
	display_WriteData(0x13);
	display_WriteCommand(0xC4); 	
	display_WriteData(0x13);
	display_WriteCommand(0xC9); 	
	display_WriteData(0x22);
	display_WriteCommand(0xBE); 	
	display_WriteData(0x11);
	display_WriteCommand(0xE1); 	
	display_WriteData(0x10);
	display_WriteData(0x0E);
	display_WriteCommand(0xDF); 	
	display_WriteData(0x21);
	display_WriteData(0x0c);
	display_WriteData(0x02);
	display_WriteCommand(0xF0); 	
	display_WriteData(0x45);
	display_WriteData(0x09);
	display_WriteData(0x08);
	display_WriteData(0x08);
	display_WriteData(0x26);
	display_WriteData(0x2A);
	display_WriteCommand(0xF1); 	
	display_WriteData(0x43);
	display_WriteData(0x70);
	display_WriteData(0x72);
	display_WriteData(0x36);
	display_WriteData(0x37);
	display_WriteData(0x6F);
	display_WriteCommand(0xF2); 	
	display_WriteData(0x45);
	display_WriteData(0x09);
	display_WriteData(0x08);
	display_WriteData(0x08);
	display_WriteData(0x26);
	display_WriteData(0x2A);
	display_WriteCommand(0xF3); 	
	display_WriteData(0x43);
	display_WriteData(0x70);
	display_WriteData(0x72);
	display_WriteData(0x36);
	display_WriteData(0x37);
	display_WriteData(0x6F);
	display_WriteCommand(0xED); 	
	display_WriteData(0x1B);
	display_WriteData(0x0B);
	display_WriteCommand(0xAE); 	
  	display_WriteData(0x77);
	display_WriteCommand(0xCD); 	
	display_WriteData(0x63);
	display_WriteCommand(0x70);
	display_WriteData(0x07);
	display_WriteData(0x07);
	display_WriteData(0x04);
	display_WriteData(0x0E);
	display_WriteData(0x0F);
	display_WriteData(0x09);
	display_WriteData(0x07);
	display_WriteData(0x08);
	display_WriteData(0x03);
	display_WriteCommand(0xE8); 	
	display_WriteData(0x34);
	display_WriteCommand(0x62); 	
	display_WriteData(0x18);
	display_WriteData(0x0D);
	display_WriteData(0x71);
	display_WriteData(0xED);
	display_WriteData(0x70);
	display_WriteData(0x70);
	display_WriteData(0x18);
	display_WriteData(0x0F);
	display_WriteData(0x71);
	display_WriteData(0xEF);
	display_WriteData(0x70);
	display_WriteData(0x70);
	display_WriteCommand(0x63); 	
	display_WriteData(0x18);
	display_WriteData(0x11);
	display_WriteData(0x71);
	display_WriteData(0xF1);
	display_WriteData(0x70);
	display_WriteData(0x70);
	display_WriteData(0x18);
	display_WriteData(0x13);
	display_WriteData(0x71);
	display_WriteData(0xF3);
	display_WriteData(0x70);
	display_WriteData(0x70);
	display_WriteCommand(0x64); 	
	display_WriteData(0x28);
	display_WriteData(0x29);
	display_WriteData(0xF1);
	display_WriteData(0x01);
	display_WriteData(0xF1);
	display_WriteData(0x00);
	display_WriteData(0x07);
	display_WriteCommand(0x66); 	
	display_WriteData(0x3C);
	display_WriteData(0x00);
	display_WriteData(0xCD);
	display_WriteData(0x67);
	display_WriteData(0x45);
	display_WriteData(0x45);
	display_WriteData(0x10);
	display_WriteData(0x00);
	display_WriteData(0x00);
	display_WriteData(0x00);
	display_WriteCommand(0x67); 	
	display_WriteData(0x00);
	display_WriteData(0x3C);
	display_WriteData(0x00);
	display_WriteData(0x00);
	display_WriteData(0x00);
	display_WriteData(0x01);
	display_WriteData(0x54);
	display_WriteData(0x10);
	display_WriteData(0x32);
	display_WriteData(0x98);
	display_WriteCommand(0x74); 	
	display_WriteData(0x10);
	display_WriteData(0x85);
	display_WriteData(0x80);
	display_WriteData(0x00);
	display_WriteData(0x00);
	display_WriteData(0x4E);
	display_WriteData(0x00);
 	display_WriteCommand(0x98); 	
	display_WriteData(0x3e);
	display_WriteData(0x07);
	display_WriteCommand(0x34); 	
	display_WriteCommand(0x21); 	
	display_WriteCommand(0x11); 
	HAL_Delay(120);
	display_WriteCommand(0x29); 	
	HAL_Delay(20);
}

void display_set_window(unsigned char x_start,unsigned char y_start,unsigned char x_end,unsigned char y_end){
	display_WriteCommand(0x2A);    
	display_WriteData(0);		
	display_WriteData(x_start);
	display_WriteData(0);		
	display_WriteData(x_end);
	display_WriteCommand(0x2B);    
	display_WriteData(0);		
	display_WriteData(y_start);
	display_WriteData(0);		
	display_WriteData(y_end);
	display_WriteCommand(0x2C);    
}
static void ConvHL(uint8_t *s, int32_t l){
	uint8_t v;
	while (l > 0) {
		v = *(s+1);
		*(s+1) = *s;
		*s = v;
		s += 2;
		l -= 2;
	}
}
void display_send_buffer(uint16_t w, uint16_t h, uint8_t *s){
	HAL_GPIO_WritePin(Display_CS_Port, Display_CS_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(Display_DC_Port, Display_DC_Pin, GPIO_PIN_SET); 
	ConvHL(s, (int32_t)w*h*2);
	HAL_SPI_Transmit(&hspi1, (uint8_t*)s, w * h *2,100);
}
