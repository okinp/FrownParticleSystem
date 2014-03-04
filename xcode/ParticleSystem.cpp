//
//  ParticleSystem.cpp
//  FrownParticleSystem
//
//  Created by Nikolas Psaroudakis on 2/23/14.
//
//

#include "ParticleSystem.h"
#include <vector>
#include "cinder/Rand.h"
#include "cinder/app/App.h"
namespace frown {
    
    ParticleSystem::ParticleSystem( int numParticles )
    {
        setup(numParticles);
    }
    
    void ParticleSystem::addMemberConstraint(MemberConstraintRef constraint)
    {
        mMemberConstraints.push_back(constraint);
    }
    
    void ParticleSystem::addGroupConstraint( GroupConstraintRef  constraint)
    {
        mGroupConstraints.push_back(constraint);
    }
    
    void ParticleSystem::applyMemberConstraints()
    {
        
    }
    
    void ParticleSystem::applyGroupConstraints()
    {
        
    }
    void ParticleSystem::init()
    {
        mPositions = std::vector<ci::Vec3f>(mNumParticles);
        mVelocities = std::vector<ci::Vec3f>(mNumParticles);
        mAccelerations = std::vector<ci::Vec3f>(mNumParticles);
        for ( int i = 0; i<mNumParticles; ++i )
        {
            mPositions[i] = 200*randVec3f();
            mPositions[i].z = 0;
            mVelocities[i] = ci::Vec3f(3,0,0);
        }
        glGenBuffers(1, &mVBO);
    }
    void ParticleSystem::setup(int numParticles)
    {
        mNumParticles = numParticles;
        init();
        std::vector<Vec2f> texCoords;
        for ( int i = 0; i<mNumParticles; ++i )
        {
            texCoords.push_back(ci::
                                Vec2f(0,0));
        }
    }
    
    void ParticleSystem::update()
    {
        std::vector<ci::Vec3f>::iterator iter;
        
        for (auto& position : mPositions )
        {
            position.x+=1;
        }
        glEnableClientState(GL_VERTEX_ARRAY); // Enables the Vertex array for drawing wit
        glBindBuffer(GL_ARRAY_BUFFER, mVBO);
        glBufferData(GL_ARRAY_BUFFER, mNumParticles*sizeof(Vec3f), &mPositions[0], GL_STREAM_DRAW);
        glVertexPointer(3, GL_FLOAT, 0, 0); // Tell OpenGL that we have 3 coordinates (x, y, z) and the coordinates are stored as floats in the array

    }
    void ParticleSystem::draw()
    {

        // this pair of lines is the standard way to clear the screen in OpenGL
        gl::color(1,1,1);
        glPointSize(1);
        
        // draw the vbo
        glDisable(GL_DEPTH_TEST); // disable depth test (whatever it is)
        glDrawArrays(GL_POINTS, 0, mNumParticles); // render all array data we putted in VBO's as quads, at index 0, and to the end of the arrays
        
        glEnable(GL_DEPTH_TEST);
        glDisableClientState(GL_VERTEX_ARRAY);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
};