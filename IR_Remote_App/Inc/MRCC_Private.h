
/***********************************************************************/
/*             guard of file will call one time in .c file             */
/***********************************************************************/

             
#ifndef MRCC_PRIVAITE_H_
#define MRCC_PRIVAITE_H_

/*#####################################################################*/
/*                        Register Defintions                          */
/*---------------------------------------------------------------------*/
/*     -Developer Can't Edit in                                        */
/*     -Register Defination                                            */
/*     -Desgin :                                                       */
/*                - #define    : YES                                   */
/*                - Struct     : NO                                    */
/*#####################################################################*/

/***********************************************************************/
/*                  Macros Of Base Adress of RCC Registers             */
/***********************************************************************/


#define  RCC_BASE_ADRESS      0x40023800



/***********************************************************************/
/*                     Macros for User Configuration                   */
/***********************************************************************/

/*#####################################################################*/
/*
   - Select The Clock Source from The Following Options : 
*/
         
#define HSI             0U
#define HSE             1U
#define PLL             2U

/*#####################################################################*/
/*
   - Select The  Source of HSE from The Following Options : 
*/

#define HSE_CRYSTAL    0U
#define HSE_RC         1U

/*#####################################################################*/

/*
   - Select The  Source of PLL from The Following Options : 
*/

#define HSE_PLL        0U
#define HSI_PLL        1U


/*#####################################################################*/
/*                     THE END OF PRIVAITE FILE                        */
/*#####################################################################*/



typedef struct
{
	u32 CR           ;
	u32 PLLCFGR      ;
	u32 CFGR         ;
	u32 CIR          ;
    u32 AHB1RSTR     ;
	u32 AHB2RSTR     ;
	u32 Reserved0	 ;
	u32 Reserved1	 ;
	u32 APB1RSTR     ;
	u32 APB2RSTR     ;
	u32 Reserved2	 ;
	u32 Reserved3	 ;
	u32 AHB1ENR      ;
	u32 AHB2ENR      ;
	u32 Reserved4	 ;
	u32 Reserved5	 ;
	u32 APB1ENR      ;
	u32 APB2ENR      ;
	u32 Reserved6	 ;
	u32 Reserved7	 ;
	u32 AHB1LPENR    ;
	u32 AHB2LPENR    ;
	u32 Reserved8	 ;
	u32 Reserved9	 ;
	u32 APB1LPENR    ;
	u32 APB2LPENR    ;
	u32 Reserved10	 ;
	u32 Reserved11	 ;
	u32 BDCR         ;
	u32 CSR          ;
	u32 Reserved12	 ;
	u32 Reserved13	 ;
	u32 SSCGR        ;
	u32 PLLI2SCFGR   ;
	u32 Reserved14	 ;
	u32 DCKCFGR      ;

}RCC_RegDef_t;


#define RCC 	((RCC_RegDef_t *)(RCC_BASE_ADRESS))



#endif /*MRCC_PRIVAITE_H_*/

