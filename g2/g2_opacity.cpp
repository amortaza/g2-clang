#include "stdafx.h"

#include "g2/g2.h"

namespace g2 {
	namespace Internal {
		float alpha1_effective = 1.f;
		float alpha2_effective = 1.f;
	}
}

using namespace g2;
using namespace g2::Internal;

void g2::opacity(float alpha) {
	alpha1_effective = alpha;
}

void g2::opacity2(float alpha) {
	alpha2_effective = alpha;
}
