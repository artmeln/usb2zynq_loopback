
#include "xusbps_IniRxTx.h"

/*****************************************************************************/
/**
 *
 * Main function to call the USB interrupt example.
 *
 * @param	None
 *
 * @return
 * 		- XST_SUCCESS if successful
 * 		- XST_FAILURE on error
 *
 ******************************************************************************/

int main(void)
{
	int Status;

	Status = SetupUsbDevice();
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

	u8* rxBuffEp1;
	u8* rxBuffEp2;
	u8* rxBuffEp3;
	u8 lenRxBuffEp1;
	u8 lenRxBuffEp2;
	u8 lenRxBuffEp3;
	while (1) {
		ReadFromEp1(&rxBuffEp1, &lenRxBuffEp1);
		if (lenRxBuffEp1!=0) {
			// printing received data
			rxBuffEp1[lenRxBuffEp1] = '\0';
			xil_printf("Received-Ep1:\r\n");
			xil_printf((char*)rxBuffEp1);
			xil_printf("\r\n");
			// looping back
			SendToEp1(rxBuffEp1, lenRxBuffEp1);
			xil_printf("Looped back-Ep1.\r\n");
			ResetRxBufferEp1();
		}
		ReadFromEp2(&rxBuffEp2, &lenRxBuffEp2);
		if (lenRxBuffEp2!=0) {
			// printing received data
			rxBuffEp2[lenRxBuffEp2] = '\0';
			xil_printf("Received-Ep2:\r\n");
			xil_printf((char*)rxBuffEp2);
			xil_printf("\r\n");
			// looping back
			SendToEp2(rxBuffEp2, lenRxBuffEp2);
			xil_printf("Looped back-Ep2.\r\n");
			ResetRxBufferEp2();
		}
		ReadFromEp3(&rxBuffEp3, &lenRxBuffEp3);
		if (lenRxBuffEp3!=0) {
			// printing received data
			rxBuffEp3[lenRxBuffEp3] = '\0';
			xil_printf("Received-Ep3:\r\n");
			xil_printf((char*)rxBuffEp3);
			xil_printf("\r\n");
			// looping back
			SendToEp3(rxBuffEp3, lenRxBuffEp3);
			xil_printf("Looped back-Ep3.\r\n");
			ResetRxBufferEp3();
		}
	}

	return XST_SUCCESS;
}

