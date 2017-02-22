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
 * $Id: monitorBManifest.c 7769 2014-03-11 15:27:13Z geisinger $
 */

/**
 * \file
 *         Defines function for creation of component type manifest
 *         for 'monitorB'.
 *
 * \author
 *         This file has been generated by the CHROMOSOME Modeling Tool (XMT)
 *         (fortiss GmbH).
 */

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include "sensorMonitor/adv/monitorB/include/monitorBManifest.h"

#include "../include/monitorBComponentWrapper.h"
#include "sensorMonitor/adv/monitorB/include/monitorBComponent.h"
#include "sensorMonitor/adv/monitorB/include/printSensorValueFunction.h"
#include "sensorMonitor/adv/monitorB/include/printSensorValueFunctionWrapper.h"
#include "sensorMonitor/topic/dictionary.h"
#include "xme/core/log.h"
#include "xme/hal/include/time.h"

/******************************************************************************/
/***   Implementation                                                       ***/
/******************************************************************************/
xme_status_t
sensorMonitor_adv_monitorB_manifest_createComponentTypeManifest
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

    componentManifest->componentType = (xme_core_componentType_t)4361;
    componentManifest->componentWrapperInit = sensorMonitor_adv_monitorB_monitorBComponentWrapper_init;
    componentManifest->componentWrapperReceivePort = sensorMonitor_adv_monitorB_monitorBComponentWrapper_receivePort;
    componentManifest->componentWrapperFini = sensorMonitor_adv_monitorB_monitorBComponentWrapper_fini;
    componentManifest->componentInit = (xme_core_componentManifest_componentInit_t)sensorMonitor_adv_monitorB_monitorBComponent_init;
    (void)xme_hal_safeString_strncpy(componentManifest->name, "monitorB", sizeof(componentManifest->name));
    componentManifest->configStructSize = sizeof(sensorMonitor_adv_monitorB_monitorBComponent_config_t);

    {
        uint32_t functionArrayLength = sizeof(componentManifest->functionManifests) / sizeof(componentManifest->functionManifests[0]);

        // Function 'printSensorValue'
        {
            if (0U >= functionArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (0U == functionArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'monitorB' defines more functions (%d) than can be stored in the manifest data structure (%d).\n",
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
                functionManifest->wcet = xme_hal_time_timeIntervalFromMilliseconds(100ull);
                functionManifest->alphaCurve.alphaCurve = 0;
                functionManifest->completion = true;
                functionManifest->requiredPortIndicesLength = 1;
                functionManifest->requiredPortIndices[0] = (sensorMonitor_adv_monitorB_monitorBComponentWrapper_internalPortId_t)SENSORMONITOR_ADV_MONITORB_MONITORBCOMPONENTWRAPPER_PORT_SENSORVALUEIN;
                functionManifest->optionalPortIndicesLength = 0;
                functionManifest->functionInit = (xme_core_exec_initCallback_t)sensorMonitor_adv_monitorB_printSensorValueFunction_init;
                functionManifest->functionFini = (xme_core_exec_finiCallback_t)sensorMonitor_adv_monitorB_printSensorValueFunction_fini;
                functionManifest->functionWrapperExecute = sensorMonitor_adv_monitorB_printSensorValueFunctionWrapper_execute;
            }
        }
    }

    {
        uint32_t portArrayLength;
        portArrayLength = sizeof(componentManifest->portManifests) / sizeof(componentManifest->portManifests[0]);

        // Subscription 'sensorValueIn'
        {
            if (0 >= portArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (0 == portArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'monitorB' defines more ports (%d) than can be stored in the manifest data structure (%d).\n",
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
                xme_status_t status;
            
                portManifest = &componentManifest->portManifests[0];
                portManifest->portType = XME_CORE_COMPONENT_PORTTYPE_DCC_SUBSCRIPTION;
                portManifest->topic = SENSORMONITOR_TOPIC_SENSORDATA; 
                portManifest->lowerConnectionBound = 0u;
                portManifest->upperConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_UNBOUNDED;
                portManifest->queueSize = 1;
                portManifest->persistent = false;
        
                portManifest->attrSet = xme_core_directory_attribute_createAttributeSet();
                
                // Add attribute filter: unit == SENSORMONITOR_ATTRIBUTE_UNIT_BYTES
                {
                    uint32_t value = SENSORMONITOR_ATTRIBUTE_UNIT_BYTES;
                    
                    status = xme_core_directory_attribute_addPredefinedAttributeFilter
                    (
                        portManifest->attrSet,
                        (xme_core_attribute_key_t)SENSORMONITOR_ATTRIBUTE_UNIT,
                        &value,
                        1U,
                        sizeof(value), 
                        XME_CORE_DIRECTORY_ATTRIBUTE_DATATYPE_UNSIGNED,
                        XME_CORE_DIRECTORY_ATTRIBUTE_FILTEROPERATION_EQUAL,
                        false
                    );
                    XME_CHECK(XME_STATUS_SUCCESS == status, XME_STATUS_INTERNAL_ERROR);
                }
            }
        }
    }
    return XME_STATUS_SUCCESS;
}
