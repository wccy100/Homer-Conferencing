/*****************************************************************************
 *
 * Copyright (C) 2011 Thomas Volkert <thomas@homer-conferencing.com>
 *
 * This software is free software.
 * Your are allowed to redistribute it and/or modify it under the terms of
 * the GNU General Public License version 2 as published by the Free Software
 * Foundation.
 *
 * This source is published in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License version 2 for more details.
 *
 * You should have received a copy of the GNU General Public License version 2
 * along with this program. Otherwise, you can write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02111, USA.
 * Alternatively, you find an online version of the license text under
 * http://www.gnu.org/licenses/gpl-2.0.html.
 *
 *****************************************************************************/

/*
 * Purpose: Requirements
 * Since:   2011-12-08
 */

#ifndef _NAPI_REQUIREMENTS_
#define _NAPI_REQUIREMENTS_

// to simplify including of all requirements
#include <RequirementTransmitLossless.h>
#include <RequirementTransmitChunks.h>
#include <RequirementTransmitStream.h>
#include <RequirementTransmitBitErrors.h>
#include <RequirementTargetPort.h>
#include <RequirementTransmitOrdered.h>
#include <RequirementLimitDelay.h>
#include <RequirementLimitDataRate.h>

#include <IRequirement.h>
#include <HBMutex.h>

#include <vector>

namespace Homer { namespace Base {

///////////////////////////////////////////////////////////////////////////////

typedef std::vector<IRequirement*> RequirementSet;

///////////////////////////////////////////////////////////////////////////////

class Requirements
{
public:
    Requirements();

    virtual ~Requirements();

    virtual std::string getDescription();

    /* manipulation */
    bool add(IRequirement *pRequ);

    /* query functions */
    bool contains(int pType);
    IRequirement* get(int pType);

private:
    void delAll();

    RequirementSet      mRequirementSet;
    Mutex               mRequirementSetMutex;
};

///////////////////////////////////////////////////////////////////////////////

}} // namespaces

#endif
