#include "bsp_key.h"

void bsp_key_init(void)
{
	GPIO_InitTypeDef GPIO_KEY_Init;
	
	__HAL_RCC_GPIOC_CLK_ENABLE();
	
	GPIO_KEY_Init.Mode = GPIO_MODE_AF_INPUT;
	GPIO_KEY_Init.Pin = PIN_KEY;
	GPIO_KEY_Init.Pull = GPIO_PULLUP;
	GPIO_KEY_Init.Speed = GPIO_SPEED_FREQ_LOW;
	
	HAL_GPIO_Init(GPIO_KEY,&GPIO_KEY_Init);
	
	HAL_GPIO_WritePin(GPIO_KEY,PIN_KEY,GPIO_PIN_SET);
}

uint8_t bsp_key_scan(void)
{
	static uint8_t count = 0;
	static uint8_t isLongPress = 0;
	if(HAL_GPIO_ReadPin(GPIO_KEY,PIN_KEY) == 0)
	{
		count++;
		if((count >= 30) && (isLongPress == 0))
		{
			count=0;
			isLongPress = 1;
			return 1;
		}
		else
		{
			isLongPress = 0;
		}
	}
	return 0;
} 

