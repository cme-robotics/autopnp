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
 * $Id: mHelperApplicationFunctionWrapper.h 3188 2013-05-07 12:31:43Z rupanov $
 */

/**
 * \file
 *         Function wrapper - a generic abstraction for one executable function
 *              scheduled by the execution manager.
 *
 * \author
 *         This file has been generated by the CHROMOSOME Modeling Tool (XMT)
 *         (fortiss GmbH).
 */

#ifndef test_mHelperApplication_mHelperApplicationFUNCTIONWRAPPER_H
#define test_mHelperApplication_mHelperApplicationFUNCTIONWRAPPER_H

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include "xme/core/executionManager/include/executionManagerDataStructures.h"
#include "xme/core/log.h"

#include "xme/defines.h"

/******************************************************************************/
/***   Implementation                                                       ***/
/******************************************************************************/
void
test_mHelperApplication_mHelperApplicationFunctionWrapper_execute
(
	void* userFunctionDescRaw
);

#endif // #ifndef test_mHelperApplication_mHelperApplicationFUNCTIONWRAPPER_H
