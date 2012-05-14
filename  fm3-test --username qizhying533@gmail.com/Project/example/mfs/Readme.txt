==========================================================================
                 Example for MB9BF506R
==========================================================================
                 (C) Fujitsu Semiconductor (Shanghai) (FSS)           
                                                                      
   The following software deliverable is intended for and must only be  
   used for reference and in an evaluation laboratory environment.      
   It is provided on an as-is basis without charge and is subject to    
   alterations.                                                         
   It is the user's obligation to fully test the software in its        
   environment and to ensure proper functionality, qualification and    
   compliance with component specifications.                            
                                                                      
   In the event the software deliverable includes the use of open       
   source components, the provisions of the governing open source       
   license agreement shall apply with respect to such software          
   deliverable.                                                         
   FSS does not warrant that the deliverables do not infringe any      
   third party intellectual property right (IPR). In the event that     
   the deliverables infringe a third party IPR it is the sole           
   responsibility of the customer to obtain necessary licenses to       
   continue the usage of the deliverable.                               
                                                                      
   To the maximum extent permitted by applicable law FSS disclaims all 
   warranties, whether express or implied, in particular, but not       
   limited to, warranties of merchantability and fitness for a          
   particular purpose for which the deliverable is not designated.      
                                                                      
   To the maximum extent permitted by applicable law, FSS's liability  
   is restricted to intentional misconduct and gross negligence.        
   FSS is not liable for consequential damages.                        
                                                                      
   (V0.1)                                                        
==========================================================================
History
==========================================================================
Date       Ver AE  IAR    ARM  Description
2012-01-16 1.0 MCU 6.21.1 ---- template version
==========================================================================
Function description
==========================================================================
1) UART Demo:
Communicate with the PC by UART line through polling/Int mode.

2) SD Card CMD Demo:
Send the CMD0 to the SD Card and check the response.

==========================================================================
Environment
==========================================================================
Test Board:
---------------
FSSDC-9B506-EVB (for UART Demo)
KSK-MB9BF506 (for SD Card CMD Demo)

Clock settings:
---------------
Crystal:  4 MHz
HCLK:    80 MHz
PCLK0:   40 MHz
PCLK1:   40 MHz
PCLK2:   40 MHz

Support Hardware:
---------------
UART Line (for UART Demo)
SD Card (for SD Card CMD Demo)

Support Software:
---------------
ComPort tool (for UART Demo)

==========================================================================
Usage Procedure
==========================================================================
. UART Demo
1) Connect the UART line between UART ch2 and the PC
2) Start the ComPort tool (or other PC UART Tools, i.e HyperTerminal)
3) Select and config the tUART0ModeConfigT, run MFS_UART0ConfigMode
(For tUART0ModeConfigT, the user can change the speed/data bits/stop bits/
parity mode/bit order/NRZ)
4) Run UART0PollTX to transmot the string to the PC in polling mode or
5) Run UART0PollRX to receive the string from the PC in polling mode or
6) Run UART0IntTX to transmot the string to the PC in interrupt mode or
7) Run UART0IntRX to receive the string from the PC in interrupt mode

B. SD Card CMD Demo
1) Insert the SD Card
2) Run the program, and if res = 1, it means the communication between SD Card 
and MCU is success
3) The user can select the transfer mode.
For pooling mode: specify the mode as 0 in SdTranserByte API
For int mode: specify the mode as 1/2 in SdTranserByte API for TX/RX
==========================================================================
Notice
==========================================================================
1) For UART, please don't use the speed less than 1200 bps.
==========================================================================
