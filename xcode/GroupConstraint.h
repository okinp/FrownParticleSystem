//
//  GroupConstraint.h
//  FrownParticleSystem
//
//  Created by Nikolas Psaroudakis on 2/24/14.
//
//

#ifndef __FrownParticleSystem__GroupConstraint__
#define __FrownParticleSystem__GroupConstraint__

#include <iostream>
#include "cinder/gl/Vbo.h"
namespace frown {
    using namespace ci;
    class GroupConstraint {
    public:
        GroupConstraint();
        virtual ~GroupConstraint();
        virtual void apply( gl::VboMeshRef mVboMesh ) = 0;
    private:
        
    };
    typedef std::shared_ptr<GroupConstraint> GroupConstraintRef;
}

#endif /* defined(__FrownParticleSystem__GroupConstraint__) */
