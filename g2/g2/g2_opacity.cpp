#include "stdafx.h"

#include "g2.h"

namespace g2 {
	namespace Internal {
		float alpha1 = 1.f;
		float alpha2 = 1.f;
	}
}

using namespace g2;
using namespace g2::Internal;

void g2::opacity(float alpha) {
	alpha1 = alpha;
}

void g2::opacity2(float alpha) {
	alpha2 = alpha;
}
