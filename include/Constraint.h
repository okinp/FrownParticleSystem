//
//  Constraint.h
//  FrownParticleSystem
//
//  Created by Nikolas Psaroudakis on 2/23/14.
//
//

#ifndef FrownParticleSystem_Constraint_h
#define FrownParticleSystem_Constraint_h
namespace frown {
    template<typename T>
    class Constraint {
    public:
        Constraint();
        void apply( T data );
    private:
    };
}
#endif
