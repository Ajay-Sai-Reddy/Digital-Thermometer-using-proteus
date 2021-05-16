#line 1 "F:/Electronics/Embeded/Digital Thermometer/dt.c"

sbit LCD_RS at RB2_bit;
sbit LCD_EN at RB3_bit;
sbit LCD_D4 at RB4_bit;
sbit LCD_D5 at RB5_bit;
sbit LCD_D6 at RB6_bit;
sbit LCD_D7 at RB7_bit;

sbit LCD_RS_Direction at TRISB2_bit;
sbit LCD_EN_Direction at TRISB3_bit;
sbit LCD_D4_Direction at TRISB4_bit;
sbit LCD_D5_Direction at TRISB5_bit;
sbit LCD_D6_Direction at TRISB6_bit;
sbit LCD_D7_Direction at TRISB7_bit;


int t;
char a;
char lcd[] = "000 Degree";

void main()
{
 ADCON1 = 0x04;
 Lcd_Init();
 Lcd_Cmd(_LCD_CURSOR_OFF);

 do
 {
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_out(1,1, "Temperature:");
 t = ADC_Read(0);

 t = t * 0.4887;
 a = t%10;
 lcd[2] = a + '0';

 t = t/10;
 a = t%10;
 lcd[1] = a + '0';

 t = t/10;
 a = t%10;
 lcd[0] = a + '0';

 Lcd_out(2,1,lcd);
 Delay_ms(100);
 }while(1);
}
