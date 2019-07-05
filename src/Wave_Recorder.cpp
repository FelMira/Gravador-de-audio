#include "mbed.h"
#include "pdm_filter.h"
uint8_t BufferI[64];        //Buffer do PDM do microfone
uint16_t BufferO[16];       //Buffer do audio final em PCM
uint16_t MicGain = 32;      //Valor do volume, entre 0 e 64
RCC_PLLI2SCFGR_PLLI2SN_8;   //Segundo tabela do fabricante, recomenda-se usar 192 para este valor de clock de I2S
RCC_PLLI2SCFGR_PLLI2SN_7;
SPI_I2SPR_I2SDIV[7:0] = 187;//Valor de 187 retirado de tabela do documento de referências
RCC_PLLI2SCFGR_PLLI2SR_1;   //Valor do PLLI2SR = 2 - Divisor no calculo da frequencia
RCC_AHB1ENR_CRCEN;          //Enable do Clock do I2S


PDMFilter_InitStruct Filter; //Estrutura definida em pdm_filter.h
int main(){
    Filter.Fs = 8000;       //Frequencia final do audio
    Filter.HP_HZ = 5000;    //Frequencia filtro passa alta
    Filter.LP_HZ = 10000;   //Frequencia filtro passa baixa
    Filter.In_MicChannels = 1;  //Canais de entrada
    Filter.Out_MicChannels = 1; //Canais de saída
    void PDM_Filter_Init(PDMFilter_InitStruct * Filter);    //Inicialização do filtro
    int32_t PDM_Filter_64_MSB(uint8_t* BufferI, uint16_t* BufferO, uint16_t MicGain,  PDMFilter_InitStruct * Filter);   //MSB e LSB do audio, para uma decimação de 64 bits
    int32_t PDM_Filter_64_LSB(uint8_t* BufferI, uint16_t* BufferO, uint16_t MicGain,  PDMFilter_InitStruct * Filter);
}
/* Não encontrei exemplos que me ajudassem a comparar o audio captado com o de uma palma */