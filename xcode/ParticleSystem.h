//
//  ParticleSystem.h
//  FrownParticleSystem
//
//  Created by Nikolas Psaroudakis on 2/23/14.
//
//

#ifndef __FrownParticleSystem__ParticleSystem__
#define __FrownParticleSystem__ParticleSystem__

#include <iostream>
#include "GroupConstraint.h"
#include "MemberConstraint.h"
#include "cinder/gl/Vbo.h"

namespace frown {
    class ParticleSystem {
    public:
        ParticleSystem( int numParticles );
        void update();
        void draw();
        void addGroupConstraint( GroupConstraintRef constraint );
        void addMemberConstraint( MemberConstraintRef constraint );
    private:
        void applyGroupConstraints();
        void applyMemberConstraints();
        void setup( int numParticles );
        std::vector<MemberConstraintRef>    mMemberConstraints;
        std::vector<GroupConstraintRef>     mGroupConstraints;
        

        
        void                    init();
        uint32_t                mNumParticles;
        GLuint                  mVBO;
        std::vector<ci::Vec3f>  mPositions;
        std::vector<ci::Vec3f>  mVelocities;
        std::vector<ci::Vec3f>  mAccelerations;
    };
}
#endif /* defined(__FrownParticleSystem__ParticleSystem__) */
