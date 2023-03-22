#include	"STD_Types.h"
#include	"BIT_Math.h"

#include	"RCC_interface.h"
#include	"DIO_int.h"
#include	"NVIC_int.h"


/*void	_delay_ms(u32 Ticks)
{
	for(u32 i = 0; i < (Ticks * 500) ; i++)
	{
		asm("NOP");
	}
}*/

void	EXTI0_IRQHandler(void);

int	main(void)
{

	
	//	System Clk init

	 	MRCC_voidSysClkInit();
	
	//	Toggle Led C13	GPIOC
	//	1- Enable Per Clk "RCC" Port C
	MRCC_voidEnablePerClk(RCC_APB2,4);
	
	//Direction for C13 is output Push Pull
	M_DIO_void_setPinDir(PORTC_ID, PIN13, OUT_2MHZ_PP);
	M_DIO_void_setPinValue(PORTC_ID, PIN13, HIGH);
	//_delay_ms(10);
	//M_DIO_void_setPinValue(PORTC_ID, PIN13, LOW);

	//	NVIC Initialization
	//NVIC_void_Init();

	//	EXTI0 NVIC interrupt Enable
	//NVIC_void_EnableInt(6);

	//	EXTI0 Set the pending flag
	/* NVIC_void_Enable_PendingFlag(6);

	while(1)
	{

	}*/
	return 0;
}

//External Peripherals
/*
void	EXTI0_IRQHandler(void)
{

		M_DIO_void_setPinValue(PORTC_ID, PIN13, LOW);
		//_delay_ms(10);
		M_DIO_void_setPinValue(PORTC_ID, PIN13, HIGH);
		//_delay_ms(10);
}
//Core Peripheral
void	SysTick_Handler(void)
{

}*/
