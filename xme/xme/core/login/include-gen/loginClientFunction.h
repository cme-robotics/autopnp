/*
 * Copyright (c) 2011-2013, fortiss GmbH.
 * Licensed under the Apache License, Version 2.0.
 *
 * Use, modification and distribution are subject to the terms specified
 * in the accompanying license file LICENSE.txt located at the root directory
 * of this software distribution. A copy is available at
 * http://chromosome.fortiss.org/.
 *
 * This file is part of CHROMOSOME.
 *
 * $Id: loginClientFunction.h 4597 2013-08-07 14:18:28Z ruiz $
 */

/**
 * \file
 *         Header file for function loginClient in component loginClient.
 *
 * \author
 *         This file has been generated by the CHROMOSOME Modeling Tool (XMT)
 *         (fortiss GmbH).
 */

#ifndef XME_CORE_LOGIN_LOGINCLIENTFUNCTION_H
#define XME_CORE_LOGIN_LOGINCLIENTFUNCTION_H

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include "xme/core/component.h"

/******************************************************************************/
/***   Prototypes                                                           ***/
/******************************************************************************/
XME_EXTERN_C_BEGIN

/**
 * \brief  Initialization of function. 
 *  
 * \details Called once before the function is executed the first time.
 *
 * \param  param Function-specific initialization parameter.
 *
 * \return XME_STATUS_SUCCESS when initialization was successful.
 */
xme_status_t
xme_core_login_loginClientFunction_init
(
    void* param
);

/**
 * \brief  Executes the function one time.
 *
 * \details Input ports of the function need to be prepared, before calling this.
 *
 * \param  param Function-specific parameter
 */
void
xme_core_login_loginClientFunction_step
(
    void* param
);

/**
 * \brief  Finalization function.
 *
 * \details Called after function will no longer be executed to free allocated resources.
 *          Function must not be executed after fini has been called.
 */
void
xme_core_login_loginClientFunction_fini(void);

XME_EXTERN_C_END

#endif // #ifndef XME_CORE_LOGIN_LOGINCLIENTFUNCTION_H
