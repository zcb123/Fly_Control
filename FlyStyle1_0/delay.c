#include <delay.h>

void delay_ms(uint32_t ticks)
{
	uint16_t CNT;
	TIM6->CNT = 0;    //定时器清零
	TIM6->CR1 |= 0x0001;   //开定时器
	do
	{
		CNT = TIM6->CNT;
	}while ((CNT < ticks * 1000));
	TIM6->CR1 &= 0x0000;   //关定时器

}
void delay_us(uint32_t ticks)
{
	uint16_t CNT;
	TIM6->CNT = 0;     //定时器清零
	TIM6->CR1 |= 0x0001;    //开定时器
	do
	{
		CNT = TIM6->CNT;
	}while ((CNT < ticks ))
		;
	TIM6->CR1 &= 0x0000;    //关定时器
}