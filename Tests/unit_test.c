/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : unit_test
 * @brief          : Main program body
 ******************************************************************************/

/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#define TEST_NBRE   10U
static uint8_t test_SendEther_Buf(void);

//#define ALL_TEST_PASS
//#define ALL_TEST_FAIL

uint8_t Test_Result[TEST_NBRE];

/**
 *
 * @return
 */
uint8_t Start_UnitTest(void)
{

	uint8_t ret=0;

	Test_Result[0]= test_SendEther_Buf();

	for (uint8_t i=1;i<10;i++)
	{

#ifdef ALL_TEST_PASS
		Test_Result[i]=0;
#elif defined ALL_TEST_FAIL
		Test_Result[i]=1;
#else

		if ((i%2)==0)
		{
		Test_Result[i]=1;
		}
		else
		{
			Test_Result[i]=0;
		}
	}
#endif

	return ret;
}


/**
 *
 * @param Buff
 * @param size
 * @param Status
 * @return
 */
static uint8_t test_SendEther_Buf(void)
{

	uint8_t TestBuf[10] ;
	uint8_t size; uint8_t Status= 1;
	uint8_t ret=0;

	/*Check Size param -----------------------------------*/
	for ( size=0; size<10;  size++)
	{
		ret=SendEther_Buf(TestBuf,size,Status );
		if (ret != 0 )
		{
			return 1U;
		}
	}
	/*Check Status param -----------------------------------*/
	for ( Status=1; Status<10;  Status++)
	{
		ret=SendEther_Buf(TestBuf,size,Status );
		if (ret != 0 )
		{
			return 1U;
		}
		for (uint8_t i=0;i<5;i++)
		{
			if (TestBuf[i]!=Status)
			{
				return 2U;
			}
		}

	}


	/*Check Assert Catch Fault*/
	ret=SendEther_Buf(0,size,Status );
    if (ret ==0)
    {
    	return 1;
    }





	return ret;

}





/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
