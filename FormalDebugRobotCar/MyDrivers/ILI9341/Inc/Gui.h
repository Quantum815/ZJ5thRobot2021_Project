#ifndef GUI_H_
#define GUI_H_
#ifdef __cplusplus
 extern "C" {
#endif

#include "arm_math.h"

uint16_t LCD_BGR2RGB(uint16_t c);
void Gui_Circle(uint16_t X,uint16_t Y,uint16_t R,uint16_t fc);
void Gui_DrawLine(uint16_t x0, uint16_t y0,uint16_t x1, uint16_t y1,uint16_t Color);
void Gui_box(uint16_t x, uint16_t y, uint16_t w, uint16_t h,uint16_t bc);
void Gui_box2(uint16_t x,uint16_t y,uint16_t w,uint16_t h, uint8_t mode);
void DisplayButtonDown(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);
void DisplayButtonUp(uint16_t x1,uint16_t y1,uint16_t x2,uint16_t y2);
void Gui_DrawFont_GBK16(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s);
void Gui_DrawFont_GBK24(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint8_t *s);
void Gui_DrawFont_Num32(uint16_t x, uint16_t y, uint16_t fc, uint16_t bc, uint16_t num);	 
void LCD_OUTPUT_Float(uint16_t LineX, uint16_t LineY, char *string,float32_t string_to_display);
void LCD_OUTPUT_Wave(void);
void LCD_OUTPUT_FFT(void);
void LcdAppendList(uint8_t * List);
void ClearReaginSet(int Bx,int By,int Ex,int Ey);
#ifdef __cplusplus
}
#endif
#endif /*__GUI_H */