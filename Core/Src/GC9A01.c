#include "GC9A01.h"

extern SPI_HandleTypeDef hspi1;

void display_Reset(void) {
    // CS = High (not selected)
    HAL_GPIO_WritePin(Display_CS_Port, Display_CS_Pin, GPIO_PIN_SET);

    // Reset the OLED
    HAL_GPIO_WritePin(Display_Reset_Port, Display_Reset_Pin, GPIO_PIN_RESET);
    HAL_Delay(10);
    HAL_GPIO_WritePin(Display_Reset_Port, Display_Reset_Pin, GPIO_PIN_SET);
    HAL_Delay(10);
}

// Send a byte to the command register
void display_WriteCommand(uint8_t byte) {
    HAL_GPIO_WritePin(Display_CS_Port, Display_CS_Pin, GPIO_PIN_RESET); // select OLED
    HAL_GPIO_WritePin(Display_DC_Port, Display_DC_Pin, GPIO_PIN_RESET); // command
    HAL_SPI_Transmit(&hspi1, (uint8_t *) &byte, 1, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(Display_CS_Port, Display_CS_Pin, GPIO_PIN_SET); // un-select OLED
}

// Send data
void display_WriteData(uint8_t buffer) {
    HAL_GPIO_WritePin(Display_CS_Port, Display_CS_Pin, GPIO_PIN_RESET); // select OLED
    HAL_GPIO_WritePin(Display_DC_Port, Display_DC_Pin, GPIO_PIN_SET); // data
    HAL_SPI_Transmit(&hspi1, (uint8_t *) &buffer, 1, HAL_MAX_DELAY);
    HAL_GPIO_WritePin(Display_CS_Port, Display_CS_Pin, GPIO_PIN_SET); // un-select OLED
}


void display_Init()	//GC9A01
  {

	display_Reset();

	  display_WriteCommand(0xEF); 		//ʹ��ָ��2
	  display_WriteCommand(0xEB); 		//
	  display_WriteData(0x14);

	  display_WriteCommand(0xFE); 		//ʹ��ָ��1
	  display_WriteCommand(0xEF); 		//ʹ��ָ��2  ����interָ�������ɣ���λ֮��ſɹر�

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

	  display_WriteCommand(0xB6); 	//�ⲿָ��  ��ʾ���ܿ���
	  display_WriteData(0x00); 		//ɨ�跽�����S1-S360 G1-32
	  display_WriteData(0x20);

	  display_WriteCommand(0x36); 	//����ָ�� �洢���� Memory Access Control
	  display_WriteData(0x08); 		//MY MX MV ML BGR MH X X

	  display_WriteCommand(0x3A); 	//����ָ�� 	Pixel Format Set
	  display_WriteData(0x05); 			//16bit MCU����ģʽ

	  display_WriteCommand(0x90); 	//xxx
	  display_WriteData(0x08);
	  display_WriteData(0x08);
	  display_WriteData(0x08);
	  display_WriteData(0x08);

	  display_WriteCommand(0xBD); 	//XXX
	  display_WriteData(0x06);

	  display_WriteCommand(0xBC); 	//XXX
	  display_WriteData(0x00);

	  display_WriteCommand(0xFF); 	//XXX
	  display_WriteData(0x60);
	  display_WriteData(0x01);
	  display_WriteData(0x04);

	  display_WriteCommand(0xC3); 	//	Vreg1a voltage Control
	  display_WriteData(0x13);

	  display_WriteCommand(0xC4); 	// Vreg1b voltage Control
	  display_WriteData(0x13);

	  display_WriteCommand(0xC9); 	//Vreg2a voltage Control
	  display_WriteData(0x22);

	  display_WriteCommand(0xBE); 	//XXX
	  display_WriteData(0x11);

	  display_WriteCommand(0xE1); 	//XXX
	  display_WriteData(0x10);
	  display_WriteData(0x0E);

	  display_WriteCommand(0xDF); 	//XXX
	  display_WriteData(0x21);
	  display_WriteData(0x0c);
	  display_WriteData(0x02);

	  display_WriteCommand(0xF0); 	//GAMMA1
	  display_WriteData(0x45);
	  display_WriteData(0x09);
	  display_WriteData(0x08);
	  display_WriteData(0x08);
	  display_WriteData(0x26);
	  display_WriteData(0x2A);

	  display_WriteCommand(0xF1); 	//GAMMA2
	  display_WriteData(0x43);
	  display_WriteData(0x70);
	  display_WriteData(0x72);
	  display_WriteData(0x36);
	  display_WriteData(0x37);
	  display_WriteData(0x6F);

	  display_WriteCommand(0xF2); 	//GAMMA3
	  display_WriteData(0x45);
	  display_WriteData(0x09);
	  display_WriteData(0x08);
	  display_WriteData(0x08);
	  display_WriteData(0x26);
	  display_WriteData(0x2A);

	  display_WriteCommand(0xF3); 	////GAMMA4
	  display_WriteData(0x43);
	  display_WriteData(0x70);
	  display_WriteData(0x72);
	  display_WriteData(0x36);
	  display_WriteData(0x37);
	  display_WriteData(0x6F);

	  display_WriteCommand(0xED); 	//XXX
	  display_WriteData(0x1B);
	  display_WriteData(0x0B);

	  display_WriteCommand(0xAE); 	//XXX
	  display_WriteData(0x77);

	  display_WriteCommand(0xCD); 	//XXX
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

	  display_WriteCommand(0xE8); 	//Frame Rate
	  display_WriteData(0x34);

	  display_WriteCommand(0x62); 	//XXX
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

	  display_WriteCommand(0x63); 	//XXX
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

	  display_WriteCommand(0x64); 	//XXX
	  display_WriteData(0x28);
	  display_WriteData(0x29);
	  display_WriteData(0xF1);
	  display_WriteData(0x01);
	  display_WriteData(0xF1);
	  display_WriteData(0x00);
	  display_WriteData(0x07);

	  display_WriteCommand(0x66); 	//XXX
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

	  display_WriteCommand(0x67); 	//XXX
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

	  display_WriteCommand(0x74); 	//XXX
	  display_WriteData(0x10);
	  display_WriteData(0x85);
	  display_WriteData(0x80);
	  display_WriteData(0x00);
	  display_WriteData(0x00);
	  display_WriteData(0x4E);
	  display_WriteData(0x00);

	  display_WriteCommand(0x98); 		//XXX
	  display_WriteData(0x3e);
	  display_WriteData(0x07);

	  display_WriteCommand(0x34); 	//Tearing Effect Line Off
	  display_WriteCommand(0x21); 	//Display Inversion ON
	  display_WriteCommand(0x11); 	//����
	  //display_WriteCommand(0x38);	//Idle Mode OFF
	  HAL_Delay(120);
	  display_WriteCommand(0x29); 	//��ʾ��
	  HAL_Delay(20);
  }

void display_set_window(unsigned char x_start,unsigned char y_start,unsigned char x_end,unsigned char y_end)
{
	display_WriteCommand(0x2A);    //�����е�ַ
	display_WriteData(0);		//�е�ַ��ʼ
	display_WriteData(x_start);
	display_WriteData(0);		//�е�ַ����
	display_WriteData(x_end);
	  display_WriteCommand(0x2B);    //�����е�ַ
	  display_WriteData(0);		//�е�ַ��ʼ
	  display_WriteData(y_start);
	  display_WriteData(0);		//�е�ַ����
	  display_WriteData(y_end);
	  display_WriteCommand(0x2C);    //׼��д����ʾ����
}
static void ConvHL(uint8_t *s, int32_t l)
{
	uint8_t v;
	while (l > 0) {
		v = *(s+1);
		*(s+1) = *s;
		*s = v;
		s += 2;
		l -= 2;
	}
}
void display_send_buffer(uint16_t w, uint16_t h, uint8_t *s)
	{
	 HAL_GPIO_WritePin(Display_CS_Port, Display_CS_Pin, GPIO_PIN_RESET); // select OLED
	    HAL_GPIO_WritePin(Display_DC_Port, Display_DC_Pin, GPIO_PIN_SET); // data
		ConvHL(s, (int32_t)w*h*2);
		HAL_SPI_Transmit(&hspi1, (uint8_t*)s, w * h *2,100);

	}
