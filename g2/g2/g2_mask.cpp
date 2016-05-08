#include "stdafx.h"

#include "g2_core.h"
#include "g2_externals.h"

using namespace g2;
using namespace g2::Internal;

void g2::mask(TextureRef* ref) {
	current_mask_ref = ref;
}