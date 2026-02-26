/******************************************************************************
*                              BeamAdapter plugin                             *
*                  (c) 2006 Inria, University of Lille, CNRS                  *
*                                                                             *
* This program is free software; you can redistribute it and/or modify it     *
* under the terms of the GNU Lesser General Public License as published by    *
* the Free Software Foundation; either version 2.1 of the License, or (at     *
* your option) any later version.                                             *
*                                                                             *
* This program is distributed in the hope that it will be useful, but WITHOUT *
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       *
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License *
* for more details.                                                           *
*                                                                             *
* You should have received a copy of the GNU Lesser General Public License    *
* along with this program. If not, see <http://www.gnu.org/licenses/>.        *
*******************************************************************************
* Authors: see Authors.md                                                     *
*                                                                             *
* Contact information: contact@sofa-framework.org                             *
******************************************************************************/
#include <sofa/qt/cuda/init.h>

#include <sofa/core/ObjectFactory.h>
#include <sofa/helper/system/PluginManager.h>

namespace sofa::qt::cuda
{

extern "C" {
    SOFA_QT_CUDA_API void initExternalModule();
    SOFA_QT_CUDA_API const char* getModuleLicense();
    SOFA_QT_CUDA_API const char* getModuleName();
    SOFA_QT_CUDA_API const char* getModuleVersion();
    SOFA_QT_CUDA_API const char* getModuleDescription();
    SOFA_QT_CUDA_API void registerObjects(sofa::core::ObjectFactory* factory);
}

void init()
{
    static bool first = true;
    if (first)
    {
        // make sure that this plugin is registered into the PluginManager
        sofa::helper::system::PluginManager::getInstance().registerPlugin(MODULE_NAME);
        
        first = false;
    }
}

//Here are just several convenient functions to help user to know what contains the plugin

void initExternalModule()
{
    init();
}

const char* getModuleLicense()
{
    return "LGPL";
}

const char* getModuleName()
{
    return MODULE_NAME;
}

const char* getModuleVersion()
{
    return MODULE_VERSION;
}

const char* getModuleDescription()
{
    return "CUDA extension of the Sofa.Qt plugin.";
}

void registerObjects(sofa::core::ObjectFactory* factory)
{
    SOFA_UNUSED(factory);
}

} // namespace sofa::qt::cuda
