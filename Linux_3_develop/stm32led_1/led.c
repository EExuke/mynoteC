/*************************************************************************
    > File Name: led.c
  > Author: EExuke
  > Mail: 997028792@qq.com 
  > Created Time: 2019年06月21日 星期五 20时25分37秒
 ************************************************************************/

#include<bsp_led.h>
void LED_GPIO_Config(void)
{
	/* 定义一个 GPIO_InitTypeDef 类型的结构体 */
	GPIO_InitTypeDef GPIO_InitStructure;
	/* 开启 LED 的外设时钟 */
	RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC,ENABLE );
	
	/* 选择要控制的 GPIOB 引脚 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	/* 设置引脚为通用推挽输出 */
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	/* 设置引脚速率为50MHz */
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	/* 调用库函数，初始化 GPIOB0 */
	GPIO_Init( GPIOB , &GPIO_InitStructure );
	
	/* 选择要控制的引脚 */
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_Init( GPIOC , &GPIO_InitStructure );
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;
	GPIO_Init( GPIOC , &GPIO_InitStructure );
	/* 关闭所有 led 灯 */
	GPIO_SetBits( GPIOB , GPIO_Pin_0 );
	/* 关闭所有 led 灯 */
	GPIO_SetBits( GPIOC , GPIO_Pin_4 | GPIO_Pin_3 );
}
