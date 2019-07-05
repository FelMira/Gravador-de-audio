# Detector de Palmas(Incompleto)
  O objetivo do programa era utilizar o microfone MEMS da placa STM32F4DISCOVERY para ligar e desligar o sistema de segurança de uma casa.
  
  Os macros da placa (utilizados para setar os bits do RCC) não funcionaram no PlatformIO nem no compildor mbed online, impossibilitando qualquer teste.
  
  Por falta de conteúdo online como guia, não pude encontrar um exemplo que ajudasse a determinar o momento que ocorriam as palmas ou não. 
  
  Este programa contém apenas a configuração do filtro do PDM para PCM, e a configuração do clock do I2S para o microfone e as funções de filtração com decimação de 64.
  
