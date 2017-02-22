/*
 * Copyright (c) 2011-2014, fortiss GmbH.
 * Licensed under the Apache License, Version 2.0.
 *
 * Use, modification and distribution are subject to the terms specified
 * in the accompanying license file LICENSE.txt located at the root directory
 * of this software distribution. A copy is available at
 * http://chromosome.fortiss.org/.
 *
 * This file is part of CHROMOSOME.
 *
 * $Id: deviceManifest.c 7769 2014-03-11 15:27:13Z geisinger $
 */

/**
 * \file
 *         Defines function for creation of component type manifest
 *         for 'device'.
 *
 * \author
 *         This file has been generated by the CHROMOSOME Modeling Tool (XMT)
 *         (fortiss GmbH).
 */

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include "detector/adv/device/include/deviceManifest.h"

#include "../include/deviceComponentWrapper.h"
#include "detector/adv/device/include/deviceComponent.h"
#include "detector/adv/device/include/operateFunction.h"
#include "detector/adv/device/include/operateFunctionWrapper.h"
#include "detector/topic/dictionary.h"
#include "xme/core/log.h"
#include "xme/hal/include/time.h"

/******************************************************************************/
/***   Implementation                                                       ***/
/******************************************************************************/
xme_status_t
detector_adv_device_manifest_createComponentTypeManifest
(
    xme_core_componentManifest_t* componentManifest
)
{
    XME_CHECK
    (
        NULL != componentManifest,
        XME_STATUS_INVALID_PARAMETER
    );

    (void)xme_hal_mem_set(componentManifest, 0U, sizeof(xme_core_componentManifest_t));

    componentManifest->componentType = (xme_core_componentType_t)4098;
    componentManifest->componentWrapperInit = detector_adv_device_deviceComponentWrapper_init;
    componentManifest->componentWrapperReceivePort = detector_adv_device_deviceComponentWrapper_receivePort;
    componentManifest->componentWrapperFini = detector_adv_device_deviceComponentWrapper_fini;
    componentManifest->componentInit = (xme_core_componentManifest_componentInit_t)detector_adv_device_deviceComponent_init;
    (void)xme_hal_safeString_strncpy(componentManifest->name, "device", sizeof(componentManifest->name));
    componentManifest->configStructSize = sizeof(detector_adv_device_deviceComponent_config_t);

    {
        uint32_t functionArrayLength = sizeof(componentManifest->functionManifests) / sizeof(componentManifest->functionManifests[0]);

        // Function 'operate'
        {
            if (0U >= functionArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (0U == functionArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'device' defines more functions (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                       1,
                       functionArrayLength
                    );
                }
            }
            else
            {
                xme_core_functionManifest_t* functionManifest;
                
                functionManifest = &componentManifest->functionManifests[0];
                functionManifest->functionId = (xme_core_component_functionId_t)1;
                functionManifest->wcet = xme_hal_time_timeIntervalFromMilliseconds(2ull);
                functionManifest->alphaCurve.alphaCurve = 0;
                functionManifest->completion = true;
                functionManifest->requiredPortIndicesLength = 1;
                functionManifest->requiredPortIndices[0] = (detector_adv_device_deviceComponentWrapper_internalPortId_t)DETECTOR_ADV_DEVICE_DEVICECOMPONENTWRAPPER_PORT_INFO;
                functionManifest->optionalPortIndicesLength = 0;
                functionManifest->functionInit = (xme_core_exec_initCallback_t)detector_adv_device_operateFunction_init;
                functionManifest->functionFini = (xme_core_exec_finiCallback_t)detector_adv_device_operateFunction_fini;
                functionManifest->functionWrapperExecute = detector_adv_device_operateFunctionWrapper_execute;
            }
        }
    }

    {
        uint32_t portArrayLength;
        portArrayLength = sizeof(componentManifest->portManifests) / sizeof(componentManifest->portManifests[0]);

        // Publication 'info'
        {
            if (0 >= portArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (0 == portArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'device' defines more ports (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                        1,
                        portArrayLength
                    );
                }
            }
            else
            {
                xme_core_componentPortManifest_t* portManifest;
            
                portManifest = &componentManifest->portManifests[0];
                portManifest->portType = XME_CORE_COMPONENT_PORTTYPE_DCC_PUBLICATION;
                portManifest->topic = DETECTOR_TOPIC_DEVICE_INFO; 
                portManifest->lowerConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_INVALID;
                portManifest->upperConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_INVALID;
                portManifest->queueSize = 1;
                portManifest->persistent = false;
        
                portManifest->attrSet = XME_CORE_ATTRIBUTE_EMPTY_ATTRIBUTE_SET;
                
            }
        }
    }
    return XME_STATUS_SUCCESS;
}
