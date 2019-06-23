/* 
 * File		: Main.c
 * Author	: Shreyesh Ragit
 * Date		: 26 November, 2016, 11:10 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Includes.h"
#include <htc.h>

__CONFIG(1, OSC_INTIO67);
__CONFIG(2, BORDIS & PWRTEN & WDTDIS & PBADDIS);
__CONFIG(3, CCP2RC1 & MCLRDIS);
__CONFIG(4, DEBUGEN & LVPDIS & STVREN);
__CONFIG(5, UNPROTECT);

int sample;
int sample=0,Det_temp=0,Det_HUM=0;
char Det_temp_buf[10],Det_HUM_buf[10];

void get_temp(void)
{
		Det_temp=ADCRead(2);
		Det_temp=(Det_temp*0.44);
		itoa(Det_temp_buf,Det_temp,10); 
}

void get_BPM(void)
{
		Det_HUM=ADCRead(3);
		Det_HUM=Det_HUM*1;
		itoa(Det_HUM_buf,Det_HUM,10); 
}

void Doctor_SMS()
{
		SendStringSerially("AT+CMGS=\"+919673840944"); 
		SendStringSerially("\" \r"); 
		myMsDelay (3000);
		SendStringSerially("TEMP: ");
		SendStringSerially(Det_HUM_buf);
		SendStringSerially("\n"); 
		SendStringSerially("BPM: ");
		SendStringSerially(Det_temp_buf);
		SendStringSerially("\n");
		SendStringSerially("BIO-MEDICAL SYSTEM");
		SendStringSerially("\n"); 
		SendStringSerially("SITS SINHGAD COLLEGE");
		SendStringSerially("\n"); 
		SendStringSerially("FINAL YEAR PROJECT");
		SendStringSerially("\n"); 
		myMsDelay (800);	
		SendByteSerially(0x1A); 
		SendStringSerially("\r");
		return;
}


void main(int argc, char** argv) 
{
		myMsDelay (1000);
		PORTs_init();
		InitUART();
		
		init_LCD();
		LCD_cmd(0x80);
		LCD_write_string("SMART  AMBULANCE");
		LCD_cmd(0xC0);
		LCD_write_string("TRAFFIC CTRL SYS");
		myMsDelay (1000);
		LCD_cmd(0x01);
		LCD_cmd(0x80);
		LCD_write_string("DEV:  BPM  TEMP ");
		LCD_cmd(0xC0);
		LCD_write_string("VAL:            ");
		
		while(1)
		{
				get_BPM();
				get_temp();
				LCD_cmd(0xC6);
				LCD_write_string(Det_temp_buf);
				LCD_cmd(0xCC);
				LCD_write_string(Det_HUM_buf);
				myMsDelay (10000);
				Doctor_SMS();
		}
}


