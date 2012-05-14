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
Function description:
==========================================================================
Demo the interrupt of low voltage detection 

The user can select to run:
2.8V, 3.0V, 3.2V, 3.6V, 3.7V, 4.0V, 4.1V, 4.2V LVD interrupt voltage
to check the above mode.
==========================================================================
Environment
==========================================================================
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
None

Support Software:
---------------
None

==========================================================================
Usage Procedure:
==========================================================================
1) Select the lVD interrupt voltage: 
LVD_VOL_VAL_2_8 for 2.8V 
LVD_VOL_VAL_3_0 for 3.0V
LVD_VOL_VAL_3_2 for 3.2V
LVD_VOL_VAL_3_6 for 3.6V
LVD_VOL_VAL_3_7 for 3.7V
LVD_VOL_VAL_4_0 for 4.0V
LVD_VOL_VAL_4_1 for 4.1V
LVD_VOL_VAL_4_2 for 4.2V

2) Enable interrupt
3) Run
4) Check whether interrupt generate when power drops below specified voltage

==========================================================================
Notice:
==========================================================================
1) None

==========================================================================
