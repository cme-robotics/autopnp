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
 *         Source file for exampleGUI component.
 *
 * \author
 *         This file has been generated by the CHROMOSOME Modeling Tool (XMT)
 *         (fortiss GmbH).
 */

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include "autoPnP/adv/exampleGUI/include/exampleGUIComponent.h"

// PROTECTED REGION ID(AUTOPNP_ADV_EXAMPLEGUI_EXAMPLEGUICOMPONENT_C_INCLUDES) ENABLED START
#pragma GCC diagnostic ignored "-Wshadow" //TODO find better solution
#include "ros/ros.h"
#include "ros/callback_queue.h"

#include "autoPnP/adv/exampleGUI/include/exampleGUIComponent.h"
#include "xme/hal/include/ros.h" //TODO
#include <iostream>

#include "xme/core/logUtils.h"
#include "autoPnP/topic/autoPnPCommonData.h"
#include "autoPnP/adv/exampleGUI/include/exampleGUIComponentWrapper.h"

#include "/opt/ros/groovy/include/std_msgs/String.h"
// PROTECTED REGION END

/******************************************************************************/
/***   Defines                                                              ***/
/******************************************************************************/

// PROTECTED REGION ID(AUTOPNP_ADV_EXAMPLEGUI_EXAMPLEGUICOMPONENT_C_DEFINES) ENABLED START
// PROTECTED REGION END

/******************************************************************************/
/***   Type definitions                                                     ***/
/******************************************************************************/

// PROTECTED REGION ID(AUTOPNP_ADV_EXAMPLEGUI_EXAMPLEGUICOMPONENT_C_TYPE_DEFINITIONS) ENABLED START
// PROTECTED REGION END

/******************************************************************************/
/***   Variables                                                            ***/
/******************************************************************************/

// PROTECTED REGION ID(ROSGATEWAY_ADV_ROS_EXECUTEROSFUNCTION_C_VARIABLES) ENABLED START
static xme_hal_sched_taskHandle_t rosTaskHandle = XME_HAL_SCHED_INVALID_TASK_HANDLE;
static ros::Subscriber ros_sub_add, ros_sub_rem;
static ros::NodeHandle* nodeHandle;
// PROTECTED REGION END

// PROTECTED REGION ID(AUTOPNP_ADV_EXAMPLEGUI_EXAMPLEGUICOMPONENT_C_VARIABLES) ENABLED START
// PROTECTED REGION END

/******************************************************************************/
/***   Prototypes                                                           ***/
/******************************************************************************/

// PROTECTED REGION ID(ROSGATEWAY_ADV_ROS_EXECUTEROSFUNCTION_C_PROTOTYPES) ENABLED START
static void runROSTaskCallback(void* userData);
// PROTECTED REGION END

// PROTECTED REGION ID(AUTOPNP_ADV_EXAMPLEGUI_EXAMPLEGUICOMPONENT_C_PROTOTYPES) ENABLED START
static void autoPnP_adv_exampleGUI_exampleGUIComponent_createWindow(void* userData);
static void autoPnP_adv_exampleGUI_exampleGUIComponent_task(void* userData);
// PROTECTED REGION END

/******************************************************************************/
/***   Implementation                                                       ***/
/******************************************************************************/


void ros_callback_add(const std_msgs::String& event)
{
    AutoPnP_topic_add_component_t addComponent;
    xme_status_t status;

    strcpy(addComponent.parent, "");
    strcpy(addComponent.name, event.data.c_str());
    addComponent.capabilitiesCount = 0;

    status = autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_writePortAddComponent(&addComponent);
    if (XME_STATUS_SUCCESS != status)
    {
        XME_LOG(XME_LOG_ERROR, "Window::addComponent: Error sending!\n");
    }

    autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_completeWriteOperations();
}

void ros_callback_rem(const std_msgs::String& event)
{
    AutoPnP_topic_remove_component_t remComponent;
    xme_status_t status;

    strcpy(remComponent.name, event.data.c_str());

    status = autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_writePortRemoveComponent(&remComponent);
    if (XME_STATUS_SUCCESS != status)
    {
        XME_LOG(XME_LOG_ERROR, "Window::removeComponent: Error sending!\n");
    }

    autoPnP_adv_exampleGUI_exampleGUIComponentWrapper_completeWriteOperations();
}


xme_status_t
autoPnP_adv_exampleGUI_exampleGUIComponent_init
(
    autoPnP_adv_exampleGUI_exampleGUIComponent_config_t* const config,
    const char* initializationString
)
{
    xme_hal_ros_init();

    nodeHandle = new ros::NodeHandle();
    ros_sub_add = nodeHandle->subscribe("/chromosom/addComponent", 1, ros_callback_add);
    ros_sub_rem = nodeHandle->subscribe("/chromosom/remComponent", 1, ros_callback_rem);

    rosTaskHandle = xme_hal_sched_addTask(xme_hal_time_timeIntervalFromMilliseconds(0), xme_hal_time_timeIntervalFromMilliseconds(50), 0, runROSTaskCallback, NULL);
    if (XME_HAL_SCHED_INVALID_TASK_HANDLE == rosTaskHandle)
    {
        XME_EXIT(EXIT_FAILURE, "Error creating runROSThread\n");
    }
    // PROTECTED REGION ID(AUTOPNP_ADV_EXAMPLEGUI_EXAMPLEGUICOMPONENT_C_INITIALIZE) ENABLED START
	XME_UNUSED_PARAMETER(initializationString);

	//xme_hal_qt_taskHandlexme_hal_sched_addTask(xme_hal_time_timeIntervalFromMilliseconds(0), xme_hal_time_timeIntervalFromMilliseconds(0), 0, xme_hal_qt_task, NULL);
	config->taskHandle = xme_hal_sched_addTask(xme_hal_time_timeIntervalFromMilliseconds(3000), xme_hal_time_timeIntervalFromMilliseconds(0), 0, autoPnP_adv_exampleGUI_exampleGUIComponent_task, config);
	// Check for errors
	XME_CHECK(XME_HAL_SCHED_INVALID_TASK_HANDLE != config->taskHandle, XME_STATUS_INTERNAL_ERROR);
	return XME_STATUS_SUCCESS;
    // PROTECTED REGION END
}

void
autoPnP_adv_exampleGUI_exampleGUIComponent_fini
(
    autoPnP_adv_exampleGUI_exampleGUIComponent_config_t* const config
)
{
    // PROTECTED REGION ID(AUTOPNP_ADV_EXAMPLEGUI_EXAMPLEGUICOMPONENT_C_FINALIZE) ENABLED START
    //delete config->window;

    xme_hal_sched_removeTask(rosTaskHandle);
    xme_hal_ros_fini();
    // PROTECTED REGION END
}

// PROTECTED REGION ID(AUTOPNP_ADV_EXAMPLEGUI_EXAMPLEGUICOMPONENT_C_IMPLEMENTATION) ENABLED START
static void autoPnP_adv_exampleGUI_exampleGUIComponent_createWindow(void* userData)
{
	autoPnP_adv_exampleGUI_exampleGUIComponent_config_t* config = (autoPnP_adv_exampleGUI_exampleGUIComponent_config_t*)userData;

    //config->window = new Window();
    //config->window->show();
}

static void autoPnP_adv_exampleGUI_exampleGUIComponent_task(void* userData)
{
	autoPnP_adv_exampleGUI_exampleGUIComponent_config_t* config = (autoPnP_adv_exampleGUI_exampleGUIComponent_config_t*)userData;

	xme_hal_qt_triggerExecution(autoPnP_adv_exampleGUI_exampleGUIComponent_createWindow, config);
}
// PROTECTED REGION END

// PROTECTED REGION ID(ROSGATEWAY_ADV_ROS_EXECUTEROSFUNCTION_IMPLEMENTATION_C) ENABLED START
static void runROSTaskCallback(void* userData)
{
    XME_UNUSED_PARAMETER(userData);

    xme_hal_ros_spin();

    XME_EXIT(EXIT_FAILURE, "ROS has been shut-down!\n");
}
// PROTECTED REGION END
