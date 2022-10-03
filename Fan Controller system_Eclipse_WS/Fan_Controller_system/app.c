#include"dcmotor.h"
#include"timer0.h"
#include"std_types.h"
#include"lm35_sensor.h"
#include "lcd.h"
#include"adc.h"
int main() {
	uint8 temp;
	Timer_Config Timer_config = { FAST_PWM_MODE, NON_INVERTING_MODE,
			F_CPU_CLOCK_8 };
	ADC_ConfigType Adc_config = { INTERNAL, F_CPU_8 };
	Timer0_init(&Timer_config);
	LCD_init();
	DcMotor_Init();
	ADC_init(&Adc_config);
	LCD_moveCursor(0, 3);
	LCD_displayString("FAN is ");
	LCD_moveCursor(1, 3);
	LCD_displayString("Temp =    C");
	while (1) {
		temp = LM35_SENSOR_getTemperature();
		if (temp >= 120) {
			LCD_moveCursor(0, 10);
			LCD_displayString("ON ");
			LCD_moveCursor(1, 10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW, 100);
		} else if (temp >= 100 && temp < 120) {
			LCD_moveCursor(0, 10);
			LCD_displayString("ON ");
			LCD_moveCursor(1, 10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW, 75);
		} else if (temp >= 90 && temp < 100) {
			LCD_moveCursor(0, 10);
			LCD_displayString("ON ");
			LCD_moveCursor(1, 10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW, 75);
			LCD_displayCharacter(' ');
		} else if (temp >= 60 && temp < 90) {
			LCD_moveCursor(0, 10);
			LCD_displayString("ON ");
			LCD_moveCursor(1, 10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW, 50);
			LCD_displayCharacter(' ');
		} else if (temp >= 30 && temp < 60) {
			LCD_moveCursor(0, 10);
			LCD_displayString("ON ");
			LCD_displayCharacter(' ');
			LCD_moveCursor(1, 10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(CW, 25);
			LCD_displayCharacter(' ');
		} else {
			LCD_moveCursor(0, 10);
			LCD_displayString("OFF");
			LCD_moveCursor(1, 10);
			LCD_intgerToString(temp);
			DcMotor_Rotate(STOP, 0);
			LCD_displayCharacter(' ');
		}
	}
}

