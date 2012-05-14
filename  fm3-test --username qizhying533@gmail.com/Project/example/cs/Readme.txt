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
Demo the CSV and FCS function of clock supervisor
1) CSV sub reset
2) CSV main reset
3) FCS reset
4) FCS interrupt

User can check terminal I/O for each function

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
1) Enable each function test code in main.c
2) Run sample code
3) Disturb source clock or modify detect threshold value
4) Check terminal I/O 

==========================================================================
Notice:
==========================================================================
1) None

==========================================================================
