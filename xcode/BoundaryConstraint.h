//
//  BoundaryConstraint.h
//  FrownParticleSystem
//
//  Created by Nikolas Psaroudakis on 3/2/14.
//
//

#ifndef __FrownParticleSystem__BoundaryConstraint__
#define __FrownParticleSystem__BoundaryConstraint__

#include <iostream>
#include "MemberConstraint.h"
namespace frown {
    class BoundaryConstraint : public MemberConstraint {
        BoundaryConstraint();
        virtual ~BoundaryConstraint();
        virtual void apply();
    };
    typedef std::shared_ptr<BoundaryConstraint> BoundaryConstraintRef;
}
#endif /* defined(__FrownParticleSystem__BoundaryConstraint__) */
