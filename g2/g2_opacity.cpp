#include "stdafx.h"

#include "g2.h"

namespace g2 {
	namespace Internal {
		float alpha1_parent = 1.f;
		float alpha1_effective = 1.f;
		float alpha2_effective = 1.f;

		std::stack<float> alphaStack;
	}
}

using namespace g2;
using namespace g2::Internal;

void g2::pushOpacity() {
	alphaStack.push(alpha2_effective);
	alphaStack.push(alpha1_effective);
	alphaStack.push(alpha1_parent);

	alpha1_parent = alpha1_effective;
}

void g2::popOpacity() {
	alpha1_parent = alphaStack.top();
	alphaStack.pop();

	alpha1_effective = alphaStack.top();
	alphaStack.pop();

	alpha2_effective = alphaStack.top();
	alphaStack.pop();
}

void g2::opacity(float alpha) {
	g2::Internal::alpha1_effective = g2::Internal::alpha1_parent * alpha;
}

void g2::opacity2(float alpha) {
	alpha2_effective = alpha1_parent * alpha;
}
