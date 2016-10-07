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
 * $Id: pnpManagerManifest.c 7768 2014-03-11 15:08:26Z geisinger $
 */

/**
 * \file
 *         Defines function for creation of component type manifest
 *         for 'pnpManager'.
 *
 * \author
 *         This file has been generated by the CHROMOSOME Modeling Tool (XMT)
 *         (fortiss GmbH).
 */

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include "xme/core/plugAndPlay/include-gen/pnpManagerManifest.h"

#include "xme/core/log.h"
#include "xme/core/plugAndPlay/include-gen/plugAndPlayManagerComponent.h"
#include "xme/core/plugAndPlay/include-gen/plugAndPlayManagerComponentWrapper.h"
#include "xme/core/plugAndPlay/include-gen/plugAndPlayManagerGenerateRuntimeGraphsFunction.h"
#include "xme/core/plugAndPlay/include-gen/plugAndPlayManagerGenerateRuntimeGraphsFunctionWrapper.h"
#include "xme/core/plugAndPlay/include-gen/plugAndPlayManagerProcessLoginRegistrationFunction.h"
#include "xme/core/plugAndPlay/include-gen/plugAndPlayManagerProcessLoginRegistrationFunctionWrapper.h"
#include "xme/core/plugAndPlay/include-gen/plugAndPlayManagerProcessLogoutAcknowledgmentsFunction.h"
#include "xme/core/plugAndPlay/include-gen/plugAndPlayManagerProcessLogoutAcknowledgmentsFunctionWrapper.h"
#include "xme/core/plugAndPlay/include-gen/plugAndPlayManagerProcessLogoutRequestsFunction.h"
#include "xme/core/plugAndPlay/include-gen/plugAndPlayManagerProcessLogoutRequestsFunctionWrapper.h"
#include "xme/core/plugAndPlay/include-gen/plugAndPlayManagerProcessRemoveComponentRequestFunction.h"
#include "xme/core/plugAndPlay/include-gen/plugAndPlayManagerProcessRemoveComponentRequestFunctionWrapper.h"
#include "xme/hal/include/time.h"

/******************************************************************************/
/***   Implementation                                                       ***/
/******************************************************************************/
xme_status_t
xme_core_pnp_pnpManager_manifest_createComponentTypeManifest
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

    componentManifest->componentType = (xme_core_componentType_t)1;
    componentManifest->componentWrapperInit = xme_core_pnp_pnpManagerComponentWrapper_init;
    componentManifest->componentWrapperReceivePort = xme_core_pnp_pnpManagerComponentWrapper_receivePort;
    componentManifest->componentWrapperFini = xme_core_pnp_pnpManagerComponentWrapper_fini;
    componentManifest->componentInit = (xme_core_componentManifest_componentInit_t)xme_core_pnp_pnpManagerComponent_init;
    (void)xme_hal_safeString_strncpy(componentManifest->name, "pnpManager", sizeof(componentManifest->name));
    componentManifest->configStructSize = sizeof(xme_core_pnp_pnpManagerComponent_config_t);

    {
        uint32_t functionArrayLength = sizeof(componentManifest->functionManifests) / sizeof(componentManifest->functionManifests[0]);

        // Function 'pnpManagerGenerateRuntimeGraphs'
        {
            if (0U >= functionArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (0U == functionArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'pnpManager' defines more functions (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                       5,
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
                functionManifest->requiredPortIndices[0] = (xme_core_pnp_pnpManagerComponentWrapper_internalPortId_t)XME_CORE_PNP_PNPMANAGERCOMPONENTWRAPPER_PORT_OUTRUNTIMEGRAPH;
                functionManifest->optionalPortIndicesLength = 1;
                functionManifest->optionalPortIndices[0] = (xme_core_pnp_pnpManagerComponentWrapper_internalPortId_t)XME_CORE_PNP_PNPMANAGERCOMPONENTWRAPPER_PORT_INCOMPONENTINSTANCEMANIFEST;
                functionManifest->functionInit = (xme_core_exec_initCallback_t)xme_core_pnp_pnpManagerGenerateRuntimeGraphsFunction_init;
                functionManifest->functionFini = (xme_core_exec_finiCallback_t)xme_core_pnp_pnpManagerGenerateRuntimeGraphsFunction_fini;
                functionManifest->functionWrapperExecute = xme_core_pnp_pnpManagerGenerateRuntimeGraphsFunctionWrapper_execute;
            }
        }
        // Function 'pnpManagerProcessLoginRegistration'
        {
            if (1U >= functionArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (1U == functionArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'pnpManager' defines more functions (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                       5,
                       functionArrayLength
                    );
                }
            }
            else
            {
                xme_core_functionManifest_t* functionManifest;
                
                functionManifest = &componentManifest->functionManifests[1];
                functionManifest->functionId = (xme_core_component_functionId_t)2;
                functionManifest->wcet = xme_hal_time_timeIntervalFromMilliseconds(100ull);
                functionManifest->alphaCurve.alphaCurve = 0;
                functionManifest->completion = true;
                functionManifest->requiredPortIndicesLength = 2;
                functionManifest->requiredPortIndices[0] = (xme_core_pnp_pnpManagerComponentWrapper_internalPortId_t)XME_CORE_PNP_PNPMANAGERCOMPONENTWRAPPER_PORT_INPNPLOGINREQUEST;
                functionManifest->requiredPortIndices[1] = (xme_core_pnp_pnpManagerComponentWrapper_internalPortId_t)XME_CORE_PNP_PNPMANAGERCOMPONENTWRAPPER_PORT_OUTPNPLOGINRESPONSE;
                functionManifest->optionalPortIndicesLength = 0;
                functionManifest->functionInit = (xme_core_exec_initCallback_t)xme_core_pnp_pnpManagerProcessLoginRegistrationFunction_init;
                functionManifest->functionFini = (xme_core_exec_finiCallback_t)xme_core_pnp_pnpManagerProcessLoginRegistrationFunction_fini;
                functionManifest->functionWrapperExecute = xme_core_pnp_pnpManagerProcessLoginRegistrationFunctionWrapper_execute;
            }
        }
        // Function 'pnpManagerProcessLogoutRequests'
        {
            if (2U >= functionArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (2U == functionArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'pnpManager' defines more functions (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                       5,
                       functionArrayLength
                    );
                }
            }
            else
            {
                xme_core_functionManifest_t* functionManifest;
                
                functionManifest = &componentManifest->functionManifests[2];
                functionManifest->functionId = (xme_core_component_functionId_t)3;
                functionManifest->wcet = xme_hal_time_timeIntervalFromMilliseconds(10ull);
                functionManifest->alphaCurve.alphaCurve = 0;
                functionManifest->completion = true;
                functionManifest->requiredPortIndicesLength = 0;
                functionManifest->optionalPortIndicesLength = 1;
                functionManifest->optionalPortIndices[0] = (xme_core_pnp_pnpManagerComponentWrapper_internalPortId_t)XME_CORE_PNP_PNPMANAGERCOMPONENTWRAPPER_PORT_INLOGOUTREQUEST;
                functionManifest->functionInit = (xme_core_exec_initCallback_t)xme_core_pnp_pnpManagerProcessLogoutRequestsFunction_init;
                functionManifest->functionFini = (xme_core_exec_finiCallback_t)xme_core_pnp_pnpManagerProcessLogoutRequestsFunction_fini;
                functionManifest->functionWrapperExecute = xme_core_pnp_pnpManagerProcessLogoutRequestsFunctionWrapper_execute;
            }
        }
        // Function 'pnpManagerProcessLogoutAcknowledgments'
        {
            if (3U >= functionArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (3U == functionArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'pnpManager' defines more functions (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                       5,
                       functionArrayLength
                    );
                }
            }
            else
            {
                xme_core_functionManifest_t* functionManifest;
                
                functionManifest = &componentManifest->functionManifests[3];
                functionManifest->functionId = (xme_core_component_functionId_t)4;
                functionManifest->wcet = xme_hal_time_timeIntervalFromMilliseconds(10ull);
                functionManifest->alphaCurve.alphaCurve = 0;
                functionManifest->completion = true;
                functionManifest->requiredPortIndicesLength = 1;
                functionManifest->requiredPortIndices[0] = (xme_core_pnp_pnpManagerComponentWrapper_internalPortId_t)XME_CORE_PNP_PNPMANAGERCOMPONENTWRAPPER_PORT_INLOGOUTACKNOWLEDGMENT;
                functionManifest->optionalPortIndicesLength = 1;
                functionManifest->optionalPortIndices[0] = (xme_core_pnp_pnpManagerComponentWrapper_internalPortId_t)XME_CORE_PNP_PNPMANAGERCOMPONENTWRAPPER_PORT_OUTLOGOUTNOTIFICATION;
                functionManifest->functionInit = (xme_core_exec_initCallback_t)xme_core_pnp_pnpManagerProcessLogoutAcknowledgmentsFunction_init;
                functionManifest->functionFini = (xme_core_exec_finiCallback_t)xme_core_pnp_pnpManagerProcessLogoutAcknowledgmentsFunction_fini;
                functionManifest->functionWrapperExecute = xme_core_pnp_pnpManagerProcessLogoutAcknowledgmentsFunctionWrapper_execute;
            }
        }
        // Function 'pnpManagerProcessRemoveComponentRequest'
        {
            if (4U >= functionArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (4U == functionArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'pnpManager' defines more functions (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                       5,
                       functionArrayLength
                    );
                }
            }
            else
            {
                xme_core_functionManifest_t* functionManifest;
                
                functionManifest = &componentManifest->functionManifests[4];
                functionManifest->functionId = (xme_core_component_functionId_t)5;
                functionManifest->wcet = xme_hal_time_timeIntervalFromMilliseconds(5ull);
                functionManifest->alphaCurve.alphaCurve = 0;
                functionManifest->completion = true;
                functionManifest->requiredPortIndicesLength = 1;
                functionManifest->requiredPortIndices[0] = (xme_core_pnp_pnpManagerComponentWrapper_internalPortId_t)XME_CORE_PNP_PNPMANAGERCOMPONENTWRAPPER_PORT_INREMOVECOMPONENTREQUEST;
                functionManifest->optionalPortIndicesLength = 0;
                functionManifest->functionInit = (xme_core_exec_initCallback_t)xme_core_pnp_pnpManagerProcessRemoveComponentRequestFunction_init;
                functionManifest->functionFini = (xme_core_exec_finiCallback_t)xme_core_pnp_pnpManagerProcessRemoveComponentRequestFunction_fini;
                functionManifest->functionWrapperExecute = xme_core_pnp_pnpManagerProcessRemoveComponentRequestFunctionWrapper_execute;
            }
        }
    }

    {
        uint32_t portArrayLength;
        portArrayLength = sizeof(componentManifest->portManifests) / sizeof(componentManifest->portManifests[0]);

        // Subscription 'inComponentInstanceManifest'
        {
            if (0 >= portArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (0 == portArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'pnpManager' defines more ports (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                        8,
                        portArrayLength
                    );
                }
            }
            else
            {
                xme_core_componentPortManifest_t* portManifest;
            
                portManifest = &componentManifest->portManifests[0];
                portManifest->portType = XME_CORE_COMPONENT_PORTTYPE_DCC_SUBSCRIPTION;
                portManifest->topic = XME_CORE_TOPIC_PNP_COMPONENTINSTANCEMANIFEST; 
                portManifest->lowerConnectionBound = 0u;
                portManifest->upperConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_UNBOUNDED;
                portManifest->queueSize = 1;
                portManifest->persistent = false;
        
                portManifest->attrSet = XME_CORE_ATTRIBUTE_EMPTY_ATTRIBUTE_SET;
            }
        }
        // Subscription 'inPnPLoginRequest'
        {
            if (1 >= portArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (1 == portArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'pnpManager' defines more ports (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                        8,
                        portArrayLength
                    );
                }
            }
            else
            {
                xme_core_componentPortManifest_t* portManifest;
            
                portManifest = &componentManifest->portManifests[1];
                portManifest->portType = XME_CORE_COMPONENT_PORTTYPE_DCC_SUBSCRIPTION;
                portManifest->topic = XME_CORE_TOPIC_LOGIN_PNPLOGINREQUEST; 
                portManifest->lowerConnectionBound = 0u;
                portManifest->upperConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_UNBOUNDED;
                portManifest->queueSize = 1;
                portManifest->persistent = false;
        
                portManifest->attrSet = XME_CORE_ATTRIBUTE_EMPTY_ATTRIBUTE_SET;
            }
        }
        // Subscription 'inLogoutRequest'
        {
            if (2 >= portArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (2 == portArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'pnpManager' defines more ports (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                        8,
                        portArrayLength
                    );
                }
            }
            else
            {
                xme_core_componentPortManifest_t* portManifest;
            
                portManifest = &componentManifest->portManifests[2];
                portManifest->portType = XME_CORE_COMPONENT_PORTTYPE_DCC_SUBSCRIPTION;
                portManifest->topic = XME_CORE_TOPIC_PNP_LOGOUTREQUEST; 
                portManifest->lowerConnectionBound = 0u;
                portManifest->upperConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_UNBOUNDED;
                portManifest->queueSize = 1;
                portManifest->persistent = false;
        
                portManifest->attrSet = XME_CORE_ATTRIBUTE_EMPTY_ATTRIBUTE_SET;
            }
        }
        // Subscription 'inLogoutAcknowledgment'
        {
            if (3 >= portArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (3 == portArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'pnpManager' defines more ports (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                        8,
                        portArrayLength
                    );
                }
            }
            else
            {
                xme_core_componentPortManifest_t* portManifest;
            
                portManifest = &componentManifest->portManifests[3];
                portManifest->portType = XME_CORE_COMPONENT_PORTTYPE_DCC_SUBSCRIPTION;
                portManifest->topic = XME_CORE_TOPIC_PNP_LOGOUTACKNOWLEDGMENT; 
                portManifest->lowerConnectionBound = 0u;
                portManifest->upperConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_UNBOUNDED;
                portManifest->queueSize = 1;
                portManifest->persistent = false;
        
                portManifest->attrSet = XME_CORE_ATTRIBUTE_EMPTY_ATTRIBUTE_SET;
            }
        }
        // Subscription 'inRemoveComponentRequest'
        {
            if (4 >= portArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (4 == portArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'pnpManager' defines more ports (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                        8,
                        portArrayLength
                    );
                }
            }
            else
            {
                xme_core_componentPortManifest_t* portManifest;
            
                portManifest = &componentManifest->portManifests[4];
                portManifest->portType = XME_CORE_COMPONENT_PORTTYPE_DCC_SUBSCRIPTION;
                portManifest->topic = XME_CORE_TOPIC_PNP_REMOVECOMPONENTREQUEST; 
                portManifest->lowerConnectionBound = 0u;
                portManifest->upperConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_UNBOUNDED;
                portManifest->queueSize = 1;
                portManifest->persistent = false;
        
                portManifest->attrSet = XME_CORE_ATTRIBUTE_EMPTY_ATTRIBUTE_SET;
            }
        }
        // Publication 'outRuntimeGraph'
        {
            if (5 >= portArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (5 == portArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'pnpManager' defines more ports (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                        8,
                        portArrayLength
                    );
                }
            }
            else
            {
                xme_core_componentPortManifest_t* portManifest;
            
                portManifest = &componentManifest->portManifests[5];
                portManifest->portType = XME_CORE_COMPONENT_PORTTYPE_DCC_PUBLICATION;
                portManifest->topic = XME_CORE_TOPIC_PNPMANAGER_RUNTIME_GRAPH_MODEL; 
                portManifest->lowerConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_INVALID;
                portManifest->upperConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_INVALID;
                portManifest->queueSize = 1;
                portManifest->persistent = false;
        
                portManifest->attrSet = XME_CORE_ATTRIBUTE_EMPTY_ATTRIBUTE_SET;
                
            }
        }
        // Publication 'outPnPLoginResponse'
        {
            if (6 >= portArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (6 == portArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'pnpManager' defines more ports (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                        8,
                        portArrayLength
                    );
                }
            }
            else
            {
                xme_core_componentPortManifest_t* portManifest;
            
                portManifest = &componentManifest->portManifests[6];
                portManifest->portType = XME_CORE_COMPONENT_PORTTYPE_DCC_PUBLICATION;
                portManifest->topic = XME_CORE_TOPIC_LOGIN_PNPLOGINRESPONSE; 
                portManifest->lowerConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_INVALID;
                portManifest->upperConnectionBound = XME_CORE_COMPONENT_CONNECTIONBOUND_INVALID;
                portManifest->queueSize = 1;
                portManifest->persistent = false;
        
                portManifest->attrSet = XME_CORE_ATTRIBUTE_EMPTY_ATTRIBUTE_SET;
                
            }
        }
        // Publication 'outLogoutNotification'
        {
            if (7 >= portArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (7 == portArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'pnpManager' defines more ports (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                        8,
                        portArrayLength
                    );
                }
            }
            else
            {
                xme_core_componentPortManifest_t* portManifest;
            
                portManifest = &componentManifest->portManifests[7];
                portManifest->portType = XME_CORE_COMPONENT_PORTTYPE_DCC_PUBLICATION;
                portManifest->topic = XME_CORE_TOPIC_PNP_LOGOUTNOTIFICATION; 
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
