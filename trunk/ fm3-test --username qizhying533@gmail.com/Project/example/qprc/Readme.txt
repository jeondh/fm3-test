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
Date       Ver AE  IAR    ARM  Description
2011-11-18 1.0 MCU 6.21.1 ----    New
==========================================================================

==========================================================================
Function description:

The example demonstrate the QPRC module initialization, interrupt enable, 
counter start and stop, get position and revolution counter value, 
how to use call back function.
==========================================================================

==========================================================================
Environment

Test Board:
---------------
FSSDC-9B506-EVB

Clock settings:
---------------
Crystal:  4 MHz
HCLK:    80 MHz
PCLK0:   40 MHz
PCLK1:   40 MHz
PCLK2:   40 MHz

Support Hardware:
---------------
-

Support Software:
---------------
-

==========================================================================

==========================================================================
Usage Procedure:

1) Hardware connect
The encoder has five inputs; they are AIN, BIN, ZIN, +5V, GND.
In MCU side, the line connects is:
AIN(pin45), BIN(pin46), ZIN(pin47), +5V(pin1), GND(pin30)
2) Start the project with IAR;
3) Open terminal IO window;
4) Turn the encoder, watch the terminal IO window;
==========================================================================

==========================================================================
Notice:
-

==========================================================================
