/*************************************************************************
    > File Name: main.c
  > Author: EExuke
  > Mail: 997028792@qq.com 
  > Created Time: 2019年06月21日 星期五 22时11分45秒
 ************************************************************************/

#include<stm32f10x.h>
#include<bsp_led.h>

void Delay(__IO u32 nCount);
/**
 * @brief	主函数；
 * @param	无；
 * @retval	无；
 */
int main(void)
{
	/* LED 端口初始化 */
	LED_GPIO_Config();
	while(1)
	{
		//熄灭第一个LED灯
		GPIO_SetBits(GPIOB , GPIO_Pin_0);
		//延时
		Delay(0xffffff);
		//点亮第一个LED灯
		GPIO_ResetBits(GPIOB , GPIO_Pin_0);
		//延时
		Delay(0xffffff);
		//以此类推
		GPIO_SetBits(GPIOC , GPIO_Pin_3);
		Delay(0xffffff);
		GPIO_ResetBits(GPIO , GPIO_Pin_3);
		Delay(0xffffff);

		GPIO_SetBits(GPIOC , GPIO_Pin_4);
		Delay(0xffffff);
		GPIO_ResetBits(GPIOC , GPIO_Pin_4);
		Delay(0xffffff);
	}
}

void Delay(__IO uint32_t nCount)	//简单延时函数；
{
	for( ; nCount != 0 ; nCount--);
}
