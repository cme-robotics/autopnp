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
 * $Id$
 */

/**
 * \file
 *         Component wrapper - implements interface of a component
 *              to the data handler
 *
 * \author
 *         This file has been generated by the CHROMOSOME Modeling Tool (XMT)
 *         (fortiss GmbH).
 */

#ifndef AUTOPNP_ADV_CAPABILITIESVIEW_CAPABILITIESVIEWCOMPONENTWRAPPER_H
#define AUTOPNP_ADV_CAPABILITIESVIEW_CAPABILITIESVIEWCOMPONENTWRAPPER_H

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include "xme/core/executionManager/include/executionManagerDataStructures.h"

#include "xme/core/topicData.h"
#include "autoPnP/topic/AutoPnPCommonData.h"

/******************************************************************************/
/***   Type definitions                                                     ***/
/******************************************************************************/

/**
 * \enum autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_internalFunctionId_e
 *
 * \brief Values for identifying functions of capabilitiesView component.
 */
enum autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_internalFunctionId_e
{
    AUTOPNP_ADV_CAPABILITIESVIEW_CAPABILITIESVIEWCOMPONENTWRAPPER_FUNCTION_ADDCOMPONENT = 0, ///< Function 'addComponent'
    AUTOPNP_ADV_CAPABILITIESVIEW_CAPABILITIESVIEWCOMPONENTWRAPPER_FUNCTION_REMOVECOMPONENT = 1  ///< Function 'removeComponent'
};

/**
 * \enum autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_internalPortId_e
 *
 * \brief Values for autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_internalPortId_t.
 */
enum autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_internalPortId_e
{
    AUTOPNP_ADV_CAPABILITIESVIEW_CAPABILITIESVIEWCOMPONENTWRAPPER_PORT_ADDCOMPONENT = 0, ///< Port 'addComponent'
    AUTOPNP_ADV_CAPABILITIESVIEW_CAPABILITIESVIEWCOMPONENTWRAPPER_PORT_REMOVECOMPONENT = 1  ///< Port 'removeComponent'
};

/**
 * \typedef autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_internalPortId_t
 *
 * \brief Defines internal port ids of component 'capabilitiesView'.
 *
 * \details These can be used when calling the autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_receivePort function.
 *          For the definition of possible values, see enum autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_internalPortId_e.
 */
typedef uint8_t autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_internalPortId_t;

/******************************************************************************/
/***   Prototypes                                                           ***/
/******************************************************************************/
XME_EXTERN_C_BEGIN

/**
 * \brief Initializes this component wrapper.
 *
 * \retval XME_STATUS_SUCCESS on success.
 */
xme_status_t
autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_init(void);

/**
 * \brief Finalizes this component wrapper.
 */
void
autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_fini(void);

/**
 * \brief Associate an internal port number with the corresponding port handle.
 *        For the ids of the individual ports, see the definition of autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_internalPortId_t.
 *
 * \param dataPacketId Port handle from the dataHandler.
 * \param componentInternalPortId Component internal port number of the above port.
 *
 * \retval XME_STATUS_SUCCESS if no problems occurred.
 * \retval XME_STATUS_INVALID_PARAMETER if componentInternalPortId is unknown.
 */
xme_status_t
autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_receivePort
(
    xme_core_dataManager_dataPacketId_t dataPacketId,
    autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_internalPortId_t componentInternalPortId
);

/**
 * \brief This function is called by the function wrapper after the step
 *        function has been called. It signals to the middleware that all
 *        input ports have been read.
 */
void
autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_completeReadOperations(void);

/**
 * \brief Read data from port 'addComponent'.
 *
 * \param[out] data User provided storage, to which the data is copied.
 *
 * \retval XME_STATUS_SUCCESS if reading was successful.
 * \retval XME_STATUS_NO_SUCH_VALUE when there is now new data on this port
 *         (only possible when this port is an optional port of the current function).
 * \retval XME_STATUS_INVALID_PARAMETER if data is NULL.
 * \retval XME_STATUS_INTERNAL_ERROR in case of any other error.
 */
xme_status_t
autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_readPortAddComponent
(
    const AutoPnP_topic_add_component_t* data
);

/**
 * \brief Read data from port 'removeComponent'.
 *
 * \param[out] data User provided storage, to which the data is copied.
 *
 * \retval XME_STATUS_SUCCESS if reading was successful.
 * \retval XME_STATUS_NO_SUCH_VALUE when there is now new data on this port
 *         (only possible when this port is an optional port of the current function).
 * \retval XME_STATUS_INVALID_PARAMETER if data is NULL.
 * \retval XME_STATUS_INTERNAL_ERROR in case of any other error.
 */
xme_status_t
autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_readPortRemoveComponent
(
    const AutoPnP_topic_remove_component_t* data
);

xme_status_t
autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_readInputPortAttribute
(
    autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_internalPortId_t portId,
    xme_core_attribute_key_t attributeKey,
    void* const buffer,
    uint32_t bufferSize
);

xme_status_t
autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_readNextPacket
(
    autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_internalPortId_t portId
);


XME_EXTERN_C_END

#endif // #ifndef AUTOPNP_ADV_CAPABILITIESVIEW_CAPABILITIESVIEWCOMPONENTWRAPPER_H
