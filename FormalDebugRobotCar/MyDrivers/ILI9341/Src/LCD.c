#include "ILI9341_STM32_Driver.h"

/***************************************************************************************
STM32测试平台介绍:
开发板：正点原子MiniSTM32开发板
MCU ：STM32_F103_RBT6
晶振 ：12MHZ
主频 ：72MHZ
接线说明:
//-------------------------------------------------------------------------------------
#define LCD_CTRL   	  	GPIOB		//定义TFT数据端口
#define LCD_LED        	GPIO_Pin_9  //PB9 连接至TFT -LED
#define LCD_RS         	GPIO_Pin_10	//PB10连接至TFT --RS
#define LCD_CS        	GPIO_Pin_11 //PB11 连接至TFT --CS
#define LCD_RST     	  GPIO_Pin_12	//PB12连接至TFT --RST
#define LCD_SCL        	GPIO_Pin_13	//PB13连接至TFT -- CLK
#define LCD_SDA        	GPIO_Pin_15	//PB15连接至TFT - SDI
//VCC:可以接5V也可以接3.3V
//LED:可以接5V也可以接3.3V或者使用任意空闲IO控制(高电平使能)
//GND：接电源地
//说明：如需要尽可能少占用IO，可以将LCD_CS接地，LCD_LED接3.3V，LCD_RST接至单片机复位端，
//将可以释放3个可用IO
//接口定义在Lcd_Driver.h内定义，
//如需变更IO接法，请根据您的实际接线修改相应IO初始化LCD_GPIO_Init()
//-----------------------------------------------------------------------------------------
例程功能说明：
1.	简单刷屏测试
2.	英文显示测试示例
3.	中文显示测试示例
4.	数码管字体显示示例
5.	图片显示示例
6.	2D按键菜单示例
7.	本例程支持横屏/竖屏切换(开启宏USE_HORIZONTAL,详见Lcd_Driver.h)
8.	本例程支持软件模拟SPI/硬件SPI切换(开启宏USE_HARDWARE_SPI,详见Lcd_Driver.h)
**********************************************************************************************/


//---------------------------------function----------------------------------------------------//

extern SPI_HandleTypeDef hspi1;

void SPI_WriteByte(uint8_t data)
{
    HAL_SPI_Transmit(&hspi1,&data,1,1);
    //HAL_SPI_Transmit_DMA(&hspi1,&data,1);
    //HAL_SPI_DMAStop(&hspi2);
//	while(((hspi3.Instance->SR)&SPI_FLAG_TXE)==RESET);
//	(hspi3.Instance->TXDR)=data;
//	while(((hspi3.Instance->SR)&SPI_FLAG_TXE)==RESET);
}

/****************************************************************************
* 名    称：LCD_SPI_Init(void)
* 功    能：STM32_SPI硬件配置初始化
* 入口参数：无
* 出口参数：无
* 说    明：STM32_SPI硬件配置初始化
****************************************************************************/
void LCD_SPI_Init(void)	
{
    uint8_t temp=0xFF;
    LCD_RST_SET;
    HAL_Delay(50);
    HAL_SPI_Transmit(&hspi1,&temp,1,1);   
}

/****************************************************************************
* 名    称：Lcd_WriteIndex(uint8_t Index)
* 功    能：向液晶屏写一个8位指令
* 入口参数：Index   寄存器地址
* 出口参数：无
* 说    明：调用前需先选中控制器，内部函数
****************************************************************************/
void Lcd_WriteIndex(uint8_t Index)
{
    LCD_CS_CLR;
    LCD_DC_CLR;
    SPI_WriteByte(Index);
    LCD_CS_SET;
}

/****************************************************************************
* 名    称：Lcd_WriteData(uint8_t Data)
* 功    能：向液晶屏写一个8位数据
* 入口参数：dat     寄存器数据
* 出口参数：无
* 说    明：向控制器指定地址写入数据，内部函数
****************************************************************************/
void Lcd_WriteData(uint8_t Data)
{
    LCD_CS_CLR;
    LCD_DC_SET;
    SPI_WriteByte(Data);
    LCD_CS_SET;
}

/****************************************************************************
* 名    称：void LCD_WriteReg(uint8_t Index,uint16_t Data)
* 功    能：写寄存器数据
* 入口参数：Index,Data
* 出口参数：无
* 说    明：本函数为组合函数，向Index地址的寄存器写入Data值
****************************************************************************/
void LCD_WriteReg(uint8_t Index,uint16_t Data)
{
	Lcd_WriteIndex(Index);
  	Lcd_WriteData_16Bit(Data);
}

/****************************************************************************
* 名    称：void Lcd_WriteData_16Bit(uint16_t Data)
* 功    能：向液晶屏写一个16位数据
* 入口参数：Data
* 出口参数：无
* 说    明：向控制器指定地址写入一个16位数据
****************************************************************************/
void Lcd_WriteData_16Bit(uint16_t Data)
{	
	Lcd_WriteData(Data>>8);
	Lcd_WriteData(Data);	
}

/****************************************************************************
* 名    称：void Lcd_Reset(void)
* 功    能：液晶硬复位函数
* 入口参数：无
* 出口参数：无
* 说    明：液晶初始化前需执行一次复位操作
****************************************************************************/
void Lcd_Reset(void)
{
	LCD_RST_CLR;
    HAL_Delay(100);
	LCD_RST_SET;
    HAL_Delay(50);
}
/****************************************************************************
* 名    称：void Lcd_Init(void)
* 功    能：液晶初始化函数
* 入口参数：无
* 出口参数：无
* 说    明：液晶初始化_ILI9225_176X220
****************************************************************************/
void Lcd_Init(void)
{	
    LCD_SPI_Init();
	Lcd_Reset(); //Reset before LCD Init.
    Lcd_WriteIndex(0xCB);
    Lcd_WriteData(0x39);
    Lcd_WriteData(0x2C);
    Lcd_WriteData(0x00);
    Lcd_WriteData(0x34);
    Lcd_WriteData(0x02); 

	Lcd_WriteIndex(0xCF);  
	Lcd_WriteData(0X00); 
	Lcd_WriteData(0XC1); 
	Lcd_WriteData(0X30);
	
    Lcd_WriteIndex(0xE8);
    Lcd_WriteData(0x85);
    Lcd_WriteData(0x00);
    Lcd_WriteData(0x78);	
	
    Lcd_WriteIndex(0xEA);
    Lcd_WriteData(0x00);
    Lcd_WriteData(0x00);
	
    Lcd_WriteIndex(0xED);
    Lcd_WriteData(0x64);
    Lcd_WriteData(0x03);
    Lcd_WriteData(0X12);
    Lcd_WriteData(0X81);

	Lcd_WriteIndex(0xF7);  
	Lcd_WriteData(0X20); 

	Lcd_WriteIndex(0xC0);  
	Lcd_WriteData(0X23); 

	Lcd_WriteIndex(0xC1);  
	Lcd_WriteData(0X10); 

	Lcd_WriteIndex(0xC5);  
	Lcd_WriteData(0X3E); 
	Lcd_WriteData(0X28); 

	Lcd_WriteIndex(0xC7);  
	Lcd_WriteData(0X86); 

	Lcd_WriteIndex(0x36);  
#ifdef USE_HORIZONTAL
	Lcd_WriteData(0xE8);  //横屏参数
#else
	Lcd_WriteData(0x48);  //竖屏参数 
#endif

    Lcd_WriteIndex(0x3A);
    Lcd_WriteData(0x55);

    Lcd_WriteIndex(0xB1);
    Lcd_WriteData(0x00);
    Lcd_WriteData(0x18);

    Lcd_WriteIndex(0xB6);    // Display Function Control
    Lcd_WriteData(0x08);
    Lcd_WriteData(0x82);
    Lcd_WriteData(0x27);

    Lcd_WriteIndex(0xF2);    // 3Gamma Function Disable
    Lcd_WriteData(0x00);

    Lcd_WriteIndex(0x26);    //Gamma curve selected
    Lcd_WriteData(0x01);

    Lcd_WriteIndex(0xE0);    //Set Gamma
    Lcd_WriteData(0x0F);
    Lcd_WriteData(0x31);
    Lcd_WriteData(0x2B);
    Lcd_WriteData(0x0C);
    Lcd_WriteData(0x0E);
    Lcd_WriteData(0x08);
    Lcd_WriteData(0x4E);
    Lcd_WriteData(0xF1);
    Lcd_WriteData(0x37);
    Lcd_WriteData(0x07);
    Lcd_WriteData(0x10);
    Lcd_WriteData(0x03);
    Lcd_WriteData(0x0E);
    Lcd_WriteData(0x09);
    Lcd_WriteData(0x00);

    Lcd_WriteIndex(0XE1);    //Set Gamma
    Lcd_WriteData(0x00);
    Lcd_WriteData(0x0E);
    Lcd_WriteData(0x14);
    Lcd_WriteData(0x03);
    Lcd_WriteData(0x11);
    Lcd_WriteData(0x07);
    Lcd_WriteData(0x31);
    Lcd_WriteData(0xC1);
    Lcd_WriteData(0x48);
    Lcd_WriteData(0x08);
    Lcd_WriteData(0x0F);
    Lcd_WriteData(0x0C);
    Lcd_WriteData(0x31);
    Lcd_WriteData(0x36);
    Lcd_WriteData(0x0F);

    Lcd_WriteIndex(0x11);    //Exit Sleep
    HAL_Delay(120);

    Lcd_WriteIndex(0x29);    //Display on
    Lcd_WriteIndex(0x2c);  	
}

/*************************************************
函数名：LCD_Set_XY
功能：设置lcd显示起始点
入口参数：xy坐标
返回值：无
*************************************************/
void Lcd_SetXY(uint16_t Xpos, uint16_t Ypos)
{	
	Lcd_WriteIndex(0x2A);
	Lcd_WriteData_16Bit(Xpos);
	Lcd_WriteIndex(0x2B);
	Lcd_WriteData_16Bit(Ypos);
	Lcd_WriteIndex(0x2c);	
} 
/*************************************************
函数名：LCD_Set_Region
功能：设置lcd显示区域，在此区域写点数据自动换行
入口参数：xy起点和终点
返回值：无
*************************************************/
//设置显示窗口
void Lcd_SetRegion(uint16_t xStar, uint16_t yStar,uint16_t xEnd,uint16_t yEnd)
{
	Lcd_WriteIndex(0x2A);
	Lcd_WriteData_16Bit(xStar);
	Lcd_WriteData_16Bit(xEnd);
	Lcd_WriteIndex(0x2B);
	Lcd_WriteData_16Bit(yStar);
	Lcd_WriteData_16Bit(yEnd);
	Lcd_WriteIndex(0x2c);
}

	
/*************************************************
函数名：LCD_DrawPoint
功能：画一个点
入口参数：xy坐标和颜色数据
返回值：无
*************************************************/
void Gui_DrawPoint(uint16_t x,uint16_t y,uint16_t Data)
{
	Lcd_SetXY(x,y);
	Lcd_WriteData_16Bit(Data);

}    

/*************************************************
函数名：Lcd_Clear
功能：全屏清屏函数
入口参数：填充颜色COLOR
返回值：无
*************************************************/
void Lcd_Clear(uint16_t Color)               
{	
	int32_t i,m;
	Lcd_SetRegion(0,0,X_MAX_PIXEL-1,Y_MAX_PIXEL-1);
	for(i=0; i<X_MAX_PIXEL; i++)
		for(m=0; m<Y_MAX_PIXEL;)
		{
			Lcd_WriteData_16Bit(Color);
			m++;
			Lcd_WriteData_16Bit(Color);
			m++;
		}
}

