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
 * $Id: demarshaler.h 6351 2014-01-15 16:03:40Z geisinger $
 */

/**
 * \file
 *
 * \brief  Waypoint that demarshals topic data.
 *
 *         This file has been generated by the CHROMOSOME Modeling Tool (XMT)
 *         (fortiss GmbH).
 */

#ifndef XME_WP_MARSHAL_DEMARSHALERGEN_H
#define XME_WP_MARSHAL_DEMARSHALERGEN_H

/**
 * \defgroup wp_marshal (De-)marshaling related waypoints.
 * @{
 */

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include "xme/core/component.h"
#include "xme/core/dataManagerTypes.h"

#include "xme/wp/waypoint.h"

#include <stdbool.h>
#include <stdint.h>

/******************************************************************************/
/***   Prototypes                                                           ***/
/******************************************************************************/
XME_EXTERN_C_BEGIN

/**
 * \brief  Execute this waypoint.
 *
 * \details Before calling this, you must once add a configuration for the given instanceId, via
 *          xme_wp_marshal_demarshaler_addConfig.
 *          Executing this function will get the marshaled data from the inputPort of the associated
 *          configuration and demarshal the data. The result will be written to the output port of
 *          the associated configuration.
 *
 * \param  instanceId Id of the configuration for which to execute the waypoint, as returned by
 *                    xme_wp_marshal_addConfig.
 *
 * \retval XME_STATUS_SUCCESS if the demarshaling was performed successfully.
 * \retval XME_STATUS_INVALID_HANDLE if no configuration has been added for the given
 *         instanceId.
 * \retval XME_STATUS_INTERNAL_ERROR if there was an error reading from the input port
 *         or writing to the output port. When this value is returned the output port value
 *         must be considered invalid.
 */
xme_status_t
xme_wp_marshal_demarshaler_run
(
    xme_wp_waypoint_instanceId_t instanceId
);

/**
 * \brief  Checks whether a given topic can be handled by this demarshaler.
 *
 * \param  topic Topic to check.
 *
 * \return True when the given topic can be handled by this demarshaler, else false.
 */
bool
xme_wp_marshal_demarshaler_isSupported
(
    xme_core_topic_t topic
);

XME_EXTERN_C_END

/**@}*/

#endif // #ifndef XME_WP_MARSHAL_DEMARSHALERGEN_H
