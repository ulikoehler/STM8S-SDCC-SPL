
/**
  ********************************************************************************
  * @file    stm8s_tim1_OC4PreloadConfig.c
  * @author  MCD Application Team
  * @version V2.2.0
  * @date    30-September-2014
  * @brief   This file contains all the functions for the UART1 peripheral.
   ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2014 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software
  * distributed under the License is distributed on an "AS IS" BASIS,
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm8s_tim1.h"
#include "private/stm8s_tim1_private.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup TIM1_Public_Functions
  * @{
  */

/**
  * @brief  Enables or disables the TIM1 peripheral Preload Register on CCR4.
  * @param   NewState new state of the Capture Compare Preload register.
  * This parameter can be ENABLE or DISABLE.
  * @retval None
  */
void TIM1_OC4PreloadConfig(FunctionalState NewState)
{
  /* Check the parameters */
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));
  
  /* Set or Reset the OC4PE Bit */
  if (NewState != DISABLE)
  {
    TIM1->CCMR4 |= TIM1_CCMR_OCxPE;
  }
  else
  {
    TIM1->CCMR4 &= (uint8_t)(~TIM1_CCMR_OCxPE);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
