#include "config.h"
#include <xc.h>
#include "delay.h"
#include "Display_LCD.h"
#include "teclado.h"



void main(void) 
{

    char estado = 0;
    char estado_senha = 0;
    char password[5] = "    ";
    char passwd[] = "7536";
    char cont_passwd = 0;
    char tecla;
    char i;
    char aux;
    dispLCD_init();
    teclado_init();
    
    dispLCD(0,0,"     SENAI      ");

    while( 1 )
    {
        tecla = teclado();
//        dispLCD_num(1,9, estado_senha, 2 );
//        dispLCD_num(1,0, tecla, 2 );
        switch( estado )
        {
            case 0:
                    dispLCD(0,0,"   Saudacoes    ");
                    delay(3000);
                    estado = 1;
                    break;
            case 1:
                    dispLCD(0,0,"   Caixa Box    ");
                    dispLCD(1,0,"A:Operacao C:Cfg");
                    if( tecla == 'A' )
                        estado = 10;
                    if( tecla == 'C')
                        estado = 20;
                    break;
            case 10:
                    dispLCD(0,0,"Operando...     ");
                    dispLCD(1,0,"                ");
                    if( tecla == '*')
                        estado = 1;
                    break;
            case 20:
                    dispLCD(0,0,"Senha:          ");
                    estado_senha = 10;
                    estado = 21;
                    break;
            case 21:
                    dispLCD(0,7, password );

                    if( estado_senha == 30 )
                        estado = 23;
                    if(  estado_senha == 40 )
                        estado = 26;
                    break;
            case 23:
                    dispLCD(0,0," Senha correta! ");
                    if( tecla == '*')
                        estado = 1;
                    break;
            case 26:
                    dispLCD(0,0,"Senha incorreta!");
                    if( tecla == '*')
                        estado = 1;
                    break;
        }
        
        switch( estado_senha )
        {
            case 0:
                    break;
            case 10:
                    if( tecla >= '0' && tecla <= '9' )
                        estado_senha = 11;
                    break;
            case 11:
                    password[cont_passwd] = tecla;
                    estado_senha = 12;
                    break;
            case 12:
                    if( !tecla )
                        estado_senha = 13;
                    break;
            case 13:
                    cont_passwd++;
                    if( cont_passwd < 4 )
                        estado_senha = 10;
                    else
                        estado_senha = 20;
                    break;
            case 20:
                    aux = 1;
                    for( i=0; i<4; i++ )
                    {
                        if( aux )
                            aux = password[i] == passwd[i];
                        password[i] = ' ';
                    }
                    cont_passwd = 0;
                    if( aux )
                        estado_senha = 30;
                    else
                        estado_senha = 40;
                break;
                
            case 30:

                break;
            case 40:
                
                break;
        }
    }
    return;
}