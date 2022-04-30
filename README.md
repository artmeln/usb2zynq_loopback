# usb2zynq_loopback
This repository documents conversion of the mass storage USB2 device example (provided by Xilinx for Zynq platform) to a generic USB2 device capable of looping back short data transfers on two endpoints. You can follow the commits made in this project to see all changes that had to be made for this conversion (changes in the code necessary for the device to be recognized as generic and addition of the second endpoint). I used Z-turn board (Xilinx Zynq-7010) for this project.

It should be easy, however, to convert this project to run on a different Zynq family board, as long as USB device mode is realized on your specific hardware. Start with a ‘Hello world’ Vivado example for the board that you have and make sure that USB0 is enabled among the peripheries. Follow through the example and build the hardware specification (.xsa) file. Then open Xilinx Vitis, create a new application using your XSA file, and then choose the ‘Hello world’ project as your template. Then replace the source files with the source files from the loopback project.

You can test your device with TestUsb2Loopback repo
