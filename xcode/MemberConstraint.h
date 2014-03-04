//
//  MemberConstraint.h
//  FrownParticleSystem
//
//  Created by Nikolas Psaroudakis on 2/23/14.
//
//

#ifndef __FrownParticleSystem__MemberConstraint__
#define __FrownParticleSystem__MemberConstraint__

#include <iostream>
#include <memory>
namespace frown {
    class MemberConstraint {
    public:
        MemberConstraint();
        virtual ~MemberConstraint();
        virtual void apply() = 0;
        
    };
    typedef std::shared_ptr<MemberConstraint> MemberConstraintRef;
}
#endif /* defined(__FrownParticleSystem__MemberConstraint__) */
