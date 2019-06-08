
/**
  ********************************************************************************
  * @file    stm8s_i2c_GeneralCallCmd.c
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
#include "stm8s_i2c.h"
#include "private/stm8s_i2c_private.h"

/** @addtogroup STM8S_StdPeriph_Driver
  * @{
  */

/** @}
  * @addtogroup I2C_Public_Functions
  * @{
  */

/**
  * @brief  Enables or disables the I2C General Call feature.
  * @param  NewState : State of the General Call feature.
  *         This parameter can be any of the @ref FunctionalState enumeration.
  * @retval None
  */
void I2C_GeneralCallCmd(FunctionalState NewState)
{
  /* Check function parameters */
  assert_param(IS_FUNCTIONALSTATE_OK(NewState));

  if (NewState != DISABLE)
  {
    /* Enable General Call */
    I2C->CR1 |= I2C_CR1_ENGC;
  }
  else /* NewState == DISABLE */
  {
    /* Disable General Call */
    I2C->CR1 &= (uint8_t)(~I2C_CR1_ENGC);
  }
}

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
