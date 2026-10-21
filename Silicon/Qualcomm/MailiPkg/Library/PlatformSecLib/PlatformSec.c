/**
  Copyright (c) 2011-2012, ARM Limited. All rights reserved.
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include <Library/PlatformSecLib.h>

VOID
PlatformInitialize ()
{
  //
  // The inherited implementation detached a list of MDP stream IDs from the
  // SMMU. That list came from SM8850; this device's DTB describes a different
  // set on its display node, so the correct IDs are still unknown. Doing
  // nothing here tells us whether the detach was what stopped SEC.
  //
}
