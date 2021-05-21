#include "config.h"
#include <xc.h>
#include "delay.h"
#include "Display_LCD.h"


    void teclado_init ()
{
        ANSELH = 0;
        TRISB = 0xF0;
        PORTB = 0;        
}
    
    
    #define MASK   0x10
    
   
    char tabTeclado[4][4] ={  {'1','2', '3','A'},
                              {'4','5', '6','B'},
                              {'7','8', '9','C'},
                              {'*','0', '#','D'}  };
    int teclado (void)
    {
        char tecla = 0;
        
        char c,l;
        
        for (l=0; l<4; l++)
        {
        PORTB = 0x01<<l;
            for (c=0; c<4; c++)
            {
                if( PORTB & MASK<<c )
               tecla = tabTeclado [l][c];
             }
        }
                    return ( tecla );
            
    }
    
  