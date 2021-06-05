#ifndef LCD_H_
#define LCD_H_

#include "spi.h"
/////////////////////////////////////用户配置区///////////////////////////////////	 
//支持横竖屏快速定义切换
#define USE_HORIZONTAL  		1	//定义是否使用横屏 		0,不使用.1,使用.

#if USE_HORIZONTAL//如果定义了横屏 
#define X_MAX_PIXEL	        LCD_Y_SIZE
#define Y_MAX_PIXEL	        LCD_X_SIZE
#else
#define X_MAX_PIXEL	        LCD_X_SIZE
#define Y_MAX_PIXEL	        LCD_Y_SIZE
#endif

//-------------------------屏幕物理像素设置--------------------------------------//
#define LCD_X_SIZE	        240
#define LCD_Y_SIZE	        320

//////////////////////////////////////////////////////////////////////////////////

#define BLACK       0x0000      
#define NAVY        0x000F      
#define DARKGREEN   0x03E0      
#define DARKCYAN    0x03EF      
#define MAROON      0x7800      
#define PURPLE      0x780F      
#define OLIVE       0x7BE0      
#define LIGHTGREY   0xC618      
#define DARKGREY    0x7BEF      
#define BLUE        0x001F      
#define GREEN       0x07E0      
#define CYAN        0x07FF      
#define RED         0xF800     
#define MAGENTA     0xF81F      
#define YELLOW      0xFFE0      
#define WHITE       0xFFFF      
#define ORANGE      0xFD20      
#define GREENYELLOW 0xAFE5     
#define PINK        0xF81F
#define GRAY0       0xEF7D   	//灰色0 3165 00110 001011 00101
#define GRAY1       0x8410    //灰色1  00000 000000 00000
#define GRAY2       0x4208    //灰色2  1111111111011111

//CHIP SELECT PIN AND PORT, STANDARD GPIO
#define LCD_CS_PORT								GPIOB
#define LCD_CS_PIN								GPIO_PIN_0

//DATA COMMAND PIN AND PORT, STANDARD GPIO
#define LCD_DC_PORT								GPIOC
#define LCD_DC_PIN								GPIO_PIN_5

//RESET PIN AND PORT, STANDARD GPIO
#define	LCD_RST_PORT							GPIOC
#define	LCD_RST_PIN								GPIO_PIN_4

//lcd io口设置
#define	LCD_CS_SET  	HAL_GPIO_WritePin(LCD_CS_PORT, LCD_CS_PIN, GPIO_PIN_SET);
#define	LCD_DC_SET  	HAL_GPIO_WritePin(LCD_DC_PORT, LCD_DC_PIN, GPIO_PIN_SET);
#define	LCD_RST_SET  	HAL_GPIO_WritePin(LCD_RST_PORT, LCD_RST_PIN, GPIO_PIN_SET);

#define	LCD_CS_CLR  	HAL_GPIO_WritePin(LCD_CS_PORT, LCD_CS_PIN, GPIO_PIN_RESET);
#define	LCD_DC_CLR  	HAL_GPIO_WritePin(LCD_DC_PORT, LCD_DC_PIN, GPIO_PIN_RESET);
#define	LCD_RST_CLR  	HAL_GPIO_WritePin(LCD_RST_PORT, LCD_RST_PIN, GPIO_PIN_RESET);

#define SPI_SPEED_SET(SPIHandle,SPIScale)	do{(SPIHandle.Instance->CR1)&=0xFFC7;(SPIHandle.Instance->CR1)|=SPIScale;}while(0);
void Lcd_WriteIndex(uint8_t Index);
void Lcd_WriteData(uint8_t Data);
void LCD_WriteReg(uint8_t Index,uint16_t Data);
void Lcd_WriteData_16Bit(uint16_t Data);
void Lcd_Reset(void);
void Lcd_Init(void);
void Lcd_SetXY(uint16_t Xpos, uint16_t Ypos);
void Lcd_SetRegion(uint16_t xStar, uint16_t yStar,uint16_t xEnd,uint16_t yEnd);
void Gui_DrawPoint(uint16_t x,uint16_t y,uint16_t Data);
void Lcd_Clear(uint16_t Color);

#endif
